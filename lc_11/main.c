#include <stdio.h>

int maxArea(int* height, int heightSize);

int main(int argc, char const *argv[])
{
    
    return 0;
}

int maxArea( int* height , int heightSize ) {
    int max = 0 , sum = 0 , leftIndex = 0 , rightIndex = heightSize - 1;
    while ( leftIndex != rightIndex ) {
        if ( height[leftIndex] <= height[rightIndex] ) {
            sum = height[leftIndex] * ( rightIndex - leftIndex );
            if ( sum > max ) {
                max = sum;
            }
            leftIndex++;
        } else {
            sum = height[rightIndex] * ( rightIndex - leftIndex );
            if ( sum > max ) {
                max = sum;
            }
            rightIndex--;
        }
    }
    return max;
}
