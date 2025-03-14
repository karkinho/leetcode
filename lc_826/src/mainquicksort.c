#include "lib.h"

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize);
void QuickSort( int * array , int * arrayD , int left , int right );

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) { // O( n * log n + n * k )
    int ans = 0;
    QuickSort( profit , difficulty , 0 , profitSize - 1 ); // O( n² ) - O( n * log n )

    // 0( n * k )

    for ( int i = 0 ; i < workerSize ; i++ ) { // O ( k )
        for ( int x = profitSize - 1 ; x >= 0 ; x-- ) { // O ( n )
            if( worker[i] >= difficulty[x] ) {
                ans += profit[x];
                break;
            }   
        }
    }
    return ans;
}


void QuickSort( int * array , int * arrayD , int left , int right ) { 
    int pivot = array[( left + right ) / 2];
    int l = left , r = right , temp = 0;
    do {
        while ( array[l] < pivot ) {
            l++;
        }
        while ( array[r] > pivot ) {
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