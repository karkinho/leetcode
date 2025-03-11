#include "lib.h"

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void testMatrix1();
void testMatrix2();

int main( int argc , char const *argv[] ) {
    testMatrix1();
    testMatrix2();
    return 0;
}

void testMatrix1() {
    int ** returnColumnSizes = ( int **)malloc( sizeof( int * )) , * returnSize = ( int *)malloc( sizeof( int ) );
    int ** ans; 
    int test1[6] = {-1,0,1,2,-1,-4}; 
    ans = threeSum( test1 , 6 , returnSize , returnColumnSizes );
    printMatrix( ans , returnSize , returnColumnSizes );
    free( returnSize );
    free( returnColumnSizes );
    // [[-1,-1,2],[-1,0,1]]
}

void testMatrix2() {
    int ** returnColumnSizes = ( int **)malloc( sizeof( int * )) , * returnSize = ( int *)malloc( sizeof( int ) );
    int ** ans; 
    int test2[11] = {-1,0,1,2,-1,-4,-2,-3,3,0,4}; 
    ans = threeSum( test2 , 11 , returnSize , returnColumnSizes );
    printMatrix( ans , returnSize , returnColumnSizes );
    free( returnSize );
    free( returnColumnSizes );
    // [[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int ** ans = (int **)malloc( sizeof( int *)  * ( numsSize * numsSize ) ) , ** aux = NULL , flag = 0 , second = 0 , third = 0;
    aux = ans;
    *returnSize = 0;

    qsort( nums , numsSize , sizeof( int ) , comp );
    
    for ( int first = 0; first < numsSize - 2  ; first++ ) {
        second = first + 1;
        third = numsSize - 1;
        while ( third > second ) {
            if ( nums[first] + nums[second] + nums[third] < 0 ) { 
                second++;
                continue;
            }
            if ( nums[first] + nums[second] + nums[third] > 0 ) { 
                third--;
                continue;
            }
            if ( nums[first] + nums[second] + nums[third] == 0 ) {
                for ( int row = 0; row < *returnSize ; row++ ) {
                    if ( nums[first] == ans[row][0] && nums[second] == ans[row][1] && nums[third] == ans[row][2] ) {
                        flag = 1;
                        break;
                    }
                }  
                if ( flag < 1 ){
                    *returnSize += 1;                  
                    *aux = ( int * )malloc( sizeof( int ) * 3);
                    aux[0][0] = nums[first];
                    aux[0][1] = nums[second];
                    aux[0][2] = nums[third];
                    aux++;
                }
                second++;
                flag = 0;
            }
        }
    } 
    *returnColumnSizes = ( int * )malloc( sizeof( int ) * *returnSize); 
    for ( int i = 0; i < *returnSize; i++ ) {
        returnColumnSizes[0][i] = 3;
    }
    return ans;
}