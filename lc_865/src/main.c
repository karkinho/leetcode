#include "lib.h"

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root);
struct TreeNode* Find( struct TreeNode * root , struct TreeNode * deep , int * heightMax );

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int main( ) {
    return 0;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    struct TreeNode * deep;
    int heightMax = 0;
}