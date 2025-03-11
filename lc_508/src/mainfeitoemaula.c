#include "lib.h"

int* findFrequentTreeSum( struct TreeNode* root, int* returnSize );
int SumSubtree( struct TreeNode* root , int * array , int * frequency , int * size );

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int main( ) {
    return 0;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    if( root == NULL ) {
        return 0;
    }
    int * array = ( int * )malloc( sizeof( int ) * 10000 );
    int * frequency = ( int * )malloc( sizeof( int ) * 10000 ) , size = 0;
    *returnSize = 0; 
    int i = 0 , biggest = -1;
    int * ans = ( int * )malloc( sizeof( int ) * 10000 );

    SumSubtree( root , array , frequency , &size );

    for ( i = 0; i < size; i++) { // O(N)
        if( frequency[i] > biggest ) {
            biggest = frequency[i];
        }
    }

    for ( i = 0; i < size; i++) { // O(N)
        if( frequency[i] == biggest ) {
            ans[*returnSize] = array[i];
            *returnSize += 1;
        }
    }
    return ans;
}

int SumSubtree( struct TreeNode* root , int * array , int * frequency , int * size ) { // O(N)
    if( root == NULL ) {
        return 0;
    }
    int left = SumSubtree( root->left , array , frequency , size );
    int right = SumSubtree( root->right , array , frequency , size );
    int sum = left + right + root->val;
    int i = 0;
    for ( i = 0 ; i < *size ; i++ ) { // O(1) - O(N)
        if( array[i] == sum ) {
            frequency[i] += 1;
            break;
        }  
    }
    if( i == *size ) {
        array[*size] = sum;
        frequency[*size] = 1;
        *size += 1;
    }
    return sum;
}