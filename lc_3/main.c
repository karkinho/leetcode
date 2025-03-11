#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s);

int main(int argc, char const *argv[])
{
    char string1[20] = "asddzxcsd"; // resposta 5
    char string2[20] = "bbbbb"; // resposta 1
    char string3[20] = "au"; // resposta 2
    //printf( "teste 1:%d\n", lengthOfLongestSubstring( string1 ) );
    //printf( "teste 2:%d\n", lengthOfLongestSubstring( string2 ) );
    printf( "teste 3:%d\n", lengthOfLongestSubstring( string3 ) ); 
    return 0;
    // que deus tenha piedade da minha alma -mauricio zahn 
    // que codigo tenebrozo
}

int test( char* s , int base, int sizeSubString ) {
    for ( int x = 0 ; x < sizeSubString ; x++) {
        for ( int y = x + 1 ; y < sizeSubString ; y++ ){
            if ( s[x + base] == s[y + base]){
                return 0;
            }
        }
    }
    return 1;
}

int lengthOfLongestSubstring(char* s) { 
    int maxSubString = 1, flag = 1, size = strlen( s );
    if ( size == 0 ){
        return 0;
    }
    for ( int sizeSubString = 2 ; sizeSubString <= size ; sizeSubString++) {   
        for ( int base = 0 ; base <= size - sizeSubString ; base++ ) {
            flag = test( s, base ,  sizeSubString );
            if ( flag  == 1 ) {
                break;
            }
        }
        if ( flag == 0 ) {
            return maxSubString;
        } else {
            maxSubString = sizeSubString;
        }
    }
    return maxSubString;
}
