#include "lib.h"

 
typedef struct MinStack MinStack;

struct MinStack{
    int num;
    int min;
    MinStack *next;
};


MinStack* minStackCreate() {
    MinStack *obj = ( MinStack * )malloc( sizeof( MinStack ) );
    obj->next = NULL;
    obj->min = INT_MAX;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    MinStack *new = ( MinStack * )malloc( sizeof( MinStack ) );
    if( val < obj->min ) {
        obj->min = val;
        new->min = val;
    } else {
        new->min = obj->min;
    }
    new->num = val;
    new->next = obj->next;
    obj->next = new;
    if( val < obj->num ) {
        obj->num = val;
    }
}

void minStackPop(MinStack* obj) {
    if( obj->next == NULL ){
        return;
    }
    MinStack *temp = NULL;
    temp = obj->next;
    if ( temp->next == NULL ) {
        free( obj->next );
        obj->next = NULL;
        obj->min = INT_MAX;
        return;
    } else{ 
        temp = temp->next;
        free( obj->next );    
    }
    obj->next = temp;
    obj->min = temp->min;
}

int minStackTop(MinStack* obj) {
    obj = obj->next;
    return obj->num;
}

/*int minStackGetMin(MinStack* obj) {
    MinStack *temp = minStackCreate();
    int min = 0 , val = 0;
    val = minStackTop( obj );
    min = val;
    while ( obj->next != NULL ) {
        val = minStackTop( obj );
        if( val < min ){
            min = val;
        }
        minStackPush( temp , minStackTop( obj ) );
        minStackPop( obj );
    }
    while ( temp->next != NULL ) {
        minStackPush( obj , minStackTop( temp ) );
        minStackPop( temp );
    }
    return min;
}*/
int minStackGetMin(MinStack* obj) {
    obj = obj->next;
    return obj->min;
}

void minStackFree(MinStack* obj) {
    while ( obj->next != NULL ) {
        minStackPop( obj );
    }
    minStackPop( obj );
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

void test1(){
/*Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
  
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top(); // return 0
minStack.getMin(); // return -2
*/
    MinStack *obj = minStackCreate();
    minStackPush( obj , -2 );   
    minStackPush( obj , 0 );
    minStackPush( obj , -3 );
    printf( "%d | -3\n", minStackGetMin( obj ) );
    minStackPop( obj );
    printf( "%d | 0\n", minStackTop( obj ) );
    minStackPop( obj );
    printf( "%d | -2\n", minStackGetMin( obj ) );
}

int main( ) {
    test1();
    
    return 0;
}