#pragma once

using namespace System;

public ref class ComboItem {
protected:
	String^ description;
	int tag;

public: ComboItem(String^ name, int value) {
	description = name;
	tag = value;
}
public: String^ ToString() override {
	return description;
}
public: int GetTagValue() {
	return tag;
}
};