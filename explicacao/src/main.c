#include "lib.h"

struct lista {
    int val;
    struct lista * next ;
};

struct tree {
    int val;
    struct tree * left;
    struct tree * right;
};

//Parametros
void ParametrosVariaiveisSimples();
void VariaveisSimples( int passagensdevalor , int * ponteirosParaVarriaveis );
void ParametrosVetores();
void Vetores( int * vetor , int tamanhoDovetor , char * strings );
void ParametrosMatrix();
void Matrix( int ** matrix , int linhaTamanho , int * colunaTamanho );
void ParametrosLista();
struct lista * CreateLista( int * vetor , int tamanhoDovetor );
void Lista( struct lista * lista );
void ParametrosArvores();
struct tree * CreateTree( int * vetor , int tamanhoDovetor , int indexParente );
void Arvore( struct tree * tree );
void PrintTree( struct tree * tree , int height );
// Retorno
void RetornoVetor();
int * Vetor( int * tamanho );
void RetornoMatrix();
int ** MatrixRetorno( int * linhas , int ** colunas );


int main( ) {
    srand( time( NULL ) );
    ParametrosVariaiveisSimples();
    ParametrosVetores();
    ParametrosMatrix();
    ParametrosLista();
    ParametrosArvores();

    RetornoVetor();
    RetornoMatrix();
    return 0;
}

// Parametros

void ParametrosVariaiveisSimples() {
    int * ponteiro = ( int * )malloc( sizeof( int ) ); // geralmente passados sem valor, vai vir a ser um dos metodos de retorno, geralmente o caller da free e aloca, ver na descrição do exercicio.
    VariaveisSimples( 12 , ponteiro ); // parametros aonde são somente valores podemos passar direto no escopo da função, em uma situação de codigo de testes rapidos isso é razoavel mas em codigos mais serios e testes de produção isso não é uma boa pratica.
}

void VariaveisSimples( int passagensDeValor , int * ponteirosParavariaveis ) {
    printf( "Variaveis Simples: %d , %p\n", passagensDeValor , ponteirosParavariaveis );
}

void ParametrosVetores() {
    char * string = "Minha String"; // jeito facil de definir uma string que não vai ser alterada.
    int vetor[] = { 0 , 1 , 2 , 3 , 4 , 5  , 6 , 7 , 8 , 9 };
    Vetores( vetor , 10 , string ); // tamanho do vetor sendo passado para sabermos o tamanho dele, em c não existem funções como o lenght do python que nos dão o tamanho de arrays, assim é nescessario sempre ter o tamanho para não haver seg fault.
}

void Vetores( int * vetor , int tamanhoDovetor , char * strings  ) {
    printf( "Vetores: %s | " , strings );
    for ( int i = 0 ; i < tamanhoDovetor ; i++ ) {
        printf( "%d ," , vetor[i] );
    }
    printf( "\n" );
}

void ParametrosMatrix() {
    // https://www.geeksforgeeks.org/pass-2d-array-parameter-c/
    // link acima para melhor aprofundamento de ponteiros no contexto de matrizes, neste exemplo trato mais de como as matrizes são tratadas no leetcode, não busco explicar como funciona a fundo a relação dos ponteiros. 
    //int matrix[][] = { { 1 , 2 , 3 } , { 1 , 2 }  };
    int linha1[] = { 1 , 2 , 3 };
    int linha2[] = { 1 , 2 };
    int  ** matrix = ( int ** )malloc( sizeof( int * ) * 2 );
    matrix[0] = linha1;
    matrix[1] = linha2;
    int colunaTamanho[] = { 3 , 2 };
    Matrix( matrix , 2 , colunaTamanho ); // tamanho das linhas qua vai definir o tamanho das linhas da matriz mas tambem o tamanho do vetor do tamanho das colunas da matriz.

}

void Matrix( int ** matrix , int linhaTamanho , int * colunaTamanho ) {
    printf( "Matrix: " );
    for ( int i = 0 ; i < linhaTamanho ; i++ ) {
        printf ( "{ " );
        for ( int x = 0 ; x < colunaTamanho[i] ; x++ ) {
            printf( "%d ,", matrix[i][x] );
        }
        printf ( " }" );
    }
    printf( "\n" );
}

void ParametrosLista() {
    // pode usar para fazer heap e stack
    int vetor[] = { 1 , 2 , 3 , 4 , 5 , 6};
    struct lista * lista = CreateLista( vetor , 6 );
    Lista( lista );
}

struct lista * CreateLista( int * vetor , int tamanhoDovetor ) {
    struct lista * lista = ( struct lista * )malloc( sizeof( struct lista ) );
    lista->next = NULL;
    struct lista * aux = lista;
    for ( int i = 0 ; i < tamanhoDovetor ; i++ ) {
        aux->next = ( struct lista * )malloc( sizeof( struct lista ) );
        aux = aux->next;
        aux->val = vetor[i];
    }
    return lista->next;
}

void Lista( struct lista * lista ) {
    printf( "Lista: " );
    for ( ; lista != NULL ; lista = lista->next ) {
        printf( "%d ,", lista->val );
    }
    printf( "\n" );
}

void ParametrosArvores() {
    // https://www.geeksforgeeks.org/array-representation-of-binary-heap/
    int vetor[] = {1,2,2,3,3,INT_MIN,INT_MIN,4,4};
    struct tree * tree = CreateTree( vetor , 9 , 0 );
    Arvore( tree );
}

struct tree * CreateTree( int * vetor , int tamanhoDovetor , int indexParente ) {
    struct tree * node = NULL;
    if( indexParente < tamanhoDovetor && vetor[indexParente] != INT_MIN ) {
        node = ( struct tree * )malloc( sizeof( struct tree ) );
        node->val = vetor[indexParente];
        node->left = CreateTree( vetor , tamanhoDovetor , ( 2 * indexParente ) + 1 );
        node->right = CreateTree( vetor , tamanhoDovetor , ( 2 * indexParente ) + 2 );
    }
    return node;
}

void Arvore( struct tree * tree ) {
    printf( "Arvores: \n" );
    PrintTree( tree , 0 );
    printf( "\n" );
}

void PrintTree( struct tree * tree , int height ) {
    if( tree == NULL ) return;
    for ( int i = 0; i < height ; i++) {
        printf( "|" );
    }
    printf( " %d \n", tree->val );
    PrintTree( tree->left , height + 1 );
    PrintTree( tree->right , height + 1 );
}

// Retornos

void RetornoVetor() {
    int * tamanho = ( int * )malloc( sizeof( int ) ); // geralmente são alocados pelo caller, mas ver no desrição do preblema se está especificado;
    int * array = Vetor( tamanho );
    for ( int i = 0 ; i < *tamanho ; i++ ) {
        
    }
    printf( "Vetor Recebido: " );   
    for ( int i = 0 ; i < *tamanho ; i++ ) {
        printf( "%d ," , array[i] );
    }
    printf( "Tamanho Vetor: %d\n", *tamanho );
} 

int * Vetor( int * tamanho ) {
    *tamanho = rand() % 9 + 1;
    int * array = ( int * )malloc( sizeof( int ) * *tamanho );
    for ( int i = 0 ; i < *tamanho ; i++ ) {
        array[i] = i;
    }
    return array;
}

void RetornoMatrix( ) {
    int * linhas = ( int * )malloc( sizeof( int ) );
    int ** colunas = ( int ** )malloc( sizeof( int * ) );
    int ** matrix = MatrixRetorno( linhas , colunas );
    printf( "Retorno Matrix: " );
    for ( int i = 0 ; i < *linhas ; i++ ) {
        printf ( "{ " );
        for ( int x = 0 ; x < colunas[0][i] ; x++ ) {
            printf( "%d ,", matrix[i][x] );
        }
        printf ( " }" );
    }
    printf( "\n" );
}

int ** MatrixRetorno( int * linhas , int ** colunas ) {
    // linhas geralmente são chamadas de returnsize e colunas de returncolumnsize
    *linhas = 5;
    int ** matrix = ( int ** )malloc( sizeof( int * ) * *linhas ); // alocar uma matrix dinaminacamnete um otimo exercicio
    *colunas = ( int * )malloc( sizeof( int ) * *linhas );


    colunas[0][0] = 1;
    matrix[0] = ( int *)malloc( sizeof( int ) * colunas[0][0] );
    matrix[0][0] = 1;


    colunas[0][1] = 1;
    matrix[1] = ( int *)malloc( sizeof( int ) * colunas[0][1] );
    matrix[1][0] = 1;

    colunas[0][2] = 1;
    matrix[2] = ( int *)malloc( sizeof( int ) * colunas[0][2] );
    matrix[2][0] = 1;
    colunas[0][3] = 2;
    matrix[3] = ( int *)malloc( sizeof( int ) * colunas[0][3] );
    matrix[3][0] = 1;
    matrix[3][1] = 2;


    
    colunas[0][4] = 2;
    matrix[4] =  ( int *)malloc( sizeof( int ) * colunas[0][4] );
    matrix[4][0] = 1;
    matrix[4][1] = 2;
    return matrix;
}