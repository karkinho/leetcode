#include <stdio.h>
#include <string.h>
#include <math.h>

#define symbols 7

char* intToRoman( int num );

int main( int argc , char const *argv[] ) {
    
    return 0;
}

char* intToRoman( int num ) {
    char symbolTable[symbols + 1] = "IVXLCDM";
    char valueTable[symbols] = { 1 , 5 , 10 , 50 , 100 , 500 , 1000 };
    char ans[27];
    int mod = 0 , fraction = 0;
    for ( int index = symbols - 1 , ansIndex = 0 ; index >= 0 ; index++ ) {
        mod = num % valueTable[index];
        
    }
    


}