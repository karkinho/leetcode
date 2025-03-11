#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main( int argc , char const *argv[] )
{
    int nums1[2] = {1,2}, nums2[2] = {3,4};
    double ans = findMedianSortedArrays( nums1 , 2 , nums2 , 2 );
    printf( "%lf\n", ans );
    return 0;
}


double findMedianSortedArrays( int* nums1 , int nums1Size , int* nums2 , int nums2Size ) {
    int array[nums1Size + nums2Size] , sum = nums1Size + nums2Size , chao , teto ;
    double ans;
    for (int pos1 = 0, pos2 = 0 , i = 0; i < sum ; i++ ){
        if ( pos1 != nums1Size && pos2 != nums2Size ){ 
            if ( nums1[pos1] < nums2[pos2] ) {
                array[i] = nums1[pos1];
                pos1++;
            } else {
                array[i] = nums2[pos2];
                pos2++;
            }
        } else if ( pos1 != nums1Size ) {
            array[i] = nums1[pos1];
            pos1++;
        } else {
            array[i] = nums2[pos2];
            pos2++;
        }
    }
    if ( ( sum ) % 2 == 0 )
    {
        chao = sum / 2 - 1;
        teto = sum / 2 ;
        ans = ( array[chao] + array[teto] ) / 2.0;
    } else {
        ans = array[ ( sum - 1 )  / 2 ];
    }
    return ans ;
}