#pragma once

#include <string>

namespace ConvertString {
	static System::String^ toSystemString(std::string string) {
		System::String^ returnString = gcnew System::String(string.c_str());
		return returnString;
	}
	static std::string toStandardString(System::String^ string) {
		using System::Runtime::InteropServices::Marshal;
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);
		return returnString;
	}
}