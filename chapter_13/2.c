#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *src, *dst;
  int ch;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s source_file,copy_file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((src = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dst = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Cannot open file %s\n", argv[2]);
    fclose(src);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(src)) != EOF) {
    putc(ch, dst);
  }

  if (fclose(src) != 0 || fclose(dst) != 0)
    fprintf(stderr, "Error closing files.\n");
}