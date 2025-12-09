#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024
int main(int argc, char *argv[]) {
  char line[MAXLINE];
  FILE *f1, *f2;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((f1 = fopen(argv[1], "r")) == 0 || (f2 = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "cannot open input files.\n");
    exit(EXIT_FAILURE);
  }

  while (true) {
    if (fgets(line, MAXLINE, f1) != NULL)
      fputs(line, stdout);
    if (fgets(line, MAXLINE, f2) != NULL)
      fputs(line, stdout);
    if (feof(f1) && feof(f2))
      break;
  }

  // reset the file pointer to the beginning.
  rewind(f1);
  rewind(f2);

  char l1[MAXLINE];
  char l2[MAXLINE];

  while (true) {
    bool got1 = fgets(l1, MAXLINE, f1) != NULL;
    bool got2 = fgets(l2, MAXLINE, f2) != NULL;

    // if file end,the return of fgets() is zero
    if (!got1 && !got2)
      break;

    if (got1) {
      size_t len = strlen(l1);
      if (len && l1[len - 1] == '\n')
        l1[len - 1] = '\0';
      fputs(l1, stdout);
    }
    if (got2)
      fputs(l2, stdout);
    else
      putchar('\n');
  }
  if (fclose(f1) != 0 || fclose(f2) != 0)
    fprintf(stderr, "Error closing.\n");
  return 0;
}