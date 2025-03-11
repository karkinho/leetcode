#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

void Test1();
void Test2();

typedef struct Node Node;

struct Node{
    int array[2] ;
    double average;
    double dif;
    Node * next;
};

void Rebalance( Node ** head );
void Push( Node ** head , int * class , double * ans  );
//void PrintHeap( Node * head );
void AddStudents( Node ** head , int students , double * ans  );

void Push( Node ** head , int * class , double * ans ) {
    Node *new = ( Node * )malloc( sizeof( Node ) ) , ** aux = NULL;
    new->array[0] = class[0];
    new->array[1] = class[1];
    new->average =( double )( new->array[0] ) / ( double ) ( new->array[1] ) ;
    new->dif = ( double )( new->array[0] + 1 ) / ( double ) ( new->array[1] + 1 ) - new->average;
    new->next = NULL;
    *ans += new->average;
    if( *head == NULL ) {
        *head = new;
        return;
    }
    aux = head;
    while ( ( *aux ) != NULL ) {
        if( ( *aux )->next == NULL ) {
            if( ( *aux )->dif < new->dif ) {            
                new->next = ( *aux );
                *aux = new;
            } else {
                ( *aux )->next = new;
            }
            break;
        }
        if( ( *aux )->dif >= new->dif ){
            aux = &( *aux )->next;
            continue;
        }
        if( ( *aux )->dif < new->dif ){
            new->next = ( *aux );
            *aux = new;
            break;
        }
    }
}

void AddStudents( Node ** head , int students , double * ans ) {
    Node *aux = *head;
    while ( students != 0) {
        if ( aux->dif == 0.0 ) {
            return;
        }
        aux->array[0] += 1;
        aux->array[1] += 1;
        students -= 1;
        *ans += aux->dif;
        aux->average = ( double )( aux->array[0] ) / ( double ) ( aux->array[1] );
        aux->dif = ( double )( aux->array[0] + 1 ) / ( double ) ( aux->array[1] + 1 ) - aux->average;
        if( aux->next->dif > aux->dif ) {
            Rebalance( head );
            aux = *head;
        }
    }
}

void Rebalance( Node ** head ){
    int * class = ( int * )malloc( sizeof( int ) * 2 );
    double temp = 0;
    class[0] = ( *head )->array[0];
    class[1] = ( *head )->array[1];
    *head = ( *head )->next;
    Push( head , class , &temp );
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    Node *head = NULL , *aux = NULL ;
    double ans = 0.0;
    for ( int index = 0; index < classesSize ; index++) {
        Push( &head , &classes[index][0] , &ans );
    }

    AddStudents( &head , extraStudents , &ans );

    return ans / ( double )( classesSize );
}

void PrintHeap( Node * head ) {
    for ( Node * aux = head; aux != NULL; aux = aux->next ) {
        printf( "%d\n", aux->array[0] );
        printf( "%d\n", aux->array[1] );
        printf( "%lf\n", aux->dif );
     }
    printf( "----------------------\n" );
}

void Test1( ){
    /*Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
    Output: 0.78333
    Explanation: You can assign the two extra students to the first class. The average pass ratio will  be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.*/
    int ** classes = ( int ** )malloc( sizeof( int * ) * 3 );
    classes[0] = ( int * )malloc( sizeof( int ) * 2 );
    classes[1] = ( int * )malloc( sizeof( int ) * 2 );
    classes[2] = ( int * )malloc( sizeof( int ) * 2 );
    classes[0][0] = 1;
    classes[0][1] = 2;
    classes[1][0] = 3;
    classes[1][1] = 5;
    classes[2][0] = 2;
    classes[2][1] = 2;
    int classesSize = 3;
    int classesColSize[3] ={ 2 , 2 , 2 };
    int extraStudents = 2;

    printf( "%lf | 0.78333\n", maxAverageRatio( classes , classesSize,  classesColSize, extraStudents) );
}

void Test2(){
    /*Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
    Output: 0.53485*/
    int ** classes = ( int ** )malloc( sizeof( int * ) * 4 );
    classes[0] = ( int * )malloc( sizeof( int ) * 2 );
    classes[1] = ( int * )malloc( sizeof( int ) * 2 );
    classes[2] = ( int * )malloc( sizeof( int ) * 2 );
    classes[3] = ( int * )malloc( sizeof( int ) * 2 );
    classes[0][0] = 2;
    classes[0][1] = 4;
    classes[1][0] = 3;
    classes[1][1] = 9;
    classes[2][0] = 4;
    classes[2][1] = 5;
    classes[3][0] = 2;
    classes[3][1] = 10;
    int classesSize = 4;
    int classesColSize[4] ={ 2 , 2 , 2 ,2 };
    int extraStudents = 4;

    printf( "%lf | 0.53485\n", maxAverageRatio( classes, classesSize,  classesColSize, extraStudents) );
}


int main( ) {
    Test1();
    Test2();
    return 0;
}




