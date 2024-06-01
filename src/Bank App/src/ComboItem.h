#pragma once

using namespace System;

public ref class ComboItem {
protected:
	String^ description;
	int tag;
	int additionalValue;
	String^ accountNumber;

public: ComboItem(String^ nameOfField, int hiddenValue, int hiddenSecondValue, String^ hiddenThirdValue) {
	description = nameOfField;
	tag = hiddenValue;
	additionalValue = hiddenSecondValue;
	accountNumber = hiddenThirdValue;
}
public: String^ ToString() override {
	return description;
}
public: int GetTagValue() {
	return tag;
}
public: int GetAdditionalValue() {
	return additionalValue;
}
public: String^ GetAccountNumber() {
	return accountNumber;
}
};