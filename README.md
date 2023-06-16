# BankApp

## Structure of Database.h file:
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

## LNK2005
If the error above is shown, add ```/FORCE:MULTIPLE``` to the Linker's Command Line option
