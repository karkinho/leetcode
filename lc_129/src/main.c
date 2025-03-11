#include "lib.h"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int sumNumbers(struct TreeNode* root);

void Sum( struct TreeNode * root , int localSum , int * sum );

int main( ) {
    return 0;
}


int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    if( root == NULL ) {
        return 0;
    }
    Sum( root , 0 , &sum );
    return sum;
}

void Sum( struct TreeNode * root , int localSum , int * sum ) {
    localSum += root->val;
    if( root->left == NULL && root->right == NULL ) {
        *sum += localSum;
        return;
    }
    localSum = localSum * 10;
    if( root->left != NULL ) {
        Sum( root->left , localSum , sum );
    }
    if( root->right != NULL ) {
        Sum( root->right , localSum , sum );
    }
}