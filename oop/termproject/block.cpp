#include "block.h"

Block::Block() {
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			this->block[y][x] = 0;
		}
	}
}

Block::Block(int type, int rotate) {
	this->t = type;
	this->r = rotate;
	this->x = 2;
	this->y = 1;

	srand((unsigned int)time(NULL));
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			int random = rand()%4;
			if (this->blocks[t][0][y][x] == 0) {
				this->block[y][x] = 0;
			}
			else {
				cur_color = color[rand()%4];
				this->block[y][x] = cur_color;
			}
		}
	}
}

int Block::get_data(int val_x, int val_y) {
	return this->block[val_y][val_x];
}

int Block::get_t() {
	return this->t;
}

int Block::get_r() {
	return this->r;
}

int Block::get_x() {
	return this->x;
}

int Block::get_y() {
	return this->y;
}

void Block::set_x(int px) {
	this->x = px;
}

void Block::set_y(int py) {
	this->y = py;
}

void Block::set_data(int val_x, int val_y, int val_data) {
	block[val_y][val_x] = val_data;
}

void Block::turn_left() {
	int temp_v = this->get_data(0,0);
	int temp_e = this->get_data(1,0);

	this->set_data(0,0,this->get_data(2,0));
	this->set_data(2,0,this->get_data(2,2));
	this->set_data(2,2,this->get_data(0,2));
	this->set_data(0,2,temp_v);

	this->set_data(1,0,this->get_data(2,1));
	this->set_data(2,1,this->get_data(1,2));
	this->set_data(1,2,this->get_data(0,1));
	this->set_data(0,1,temp_e);
}

void Block::turn_right() {
	int temp_v = this->get_data(0,0);
	int temp_e = this->get_data(1,0);

	this->set_data(0,0,this->get_data(0,2));
	this->set_data(0,2,this->get_data(2,2));
	this->set_data(2,2,this->get_data(2,0));
	this->set_data(2,0,temp_v);

	this->set_data(1,0,this->get_data(0,1));
	this->set_data(0,1,this->get_data(1,2));
	this->set_data(1,2,this->get_data(2,1));
	this->set_data(2,1,temp_e);
}

void Block::move_left() {
	if (this->get_x() > 1) {
		this->set_x(this->get_x() - 1);
	}
}

void Block::move_down() {
	if (this->get_y() < 10) {
		this->set_y(this->get_y() + 1);
	}
}

void Block::move_right() {
	if (this->get_x() < 3) {
		this->set_x(this->get_x() + 1);
	}
}

void Block::print_block() {
	for (int block_y = 0; block_y < 3; block_y++) {
		for (int block_x = 0; block_x < 3; block_x++) {
			int data = this->get_data(block_x, block_y);
			if (data == 0) {
				cout<<"  ";
			}
			if (data == 30) {
				cout<<"\33[1;30m";
				cout<<" ■";
				cout<<"\33[0m";
			}
			if (data == 31) {
				cout<<"\33[1;31m";
				cout<<" ■";
				cout<<"\33[0m";
			}
			if (data == 32) {
				cout<<"\33[1;32m";
				cout<<" ■";
				cout<<"\33[0m";
			}
			if (data == 34) {
				cout<<"\33[1;34m";
				cout<<" ■";
				cout<<"\33[0m";
			}
		}
		cout<<endl;
	}
}
