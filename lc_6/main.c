#include <string.h>
#include <stdio.h>

char* convert(char* s, int numRows);

int main(int argc, char const *argv[])
{
    char string[255] = "PAYPALISHIRING";
    int rows = 3;
    printf( "%s\n" , convert( string , rows ) );
    return 0;
}


char* convert(char* s, int numRows) {
    int sSize = strlen( s ) , index = 0, collunm = 0;
    char matrix [sSize][numRows] ;
    for ( int x = 0 ; x < numRows ; x++ ) {
        for ( int y = 0 ; y < sSize; y++){
            matrix[y][x] = ' ';
        }
    }
    
    while ( s[index] != '\0' ) {
        for ( int i = 0 ; i < numRows ; i++ ) {
            matrix[collunm][i] = s[index];
            index++;
        }
        collunm++;
        for ( int  i = numRows - 2 ; i > 0 ; i-- ){
            matrix[collunm][i] = s[index];
            index++;
            collunm++;
        }
    }
    index = 0;
    for ( int i = 0; i < numRows; i++ ){
        for ( int x = 0 ; x < sSize ; x++)
        {
            if ( matrix[x][i] != ' ' && matrix[x][i] != '\0' ) { 
                s[index] = matrix[x][i];
                index++;
            }
        }
        
    }
    return s;
}