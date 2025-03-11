#include "lib.h"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int sumNumbers(struct TreeNode* root);

void Sum( struct TreeNode * root , int * array , int * sum , int size );

int main( ) {
    return 0;
}


int sumNumbers(struct TreeNode* root) {
    int * array = ( int * )malloc( sizeof( int ) * 10 ), sum = 0;
    if( root == NULL ) {
        return 0;
    }
    Sum( root , array , &sum , -1 );
    return sum;
}

void Sum( struct TreeNode * root , int * array , int * sum , int size ) {
    int localSum = 0;
    size += 1;
    array[ size ] = root->val;
    if( root->left == NULL && root->right == NULL ) {
        for ( int i = 0; i <= size ; i++ ) {
            localSum += array[i] * pow( 10 , ( size - i ) ) ;
        }
        printf( "%d\n", localSum );
        *sum += localSum;
    }

    if( root->left != NULL ) {
        Sum( root->left , array , sum , size );
    }
    if( root->right != NULL ) {
        Sum( root->right , array , sum , size );
    }
}