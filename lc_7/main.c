#include <stdio.h>
#include <string.h>
#include <limits.h>

int reverse( int x );

int main( int argc , char const *argv[] ){
    int x = -123;
    printf( "%d\n", reverse( x ) );
    return 0;
}

int reverse( int x ) {
    int ans = 0 , numb = 0 , intMax = INT_MAX / 10 , intMin = INT_MIN / 10;
    while ( x != 0 ) {
        numb = x % 10;
        x /= 10;
        if ( x < 10 && x > -10 ) {
            if ( ans > intMax || ( ans == intMax && numb > 7 ) ){
                return 0;
            }
            if ( ans < intMin || ( ans == intMin && numb < -8 ) ){
                return 0;
            }
         }
        ans = ans * 10 + numb; 
    }
    return ans;
}

int reverseFirstAdaptada( int x ) {
    char buff[12] , buff2[12];
    int index = 0, size , ans;
    sprintf( buff , "%d" , x );
    size = strlen( buff );
    for ( int aux = size - 1 ; aux >= 0 ; index++ , aux-- ){
        buff2[index] = buff[aux]; 
    }
    buff2[index] = '\0';
    if ( size >= 9) {
        strcpy( buff , buff2 );
        if ( x < 0 ) {
            buff[index - 2] = '\0';
            sscanf( buff , "%d" , &ans );
            if ( ans > INT_MAX / 10  || ( ans ==  INT_MAX / 10 && buff2[index - 1] > '8' ) ){
                return 0;
            }
        } else {
            buff[index - 1] = '\0';
            sscanf( buff , "%d" , &ans );
            if ( ans > INT_MAX / 10 || ( ans == INT_MAX / 10 && buff2[index] > '7' ) ){
                return 0;
            }
        }
    }
    sscanf( buff2 , "%d" , &ans );
    if ( x < 0 ){
        ans = ans * -1;
    }
    return ans;
}
int reverseNicesolution( int x ) {
    int ans = 0 , numb = 0;
    while ( x != 0 ) {
        numb = x % 10;
        x /= 10;
        if ( ans > INT_MAX / 10 || ( ans == INT_MAX / 10 && numb > 7 ) ){
            return 0;
        }
        if ( ans < INT_MIN / 10 || ( ans == INT_MIN / 10 && numb < -8 ) ){
            return 0;
        }
        ans = ans * 10 + numb; 
    }
    return ans;
}

int reverseFirst( int x ){
    char buff[12] , buff2[12];
    int index = 0, size;
    if ( x == INT_MIN ) {
        return 0;
    }
    sprintf( buff , "%d" , x );
    size = strlen( buff );
    for ( int aux = size - 1 ; aux >= 0 ; index++ , aux-- ){
        buff2[index] = buff[aux]; 
    }
    buff2[index] = '\0';
    sscanf( buff2 , "%d" , &index );
    if ( x < 0 ){
        buff[size - 1] = '\0';
        size--;
        index = index * -1;
    }
    if ( strcmp ( "2147483647" , buff2 ) < 0 && size == 10){
        return 0;
    }
    return index;  
}
