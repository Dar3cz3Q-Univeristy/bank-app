# BankApp

Structure of Database.h file:

#pragma once
#include <string>

namespace DatabaseConfig {
	std::string hostname = ""; //Your database server hostname
	std::string database = ""; //Your database name
	std::string username = ""; //Your user name
	std::string password = ""; //Your password

	std::string sqlConnectionString = "Data Source=" + hostname + ";Initial Catalog=" + database + ";User ID=" + username + ";Password=" + password + "";
}
