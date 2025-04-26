#include "lib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists( struct ListNode* list1 , struct ListNode* list2 );
struct ListNode* CreateList( int * array , int size);
void IsAlloced( struct ListNode * ptr );
void PrintList( struct ListNode * list );
void CleanList( struct ListNode * list );

int main( ) {
    int array1[5] = { 1, 2, 3 , 4 , 5 };
    int array2[5] = { 0 , 4 , 5 , 6 , 7 };
    struct ListNode * list1 = CreateList( array1 , 5 );
    struct ListNode * list2 = CreateList( array2 , 5 );
    PrintList( list1 );
    PrintList( list2 );
    struct ListNode * ans = mergeTwoLists( list1 , list2 );
    PrintList( ans );
    CleanList( ans );
    list1 = NULL;
    list2 = NULL;
    ans = NULL;
    return 0;
}

void CleanList( struct ListNode * list ) {
    struct ListNode * aux = NULL;
    for ( ; list != NULL ; ) {
        aux = list;
        list = list->next;
        free( aux );
    }
}

void PrintList( struct ListNode * list ) {
    for ( ; list != NULL ; list = list->next ) {
        printf( "%d, " , list->val );
    }
    printf( "\n" );
}

void IsAlloced( struct ListNode * ptr ) {
    if ( ptr == NULL ) {
        printf( "Ponteiro Não Alocado\n" );
    }
}

struct ListNode * CreateList( int * array , int size ) {
    struct ListNode * list = ( struct ListNode * )malloc( sizeof( struct ListNode ) );
    IsAlloced( list );
    struct ListNode * aux = list;
    aux->val = array[0];
    for ( int i = 1 ; i < size ; i++ ) {
        aux->next = ( struct ListNode * )malloc( sizeof( struct ListNode ) );
        IsAlloced( aux->next );
        aux = aux->next;
        aux->val = array[i] ;
    }
    aux->next = NULL;
    return list;
}

struct ListNode* mergeTwoLists( struct ListNode* list1 , struct ListNode* list2 ) {
    struct ListNode * ans = NULL , * aux = NULL;
    if( list1 != NULL && list2 != NULL ) {
        if ( list1->val < list2->val ){
            ans = list1;
            list1 = list1->next;
        } else {
            ans = list2;
            list2 = list2->next;
        }
    } else {
        if( list1 != NULL ) {
            return list1;
        } else {
            return list2;
        }
    }
    aux = ans;

    while ( list1 != NULL && list2 != NULL ) {
        if( list1->val < list2->val ) {
            aux->next = list1;
            list1 = list1->next;
        } else {
            aux->next = list2;
            list2 = list2->next;
        }
        aux = aux->next;
        aux->next = NULL;
    }
    if( list1 != NULL ) {
        aux->next = list1;
    }
    if( list2 != NULL ) {
        aux->next = list2;
    }
    return ans;
}

