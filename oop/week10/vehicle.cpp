#include "vehicle.h"

/* class object initializer */

vehicle::vehicle() {
	this->wheel_number = 0;
	this->max_speed = 0;
	this->has_name = false;
}

vehicle::vehicle(int w, int s) {
	this->wheel_number = w;
	this->max_speed = s;
	this->has_name = false;
}

vehicle::vehicle(int w, int s, bool n) {
	this->wheel_number = w;
	this->max_speed = s;
	this->has_name = n;
}


/* getter method */

int vehicle::get_wheel_number() {
	return this->wheel_number;
}

int vehicle::get_max_speed() {
	return this->max_speed;
}

bool vehicle::get_has_name() {
	return this->has_name;
}

const char* vehicle::get_class_name() {
	return "vehicle";
}


/* setter method */

void vehicle::set_wheel_number(int w) {
	this->wheel_number = w;
}

void vehicle::set_max_speed(int s) {
	this->max_speed = s;
}

void vehicle::set_has_name(bool n) {
	this->has_name = n;
}

