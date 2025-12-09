#include <stdio.h>
#include <stdlib.h>
#define MAX 48

int main() {
  FILE *fp;
  char word[MAX];
  int number = 0;
  if ((fp = fopen("words.txt", "a+")) == NULL) {
    fprintf(stderr, "Can't open \"words.txt\" file.\n");
    exit(EXIT_FAILURE);
  }

  rewind(fp);
  while (fscanf(fp, "%d %47s", &number, word) == 2)
    ;

  printf("Current word count: %d\n", number);
  puts("Enter new words(ress # at begining of line to quit):");

  while (fscanf(stdin, "%46s", word) == 1 && word[0] != '#') {
    fprintf(fp, "%d %s\n", ++number, word);
  }
  puts("Done!");
  fclose(fp);
  return 0;
}