#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256

int main(int argc, char *argv[]) {
  FILE *fp;
  char line[LEN];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s string filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, LEN, fp) != NULL) {
    if (strstr(line, argv[1]) != NULL)
      fputs(line, stdout);
  }

  fclose(fp);
  return 0;
}