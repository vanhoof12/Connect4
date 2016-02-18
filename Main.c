#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "connect4_engine.h"

int main(int argc, char **argv) {
	if (argc == 3) {
		int i;
		
		int num_rows = atoi(argv[1]);
		int num_columns = num_rows;
		int board_size = num_rows;
		int game[num_rows][num_columns];
		int length_to_win = atoi(argv[2]);
		int win = -1;
		int playernumber = 0;
		initialize(num_rows, num_columns, game);
		while (win == -1) {
			if (playernumber == 0)
			{
				player_play(playernumber,num_rows, num_columns,game);
				win = winner(num_rows, num_columns, length_to_win,game);
			
				if (win == 0) {
					printf( "Player 1 wins!\n" );
				}
			
				if (win == 2) {	//tie
					printf("Tie game!\n");
				}
				playernumber = 1;
			}
			else{
				player_play(playernumber,num_rows, num_columns,game);
				win = winner(num_rows, num_columns, length_to_win,game);
				if (win == 1) {
					printf( "Player 2 wins!\n" );
				}
			
				if (win == 2) {
					printf("Tie game!\n");
				}
				playernumber = 0;
			}
		}
	} 
	else
	{
		printf("Invalid number of arguments\n");
	}
	return 0;
}
