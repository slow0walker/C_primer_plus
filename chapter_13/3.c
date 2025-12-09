#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN 20

int main() {
  int ch;
  FILE *src, *dst;
  char src_filename[20];
  char dst_filename[20];

  printf("Enter the source filename:");
  while (scanf("%255s", src_filename) != 1) {
    fprintf(stderr, "Error input\n");
    exit(EXIT_FAILURE);
  }

  if ((src = fopen(src_filename, "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", src_filename);
    exit(EXIT_FAILURE);
  }

  printf("Enter the output filename:");
  while (scanf("%255s", dst_filename) != 1) {
    fprintf(stderr, "error input\n");
    fclose(src);
    exit(EXIT_FAILURE);
  }

  if ((dst = fopen(dst_filename, "w")) == NULL) {
    fprintf(stderr, "cannot open file %s", dst_filename);
    fclose(src);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(src)) != EOF) {
    putc(toupper(ch), dst);
  }
  if (fclose(src) != 0 || fclose(dst) != 0)
    fprintf(stderr, "error closing\n");
  return 0;
}