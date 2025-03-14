#include "lib.h"

int maximumGap( int* nums , int numsSize );
int * Merge_Sort( int * array , int start , int end );
int * Merge( int * arrayL , int * arrayR , int sizeL , int sizeR );

int main( ) {
    return 0;
}

int maximumGap( int* nums , int numsSize ) {
    if( numsSize < 2 ) return 0;
    int * ans = Merge_Sort( nums , 0 , numsSize );
    int dif = 0;
    for ( int i = 1; i < numsSize; i++) {
        if( ans[i] - ans[i - 1] > dif ) {
            dif = ans[i] - ans[i - 1];
        }
    }
    return dif;
}

int * Merge_Sort( int * array , int start , int end ) {
    int size = end - start;
    int half = size / 2;
    int * left , * right;
    if( size == 1 ) {
        return &array[start];
    }
    left = Merge_Sort( array , start , start + half );
    right = Merge_Sort( array , start + half , end );

    return Merge( left , right , half , size - half );
}

int * Merge( int * arrayL , int * arrayR , int sizeL , int sizeR ) {
    int * ans = ( int * )malloc( sizeof( int ) * ( sizeL + sizeR ) );
    int top = 0 , topL = 0 , topR = 0;

    while ( topL < sizeL && topR < sizeR ) {
        if( arrayL[topL] < arrayR[topR] ) {
            ans[top] = arrayL[topL];
            top++;
            topL++;
        } else {
            ans[top] = arrayR[topR];
            top++;
            topR++;
        }
    }
    if( topL < sizeL ) {
        while ( topL < sizeL ) {
            ans[top] = arrayL[topL];
            top++;
            topL++;
        }
        return ans;
        
    }
    if( topR < sizeR ) {
        while ( topR < sizeR ) {
            printf( "%d\n", arrayR[topR] );
            ans[top] = arrayR[topR];
            top++;
            topR++;
        }
        return ans;
    }
    return ans;
}