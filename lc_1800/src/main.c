#include "lib.h"

int maxAscendingSum( int* nums , int numsSize );
void test1();
void test2();
void test3();

int main( ) {
    test1();
    test2();
    test3();
    return 0;
}

void test1() {
    /*Input: nums = [10,20,30,5,10,50]
    Output: 65
    Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.*/
    int nums[6] = {10,20,30,5,10,50};
    printf( "Teste 1: %d | Deve Ser 65\n", maxAscendingSum( nums , 6 ) );
}

void test2() {
    /* Input: nums = [10,20,30,40,50]
    Output: 150
    Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.*/
    int nums[5] = {10,20,30,40,50};
    printf( "Teste 2: %d | Deve Ser 150\n", maxAscendingSum( nums , 5 ) );
}

void test3() {
    /* Input: nums = [12,17,15,13,10,11,12]
    Output: 33
    Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.*/
    int nums[7] = {12,17,15,13,10,11,12};
    printf( "Teste 3: %d | Deve Ser 33\n", maxAscendingSum( nums , 7 ) );
}

int maxAscendingSum( int* nums, int numsSize ) {
    int top = numsSize - 1 , sum = 0 , ans = 0 , lastnum = 0;
    while ( top >= 0 ) {
        if( top == numsSize - 1 ) {
            sum = nums[ top ];
            lastnum = nums[ top ];
            top--;
            continue;
        }
        if( nums[ top ] < lastnum ){
            sum += nums[ top ];
        } else {
            if( ans < sum ) {
                ans = sum;
            }
            if( nums[ top ] > ans ) {
                ans = nums[ top ];
            }
            sum = nums [ top ];
        }
        lastnum = nums[ top ];
        top--;
    }
    if ( sum > ans ) {
        ans = sum;
        sum = 0;
    }
    return ans;
}
