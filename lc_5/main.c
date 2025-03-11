#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char* longestPalindrome( char* s );

int main(int argc, char const *argv[])
{   
    char string[20] = "babad";
    char* ans = longestPalindrome( string );
    printf( "%s\n" , ans );
    return 0;
}

int test( char* s , int* start , int* end , int base , int sizeWindow ) {
    for ( int x = 0 ,y = sizeWindow - 1 ; x < sizeWindow ; x++ , y--){
        if ( s[x + base] != s[y + base] ) {
            return 0;
        }
    }
    *start = base;
    *end = base + sizeWindow - 1;
    return 1;
}

char* longestPalindrome( char* s ) {
    int start , end , sizeS = strlen( s );
    for ( int sizeWindow = 1 ; sizeWindow <= sizeS ; sizeWindow++) {
        for (int base = 0; base <= sizeS - sizeWindow; base++){
            if ( test( s , &start , &end , base , sizeWindow ) ){
                break;
            }
        }
    }
    s[end + 1] = '\0';
    s = &s[start];
    return s;
}
