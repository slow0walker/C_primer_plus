#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

int main(void) {
  int src[ROWS][COLS];
  int dst[ROWS][COLS];
  const char map[] = " .':~*=&%#";
  char picture[ROWS][COLS + 1];
  int r, c;
  FILE *fin;

  if ((fin = fopen("picture.dat", "r")) == NULL) {
    fprintf(stderr, "Can't open picture.dat\n");
    exit(EXIT_FAILURE);
  }

  for (r = 0; r < ROWS; r++)
    for (c = 0; c < COLS; c++)
      fscanf(fin, "%d", &src[r][c]);
  fclose(fin);

  // copy original to dst first
  for (r = 0; r < ROWS; r++)
    for (c = 0; c < COLS; c++)
      dst[r][c] = src[r][c];

  // deglitching
  for (r = 0; r < ROWS; r++) {
    for (c = 0; c < COLS; c++) {
      int sum = 0, neighbors = 0;

      if (r > 0) {
        sum += src[r - 1][c];
        neighbors++;
      }
      if (r < ROWS - 1) {
        sum += src[r + 1][c];
        neighbors++;
      }
      if (c > 0) {
        sum += src[r][c - 1];
        neighbors++;
      }
      if (c < COLS - 1) {
        sum += src[r][c + 1];
        neighbors++;
      }

      if (neighbors > 0) {
        double avg = (double)sum / neighbors;
        int rounded = (int)floor(avg + 0.5);

        if (abs(src[r][c] - rounded) > 1)
          dst[r][c] = rounded;
      }
    }
  }

  /* convert to chars and show */
  for (r = 0; r < ROWS; r++) {
    for (c = 0; c < COLS; c++)
      picture[r][c] = map[dst[r][c]];
    picture[r][COLS] = '\0';
  }

  for (r = 0; r < ROWS; r++)
    puts(picture[r]);

  return 0;
}
