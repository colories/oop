#include "bike.h"


/* class object initializer */

bike::bike() {
	this->wheel_number = 0;
	this->max_speed = 0;
	this->bike_name = 0;	/* null-pointer */
	this->bike_number = 0;
	this->has_name = false;
}

bike::bike(int w, int s) {
	this->wheel_number = w;
	this->max_speed = s;
	this->bike_name = 0;	/* null-pointer */
	this->bike_number = 0;
	this->has_name = false;
}

bike::bike(int w, int s, char* b_name) {
	this->wheel_number = w;
	this->max_speed = s;
	this->bike_name = b_name;
	this->bike_number = 0;
	this->has_name = true;
}

bike::bike(int w, int s, char* b_name, int b_num) {
	this->wheel_number = w;
	this->max_speed = s;
	this->bike_name = b_name;
	this->bike_number = b_num;
	this->has_name = true;
}

bike::bike(int w, int s, char* b_name, int b_num, bool n) {
	this->wheel_number = w;
	this->max_speed = s;
	this->bike_name = b_name;
	this->bike_number = b_num;
	this->has_name = n;
}


/* getter method */

int bike::get_bike_number() {
	return this->bike_number;
}

char* bike::get_bike_name() {
	return this->bike_name;
}

const char* bike::get_class_name() {
	return "bike";	/* This class name is "bike" */
}


/* setter method */

void bike::set_bike_number(int b_num) {
	this->bike_number = b_num;
}

void bike::set_bike_name(char* b_name) {
	this->bike_name = b_name;
}

