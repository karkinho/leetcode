#include "lib.h"

bool isHappy(int n);

int main( ) {
    isHappy( 2 );
    return 0;
}

bool isHappy(int n) {
    int digits[14] , index = 0 , sums[200000] , sumsSize = 0;
    while ( true ) {
        do {
            digits[index] = n % 10;
            n /= 10;
            index++; 
        } while ( n != 0 );
        for ( int i = 0 ; i < index ; i++ ){
            n += digits[i] * digits[i];
        }
        if( n == 1 ) {
            return true;
        }
        sums[sumsSize + 1] = n;
        for ( int i = 0 ; i < sumsSize ; i++ ) {
            if ( sums[i] == n ){ return false; }            
        }
        sumsSize++;
        index = 0;
    }
}