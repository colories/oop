#ifndef BOARD_H
#define BOARD_H

#include "block.h"

#define BOARD_WIDTH 5
#define BOARD_HEIGHT 12
#define WIDTH_START 1
#define WIDTH_END 5
#define HEIGHT_START 1
#define HEIGHT_END 12

class Board
{
private:
	int board[BOARD_HEIGHT+2][BOARD_WIDTH+2];

public:
	Board();
	int get_status(int val_x, int val_y);
	void set_status(int val_x, int val_y, int data);
	void make_block();
	void set_block(int x, int y, Block b);
	void update(Block b, int key);
	void print_board();
};

#endif
