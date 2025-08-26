#include <stdio.h>
#include <string.h>

//#include <ncurses.h>
//#include <unistd.h>


void error(){
	printf("\nA Simple Callculator \n\neg:  > 2+2\n     > +2\n\nop: + - / *\n\n> ");
}

void game();


int main(){

double a, b,last_b, result = 0;
char op = 0, last_op= 0;
char input[100];

/*
int x, y, max_x, max_y;
int line1_x, line1_y, line2_x, line2_y;
int op_x = -1, op_y = -1;
int enemy_x = 5, enemy_y = 3;
int enemy_dir = 1;

initscr();
nodelay(stdscr, TRUE);

getmaxyx(stdscr, max_y, max_x);
	ship_x =  max_x / 2;
	ship_y = max_y - 2;


*/


printf("Callculate: \n> ");

while(1){	
//	clear();
	if(!fgets(input, sizeof(input), stdin)) break;
	
	input[strcspn(input, "\n")] = 0;
	
	if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0 ){
		printf("Bye Bye!   ");
		break;
	}
	else if (strlen(input)==0 /*&& last_op == !0*/ ){
		b = last_b;
		op = last_op;
		a = result;
	}
	else if (sscanf(input, "%lf %c %lf", &a, &op, &b)==3){
	}
	else if (sscanf(input, "%c %lf", &op, &b)==2){
		a = result;
	}
	else if (strcmp(input, "y") == 0 || strcmp(input, "n") == 0 ) {
	}
	else {
		error();
	}

	switch(op){
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '/':
			if(b==0){
				printf("Are you sure? (y)[N]\n> ");
				if(!fgets(input, sizeof(input), stdin)) continue;
				input[strcspn(input, "\n")] = 0;
				if (strcmp(input, "n")== 0 || strlen(input) == 0){
					printf("Cool :)\n> ");
					a = 0;
					b = 0;
					continue;
				}
				else if (strcmp(input, "y")== 0 ){
					printf("GAME OVER\n ");
					game();
					continue;
				}
				else {
					printf("What?\n> ");
					break;
				}
			}
			else {
				result = a / b;
				break;
			}
		case '*':
			result = a * b;
			break;
		default:
			break;
	}
	last_b = b;
	last_op = op;
	printf("  %f \n> ", result);
}
}
