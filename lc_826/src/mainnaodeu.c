#include "lib.h"

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize);
void QuickSort( int * array , int * arrayD , int left , int right );

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) { // O( n * log n + 2n * k )
    int ans = 0 , maxProfit = 0;
    QuickSort( difficulty , profit , 0 , difficultySize - 1 ); // O( n² ) - O( n * log n )

    // O( K * 2n ) 

    for ( int i = 0 ; i < workerSize ; i++ ) {  // O( k )
        for ( int x = 0 ; x < difficultySize ; x++ ) { // O( 2n )
            if( worker[i] < difficulty[x] ) {
                break;
            }   
            if( profit[x] > maxProfit ) {
                maxProfit = profit[x];
            }
        }
        ans += maxProfit;
        maxProfit = 0;
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