#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* twoSum( int* nums , int numsSize, int target , int* returnSize );

int main( int argc , char const *argv[] ){
    int nums[3] = {3,2,4};
    int target = 6;
    int numsSize = 3;
    int *returnSize;
    int *array;
    returnSize = (int *)malloc(4);
    array = twoSum( nums , numsSize , target , returnSize);
    printf( "%d %d\n", array[0], array[1] );
    return 0;
}

int* twoSum( int* nums , int numsSize, int target , int* returnSize ) {
    int *array = ( int *)malloc( 2 * sizeof( int ) );
    *returnSize = 2;
    for ( int index = 0 ; index < numsSize ; index++ ) {
        for ( int pointer = index + 1 ; pointer < numsSize ; pointer++ ) {
            if ( nums[index] + nums[pointer] == target ) {
                array[0] = index;
                array[1] = pointer;
                return array;
            }
        }
    }
    return array;
}