#include "car.h"


/* class object initilizer */

car::car() {
	this->wheel_number = 0;
	this->max_speed = 0;
	this->car_name = 0;	/* null-pointer */
	this->has_name = false;
}

car::car(int w, int s) {
	this->wheel_number = w;
	this->max_speed = s;
	this->car_name = 0;	/* null-pointer */
	this->has_name = false;
}

car::car(int w, int s, char* c_name) {
	this->wheel_number = w;
	this->max_speed = s;
	this->car_name = c_name;
	this->has_name = true;
}

car::car(int w, int s, char* c_name, bool n) {
	this->wheel_number = w;
	this->max_speed = s;
	this->car_name = c_name;
	this->has_name = n;
}


/* getter method */

char* car::get_car_name() {
	return this->car_name;
}

const char* car::get_class_name() {
	return "car";	/* this class name is "car" */
}

/* setter method */

void car::set_car_name(char* c_name) {
	this->car_name = c_name;
}
