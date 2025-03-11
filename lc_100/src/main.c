#include "lib.h"

int main( ) {
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void check( struct TreeNode* p, struct TreeNode* q , bool * ans) {
    if( p->val == q->val ) {
        if( p->left != NULL && q->left != NULL  ) {
            check( p->left , q->left , ans );
        }
        if( p->right != NULL && q->right != NULL  ) {
            check( p->right , q->right , ans );
        }
        if( p->right != NULL && q->right == NULL || p->right == NULL && q->right != NULL  ) {
            *ans = false;
            return;
        }
        if( p->left != NULL && q->left == NULL || p->left == NULL && q->left != NULL  ) {
            *ans = false;
            return;
        }
    } else {
        *ans = false;
        return;
    }
    return;
}

