//#include <stdio.h>
//#include <stdlib.h>
//#include "secret.h"
#include <ncurses.h>
#include <unistd.h>

#define DELAY 40000

void game(){
	int x, y, max_x, max_y, ship_x, ship_y;
	int bullet_x = -1, bullet_y = -1;
	int enemy_x = 5, enemy_y = 3;
	int enemy_dir = 1;

	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	getmaxyx(stdscr, max_y, max_x);
	ship_x =  max_x / 2;
	ship_y = max_y - 2;

	while(1){
		clear();

		mvprintw(enemy_y, enemy_x, "0");
	   
		enemy_x += enemy_dir;
		if (enemy_x == max_x - 1 || enemy_x == 1){
			enemy_dir *= -1;
			enemy_y ++;
		}

		mvprintw(ship_y, ship_x, "^");
		if (bullet_y > 0){
			mvprintw(bullet_y, bullet_x, "|");
			bullet_y -- ;
		}

		if (bullet_y == enemy_y && bullet_x == enemy_x){
			mvprintw(max_y / 2, max_x /2, "HIT");
			refresh();
			sleep(2);
			break;
		}
		if (ship_y == enemy_y && ship_x == enemy_x){
			mvprintw(max_y / 2, max_x /2, "YOU LOSE");
			refresh();
			sleep(2);
			break;
		}
		refresh();


		int ch = getch();
		if (ch == 'q') break;
		if (ch == 'a' && ship_x != 0) ship_x -- ;
		if (ch == 'd' && ship_x != max_x - 1) ship_x ++ ;
		if (ch == ' ' && bullet_y <= 0){
			bullet_x = ship_x;
			bullet_y = ship_y - 1 ;
		}
		usleep(DELAY);
	}
endwin();
}




