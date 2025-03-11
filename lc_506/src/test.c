#include "lib.h"

void printArrayChar( char ** array , int size ) {
    for ( int index = 0 ; index < size ; index++ ) {
        printf( "%s, " , *( char ** )( array + index ) );
    }
    printf( "\n" );
}