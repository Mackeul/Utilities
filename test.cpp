#include <stdio.h>

int main()
{
  int x;
  int y;
  int array[8][8]; /* Declares an array like a chessboard */
  
  for ( x = 0; x < 8; x++ ) {
    for ( y = 0; y < 8; y++ )
      array[x][y] = x * y; /* Set each element to a value */
  }
  printf( "Array Indices:\n" );
  for ( x = 0; x < 8;x++ ) {
    if ( x == 0 ) {
      printf("   01234567\n");
      printf("   --------\n");
    }
    for ( y = 0; y < 8; y++ )
    {
    if ( y == 0 ) {
      printf("%d |",x);
    }
        printf( "%d", array[x][y] );
    }
    printf( "\n" );
  }
  getchar();
}
