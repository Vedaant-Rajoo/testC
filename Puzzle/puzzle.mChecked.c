#include <stdio_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE on
// CheckedC version of puzzle code 
// sourced at : https://gist.githubusercontent.com/qwerty2323/110d63e8560453323d0cceba128f42d7/raw/6639355d51519855bcedad87180a5c31d2db9ec9/.c
int valid(int checked[][9]:count(9),int row,int column,int guess);
int solve(int checked[][9]:count(9));
int find_empty_cell(int checked[][9]:count(9),_Ptr<int>,_Ptr<int>);

int main(void){
  int puzzle _Checked[9][9] = {{1, 7, 4, 0, 9, 0, 6, 0, 0},
                      {0, 0, 0, 0, 3, 8, 1, 5, 7},
                      {5, 3, 0, 7, 0, 1, 0, 0, 4},
                      {0, 0, 7, 3, 4, 9, 8, 0, 0},
                      {8, 4, 0, 5, 0, 0, 3, 6, 0},
                      {3, 0, 5, 0, 0, 6, 4, 7, 0},
                      {2, 8, 6, 9, 0, 0, 0, 0, 1},
                      {0, 0, 0, 6, 2, 7, 0, 3, 8},
                      {0, 5, 3, 0, 8, 0, 0, 9, 6}};
  int row = 0;
  int column = 0;
  if (solve(puzzle)) {
    printf("\n+-----+-----+-----+\n");
    for (int x = 0; x < 9; ++x) {
      for (int y = 0; y < 9; ++y) printf("|%d", puzzle[x][y]);
      printf("|\n");
      if (x % 3 == 2) printf("\n+-----+-----+-----+\n");
    }
  }
  else {
    printf("\n\nNO SOLUTION FOUND\n\n");
  }
  return 0;
}
int valid (int puzzle checked[][9]:count(9), int row, int column, int guess) {
  int corner_x = row / 3 * 3;
  int corner_y = column / 3 * 3;
  

  for (int x = 0; x < 9; ++x) {
    if (puzzle[row][x] == guess) return 0;
    if (puzzle[x][column] == guess) return 0;
    if (puzzle[corner_x + (x % 3)][corner_y + (x / 3)] == guess) return 0;
  }
  return 1;
}

int find_empty_cell(int puzzle checked[][9]:count(9), _Ptr<int> row,_Ptr<int> column) {
  for (int x = 0; x < 9; x++) {
    for (int y = 0; y < 9; y++) {
      if (!puzzle[x][y]) {
        *row = x;
        *column = y;

        return 1;
      }
    }
  }
  return 0;
}

int solve(int puzzle checked[][9]:count(9)) {
  int row;
  int column;

  if(!find_empty_cell(puzzle, &row, &column)) return 1;

  for (int guess = 1; guess < 10; guess++) {
    if (valid(puzzle, row, column, guess)) {
      puzzle[row][column] = guess;

      if(solve(puzzle)) return 1;
      puzzle[row][column] = 0;
    }
  }
  return 0;
}