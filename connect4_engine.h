#include <stdio.h>
#ifndef CONNECT_H
#define CONNECT_H

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]);
int winner(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int row_match(int board[], int count, int length_to_win);
int winner_by_row(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int winner_by_column(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int winner_by_diagonal1(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int winner_by_diagonal2(int row_cur, int col_cur, int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int winner_tie(int num_rows, int num_columns, int board[num_rows][num_columns]);
int initialize(int num_rows, int num_columns, int board[num_rows][num_columns]);
void display_board(int num_rows, int num_columns, int board[num_rows][num_columns]);
void make_move(int row, int column);
int player_play(int player, int num_rows, int num_columns, int game[num_rows][num_columns]) ;
#endif
