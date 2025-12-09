#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int ch;
  if (argc == 1) {
    fprintf(stderr, "Usage: %s filename[s]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "cannot open %s\n", argv[i]);
      exit(EXIT_FAILURE);
    }

    printf("====== %s ======\n", argv[i]);
    while ((ch = getc(fp)) != EOF) {
      putchar(ch);
    }
    putchar('\n');

    if (fclose(fp) != 0)
      fprintf(stderr, "error closing %s\n", argv[i]);
  }
  return 0;
}