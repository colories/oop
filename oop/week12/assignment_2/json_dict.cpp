#include "json_dict.h"


// private
static int _index = 0;

void json_dict::put(json_object* key, json_object* val) {
	p = make_pair(key, val);
	this->v.push_back(p);
}

int json_dict::find(json_object* key) {

}

// public

json_dict() {
	this->v.push_back(make_pair(0,0));
}

json_object* json_dict::parse(const char *str, int length) {
	
	while (_index < length) {
		if (str[_index] == '"'|'{'|'}'|',') {
			_index++;
		}

		const char *key;
		while (str[_index] != ':') {
			key = key + str[_index];
			_index++;
		}

		const char *value;
		while (str[_index] != '}'|',') {
			value = value + str[_index];
			_index++;
		}

		this->put(key, value);
	}	
}

json_object* json_dict::operator[] (json_object* key) const {

}

_type json_dict::type() {
	return DICT;
}

std::string to_string() {
	return std::to_string(v);
}

