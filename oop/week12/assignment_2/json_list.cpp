#include "json_list.h"

json_list::json_list() {
	this->v = 0;
}

json_object* json_list::parse(const char*, int length) {
}

json_object * json_list::operator[] (int key) const {
}

_type json_list::type() {
	return LIST;
}

std::string to_string() {
	return std::to_string(v);
}


