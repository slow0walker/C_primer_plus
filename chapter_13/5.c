#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096

void append(FILE *src, FILE *dst);

int main(int argc, char *argv[]) {
  int ch;
  FILE *fa, *fs;
  int files = 0;

  if (argc == 2) {
    fprintf(stderr, "Usage: %s appendfile sourcefile[s]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((fa = fopen(argv[1], "a+")) == NULL) {
    fprintf(stderr, "cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
    fprintf(stderr, "cannot create output buffer\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[1], argv[i]) == 0) {
      fprintf(stderr, "cannot append file %s to itself.\n", argv[i]);
      exit(EXIT_FAILURE);
    }

    if ((fs = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "canot open file %s\n", argv[i]);
      continue;
    }

    if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
      fprintf(stderr, "cannot create input buffer\n");
      fclose(fs);
      continue;
    }

    printf("Appending %s...\n", argv[i]);
    append(fs, fa);
    if (ferror(fs) != 0)
      fprintf(stderr, "Error in reading file %s\n", argv[i]);
    if (ferror(fa) != 0)
      fprintf(stderr, "Error in writing file %s\n", argv[1]);
    fclose(fs);
    files++;
    printf("File %s append.\n", argv[i]);
  }

  printf("Done appending.%d files append.\n", files);
  rewind(fa);
  while ((ch = getc(fa) != EOF)) {
    putchar(ch);
  }
  puts("Done display.");
  fclose(fa);
  return 0;
}

void append(FILE *src, FILE *dst) {
  static char buf[BUFSIZE];
  size_t bytes;
  while ((bytes = fread(buf, 1, BUFSIZE, src)) > 0)
    fwrite(buf, 1, BUFSIZE, dst);
}