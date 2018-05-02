#ifndef AST_HEADER
#define AST_HEADER


#include "hash.h"


//Número máximo de folhas
#define MAX_SONS 4


//Constantes para cada coisa que vai ser colocada na AST.
//Identificador SYMBOL recebe 1 nesse caso.
#define AST_SYMBOL 1


typedef struct ast_node{
    int type;
    HASH *symbol;
    struct ast_node *son[MAX_SONS];
} AST;

AST* astCreate(int type, HASH*symbol , AST *son0 , AST *son1 , AST *son2, AST *son3);

void astPrint(AST *node, int level);


#endif
