#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

char* addSpaces(char* s, int* spaces, int spacesSize);
void test();

char* addSpaces(char* s, int* spaces, int spacesSize) {
    int sSize = strlen( s ) , index = 0;
    char* ans = malloc( sSize + spacesSize + 1 ) ;
    for ( int spacesIndex = 0 ; index < sSize + spacesSize ; index++ ) {
        if (spacesIndex < spacesSize && index - spacesIndex == spaces[spacesIndex] ) {
            ans[index] = ' ';
            spacesIndex++;
        } else {
            ans[index] = s[index - spacesIndex];
        }
    }
    ans[index] = 0;
    return ans;
}

int main( int argc , char const *argv[] ) {
    test();
    return 0;
}

void test(){
    int a[3] = {8,13,15};
    int b[4] = {1,5,7,9};
    int c[7] = {0,1,2,3,4,5,6};
    printf( "%s\n" , addSpaces( "LeetcodeHelpsMeLearn" , a , 3) );
    printf( "%s\n" , addSpaces( "icodeinpython" , a , 4) );
    printf( "%s\n" , addSpaces( "spacing" , a , 7) );
}
