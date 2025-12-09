#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main() {
  char src_filename[LEN];
  char dst_filename[LEN];
  FILE *src, *dst;
  int count = 0;
  int ch;

  printf("Enter source filename:");
  while (scanf("%255s", src_filename) != 1) {
    fprintf(stderr, "Error input.");
    exit(EXIT_FAILURE);
  }

  printf("Enter destionation filename:");
  while (scanf("%255s", dst_filename) != 1) {
    fprintf(stderr, "Error input.");
    exit(EXIT_FAILURE);
  }

  if ((src = fopen(src_filename, "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", src_filename);
    exit(EXIT_FAILURE);
  }

  if ((dst = fopen(dst_filename, "w")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", dst_filename);
    fclose(src);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(src)) != EOF) {
    if (count++ % 3 == 0)
      putc(ch, dst);
  }

  if (fclose(src) != 0 || fclose(dst) != 0)
    puts("Error closing.\n");
  puts("Done!");
  return 0;
}
