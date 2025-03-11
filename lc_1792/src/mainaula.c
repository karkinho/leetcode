#include "lib.h"

typedef struct Node Node;

struct Node{
    int array[2];
    double average;
    Node * next;
};

void Rebalance( Node ** head );   

void Push( Node ** head , int * class ) {
    Node *new = ( Node * )malloc( sizeof( Node ) ) , ** aux = NULL;
    new->array[0] = class[0];
    new->array[1] = class[1];
    new->average =( double )( new->array[0] ) / ( double ) ( new->array[1] );
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
        if( ( *aux )->average < new->average ){
            aux = &( *aux )->next;
            continue;
        }
        if( ( *aux )->average >= new->average ){
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
        aux->average =( double )( aux->array[0] ) / ( double ) ( aux->array[1] );
        Rebalance( head );
    }
    

}
void Rebalance( Node ** head ){
    Node ** aux = head , * next = *head;
    next = next->next;
    if( (*aux)->average < next->average ) {
        return;
    }
    while ( next != NULL  ) {
        if( (*aux)->average <= next->average ) {
            break;
        }
        if( (*aux)->average > next->average ) {
            ( *aux )->next = next->next;
            next->next = *aux;
            *aux = next;
            next = ( * aux )->next; 
        }
    }
     
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    Node *head = NULL;
    double ans = 0.0;
    for ( int i = 0; i < classesSize ; i++) {
        Push( &head , &classes[i][0] );
    }
    AddStudents( &head , extraStudents );
    
    for ( ; head != NULL; head = head->next ) {
        printf( "%d\n", head->array[0] );
        printf( "%d\n", head->array[1] );
        printf( "%lf\n", head->average );
        ans += head->average;
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

/*void Test2(){
    Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
    Output: 0.53485
    int classes[4][2] = { {2,4} , {3,9} , {4,5} , {2 ,10 } };
    int classesSize = 4;
    int classesColSize[4] ={ 2 , 2 , 2 ,2 };
    int extraStudents = 4;

    printf( "%lf | 0.53485\n", maxAverageRatio( classes, classesSize,  classesColSize, extraStudents) );
}
*/


int main( ) {
    Test1();
    //Test2();
    return 0;
}




