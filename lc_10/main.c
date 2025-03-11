#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool isMatch( char* s , char* p );

int main( int argc , char const *argv[] ) {
    // printf( "%d\n" , isMatch( "aa" , "a") );
    // printf( "%d\n" , isMatch( "aab" , "c*a*b") );
    // printf( "%d\n" , isMatch( "a" , "ab*" ) );
    // printf( "%d\n" , isMatch( "ab" , ".*.." ) );
    //printf( "%d\n" , isMatch( "mississippi" , "mis*is*ip*.") );
    //printf( "%d\n" , isMatch( "aab" , "c*a*b") );
    // printf( "%d\n" , isMatch( "aaa" , "aaaa") );
    printf( "%d\n" , isMatch( "aaa" , "a*a") );
    return 0;
}

bool isMatch( char* s , char* p ) {
    int pIndex = 0 , sIndex = 0 , starFlag = 0 , index = 0, pSize = strlen( p );
    char rule[ pSize + 1 ];
    
    while  ( p[pIndex] != '\0' ) {
        for ( index = pIndex ; ; index++ ) {
            if ( p[index] == '*') {
                starFlag = 1;
                continue;
            } else if ( p[index] != p[pIndex] ) {
                break;
            }
            if ( starFlag == 1 ) {
                rule[index - 1] = p[pIndex];
                continue;
            }
            rule[index] = p[pIndex];
            
        }
        if ( starFlag == 1 ) {
            rule[index - 1] = '*';
            starFlag = 0;
        }
        pIndex = index;
        if ( p[index] == '\0') {
            break;
        }
    }
    rule[pIndex] = '\0';
    pIndex = 0;
    while ( s[sIndex] != '\0' && rule[pIndex] != '\0' ) {
        if (p[pIndex + 1] == '*') {
            if ( s[sIndex] == rule[pIndex] || rule[pIndex] == '.') {
                sIndex++;
            } else {
                pIndex++;
                pIndex++;
            }
            continue;
        }
        if ( s[sIndex] == rule[pIndex] || rule[pIndex] == '.' ) {
            pIndex++;
            sIndex++;
            continue;
        }
        return 0;
    }
    if ( s[sIndex] != '\0' ){
        return 0;    
    }
    pIndex = pSize - 1;
    sIndex--;
    while ( sIndex >= 0 && pIndex >= 0 ) {
        if ( starFlag == 1 ) {
            if ( s[sIndex] == rule[pIndex] || rule[pIndex] == '.' ) {
                sIndex--;
                if ( pIndex > 0 || sIndex == -1 ){
                    pIndex--;
                }
                continue;
            }
            if ( s[sIndex] == rule[pIndex + 1] || rule[pIndex + 1] == '.' ) {
                sIndex--;
                continue;
            }
            starFlag == 0;
        }
        if ( rule[pIndex] == '*' ) {
            starFlag = 1;
            pIndex--;
            continue;
        }
        if ( s[sIndex] == rule[pIndex] || rule[pIndex] == '.' ) {        
            sIndex--;
            pIndex--;
            continue;
        }
        return 0;
    }
    if ( pIndex == 0 && rule[pIndex + 1] != '*') {
        return 0;
    }
    return 1;
}
// bool isMatch( char* s , char* p ) {
//     int pIndex = 0 , sIndex = 0 , count = 0 , tempIndex = 0 ;
//     while ( s[sIndex] != '\0' &&  p[pIndex] != '\0' ) {
//         if ( s[sIndex] == p[pIndex] ) {
//             sIndex++;
//             pIndex++;
//             continue;
//         }
//         if ( p[pIndex] == '.' ) {
//             sIndex++;
//             pIndex++;
//             continue;
//         }
//         if ( p[pIndex] == '*' ){
//             if ( p[pIndex - 1] == '.' ) {
//                 if ( p[pIndex + 1] == '\0' ) {
//                     return true;
//                 }                 
//                 sIndex++;
//                 continue; 
//             } else {
//                 if (  s[sIndex] == p[pIndex - 1]  ) {
//                     sIndex++;
//                     continue;
//                 } else {
//                     pIndex++;
//                     continue;
//                 }
//             }
//         }
//         if ( p[pIndex + 1] == '*' ) {
//             pIndex += 2;
//             continue;
//         }   
//         return false;
//     }

//     if ( s[sIndex] != '\0' ) {
//         return false;
//     }

//     while ( p[pIndex] != '\0') {
//         if ( p[pIndex] == '*' || p[pIndex + 1] == '*' ) {
//             pIndex++;
//             continue;
//         }
        
//         if ( p[pIndex + 1] == '\0' && p[pIndex] == s[sIndex - 1] ) {
//             while ( s[tempIndex] != '\0' ) {
//                 if ( s[tempIndex] == s[sIndex - 1] ) {
//                     count++;
//                 }
//                 tempIndex++;
//             }
//             tempIndex = 0;
//             while ( p[tempIndex] != '\0' ) {
//                 if ( p[tempIndex] == s[sIndex - 1] && p[tempIndex + 1] != '*' ) {
//                     count--;
//                 }
//                 tempIndex++;
//             }
//             if ( count < 0 ) {
//                 return false;
//             }
//             return true;   
//         }
//         if ( p[pIndex] == '.' ) {
//             tempIndex = 0;
//             while ( s[count] != '\0' ) {
//                 count++;
//             }
//             while ( p[tempIndex] != '\0' ) {
//                 if ( p[tempIndex] == '.' && p[tempIndex + 1] != '*' ) {
//                     count--;
//                 }
//                 tempIndex++;
//             }
//             if ( count < 0 ) {
//                 return false;
//             }
//             return true;   
//         }
//         return false;
//     }
    
//     return true;
// }