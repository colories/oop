#include "String.h"

String::String(const std::string& str) {
	this->_val = parse(str);
}

std::string String::val() {
	return this->_val;
}

void String::set_val(const std::string& str) {
	this->_val = parse(str);
}

json_object* String::parse(const char *, int length, char base) {
	
}

_type String::type() {
	return STRING;
}

std::string to_string() {
	return std::to_string(_val);
}
