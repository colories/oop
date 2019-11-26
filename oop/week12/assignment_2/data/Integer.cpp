#include "Integer.h"

Integer::Integer(int value) {
	this->_val = value;
}

int Integer::val() {
	return this->_val;
}

void Integer::set_val(const int& value) {
	this->val = value;
}

json_object* Integer::parse(const char *, int length) {
	
}

_type Integer::type() {
	return INT;
}

std::string to_string() {
	return std::to_string(_val);
}
