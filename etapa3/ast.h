#ifndef AST_HEADER
#define AST_HEADER


#include "hash.h"
#include <stdio.h>
//Número máximo de folhas
#define MAX_SONS 4


//Constantes para cada coisa que vai ser colocada na AST.
//Identificador SYMBOL recebe 1 nesse caso.
#define SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_DEC 4
#define AST_ASS 5
#define AST_LCMD 6
#define AST_VARIABLE 7
#define AST_LT 8//less then
#define AST_FUNC_PAR_FLOAT 9
#define AST_GT 10//greater then
#define AST_LE 11//less or equal
#define AST_GE 12//great or equal
#define AST_EQ 13//equal
#define AST_NE 14//not equal
#define AST_AND 15
#define AST_OR 16
#define AST_PARENTHESES 17 //paranteses
#define AST_FUNCTIONCALL 18//chamada de função
#define AST_NOT 19// ponto exclm
#define AST_TRUE 20
#define AST_BOOL 21
#define AST_BLOCK 22
#define AST_IF_THEN 23 //if then
#define AST_IF_THEN_ELSE 24 // if else
#define AST_FOR_TO 25
#define AST_VARIABLE_VEC_1_INT 26
#define AST_VARIABLE_VEC_2_INT 27
#define AST_VARIABLE_VEC_1_FLOAT 28
#define AST_VARIABLE_VEC_2_FLOAT 29
#define AST_VARIABLE_VEC_1_CHAR 30
#define AST_VARIABLE_VEC_2_CHAR 31
#define AST_FUNC_RESET 32
#define AST_ATRIBUTION 33  //attribution like TK_IDENTIFIER = exp
#define AST_TO_PTR_ATRIBUTION 34
#define AST_TO_END_ATRIBUTION 35
#define AST_PTR_ATRIBUTION 36
#define AST_END_ATRIBUTION 37
#define AST_VEC_ATRIBUTION 38
#define AST_TO_PTR_VEC_ATRIBUTION 39
#define AST_TO_END_VEC_ATRIBUTION 40
#define AST_PTR_VEC_ATRIBUTION 41
#define AST_RETURN 42
#define AST_INT 43
#define AST_FLOAT 44
#define AST_CHAR 45
#define READ_VEC 46
#define AST_MULT 47
#define AST_DIV 48
#define AST_PTR 49
#define AST_END 50
#define AST_FUNC_ARGL_LIST 51
#define AST_FUNC_BLOCK 52
#define AST_FUNC_HEADER 53
#define AST_FUNC_PAR_LIST 54
#define AST_FUNC_PAR 55
#define AST_PRINT_LIST 56
#define END_SYMBOL 57
#define PTR_SYMBOL 58
#define AST_PRINT 59
#define AST_READ 60
#define AST_FUNC_HEADER_CHAR 61
#define AST_FUNC_HEADER_INT 62
#define AST_FUNC_HEADER_FLOAT 63
#define AST_FUNC_PAR_INT 64
#define AST_END_VEC_ATRIBUTION 65
#define AST_VARIABLE_PTR_CHAR 66
#define AST_VARIABLE_PTR_INT 67
#define AST_VARIABLE_PTR_FLOAT 68
#define AST_VAR_PRINT 69
#define AST_VAR_END 70
#define AST_VAR_PTR 71
#define AST_FUNC_PAR_CHAR 72
#define AST_VARIABLE_DEC_FLOAT 73
#define AST_VARIABLE_DEC_INT 74
#define AST_VARIABLE_DEC_CHAR 75
#define AST_LCMD2 76
#define AST_VET_LIST 77
#define AST_WHILE 78
#define AST_END_IF 79

typedef struct ast_node{
    int type;
    HASH *symbol;
    HASH *text;
    struct ast_node *son[MAX_SONS];
} AST;

AST* astCreate(int type, HASH*symbol , AST *son0 , AST *son1 , AST *son2, AST *son3);

void astToFile(int level,AST*node, FILE *fileTree);



#endif
