

/*
   UCF 2014 (Fall) Local Programming Contest
   Problem: vowel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ************************************************************ */

int main(void)
{
   int   vowel_count, j;
   char  name[25];
   FILE  *in_fptr = stdin;;

   fscanf(in_fptr, "%s\n", &name[0]);
   printf("%s\n", name);
   vowel_count = 0;

   for ( j = 0;  j < strlen(name);  ++j )
      switch(name[j])
        {
         case 'a':
         case 'e':
         case 'i':
         case 'o':
         case 'u':
            ++vowel_count;
        }

   if ( vowel_count > (strlen(name) - vowel_count) )
      printf("1\n");
   else
      printf("0\n");

   return(0);

}/* end main */

/* ************************************************************ */

