#include <stdio.h>
#include "connect4_engine.h"
#include "CuTest.h"

#define EMPTY 0
#define NO_WINNER_YET -1

void ct_initialize(int num_rows, int num_cols, int array[num_rows][num_cols]) {
  int r, c;
  size = num_cols;
  for (r = 0; r < num_rows; r++) {
    for (c = 0; c < num_cols; c++) {
      array[r][c] = 0;
    }
  }
}

/*******************************************************************************************
 *
 * Test winner function
 *
 * Note: This is just a sample of how you can test your own winner
 * function.  You may need to modify this code depending on how your
 * organized your array.  I will not be testing your winner function
 * directly.
 *
 * Note:  Be sure to add tests for different directions, quadrants, and board sizes.
 *
 ******************************************************************************************/
void winner_horizontal_r0(CuTest *tc) {

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[0][0] = 1;
  array[0][1] = 1;
  array[0][2] = 1;
  array[0][3] = 1;
  
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "1s in bottom row", 1, answer);
}

void winner_horizontal_r6(CuTest *tc) {

  int num_rows = 8;
  int num_columns = 8;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  array[4][0] = 1;
  array[4][1] = 1;
  array[4][2] = 1;
  array[4][3] = 1;
  
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "1s in bottom row", 1, answer);
}

/*******************************************************************************************
 *
 * Test place_token function
 *
 * Note: This is just a sample of how you can test your own
 * place_token function.  You may need to modify this code depending
 * on how your organized your array.  I will not be testing your
 * place_token function directly.
 *
 * Note:  Be sure to add tests for different directions, quadrants, and board sizes.
 *
 ******************************************************************************************/

void place_token_c1(CuTest *tc) {

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  ct_initialize(num_rows, num_columns, array);

  place_token(1, 3, num_rows, num_columns, array);

  // make s0re there is a 1 at the bottom of column 3 and a 0 everywhere else
  CuAssertIntEquals_Msg(tc, "Drop 1 into empty column 3", 1, array[num_rows-1][2]);
  int r, c;
  for (r = 0; r < num_rows; r++) {
    for (c = 0; c < num_columns; c++) {
      if (r != (num_rows -1) || c != 2) {
	CuAssertIntEquals_Msg(tc, "Should be empty", 0, array[r][c]);
      }
    }
  }
}


/*******************************************************************************************
 *
 * Test overall game play
 *
 * These tests below demonstrate how I will be testing your game.
 * These tests below should run wihtout modification.  If they don't
 * then something in your design conflicts with the tests and we need
 * to figure out what it is.  Make sure you find any such conflicts
 * and work with me to resole them well before the assignment due
 * date.
 *
 * Because they test the interaction between several methods, these
 * tests below are not technically "unit" tests.  If your tests for
 * your connect4_engine functions are thorough, you need not add many
 * tests to this section.
 *
 ******************************************************************************************/

//Horizontal
void horizontal_row0(CuTest* tc) 
{
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Single 0 in column 0", NO_WINNER_YET, answer);

  place_token(1, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1}", NO_WINNER_YET, answer);


  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1, 2}", NO_WINNER_YET, answer);


  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "4 in a row, horizontal", 1, answer);
}

void horizontal_row6(CuTest* tc) 
{
  int num_rows = 10;
  int num_columns = 10;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "Single 0 in column 0", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1}", NO_WINNER_YET, answer);

  place_token(2, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1, 2}", NO_WINNER_YET, answer);

  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1, 2}", NO_WINNER_YET, answer);
  
  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1, 2}", NO_WINNER_YET, answer);
  
  place_token(2, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "0s in columns {0,1, 2}", NO_WINNER_YET, answer);

  place_token(1, 6, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 3, array);
  CuAssertIntEquals_Msg(tc, "4 in a row, horizontal", 2, answer);
}

//Vertical
void vertical_column1(CuTest* tc) 
{
  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Single 0 in column 1", NO_WINNER_YET, answer);

  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Two 0s in column 1", NO_WINNER_YET, answer);


  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Three 0s in column 1", NO_WINNER_YET, answer);


  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "4 in a row, vertical", 1, answer);
}

void vertical_column5(CuTest* tc) 
{
  int num_rows = 8;
  int num_columns = 8;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Single 0 in column 1", NO_WINNER_YET, answer);

  place_token(2, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Two 0s in column 1", NO_WINNER_YET, answer);

  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Three 0s in column 1", NO_WINNER_YET, answer);
  
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Three 0s in column 1", NO_WINNER_YET, answer);
  
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Three 0s in column 1", NO_WINNER_YET, answer);
  
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Three 0s in column 1", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "4 in a row, vertical", 1, answer);
}

//Diagnoals
void forward_diagonal(CuTest* tc) 
{
 /*
    . . . . . . .
    . . . . . . .
    . . . . . . .
    . . . 1 . . .
    . . . 2 1 . .
    . . . 1 1 1 .
    2 . . 2 2 2 1
  */ 

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  /* column 6*/
  place_token(1, 6, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 1", NO_WINNER_YET, answer);

  /* column 5*/
  place_token(2, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 2", NO_WINNER_YET, answer);

  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 3", NO_WINNER_YET, answer);


  /* column 4*/
  place_token(2, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 4", NO_WINNER_YET, answer);

  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 5", NO_WINNER_YET, answer);

  place_token(2, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 6", NO_WINNER_YET, answer);

  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 7", NO_WINNER_YET, answer);

 /* column 3 */
  place_token(2, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 8", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 9", NO_WINNER_YET, answer);

  place_token(2, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 10", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 11 -- Winner!", 1, answer);
}

void forward_diagonal2(CuTest* tc) 
{
 /*
    . . . . . . .
    . . . . . . .
    . . . . . . .
    2 . . . . . .
	1 2 . . . . .
    2 2 2 . . 1 .
    1 1 1 2 . 1 .
  */ 

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);
  
  //column 1
  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 1", NO_WINNER_YET, answer);
  
  place_token(2, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 2", NO_WINNER_YET, answer);
  
  //column 2
  place_token(1, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 3", NO_WINNER_YET, answer);
  
  //column 1 
  place_token(2, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 4", NO_WINNER_YET, answer);
  
  //column 0
  place_token(1, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 5", NO_WINNER_YET, answer);
  
  place_token(2, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 6", NO_WINNER_YET, answer);
  
  place_token(1, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 7", NO_WINNER_YET, answer);
  
  place_token(2, 0, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 8", NO_WINNER_YET, answer);
  
  //column 5
  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 9", NO_WINNER_YET, answer);  
  
  //column 2
  place_token(2, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 10", NO_WINNER_YET, answer);
  
  //column 5
  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 11", NO_WINNER_YET, answer);
  
  //column 3
  place_token(2, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 12 -- Winner!", 1, answer);
}
void backward_diagonal(CuTest* tc) 
{
 /*
    . . . . . . .
    . . . . . . .
    . . . . . . .
    . . . 1 . . .
    . . 1 2 . . .
    . 1 1 1 . . .
    1 2 2 2 . 2 .
  */ 

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  /* column 0*/
  place_token(1, 1, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 1", NO_WINNER_YET, answer);

  /* column 1*/
  place_token(2, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 2", NO_WINNER_YET, answer);

  place_token(1, 2, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 3", NO_WINNER_YET, answer);


  /* column 2*/
  place_token(2, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 4", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 5", NO_WINNER_YET, answer);

  place_token(2, 6, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 6", NO_WINNER_YET, answer);

  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 7", NO_WINNER_YET, answer);

 /* column 3 */
  place_token(2, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 8", NO_WINNER_YET, answer);

  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 9", NO_WINNER_YET, answer);

  place_token(2, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 10", NO_WINNER_YET, answer);

  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 11 -- Winner!", 1, answer);
}

void backward_diagonal2(CuTest* tc) 
{
 /*
    . . . . . . .
    . . . . . . .
    . . . . . . .
    . . . . . 1 .
    . . . . 1 2 .
    . . . 1 1 1 .
    . . 1 2 2 2 .
  */ 

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

	//column 2
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 1", NO_WINNER_YET, answer);
	
	//column 3
  place_token(2, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 2", NO_WINNER_YET, answer);
  
  place_token(1, 3, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 3", NO_WINNER_YET, answer);
  
  //column 4
  place_token(2, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 4", NO_WINNER_YET, answer);
  
  place_token(1, 4, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 5", NO_WINNER_YET, answer);
  
  //column 5
  place_token(2, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 6", NO_WINNER_YET, answer);
  
  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 7", NO_WINNER_YET, answer);
  
  place_token(2, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 8, NO_WINNER_YET, answer);
  
  place_token(1, 5, num_rows, num_columns, array);
  answer = winner(num_rows, num_columns, 4, array);
  CuAssertIntEquals_Msg(tc, "Step 9 -- Winner!", 1, answer);

}
/*  setup */

CuSuite* c4_engine_suite() {
   CuSuite* suite = CuSuiteNew();

   SUITE_ADD_TEST(suite, winner_horizontal_r0);
   SUITE_ADD_TEST(suite, winner_horizontal_r6);
   SUITE_ADD_TEST(suite, place_token_c1);
  
   SUITE_ADD_TEST(suite, horizontal_row0);
   SUITE_ADD_TEST(suite, horizontal_row6);
   SUITE_ADD_TEST(suite, vertical_column2);
   SUITE_ADD_TEST(suite, vertical_column4);
   SUITE_ADD_TEST(suite, forward_diagonal);
   SUITE_ADD_TEST(suite, forward_diagonal3);
   SUITE_ADD_TEST(suite, backward_diagonal);
   SUITE_ADD_TEST(suite, backward_diagonal3);

   return suite;
}


void RunC4Tests(void) {
   CuString *output = CuStringNew();
   CuSuite* suite = CuSuiteNew();

   CuSuiteAddSuite(suite, c4_engine_suite());
   CuSuiteRun(suite);
   CuSuiteSummary(suite, output);
   CuSuiteDetails(suite, output);
   printf("%s\n", output->buffer);
}

int main(void) {
   RunC4Tests();
   return 0;
}
