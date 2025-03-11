#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int maxCount(int* banned, int bannedSize, int n, int maxSum);
void test();

int maxCount(int* banned, int bannedSize, int n, int maxSum){    
    int count = 0 , sum = 0 , index = 0;
    bannedSize -= 1;
    for ( int num = 1 ; num <= n ; num++ ) {
        for ( index = 0 ; index < bannedSize ; index++ ) {
            if ( banned[index] == num ) {
                break;
            } 
        }
        if ( banned[index] != num ) {
            if ( num + sum <= maxSum ) {
                sum += num;
                count++;
            } else {
                return count;
            }  
        }
    }
    return count;
}




int main( int argc , char const *argv[] ) {
    test();
    return 0;
}

void test(){
    int a[3] = {1,6,5};
    printf( "%d\n" , maxCount( a , 3 , 5 , 6) );
}
