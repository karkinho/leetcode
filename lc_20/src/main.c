#include "lib.h"

bool isValid(char* s);

int main( int argc , char const *argv[] ) {
    printf( "%d\n" , isValid( "()" )); // true
    printf( "%d\n" , isValid( "()[]{}" )); // true
    printf( "%d\n" , isValid( "(]" )); // false
    printf( "%d\n" , isValid( "([])" )); // true
    return 0;
}

bool isValid(char* s) {
    int sSize = strlen( s ) , top = 0;
    int pile[sSize + 1];
    for ( int i = 0 ; i < sSize ; i++ ) {
        if ( s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
            top++;
            pile[top] = s[i]; 
            continue;
        }
        if ( pile[top] == '(' && s[i] == ')' ) {
            top--;
            continue;
        }
        if ( pile[top] == '[' && s[i] == ']' ) {
            top--;
            continue;
        }
        if ( pile[top] == '{' && s[i] == '}' ) {
            top--;
            continue;
        }
        return 0;
    }
    if ( top == 0 ) {
        return 1;
    } else {
        return 0;
    }
}