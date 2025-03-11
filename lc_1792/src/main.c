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
    int array[2];
    double dif;
};

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents);
void Push( int * class , Node * heap , int * size );
void Heapfy( Node * heap , int size , int pos );
void AddStudents( int extraStudents , Node * heap , int * size );

void Heapfy( Node * heap , int size , int pos ) {
    int left = 2 * pos + 1 , right = 2 * pos + 2 , large = pos;
    Node temp;
    if( left < size && heap[left].dif >= heap[pos].dif ) {
        large = left;
    }

    if( right < size && heap[right].dif >= heap[pos].dif && heap[right].dif >= heap[left].dif ) {
        large = right;
    }
    if( large != pos ) {
        temp = heap[ large ];
        heap[ large ] = heap[ pos ];
        heap[ pos ] = temp;
        Heapfy( heap , size , large );
    }
}  

void Push( int * class , Node * heap , int * size ) {
    Node new;
    new.array[0] = class[0];
    new.array[1] = class[1]; 
    new.dif = ( double )( ( double)( new.array[0] + 1 ) / ( double)( new.array[1] + 1 ) - ( double)( new.array[0] ) / ( double)( new.array[1] ) );

    *size += 1;
    heap[ *size - 1 ] = new;   
}

void AddStudents( int students , Node * heap , int * size ) {
    int class[2];
    while ( students > 0 ) {
        heap[0].array[0] += 1;
        heap[0].array[1] += 1;
        students -= 1;
        heap[0].dif = ( double )( ( double)( heap[0].array[0] + 1 ) / ( double)( heap[0].array[1] + 1 ) - ( double)( heap[0].array[0] ) / ( double)( heap[0].array[1] ) );
        class[0] = heap[0].array[0];
        class[1] = heap[0].array[1];
        heap[0] = heap[ *size - 1 ];
        *size -=1;
        Push( class , heap , size );
        for ( int i = ( *size - 2 ) / 2 ; i > 0 ; i = ( i - 1 ) / 2 )  {
            Heapfy( heap , *size , i );
        }
        Heapfy( heap , *size , 0 );
    }
    
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    Node * heap = ( Node * )malloc( sizeof( Node ) * ( 5 + classesSize ) );
    int size = 0;
    double ans = 0.0;
    for ( int index = 0 ; index < classesSize ; index++ ) {
        Push( &classes[index][0] , heap , &size );
    }
    for ( int i = size / 2 - 1 ; i >= 0 ; i-- ) {
        Heapfy( heap , size , i );
    }

    AddStudents( extraStudents , heap , &size );

    for ( int index = 0 ; index < classesSize ; index++ ) {
        ans += ( double)( heap[index].array[0] ) / ( double)( heap[index].array[1] );
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