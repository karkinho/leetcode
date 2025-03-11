#include "lib.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode* sortedListToBST(struct ListNode* head);
void CreateTree( struct ListNode * list , struct TreeNode ** root );

int main() {
    return 0;
}

void CreateTree( struct ListNode * list , struct TreeNode ** root ) {
    if( list == NULL ) {
        return;
    }
    int size = 0 , half = 0;
    struct ListNode * aux = list;
    for ( ; aux != NULL ; aux = aux->next , size++ );
    half = size / 2;
    aux = list;
    for ( int i = 0; i < half; i++ , aux = aux->next );
    *root = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) );
    ( *root )->val = aux->val;
    ( *root )->left = NULL;
    ( *root )->right = NULL;

    // right tree
    CreateTree( aux->next , ( struct TreeNode ** )&( *root )->right );
    // left tree
    if( half > 1 ) {
        aux = list;
        for ( int i = 0; i < half - 1 ; i++ , aux = aux->next );
        aux->next = NULL;
        CreateTree( list , ( struct TreeNode ** )&( *root )->left );
    }
}   


struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct TreeNode * root = NULL;
    if( head == NULL ) {
        return root;
    }
    CreateTree( head , ( struct TreeNode ** )&root );
    return root;
}