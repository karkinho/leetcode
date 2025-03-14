#include "lib.h"

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize);
void QuickSort( int * array , int * arrayD , int left , int right );

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    int ans = 0;
    QuickSort( profit , difficulty , 0 , profitSize - 1 );
    for ( int i = 0 ; i < workerSize ; i++ ) {
        for ( int x = profitSize - 1 ; x >= 0 ; x-- ) {
            if( worker[i] >= difficulty[x] ) {
                ans += profit[x];
                break;
            }   
        }
    }
    return ans;
}


void QuickSort( int * array , int * arrayD , int left , int right ) {
    int pivot = ( right + left ) / 2;
    int l = left , r = right , temp = 0;
    do {
        while ( array[l] < array[pivot] ) {
            l++;
        }
        while ( array[r] > array[pivot] ) {
            r--;
        }
        if( l <= r ) {
            temp = array[r];
            array[r] = array[l];
            array[l] = temp;
            temp = arrayD[r];
            arrayD[r] = arrayD[l];
            arrayD[l] = temp;
            l++;
            r--;
        }
    } while ( l <= r );
    if( left < r ) {
        QuickSort( array , arrayD , left , r );
    }
    if( l < right ) {
        QuickSort( array , arrayD , l , right );
    }
}