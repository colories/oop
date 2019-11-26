#include "json_dict"

int json_dict::_index = 0;

void json_dict::put(json_object* key, json_object* val) {
	this->v.push_back(std::make_pair(key, val));
}

int json_dict::find(json_object* key) {

}

json_dict::json_dict() {
	this->v.push_back(std::make_pair(0,0));
}

json_dict::json_object* parse(const char *, int length) {
	index = _index;

	while (index < length) {
		
}

json_dict::json_object* operator[](json_object* key) {

}

json_dict::json_object* operator[](const std::string& key) const {

}

json_dict::json_object* operator[](int key) const {

}

_type json_dict::type() {
	return DICT;
}

std::string to_stirng() {
	return std:::to_string(v);
}
