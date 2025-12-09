#include <stdio.h>
#include <stdlib.h>
#define LEN 20

int main() {
  int ch; // character one by one
  FILE *fp;
  char filename[LEN];
  long count;

  printf("Enter the filename you want:");
  while (scanf("%255s", filename) != 1) {
    fprintf(stderr, "Error input!");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Cannot open the file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF) {
    putc(ch, stdout);
    count++;
  }

  fclose(fp);
  printf("\nfile %s has %lu characters.\n", filename, count);
  return 0;
}