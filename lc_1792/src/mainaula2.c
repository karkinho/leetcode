#include "lib.h"

typedef struct Node Node;

struct Node{  
    int array[2] ;
    double average;
    double sum1Average;
    double dif;
    Node * next;
};

void Rebalance( Node ** head );

void Push( Node ** head , int * class ) {
    Node *new = ( Node * )malloc( sizeof( Node ) ) , ** aux = NULL;
    new->array[0] = class[0];
    new->array[1] = class[1];
    new->average =( double )( new->array[0] ) / ( double ) ( new->array[1] ) ;
    new->sum1Average =( double )( new->array[0] + 1 ) / ( double ) ( new->array[1] + 1 ) ;
    new->dif = new->sum1Average - new->average;
    new->next = NULL;
    if( *head == NULL ) {
        *head = new;
        return;
    }
    aux = head;
    while ( ( *aux ) != NULL ) {
        if( ( *aux )->next == NULL ) {
            ( *aux )->next = new;
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

void AddStudents( Node ** head , int students ) {
    Node *aux = *head;
    while ( students != 0) {
        aux = *head;
        aux->array[0] += 1;
        aux->array[1] += 1;
        students -= 1;
        aux->average = ( double )( aux->array[0] ) / ( double ) ( aux->array[1] );
        aux->sum1Average = ( double )( aux->array[0] + 1 ) / ( double ) ( aux->array[1] + 1 );
        aux->dif = aux->sum1Average - aux->average;
        Rebalance( head );
    }
    Rebalance( head );

}
void Rebalance( Node ** head ){
    Node * aux = *head , *new = NULL;
    int * class = ( int * )malloc( sizeof( int ) * 2 );
    while ( aux != NULL ) {
        class[0] = aux->array[0];
        class[1] = aux->array[1];
        Push( &new , class );
        aux = aux->next;
    }
    *head = new;

    
     
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    Node *head = NULL , *aux = NULL ;
    double ans = 0.0;
    for ( int i = 0; i < classesSize ; i++) {
        Push( &head , &classes[i][0] );
    }

    
    for ( aux = head ; aux != NULL; aux = aux->next ) {
        printf( "%d\n", aux->array[0] );
        printf( "%d\n", aux->array[1] );
        printf( "%lf\n", aux->dif );
    }

    AddStudents( &head , extraStudents );
    printf( "asdddddddddddddddddddddddddddddd\n" );
    for ( aux = head; aux != NULL; aux = aux->next ) {
        printf( "%d\n", aux->array[0] );
        printf( "%d\n", aux->array[1] );
        printf( "%lf\n", aux->dif );
    }
    
    for ( aux =head ; aux != NULL; aux = aux->next ) {
        ans += aux->average;
    }

    return ans / ( double )( classesSize );
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




