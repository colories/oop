#include "board.h"

Board::Board() {
	for (int h = 0; h < BOARD_HEIGHT + 2; h++) {
		for (int w = 0; w < BOARD_WIDTH + 2; w++) {
			if (h==0 | h==BOARD_HEIGHT+1) {
				set_status(w, h, 1);
			}
			else if (w==0 | w==BOARD_WIDTH+1) {
				set_status(w, h, 1);
			}
			else {
				set_status(w, h, 0);
			}
		}
	}
}

int Board::get_status(int val_x, int val_y) {
	return this->board[val_y][val_x];
}

void Board::set_status(int val_x, int val_y, int data) {
	this->board[val_y][val_x] = data;
}

/*void Board::make_block() {
	int x, y;
	srand((unsigned int)time(NULL));
	Block cur_block = Block(rand()%3, 0);

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			this->set_status(x+2, y+1, cur_block.get_data(x,y));
		}
	}
}*/

void Board::update(Block b, int key) {
	int x, y;
	int cur_x = b.get_x();
	int cur_y = b.get_y();

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			this->set_status(b.get_x()+x, b.get_y()+y, b.get_data(x,y));
		}
	}

	if (key == 97) {
		for (y = 0; y < 3; y++) {
			this->set_status(cur_x+3, cur_y+y, 0);
		}
	}

	if (key == 115) {
		for (x = 0; x < 3; x++) {
			this->set_status(cur_x+x, cur_y-1, 0);
		}
	}

	if (key == 100) {
		for (y = 0; y < 3; y++) {
			this->set_status(cur_x-1, cur_y+y, 0);
		}
	}

	this->print_board();
}

void Board::print_board() {
	int h, w;

	for (h = 0; h < BOARD_HEIGHT+2; h++) {
		for (w = 0; w < BOARD_WIDTH+2; w++) {
			int data = this->get_status(w, h);
			if (data == 0) {
				cout<<"  ";
			}
			
			if (data == 1) {
				cout<<" ■";
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
