#include <stdlib.h>
#include <math.h>
#include <stdio.h>


struct ListNode {
     int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void insert( struct ListNode* l , int times );
void print( struct ListNode* l );

int main(int argc, char const *argv[])
{
    struct ListNode *l1 = ( struct ListNode* )malloc( sizeof( struct ListNode* ));
    struct ListNode *l2 = ( struct ListNode* )malloc( sizeof( struct ListNode* ));
    insert( l1 , 20 );
    insert( l2 , 20 );
    print( addTwoNumbers( l1, l2 ) );
    return 0;
}

void insert( struct ListNode* l , int times ){
    for (int i = 0; i < times; i++)
    {
        l->val = 9;
        l->next = ( struct ListNode* )malloc( sizeof( struct ListNode* ));
        l = l->next;
    }
    l->val = 9;
    l->next = NULL;
    return;
}

void print( struct ListNode* l ){
    for ( int i = 0  ; l->next != NULL ; l = l->next)
    {
        printf( "%d", l->val );
    }
    printf( "%d\n", l->val );
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0, pass = 0, f1 = 0 , f2 = 0;
    struct ListNode* ansReturn = ( struct ListNode* )malloc( sizeof( struct ListNode ) );
    struct ListNode* ans;
    ans = ansReturn;
    while ( 1 ) {
        sum = l1->val + l2->val + pass;
        pass = 0;
        if ( sum >= 10) {
            pass = floor( sum / 10 );
            sum = sum - floor( sum / 10 ) * 10;
        } 
        
        ans->val = sum;

        if ( l1->next != NULL ){
            l1 = l1->next;    
        } else {
            f1 = 1;
            l1->val = 0;
        }
         
        if ( l2->next != NULL ){
            l2 = l2->next;    
        } else { 
            f2 = 1;
            l2->val = 0;
        }

        if ( f1 && f2 && ( pass == 0 ) ) {
            ans->next = NULL;
            break;
        }

        ans->next = ( struct ListNode* )malloc( sizeof( struct ListNode ) );
        ans = ans->next;
    }
    return ansReturn;
}