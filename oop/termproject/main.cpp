#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include "getch.h"
#include "kbhit.h"
#include "block.h"
#include "clear.h"
#include "board.h"

int main(void)
{

	clear();
/*	cout<<"This is block!"<<endl;
	Block b = Block(1,0);
	b.print_block();
	*/

	Board board = Board();
	srand((unsigned int)time(NULL));
	int type = rand()%3;
	Block b = Block(type, 0);
	cout<<"Hello~~~~~"<<endl;
	board.update(b, 0);

	int key;
	bool cont = true;

	while (cont) {
		if(kbhit())
		{
			key = getch();
			switch(key)
			{
				case 113: /* key value 'q' is turn_left */
					clear();
					cout<<"turn_left!"<<endl;
					b.turn_left();
					break;

				case 101: /* key value 'e' is turn_right */
					clear();
					cout<<"turn_right!"<<endl;
					b.turn_right();
					break;

				case 97: /* key value 'a' is move_left */
					clear();
					cout<<"move_left!"<<endl;
					b.move_left();
					break;

				case 115: /* key value 's' is move_down */
					clear();
					cout<<"move_down!"<<endl;
					b.move_down();
					break;

				case 100: /* key value 'd' is move_right */
					clear();
					cout<<"move_right!"<<endl;
					b.move_right();
					break;
			
				case 49: /* key value '1' is end playing */
					clear();
					cout<<"bye bye~"<<endl;
					cont = false;
					break;

				default:
					break;
			}
			board.update(b, key);
		}
	}

	return 0;
}
