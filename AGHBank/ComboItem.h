#pragma once

using namespace System;

public ref class ComboItem {
protected:
	String^ description;
	int tag;
	int additionalValue;

public: ComboItem(String^ nameOfField, int hiddenValue, int hiddenSecondValue) {
	description = nameOfField;
	tag = hiddenValue;
	additionalValue = hiddenSecondValue;
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
};