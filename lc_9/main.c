#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x);

int main( int argc , char const *argv[] ){
    int nums[3] = {3,2,4};
    int target = 6;
    int numsSize = 3;
    int *returnSize;
    int *array;
    returnSize = (int *)malloc(4);

    printf( "%d\n" , isPalindrome(121));
    return 0;
}

bool isPalindrome(int x) {
    char str[11], str2[11];
    int i = 0;
    if ( x < 0 ){
        return false;
    }
    sprintf( str, "%d", x );
    for ( int index = strlen( str ) - 1 ; index >= 0 ; index-- ){
        str2[i] = str[index];
        i++;
    }
    str2[i] = '\0';
    if ( strcmp( str , str2) == 0 ) {
        return true;
    }
    return false;
}
