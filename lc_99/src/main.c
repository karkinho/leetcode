#include "lib.h"



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void recoverTree( struct TreeNode* root );
struct TreeNode * LeftHigh( struct TreeNode * root );
struct TreeNode * RightLow( struct TreeNode * root );
void Swap( struct TreeNode * node , int val , int swap );
void Check( struct TreeNode * root );


int main( ) {
    return 0;
}

void recoverTree(struct TreeNode* root) {
    Check( root );
}

void Check( struct TreeNode * root ) {
    struct TreeNode * left = LeftHigh( root->left ) , * right = RightLow( root->right );
    int temp = 0;

    if( left == NULL && right == NULL ) {
        return;
    }

    if( left != NULL && right != NULL ) {
        if( left->val > root->val && right->val < root->val ) {
            temp = left->val;
            left->val = right->val;
            right->val = temp;
            return;
        } 
        if( left->val > root->val  ) {
            temp = root->val;
            root->val = left->val;
            left->val = temp;
            return;
        }

        if( right->val < root->val  ) {
            temp = root->val;
            root->val = right->val;
            right->val = temp;
            return;
        }
    }

    if( left != NULL ) {
        if( left->val > root->val  ) {
            temp = root->val;
            root->val = left->val;
            left->val = temp;
            return;
        }
    }

    if( right != NULL ) {
        if( right->val < root->val  ) {
            temp = root->val;
            root->val = right->val;
            right->val = temp;
            return;
        }
    }

    if( root->left != NULL ) {
        Check( root->left );
    }

    if( root->right != NULL ) {
        Check( root->right );
    }
}

struct TreeNode * RightLow( struct TreeNode * root ) {
    if( root == NULL ) {
        return NULL;
    }
    struct TreeNode * left = RightLow( root->left ) , * right = RightLow( root->right );

    if( left == NULL && right == NULL ) {
        return root;
    }

    if( left == NULL ) {
        if( right->val < root->val ) {
            return right;
        } else {
            return root;
        }
    }

    if( right == NULL ) {
        if( left->val < root->val ) {
            return left;
        } else {
            return root;
        }
    }

    if( root->val > left->val ) {
        if( left->val < right->val ) {
            return left;
        } else {
            return right;
        }
    } else {
        if( root->val < right->val ) {
            return root;
        } else {
            return right;
        }
    }        
}

struct TreeNode * LeftHigh( struct TreeNode * root ) {
    if( root == NULL ) {
        return NULL;
    }
    struct TreeNode * left = LeftHigh( root->left ) , * right = LeftHigh( root->right );

    if( left == NULL && right == NULL ) {
        return root;
    }

    if( left == NULL ) {
        if( right->val > root->val ) {
            return right;
        } else {
            return root;
        }
    }

    if( right == NULL ) {
        if( left->val > root->val ) {
            return left;
        } else {
            return root;
        }
    }

    if( root->val < left->val ) {
        if( left->val > right->val ) {
            return left;
        } else {
            return right;
        }
    } else {
        if( root->val > right->val ) {
            return root;
        } else {
            return right;
        }
    }        
}

