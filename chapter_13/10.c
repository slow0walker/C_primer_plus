#include <stdio.h>
#include <stdlib.h>

#define LINE 256

int main() {
  char filename[LINE];
  FILE *fp;
  long pos;
  int ch;

  printf("Enter filename:");
  while (scanf("%10s", filename) != 1) {
    fprintf(stderr, "Error inputing!");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  printf("Enter a file position (negatie to quit):");
  while (scanf("%ld", &pos) == 1 && pos >= 0) {
    if (fseek(fp, pos, SEEK_SET) != 0) {
      puts("seek error.");
      break;
    }
    while ((ch = getc(fp)) != EOF && ch != '\n') {
      putchar(ch);
    }
    putchar('\n');
    puts("Next position:");
  }
  fclose(fp);
  puts("Done!");
  return 0;
}