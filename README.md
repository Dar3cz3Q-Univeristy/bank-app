# Disclaimer
**AGHBankApp** is final project on the basis of computer science in the 1st semester of studies. Application isn’t endorsed by *Akademia Górniczo-Hutnicza im. Stanisława Staszica w Krakowie* and doesn’t reflect the views or opinions of it.

# Installation
## In order to run this application, you need MSSQL Server.
1. Clone the repository,
2. Use "database/Database-script.sql" to create database on your MSSQL Server,
3. Create "Database.h" file in "src/Bank App/src" folder. Structure of the file is shown below.
4. Compile and run the program. 

### Note
If LNK2005 error is shown, add ```/FORCE:MULTIPLE``` to the Linker’s Command Line options.

### Structure of Database.h file:
```
#pragma once
#include <string>

namespace DatabaseConfig {
	std::string hostname = ""; //Your database server hostname
	std::string database = ""; //Your database name
	std::string username = ""; //Your user name
	std::string password = ""; //Your password

	std::string sqlConnectionString = "Data Source=" + hostname + ";Initial Catalog=" + database + ";User ID=" + username + ";Password=" + password + "";
}
```
