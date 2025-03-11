#include <string.h>
#include <limits.h>
#include <stdio.h>

int myAtoi( char* s );

int main( int argc , char const *argv[] ) {
    myAtoi( "2147483648" );
    return 0;
}

int myAtoi( char* s ) {
    int size = strlen( s ) , sIndex = 0 , ansIndex = 0 , ans = 0;
    int negative = 0 , reading = 1;
    char buff[size + 1] , auxBuff[12];

    // find first valid char

    while ( s[sIndex] != '\0' ) {
        if ( s[sIndex] == '0' ) {
            sIndex++;
            break;
        }

        if ( s[sIndex] >= '1' && s[sIndex] <= '9' ) {
            break;
        }

        if ( s[sIndex] >= 'a' && s[sIndex] <= 'z' || s[sIndex] >= 'A' && s[sIndex] <= 'Z' || s[sIndex] == '.' ){
            reading = 0;
            break;
        }

        if ( s[sIndex] == '-' ) {
            negative = 1;
            sIndex++;
            break;
        }
        if ( s[sIndex] == '+' ) {
            negative = 0;
            sIndex++;
            break;
        }
        sIndex++;
    }

    // remove leading 0's

    while ( s[sIndex] != '\0' && reading == 1 ) {
        if ( s[sIndex] == '0' ) {
            sIndex++;
        } else {
            break;
        }
    }   

    // reading to the right of the firt valid char;

    while ( s[sIndex] != '\0' && reading == 1  ){
        if ( s[sIndex] >= '0' && s[sIndex] <= '9' ) {
            buff[ansIndex] = s[sIndex];
            ansIndex++;
        } else { 
            break;
        }
        sIndex++;
    }
    buff[ansIndex] = '\0';
    if ( ansIndex > 10 ){
        if ( negative == 1) {
            return INT_MIN;
        } else {
            return INT_MAX;
        }
    }
    if ( ansIndex == 10 ) {
        strcpy( auxBuff , buff );
        auxBuff[9] = '\0';
        sscanf( auxBuff , "%d" , &ans );
        if ( negative == 1 ) {
            if ( ans * -1 < INT_MIN / 10 || ( ans * -1 == INT_MIN / 10 && buff[9] >= '8' ) ) {
                return INT_MIN;
            }
        } else {
            if ( ans > INT_MAX / 10 || ( ans == INT_MAX / 10 && buff[9] >= '7' ) ) {
                return INT_MAX ;
            }
        }
    }
    sscanf( buff , "%d" , &ans );
    if ( negative == 1 && ans > 0 ) {
        ans = ans * -1;
    }
    return ans;
}