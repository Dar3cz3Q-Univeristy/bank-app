DROP DATABASE AGHBank

CREATE DATABASE AGHBank

USE AGHBank

/*
*
* Tworzenie tabel
*
*/

CREATE TABLE PersonLogins (
	PersonID int PRIMARY KEY IDENTITY(1,1),
	Username varchar(50) NOT NULL UNIQUE,
	Password char(60) NOT NULL,
	CreatedTime datetime DEFAULT GETDATE() NOT NULL,
	Active bit DEFAULT 1
);

CREATE TABLE PersonDetails(
	PersonID int PRIMARY KEY IDENTITY(1,1) REFERENCES PersonLogins(PersonID),
	Forename varchar(50) NOT NULL,
	Surname varchar(50) NOT NULL,
	Pesel char(11) NOT NULL,
	IdentityCardNumber char(9) NOT NULL,
	BirthDate date NOT NULL,
	EMail varchar(50) NOT NULL UNIQUE,
	PhoneNumber char(9) NOT NULL UNIQUE
);

CREATE TABLE BankAccountTypes(
	TypeID int PRIMARY KEY IDENTITY(1,1),
	Name nvarchar(50) NOT NULL,
);

CREATE TABLE Currencies(
	CurrencyID int PRIMARY KEY IDENTITY(1,1),
	Name nvarchar(50) NOT NULL,
	Shortcut char(3) NOT NULL,
	ExchangeRate money NOT NULL,
	ExchangeDate date NOT NULL
);

CREATE TABLE BankAccounts(
	AccountID int PRIMARY KEY IDENTITY(1,1),
	PersonID int REFERENCES PersonDetails(PersonID),
	TypeID int REFERENCES BankAccountTypes(TypeID),
	Number char(35) NOT NULL UNIQUE,
	Balance money NOT NULL DEFAULT 0,
	Currency int REFERENCES Currencies(CurrencyID),
	Active bit DEFAULT 1 NOT NULL,
	CHECK (Balance >= 0),
);

CREATE TABLE TransactionTypes(
	TypeID int PRIMARY KEY IDENTITY(1,1),
	Name varchar(50) NOT NULL
);

CREATE TABLE Transactions(
	TransferID int PRIMARY KEY IDENTITY(1,1),
	StartingAccountID int REFERENCES BankAccounts(AccountID),
	DestinationAccountID int NOT NULL,
	Amount money NOT NULL,
	AmountInAccountMainCurrency money NOT NULL,
	Title varchar(100) DEFAULT 'Przelew œrodków',
	CurrencyID int REFERENCES Currencies(CurrencyID),
	TypeID int REFERENCES TransactionTypes(TypeID),
	TransferDate datetime DEFAULT GETDATE() NOT NULL,
	CHECK (Amount > 0)
);

CREATE TABLE Contractors(
	ContractorID int PRIMARY KEY IDENTITY(1,1),
	PersonID int REFERENCES PersonDetails(PersonID),
	CustomName varchar(50) NOT NULL,
	Number char(35) NOT NULL
);

/*
*
* Procedura dodaj¹ca u¿ytkownika
*
*/

CREATE PROCEDURE dbo.CreateAccount
	@username varchar(50),
	@password char(60),
	@forename varchar(50),
	@surname varchar(50),
	@email varchar(50),
	@phone char(9),
	@CardID char(9),
	@pesel char(11),
	@birthdate date
AS 
BEGIN
	DECLARE @profileID int;
	INSERT INTO PersonLogins (Username, Password) VALUES(@username, @password);
	INSERT INTO PersonDetails (Forename, Surname, EMail, PhoneNumber, IdentityCardNumber, Pesel, BirthDate) VALUES(@forename, @surname, @email, @phone, @CardID, @pesel, @birthdate);
	SET @profileID = SCOPE_IDENTITY();
	exec CreateBill @profileID, 1, 1;
END

/*
*
* Procedura otwieraj¹ca rachunek
*
*/

CREATE PROCEDURE dbo.CreateBill
	@personID int,
	@accountTypeID int,
	@currencyID int
AS
BEGIN
	DECLARE @counter int;
	DECLARE @newAccountNumber char(35);
	DECLARE @accountType char(4);
	DECLARE @accountCounter int;
	DECLARE @createdAccountID int;
	DECLARE @randomNum1 int; 
	DECLARE @randomNum2 int; 

	SET @randomNum1 = (SELECT FLOOR(RAND()*(9999-1000)+1000));
	SET @randomNum2 = (SELECT FLOOR(RAND()*(9999-1000)+1000));

	IF @accountTypeID = 1
		BEGIN
			SET @accountType = '5424';
		END
	ELSE IF @accountTypeID = 2
		BEGIN
			SET @accountType = '8781';
		END
	ELSE IF @accountTypeID = 3
		BEGIN
			SET @accountType = '7553';
		END
	ELSE IF @accountTypeID = 4
		BEGIN
			SET @accountType = '2894';
		END

	SET @counter = (SELECT COUNT(*) FROM BankAccounts);
	SET @accountCounter = (@counter * 13) + 1000;
	SET @newAccountNumber = CONCAT('30 10 6571 7266 ', @randomNum1, ' ', @accountType, ' ', @randomNum2, ' ', CONVERT(char(4), @accountCounter));
	INSERT INTO BankAccounts(PersonID, TypeID, Currency, Number) VALUES (@personID, @accountTypeID, @currencyID, @newAccountNumber);
END

/*
*
* Procedura do wp³acania/wyp³acania pieniêdzy
*
*/

CREATE PROCEDURE dbo.AddPaymentPaycheck
	@accountID int,
	@currencyID int,
	@amount money,
	@typeID int
AS
BEGIN
	DECLARE @accountSetCurrency int;

	SET @accountSetCurrency = (SELECT Currency FROM BankAccounts WHERE AccountID = @accountID);

	IF @currencyID != @accountSetCurrency
		BEGIN
			DECLARE @firstExchangeRate money = (SELECT ExchangeRate FROM Currencies WHERE CurrencyID = @currencyID);
			DECLARE @secondExchangeRate money = (SELECT ExchangeRate FROM Currencies WHERE CurrencyID = @accountSetCurrency);
			DECLARE @resultAmount money = ROUND((@amount * @firstExchangeRate) / @secondExchangeRate, 2);
		END
	ELSE
		BEGIN
			SET @resultAmount = ROUND(@amount, 2);
		END

	BEGIN TRY
		IF @typeID = 1
			BEGIN
				UPDATE BankAccounts SET Balance = Balance + @resultAmount WHERE AccountID = @accountID;
			END
		ELSE IF @typeID = 2
			BEGIN 
				UPDATE BankAccounts SET Balance = Balance - @resultAmount WHERE AccountID = @accountID;
			END
	END TRY
	Begin CATCH
		THROW
		return -1
	End CATCH

	INSERT INTO Transactions(StartingAccountID, DestinationAccountID, Amount, AmountInAccountMainCurrency, Title, CurrencyID, TypeID) 
	VALUES(@accountID, @accountID, ROUND(@amount, 2), @resultAmount, 'Operacja w bankomacie', @currencyID, @typeID);
END

/*
*
* Procedura do przelewów
*
*/

CREATE PROCEDURE dbo.AddTransfer
	@startingAccountID int,
	@destinationAccountNumber char(35),
	@title varchar(100),
	@amount money,
	@currencyID int
AS
BEGIN
	DECLARE @destinationAccountID int;
	DECLARE @destinationAccountCurrency int;
	DECLARE @startingAccountCurrency int;

	BEGIN TRY
		IF EXISTS (SELECT AccountID FROM BankAccounts WHERE Number = @destinationAccountNumber)
			BEGIN
				SET @destinationAccountID = (SELECT AccountID FROM BankAccounts WHERE Number = @destinationAccountNumber);
			END
		ELSE
			BEGIN
				THROW 50005, 'Konto o takim numerze nie istnieje/inny bank', 1;
			END

		SET @startingAccountCurrency = (SELECT Currency FROM BankAccounts WHERE AccountID = @startingAccountID);
		SET @destinationAccountCurrency = (SELECT Currency FROM BankAccounts WHERE AccountID = @destinationAccountID);

		DECLARE @firstResultAmount money;
		DECLARE @secondResultAmount money;
		DECLARE @firstExchangeRate money;
		DECLARE @secondExchangeRate money;

		IF @currencyID != @startingAccountCurrency
			BEGIN
				SET @firstExchangeRate = (SELECT ExchangeRate FROM Currencies WHERE CurrencyID = @currencyID);
				SET @secondExchangeRate = (SELECT ExchangeRate FROM Currencies WHERE CurrencyID = @startingAccountCurrency);
				SET @firstResultAmount = ROUND((@amount * @firstExchangeRate) / @secondExchangeRate, 2);
			END
		ELSE
			BEGIN
				SET @firstResultAmount = ROUND(@amount, 2);
			END

		IF @currencyID != @destinationAccountCurrency
			BEGIN
				SET @firstExchangeRate = (SELECT ExchangeRate FROM Currencies WHERE CurrencyID = @currencyID);
				SET @secondExchangeRate = (SELECT ExchangeRate FROM Currencies WHERE CurrencyID = @destinationAccountCurrency);
				SET @secondResultAmount = ROUND((@amount * @firstExchangeRate) / @secondExchangeRate, 2);
			END
		ELSE
			BEGIN
				SET @secondResultAmount = ROUND(@amount, 2);
			END

		UPDATE BankAccounts SET Balance = Balance - @firstResultAmount WHERE AccountID = @startingAccountID;
		UPDATE BankAccounts SET Balance = Balance + @secondResultAmount WHERE AccountID = @destinationAccountID;

		IF @title = ''
			BEGIN
				SET @title = 'Przelew œrodków';
			END

		INSERT INTO Transactions(StartingAccountID, DestinationAccountID, Amount, AmountInAccountMainCurrency, Title, CurrencyID, TypeID) 
		VALUES(@startingAccountID, @destinationAccountID, ROUND(@amount, 2), @firstResultAmount, @title, @currencyID, 4);

		INSERT INTO Transactions(StartingAccountID, DestinationAccountID, Amount, AmountInAccountMainCurrency, Title, CurrencyID, TypeID) 
		VALUES (@destinationAccountID, @startingAccountID, ROUND(@amount, 2), @secondResultAmount, @title, @currencyID, 3);

	END TRY
	BEGIN CATCH
		THROW
		return -1
	END CATCH
END

/*
*
* Procedura kapitalizuj¹ca odsetki
*
*/

CREATE PROCEDURE dbo.CapitalizeIntrest
AS
BEGIN
	DECLARE @intrest float = 0.05;
	DECLARE @au_id char( 11 );

	SELECT @au_id = MIN( AccountID ) FROM BankAccounts WHERE TypeID = 2;

	DECLARE @accountID int;
	DECLARE @balance money;
	DECLARE @currencyID int;

	WHILE @au_id IS NOT NULL
		BEGIN
			SELECT @accountID = AccountID, @balance = Balance, @currencyID = Currency FROM BankAccounts WHERE AccountID = @au_id;

			SET @balance = ROUND(@balance * @intrest, 2);

			UPDATE BankAccounts SET Balance = Balance + @balance WHERE AccountID = @au_id;

			IF @balance > 0
				BEGIN
					INSERT INTO Transactions(StartingAccountID, DestinationAccountID, Amount, AmountInAccountMainCurrency, Title, CurrencyID, TypeID) 
					VALUES(@accountID, @accountID, @balance, @balance, CONCAT('Odsetki: ', @intrest * 100, '%'), @currencyID, 5);
				END

			SELECT @au_id = MIN( AccountID ) FROM BankAccounts WHERE AccountID > @au_id AND TypeID = 2;
		END
END

/*
*
* Wprowadzanie podstawowych danych
*
*/

INSERT INTO BankAccountTypes(Name) VALUES
('Konto zwyk³e'),
('Konto oszczêdnoœciowe'),
('Konto walutowe'),
('Konto firmowe');

INSERT INTO TransactionTypes(Name) VALUES
('Wp³ata œrodków'),
('Wyp³ata œrodków'),
('Przelew przychodz¹cy'),
('Przelew wychodz¹cy'),
('Kapitalizacja odsetek');

INSERT INTO Currencies(Name, Shortcut, ExchangeRate, ExchangeDate) VALUES 
('z³oty', 'PLN', 1.0000, '2022-12-29'),
('euro', 'EUR', 4.6800, '2022-12-29'),
('bat (Tajlandia)', 'THB', 0.1272, '2022-12-29'), 
('dolar amerykañski','USD', 4.4078, '2022-12-29'),
('dolar australijski','AUD',2.9666, '2022-12-29'),
('dolar Hongkongu','HKD',0.5654, '2022-12-29'),
('dolar kanadyjski','CAD',3.2441, '2022-12-29'),
('dolar nowozelandzki','NZD',2.7824, '2022-12-29'),
('dolar singapurski','SGD',3.2697, '2022-12-29'),
('forint (Wêgry)','HUF',0.011667, '2022-12-29'),
('frank szwajcarski','CHF',4.7725, '2022-12-29'),
('funt szterling','GBP',5.3132, '2022-12-29'),
('hrywna (Ukraina)','UAH',0.1258, '2022-12-29'),
('jen (Japonia)','JPY',0.032986, '2022-12-29'),
('korona czeska','CZK',0.1942, '2022-12-29'),
('korona duñska','DKK',0.6316, '2022-12-29'),
('korona islandzka','ISK',0.030921, '2022-12-29'),
('korona norweska','NOK',0.4457, '2022-12-29'),
('korona szwedzka','SEK',0.4216, '2022-12-29'),
('kuna (Chorwacja)','HRK',0.6233, '2022-12-29'),
('lej rumuñski','RON',0.9498, '2022-12-29'),
('lew (Bu³garia)','BGN',2.4015, '2022-12-29'),
('lira turecka','TRY',0.2355, '2022-12-29'),
('nowy izraelski szekel','ILS',1.2517, '2022-12-29'),
('peso chilijskie','CLP',0.005112, '2022-12-29'),
('peso filipiñskie','PHP',0.0789, '2022-12-29'),
('peso meksykañskie','MXN',0.2276, '2022-12-29'),
('rand (Republika Po³udniowej Afryki)','ZAR',0.2590, '2022-12-29'),
('real (Brazylia)','BRL',0.8367, '2022-12-29'),
('ringgit (Malezja)','MYR',0.9964, '2022-12-29'),
('rupia indonezyjska','IDR',0.00028151, '2022-12-29'),
('rupia indyjska','INR',0.053222, '2022-12-29'),
('won po³udniowokoreañski','KRW',0.003481, '2022-12-29'),
('yuan renminbi (Chiny)','CNY',0.6331, '2022-12-29'),
('SDR (MFW)','XDR',5.8848, '2022-12-29');