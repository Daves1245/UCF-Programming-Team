

/*
   UCF 2014 (Fall) Local Programming Contest
   Problem: soccer
*/

#include <stdio.h>
#include <stdlib.h>

/* ************************************************************ */

int main(void)
{
   int   data_set_count, k, games, points, win, tie;
   FILE  *in_fptr = stdin;

   fscanf(in_fptr, "%d %d", &games, &points);

   for ( win = (points / 3);  win >= 0;  --win )
   {
      tie = points - (3 * win);
      if ( games >= (win + tie) )
         printf("%d-%d-%d\n", win, tie, (games - win - tie) );
   }

   printf("\n");

   return(0);

}/* end main */

/* ************************************************************ */

