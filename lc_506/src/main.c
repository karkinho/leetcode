#include "lib.h"

char** findRelativeRanks(int* score, int scoreSize, int* returnSize);
void test1();
void test2();
void test3();

int main( ) {
    test1();
    test2();
    test3();
    return 0;
}

void test1() {
    int input[5] = {5,4,3,2,1} , * returnSize = ( int * )malloc( sizeof( int ) );
    char ** ans = findRelativeRanks( input , 5 , returnSize);
    printArrayChar( ans , * returnSize  );
    free( returnSize );
    // ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
}

void test2() {
    int input[5] = {10,3,8,9,4} , * returnSize = ( int * )malloc( sizeof( int ) );
    char ** ans = findRelativeRanks( input , 5 , returnSize);
    printArrayChar( ans , * returnSize  );
    free( returnSize );
    // ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
}

void test3() {
    int input[5] = { 1, 2, 3, 4 , 5} , * returnSize = ( int * )malloc( sizeof( int ) );
    char ** ans = findRelativeRanks( input , 5 , returnSize);
    printArrayChar( ans , * returnSize  );
    free( returnSize );
    // [ "5", "4","Bronze Medal", "Silver Medal" , "Gold Medal"]
}

// solution

typedef struct node {
    int index;
    struct node * next;
} node;

typedef struct {
    node * first;
    node * last;
} sentinel;

sentinel sHeap;

bool empty() {
    if ( sHeap.first == NULL || sHeap.last == NULL ) {
        return true;
    }
    return false;
}

void push( int index , int *score ) {
    node * newNode = ( node * )malloc( sizeof( node ) );
    newNode->index = index;
    newNode->next = NULL;
    if ( !empty() ) {
        if( score[ sHeap.last->index ] < score[ index ] ){
            if ( score[ sHeap.first->index ] < score[ index ] ) {
                newNode->next = sHeap.first;
                sHeap.first = newNode;
            } else {
                node ** aux = &sHeap.first;
                for ( ; score[ index ] < score[ ( *aux )->index ] ; aux = &( *aux )->next );
                newNode->next = *aux;
                *aux = newNode;
            }
        } else {
            sHeap.last->next = newNode;
            sHeap.last = sHeap.last->next;
        }
    } else {
        sHeap.first = newNode;
        sHeap.last = newNode;
    }
}

char** findRelativeRanks( int* score , int scoreSize , int* returnSize ) {
    char ** ans = ( char ** )malloc( sizeof( char * ) * scoreSize );
    node * aux = NULL;
    sHeap.first = NULL; 
    sHeap.last = NULL;
    *returnSize = scoreSize;
    for ( int index = 0 ; index < scoreSize ; index++ ) {
        push( index , score );
        *( char **)( ans + index ) = ( char * )malloc( sizeof( char ) * 20 );
    }
    aux = sHeap.first;
    for ( int i = 0 ; i < scoreSize ; i++ , aux = aux->next ) {
        switch ( i ) {  
            case 0:
                *( char **)( ans + aux->index ) = "Gold Medal";
                break;
            case 1:
                *( char **)( ans + aux->index ) = "Silver Medal";
                break;
            case 2:
                *( char **)( ans + aux->index ) = "Bronze Medal";
                break;
            default:
                sprintf( *( char **)( ans + aux->index ) , "%d" , ( i + 1 ) );
                break;
        }
    }
    return ans;
}


