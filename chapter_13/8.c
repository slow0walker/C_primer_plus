#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int ch;
  int target;
  FILE *fp;
  long count = 0L;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s character [file...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  target = (unsigned char)argv[1][0];

  if (argc == 2) {
    count = 0;
    printf("Enter text what you want:");
    while ((ch = getchar()) != EOF)
      if (ch == target)
        count++;
    printf("stdin: '%c'occurs %ld times\n", target, count);
  } else {
    for (int i = 2; i < argc; i++) {
      if ((fp = fopen(argv[i], "r")) == NULL) {
        fprintf(stderr, "cannot open file %s \n", argv[i]);
        continue;
      }

      count = 0;
      while ((ch = getc(fp)) != EOF)
        if (ch == target)
          count++;
      printf("%s: '%c' occurs %ld times\n", argv[i], target, count);

      fclose(fp);
    }
  }
  return 0;
}