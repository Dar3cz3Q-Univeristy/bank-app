#pragma once

#include <string>
#include <ctime>
#include <time.h>

namespace PersonDetailsCheck {
	static bool peselSum(std::string pesel) {
		if (pesel.length() != 11) {
			return false;
		}
		int sum = 1 * (pesel[0] - '0') +
			3 * (pesel[1] - '0') +
			7 * (pesel[2] - '0') +
			9 * (pesel[3] - '0') +
			1 * (pesel[4] - '0') +
			3 * (pesel[5] - '0') +
			7 * (pesel[6] - '0') +
			9 * (pesel[7] - '0') +
			1 * (pesel[8] - '0') +
			3 * (pesel[9] - '0');

		if (10 - (sum % 10) == (pesel[10] - '0')) {
			return true;
		}
		return false;
	}
	static int getLetterValue(char letter)
	{
		char* letterValues = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int letterValuesLen = 36;
		int i;
		for (i = 0; i < letterValuesLen; i++)
		{
			if (letter == letterValues[i])
			{
				return i;
			}
		}
		return -1;
	}
	static bool idCardSum(std::string cardID) {
		if (cardID.length() != 9) {
			return false;
		}
		for (int i = 0; i < 3; i++)
		{
			if (getLetterValue(cardID[i]) < 10)
			{
				return false;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			if (getLetterValue(cardID[i]) < 0 || getLetterValue(cardID[i]) > 9)
			{
				return false;
			}
		}
		int checkSum;
		checkSum = 7 * getLetterValue(cardID[0]);
		checkSum += 3 * getLetterValue(cardID[1]);
		checkSum += 1 * getLetterValue(cardID[2]);
		checkSum += 7 * getLetterValue(cardID[4]);
		checkSum += 3 * getLetterValue(cardID[5]);
		checkSum += 1 * getLetterValue(cardID[6]);
		checkSum += 7 * getLetterValue(cardID[7]);
		checkSum += 3 * getLetterValue(cardID[8]);
		checkSum %= 10;
		if (checkSum != getLetterValue(cardID[3]))
		{
			return false;
		}
		return true;
	}
	static bool isAdult(System::DateTime birthDate) {
		time_t now = time(0);
		tm* today = std::localtime(&now);

		int birthYear = birthDate.Year;
		int todayYear = today->tm_year + 1900;

		if (todayYear - birthYear > 18) {
			return true;
		}
		else if (todayYear - birthYear < 18) {
			return false;
		}

		int birthMonth = birthDate.Month;
		int todayMonth = today->tm_mon + 1;

		if (todayMonth - birthMonth > 0) {
			return true;
		}
		else if (todayMonth - birthMonth < 0) {
			return false;
		}

		int birthDay = birthDate.Day;
		int todayDay = today->tm_mday - 1;

		if (todayDay - birthDay >= 0) {
			return true;
		}
		else if (todayDay - birthDay < 0) {
			return false;
		}
		return false;
	}
}