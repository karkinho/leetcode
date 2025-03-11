#include "lib.h"

void printMatrix( int ** matrix , int* returnSize , int** returnColumnSizes ) {
    int **aux;
    for ( int row = 0 ; row < *returnSize ; row++ ) {
        printf("[");
        for ( int column = 0 ; column < returnColumnSizes[0][row] ; column++ ) {
            printf("%d " , matrix[row][column] );
        }
        printf("]\n");        
    }
    aux = matrix;
    for ( int row = 0 ; row < *returnSize ; row++ , aux++ ) {
        free( *aux );
    }
    free( matrix );
    free( *returnColumnSizes );
    printf( "------Test Finish------\n" );
}