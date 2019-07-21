#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reconfigure(char *board_even[], char *board_odd[]);
int populatedCount(int i, int j, char *board[]);
void printBoard(char *board[]);

int h, w;
int n;

int main(int argc, char **argv) {
  /* error check */
  if (atoi(argv[1]) < 0) {
    printf("N must be greater than or equal to 0\n");
    return 0;
  }
  if (argc != 3) {
    printf("insufficient number of arguments\n");
    return 0;
  }
  FILE *fp;
  /* opening the file */
  fp = fopen(argv[2], "r");
  if (fp == NULL) {
    printf("unable to open file\n");
    return 0;
  }

  /* only valid input past this point */
  int i, j, N;
  char temp;
  N = atoi(argv[1]);
  n = 1;
  fscanf(fp, "%d", &h);
  fscanf(fp, "%d", &w);
  fscanf(fp, "%*c");

  char *board_even[h];
  char *board_odd[h];

  /* allocating memory for two dynamic arrays */
  for (i = 0; i < h; i++) {
    board_even[i] = malloc(w * sizeof(char));
    board_odd[i] = malloc(w * sizeof(char));
  }

  /* reading file & loading values into board_even */
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      fscanf(fp, "%c", &temp);
      board_even[i][j] = temp;
    }
    fscanf(fp, "%*c");
  }

  /* closing file */
  fclose(fp);

  /* reconfiguring the board N times */
  while (n <= N) {
    reconfigure(board_even, board_odd);
    n++;
  }

  (N%2 == 0) ? printBoard(board_even) : printBoard(board_odd);

  /* FREE MEMORY */
  for (i = 0; i < h; i++) {
    free(board_even[i]);
    free(board_odd[i]);
  }

  return 0;
}

void printBoard(char *board[]) {
  int i, j;

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }

}


void reconfigure(char *board_even[], char *board_odd[]) {
  int i, j, count;

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
   
      if (n%2 == 0) { // even iteration
        count = populatedCount(i, j, board_odd);
        if (board_odd[i][j] == '.') { // unpopulated cell
          board_even[i][j] = (count == 3) ? '*' : '.'; 
        } else { // populated cell
          board_even[i][j] = (count < 2 || count > 3) ? '.' : '*';
        }
        
      } else { // odd iteration
        count = populatedCount(i, j, board_even);
        if (board_even[i][j] == '.') { // unpopulated cell
          board_odd[i][j] = (count == 3) ? '*' : '.';
        } else { // populated cell
          board_odd[i][j] = (count < 2 || count > 3) ? '.' : '*';
        }

      }
    }
  }

}


int populatedCount(int i, int j, char *board[]) {
  int pop_count = 0;
  int i_temp, j_temp;
  int counter = 1;

  while (counter < 9) {
    switch (counter) { // checks all eight indexes using switch statement
      case 1 :
        i_temp = i - 1;
        j_temp = j;
        break;
      case 2 :
        i_temp = i - 1;
        j_temp = j + 1;
        break;
      case 3 :
        i_temp = i;
        j_temp = j + 1;
        break;
      case 4 :
        i_temp = i + 1;
        j_temp = j + 1;
        break;
      case 5 :
        i_temp = i + 1;
        j_temp = j;
        break;
      case 6 :
        i_temp = i + 1;
        j_temp = j - 1;
        break;
      case 7 :
        i_temp = i;
        j_temp = j - 1;
        break;
      case 8 :
        i_temp = i - 1;
        j_temp = j - 1;
        break;
      default :
        printf("something went wrong ...\n");
        break;
    } // end of switch statement

    /* checks to make sure all indexes are within bounds else it wraps them around (torus) */
    if (j_temp > (w-1)) {
      j_temp = j_temp - w;
    }
    if (j_temp < 0) {
      j_temp = j_temp + w;
    }

    if (i_temp > (h-1)) {
      i_temp = i_temp - h;
    }
    if (i_temp < 0) {
      i_temp = i_temp + h;
    }

    if (board[i_temp][j_temp] == '*') { pop_count++; }
    counter++;

  } // end of while statement

  return pop_count;
}









