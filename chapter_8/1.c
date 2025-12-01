#include <stdio.h>
// counts the number of characters in a file
int main()
{
    // FILE *file;
    // char filename[100];
    int count = 0;
    char ch;

    /*   printf("Enter the filename: ");
      scanf("%s", filename);
      if ((file = fopen(filename, "r")) == NULL)
      {
          printf("Could not open file %s\n", filename);
          return 1;
      } */

    while ((ch = getchar()) != EOF)
    {
        count++;
    }
    // fclose(file);
    printf("Number of characters in file: %d\n", count);
    return 0;
}