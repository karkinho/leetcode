#include "lib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* sortList( struct ListNode* head );
struct ListNode* Merge_Sort( struct ListNode* head , int size );
struct ListNode* Merge( struct ListNode* l1 , struct ListNode* l2 );

int main( ) {
    return 0;
}

struct ListNode* sortList( struct ListNode* head ) {
    if( head == NULL ) return NULL;
    int size = 0;
    struct ListNode * temp;
    for ( size = 0 , temp = head ; temp != NULL ; temp = temp->next , size++ );
    return Merge_Sort( head , size );
}

struct ListNode* Merge_Sort( struct ListNode* head , int size ) {
    int half = 0;
    struct ListNode * aux1 , * aux2 , *temp , *l1 , *l2 , *ans;
    if( size == 1 ) {
        return head;
    }

    half = size / 2;
    aux1 = head;
    aux2 = head;
    for ( int i = 1 ; i < half; i++ , aux2 = aux2->next );
    temp = aux2->next;
    aux2->next = NULL;
    aux2 = temp;

    l1 = Merge_Sort( aux1 , half );
    l2 = Merge_Sort( aux2 , size - half );
    
    return Merge( l1 , l2 );
}

struct ListNode* Merge( struct ListNode* l1 , struct ListNode* l2 ) {
    struct ListNode * ans = NULL , * temp = NULL;
    if( l1->val < l2->val ) {
        temp = l1;
        ans = temp;
        l1 = l1->next;
        temp->next = NULL;
    } else {
        temp = l2;
        ans = temp;
        l2 = l2->next;
        temp->next = NULL;
    }
    while( l1 != NULL && l2 != NULL ) {
        if( l1->val < l2->val ) {
            temp->next = l1; 
            l1 = l1->next;
            temp = temp->next;
            temp->next = NULL;
        } else {
            temp->next = l2; 
            l2 = l2->next;
            temp = temp->next;
            temp->next = NULL;
        }
    }

    if( l1 == NULL && l2 == NULL ) {
        return ans;
    }

    if( l1 == NULL ) {
        temp->next = l2;
        return ans;
    } else {
        temp->next = l1;
        return ans;
    }
}