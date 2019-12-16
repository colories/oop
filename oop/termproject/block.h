#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

#define GREY 30
#define RED 31
#define GREEN 32
#define BLUE 34

class Block
{
private:
	int t, r, x, y;
	const int color[4] = {GREY, RED, GREEN, BLUE};
	const int blocks[3][4][3][3] = {
		{
			{0,1,0,1,1,0,0,0,0},
			{0,1,0,0,1,1,0,0,0},
			{0,0,0,0,1,1,0,1,0},
			{0,0,0,1,1,0,0,1,0}
		},
		{
			{0,1,0,0,1,0,0,1,0},
			{0,0,0,1,1,1,0,0,0},
			{0,1,0,0,1,0,0,1,0},
			{0,0,0,1,1,1,0,0,0}
		},
		{
			{0,1,0,1,1,1,0,1,0},
			{0,1,0,1,1,1,0,1,0},
			{0,1,0,1,1,1,0,1,0},
			{0,1,0,1,1,1,0,1,0}
		}
	};

	int block[3][3];
	int cur_color;
	
public:
	Block();
	Block(int type, int rotate);
	void left(Block b);
	void right(Block b);
	void space(Block b);
	int get_data(int val_x, int val_y);
	void set_data(int val_x, int val_y, int val_data);
	void turn_left();
	void turn_right();
	void move_left();
	void move_down();
	void move_right();
	int get_t();
	int get_r();
	int get_x();
	int get_y();
	void set_x(int px);
	void set_y(int py);
	void print_block();
};

#endif
