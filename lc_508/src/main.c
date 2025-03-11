#include "lib.h"

int* findFrequentTreeSum( struct TreeNode* root, int* returnSize );
int SumSubtree( struct TreeNode* root , int * array , int * frequency , int * size , int * biggest);

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
    int * frequency = ( int * )malloc( sizeof( int ) * 10000 );
    *returnSize = 0; 
    int i = 0 , biggest = -1 , size = 0 ;
    int * ans = ( int * )malloc( sizeof( int ) * 10000 );

    SumSubtree( root , array , frequency , &size , &biggest );

    for ( i = 0; i < size; i++) {
        if( frequency[i] == biggest ) {
            ans[*returnSize] = array[i];
            *returnSize += 1;
        }
    }
    return ans;
}

int SumSubtree( struct TreeNode* root , int * array , int * frequency , int * size , int * biggest ) {  
    if( root == NULL ) {
        return 0;
    }
    int left = SumSubtree( root->left , array , frequency , size , biggest );
    int right = SumSubtree( root->right , array , frequency , size , biggest );
    int sum = left + right + root->val;
    int i = 0;
    for ( i = 0 ; i < *size ; i++ ) { 
        if( array[i] == sum ) {
            frequency[i] += 1;
            if( frequency[i] > *biggest ) {
                *biggest = frequency[i];
            }
            break;
        }  
    }
    if( i == *size ) {
        array[*size] = sum;
        frequency[*size] = 1;
        if( frequency[i] > *biggest ) {
            *biggest = frequency[i];
        }
        *size += 1;
    }
    return sum;
}