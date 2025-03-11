#include <stdbool.h>

bool test( int index , const int *nums , int delta ) {
    if ( index == 0 ) {
        return true;
    }
    while ( nums[index - delta ] < delta  ){
        if ( index == delta   ) { 
            return false;
        }
        delta++;
    }
    return test( index - delta , nums , 1 );
}

bool canJump(const int *nums, int numsSize) {
    if ( numsSize == 1 ) {
        return true;
    }
    if ( nums[0] == 0 ) {
        return false;
    }
    return test( numsSize - 1 , nums , 1 );
}