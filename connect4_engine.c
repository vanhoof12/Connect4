#include "connect4_engine.h"

int top_row,top_col;

/************************************************
Method to display the board
*************************************************/
void display_board(int num_rows, int num_columns, int board[num_rows][num_columns]) {
	int i,j;
	printf("\n");
	for (i = 0; i < num_rows; ++i) {
		for (j = 0; j < num_columns; ++j) {
			switch (board[i][j]) {
				case -1: 
					printf("X ");
					break;
				case 0:
					printf( "1 " );
					break;
				case 1:
					printf( "2 " );
					break;
			}
		}
		printf("\n");
	}
	
	if (num_columns < 10) { 
		for (j = 0; j < num_columns; ++j) {
			printf("- ");
		} 
		printf("\n");
		for (j = 0; j < num_columns; ++j) {
			printf("%d ", j);
		} 
	}
	printf("\n");
}

void make_move(int row, int column) {
	top_row = row;
	top_col = column;
}

/**********************************************
Method to get winner of the game
**********************************************/
int winner(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]) {
	
	int win, row_cur, col_cur;
	
	row_cur = top_col;
	col_cur = top_row;
	
	//call outside method for tie
	win = winner_tie(num_rows, num_columns, board);
	if (win != -1) {
		return win;
	}
	//call outside method for win in a single row
	win = winner_by_row(col_cur, row_cur, num_rows, num_columns,length_to_win, board);
	if (win != -1) {
		return win;
	}
	//call outside method for win in single column
	win = winner_by_column(col_cur, row_cur, num_rows, num_columns,length_to_win, board);
	if (win != -1) {
		return win;
	}
	//call outside method for win in diagonal
	win = winner_by_diagonal1(col_cur, row_cur, num_rows, num_columns,length_to_win, board);
	if (win != -1) {
		return win;
	}
		//call outside method for win in diagonal
	win = winner_by_diagonal2(col_cur, row_cur, num_rows, num_columns,length_to_win, board);
	if (win != -1) {
		return win;
	}
	return -1;
}
/****************************************************************************
Method that lets player place token, lets player know if it is full/invalid
*****************************************************************************/
int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {
	int i;
	if (column < num_columns) {
		for (i = num_rows-1; i >= 0; --i) {
			if (board[i][column] == -1) {
				
				if (player == 0) {
					board[i][column] = 0;
				} else {
					board[i][column] = 1;
				}
				
				display_board(num_rows, num_columns, board);
				make_move(i, column);
				return 0;
			} 
		}
		
		printf("\nThis column is full. Choose another column\n");
		return 1;
		
	} else {
		printf("\nThis column does not exist. Choose another column\n");
		return 1;
	}
}

/**********************************************
Method creates the board
**********************************************/
int initialize(int num_rows, int num_columns, int board[num_rows][num_columns]) {
  
	int i;
	int j;
	for (i = 0; i < num_rows; ++i) {
		for (j = 0; j < num_columns; ++j) {
			board[i][j] = -1;
		}
	}
	
	display_board(num_rows, num_columns,board);
	return 0;
}

int winner_by_row(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]) {
	
	int i;
	int count = 0;
	int check_row[num_columns];
	for (i = 0; i < num_columns; ++i) {
		check_row[i] = board[row_cur][i]; 
		count++;
	}
	
    return row_match(check_row,count,length_to_win);
}

int winner_by_column(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]) {
	
	int n;
	int count = 0;
	
	int check_col[num_rows];
	
	for (n = 0; n < num_rows; ++n) {
		check_col[n] = board[n][col_cur];
		count++;
	}
	return row_match(check_col,count,length_to_win);
}

int winner_by_diagonal1(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]) {
	
	int i;
	int count = 0;
	
	int diag1[num_columns];
	
	if (row_cur > col_cur) {
		while (col_cur != 0) {
			col_cur--;
			row_cur--;
		}
		
		for (i = 0; row_cur < num_rows; ++i, ++row_cur) {
			diag1[i] = board[row_cur][i];
			count++;
		}
	} else if ( col_cur > row_cur) {
		while (row_cur != 0) {
			row_cur--;
			col_cur--;
		}
		
		for (i = 0; col_cur < num_columns; ++i, ++col_cur) {
			diag1[i] = board[i][col_cur];
			count++;
		}
	} else {
		for (i = 0; i < num_columns; ++i) {
			diag1[i] = board[i][i];
			count++;
		}
	}
	return row_match(diag1,count,length_to_win);
}

int winner_by_diagonal2(int row_cur, int col_cur, int num_rows, int num_columns,  int length_to_win, int board[num_rows][num_columns]) {
	int i;
	int count = 0;
	
	int diag2[num_columns];
	
	while (col_cur  > 0 && row_cur < num_rows - 1) {
		col_cur--;
		row_cur++;
	}
	for (i = 0; col_cur < num_columns && row_cur >= 0; ++i, ++col_cur, --row_cur) {
		diag2[i] = board[row_cur][col_cur];
		count++;
	}
	return row_match(diag2,count,length_to_win);
}

int winner_tie(int num_rows, int num_columns, int board[num_rows][num_columns]) {
	int i,j,temp;
	temp = 2;
	
	for (i = 0; i < num_rows; ++i) {
		for (j = 0; j < num_columns; ++j) {
			
			if (board[i][j] == -1) {
				temp = -1;
			}
		}
	}
	return temp;
}


int row_match(int board[], int count, int length_to_win) {

  if (count < length_to_win || length_to_win == 0 || count <= 0) {
    return -1;
  }
  
  int i, last, done;
  last = count-1;
  done = 1;
 
  if (board[last] != -1) {
    
    for (i = last; i > (last -(length_to_win-1)) && done; i--) {
      if (board[i] != board[i-1]) {
	done = 0;
      }
    }
  }
  
  if (done == 1 && board[last] != -1 ){
    return board[last];
    
  } else {
    return row_match(board, count-1,length_to_win);
  }
}

/*************************************************
Method that rotates between players turns
**************************************************/
int player_play(int player, int num_rows, int num_columns, int game[num_rows][num_columns]) {
	
	int returncode = 1;
	int column;
	
	if (player == 0) {
		printf( "Player 1 select a column: ");
		scanf("%d", &column);
		returncode = place_token(0,column,num_rows, num_columns,game);
		
		return 1;
	} 
	else {
		printf( "Player 2 enter a column: ");
		scanf("%d", &column);
		returncode = place_token(1,column,num_rows, num_columns,game);
		
		return 2;
	}
	return 0;
}
