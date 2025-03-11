#include "lib.h"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten( struct TreeNode* root );
void InOrder( struct TreeNode * root , int * stack , int * top );

int main( ) {
    return 0;
}

void flatten( struct TreeNode* root ) {
    int * stack = ( int * )malloc( sizeof( int ) * 20000 ) , top = -1;
    struct TreeNode * aux;
    if( root == NULL ) {
        return;
    }
    InOrder( root , stack , &top );
    aux = root;
    for ( int i = 0 ; i <= top ; i++ ) {
        if( i != 0 ) {
            aux = aux->right;
        }
        aux->val = stack[i];
        aux->left = NULL;
        aux->right = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) );
    }
    aux->right = NULL;
    

}

void InOrder( struct TreeNode * root , int * stack , int * top ) {
    if( root == NULL ) return;
    *top += 1;
    stack[*top] = root->val;
    InOrder( root->left , stack , top );
    InOrder( root->right , stack , top);
}
