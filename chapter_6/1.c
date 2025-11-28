#include <stdio.h>

int main()
{
   char lowercase_letter[26];
   for(int i =0; i<26;i++)
  {
      lowercase_letter[i]=  'a'+i ;
  }  
  for(int i=0;i<26;i++)
  {
      printf("%c ",lowercase_letter[i]);
  }
  printf("\n");
  return 0;
}                              