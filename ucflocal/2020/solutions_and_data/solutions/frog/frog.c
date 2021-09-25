
/*
   UCF 2014 (Fall) Local Programming Contest
   Problem: frog
*/

#include <stdio.h>
#include <stdlib.h>

#define  BLOCKED_CELL  'X'

/* ************************************************************ */

int main(void)
{
   int   data_set_count, 
         cell_count, how_far, /* the two input values per data set */
         jump_count, curr_loc,
         k, j;
   char  cell[60]; /* cell[0] is not used to make programming easier */
   FILE  *in_fptr = stdin;

   fscanf(in_fptr, "%d %d\n", &cell_count, &how_far);
   for ( j = 1;  j <= cell_count;  ++j )
   {
      fscanf(in_fptr, "%c", &cell[j]);
   }

   jump_count = 0;
   curr_loc = 1;

   while ( curr_loc < cell_count )
     {
      /* jump as far as possible */
      j = how_far + 1;
      while ( (j > 0)  &&
              ((curr_loc + j) <= cell_count)  &&
              (cell[curr_loc + j] == BLOCKED_CELL) )
         --j;

      if ( j > 0 )
        {/* was able to jump */
         curr_loc += j;
         ++jump_count;
        }
      else
         /* could not jump */
         break;

     } /* end while ( curr_loc < cell_count ) */

   if ( curr_loc >=  cell_count )
      printf("%d\n", jump_count);
   else
      printf("0\n");

   return(0);

}/* end main */

/* ************************************************************ */

