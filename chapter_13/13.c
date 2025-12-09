#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rows = 20, cols = 30;
  int data[rows][cols];
  char picture[rows][cols + 1];
  const char map[] = " .':~*=&%#";
  int r, c;
  FILE *fin, *fout;

  if ((fin = fopen("picture.dat", "r")) == NULL) {
    fprintf(stderr, "Can't open picture.dat\n");
    exit(EXIT_FAILURE);
  }

  for (r = 0; r < rows; r++)
    for (c = 0; c < cols; c++)
      fscanf(fin, "%d", &data[r][c]);
  fclose(fin);

  for (r = 0; r < rows; r++) {
    for (c = 0; c < cols; c++)
      picture[r][c] = map[data[r][c]];
    picture[r][cols] = '\0';
  }

  for (r = 0; r < rows; r++)
    puts(picture[r]);

  if ((fout = fopen("picture.txt", "w")) == NULL) {
    fprintf(stderr, "Can't open picture.txt\n");
    exit(EXIT_FAILURE);
  }
  for (r = 0; r < rows; r++)
    fprintf(fout, "%s\n", picture[r]);
  fclose(fout);

  return 0;
}
