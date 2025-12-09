#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

int main(void) {
  int data[ROWS][COLS];
  char picture[ROWS][COLS + 1];
  const char map[] = " .':~*=&%#"; // 0..9 -> chars
  int r, c;
  FILE *fin, *fout;

  if ((fin = fopen("picture.dat", "r")) == NULL) {
    fprintf(stderr, "Can't open picture.dat\n");
    exit(EXIT_FAILURE);
  }

  for (r = 0; r < ROWS; r++)
    for (c = 0; c < COLS; c++)
      if (fscanf(fin, "%d", &data[r][c]) != 1) {
        fprintf(stderr, "Bad data in file.\n");
        fclose(fin);
        exit(EXIT_FAILURE);
      }

  fclose(fin);

  /* convert to chars */
  for (r = 0; r < ROWS; r++) {
    for (c = 0; c < COLS; c++)
      picture[r][c] = map[data[r][c]];
    picture[r][COLS] = '\0';
  }

  /* print to screen */
  for (r = 0; r < ROWS; r++)
    puts(picture[r]);

  /* also save to text file */
  if ((fout = fopen("picture.txt", "w")) == NULL) {
    fprintf(stderr, "Can't open picture.txt\n");
    exit(EXIT_FAILURE);
  }

  for (r = 0; r < ROWS; r++)
    fprintf(fout, "%s\n", picture[r]);

  fclose(fout);
  return 0;
}
