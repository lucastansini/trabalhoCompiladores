#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

#define FILHOZERO 0
#define FILHOUM 1
#define FILHODOIS 2
#define FILHOTRES 3


AST* astCreate(int Type, HASH*Symbol , AST *Son0 , AST *Son1 , AST *Son2, AST *Son3){


  //Criamos o novo nodo
  AST* newnode;

  newnode = (AST*) calloc(1,sizeof(AST));
  newnode->type = Type;
  newnode->symbol = Symbol;
  newnode->son[FILHOZERO] = Son0;
  newnode->son[FILHOUM] = Son1;
  newnode->son[FILHODOIS] = Son2;
  newnode->son[FILHOTRES] = Son3;


  return newnode;
}


void astPrint(AST *node, int level){

  int i = 0;

  if(!node){
    return;
  }
  for(i; i<level; i++)
    fprintf(stderr, "  ");
  fprintf(stderr,"AST(");
  switch(node->type){
    case SYMBOL: fprintf(stderr, "AST_SYMBOL,\n");      break;
    case AST_ADD: fprintf(stderr, "AST_ADD,\n");      break;
    case AST_SUB: fprintf(stderr, "AST_SUB,\n");      break;
    case AST_DEC: fprintf(stderr, "AST_DEC,\n");      break;
    case AST_ASS: fprintf(stderr, "AST_ASS,\n");      break;
    case AST_LCMD: fprintf(stderr, "AST_LCMD,\n");      break;
    case AST_VARIABLE: fprintf(stderr, "AST_VARIABLE,\n");      break;
    case AST_LT: fprintf(stderr, "AST_LT,\n");      break;
    case AST_FUNC_PAR_FLOAT: fprintf(stderr, "AST_FUNC_PAR_FLOAT,\n");      break;
    case AST_GT: fprintf(stderr, "AST_GT,\n");      break;
    case AST_LE: fprintf(stderr, "AST_LE,\n");      break;
    case AST_GE: fprintf(stderr, "AST_GE,\n");      break;
    case AST_EQ: fprintf(stderr, "AST_EQ,\n");      break;
    case AST_NE: fprintf(stderr, "AST_NE,\n");      break;
    case AST_AND: fprintf(stderr, "AST_AND,\n");      break;
    case AST_OR: fprintf(stderr, "AST_OR,\n");      break;
    case AST_PARENTHESES: fprintf(stderr, "AST_PARENTHESES,\n");      break;
    case AST_FUNCTIONCALL: fprintf(stderr, "AST_FUNCTIONCALL,\n");      break;
    case AST_NOT: fprintf(stderr, "AST_NOT,\n");      break;
    case AST_TRUE: fprintf(stderr, "AST_TRUE,\n");      break;
    case AST_BOOL: fprintf(stderr, "AST_BOOL,\n");      break;
    case AST_BLOCK: fprintf(stderr, "AST_BLOCK,\n");      break;
    case AST_IF_THEN: fprintf(stderr, "AST_IF_THEN,\n"); break;
    case AST_IF_THEN_ELSE: fprintf(stderr, "AST_IF_THEN_ELSE,\n");      break;
    case AST_FOR_TO: fprintf(stderr, "AST_FOR_TO,\n");      break;
    case AST_VARIABLE_VEC_1_INT: fprintf(stderr, "AST_VARIABLE_VEC_1_INT,\n");      break;
    case AST_VARIABLE_VEC_2_INT: fprintf(stderr, "AST_VARIABLE_VEC_2_INT,\n");      break;
    case AST_VARIABLE_VEC_1_FLOAT: fprintf(stderr, "AST_VARIABLE_VEC_1_FLOAT,\n");      break;
    case AST_VARIABLE_VEC_2_FLOAT: fprintf(stderr, "AST_VARIABLE_VEC_1_CHAR,\n");      break;
    case AST_VARIABLE_VEC_2_CHAR: fprintf(stderr, "AST_FUNC_RESET,\n");      break;
    case AST_ATRIBUTION: fprintf(stderr, "AST_ATRIBUTION,\n");      break;
    case AST_TO_PTR_ATRIBUTION: fprintf(stderr, "AST_TO_PTR_ATRIBUTION,\n");      break;
    case AST_TO_END_ATRIBUTION: fprintf(stderr, "AST_TO_END_ATRIBUTION,\n");      break;
    case AST_PTR_ATRIBUTION: fprintf(stderr, "AST_PTR_ATRIBUTION,\n");      break;
    case AST_END_ATRIBUTION: fprintf(stderr, "AST_END_ATRIBUTION,\n");      break;
    case AST_VEC_ATRIBUTION: fprintf(stderr, "AST_VEC_ATRIBUTION,\n");      break;
    case AST_TO_PTR_VEC_ATRIBUTION: fprintf(stderr, "AST_TO_PTR_VEC_ATRIBUTION,\n");      break;
    case AST_TO_END_VEC_ATRIBUTION: fprintf(stderr, "AST_TO_END_VEC_ATRIBUTION,\n");      break;
    case AST_PTR_VEC_ATRIBUTION: fprintf(stderr, "AST_PTR_VEC_ATRIBUTION,\n");      break;
    case AST_RETURN: fprintf(stderr, "AST_RETURN,\n");      break;
    case AST_INT: fprintf(stderr, "AST_INT,\n");      break;
    case AST_FLOAT: fprintf(stderr, "AST_FLOAT,\n");      break;
    case AST_CHAR: fprintf(stderr, "AST_CHAR,\n");      break;
    case READ_VEC: fprintf(stderr, "READ_VEC,\n");      break;
    case AST_MULT: fprintf(stderr, "AST_MULT,\n");      break;
    case AST_DIV: fprintf(stderr, "AST_DIV,\n");      break;
    case AST_END: fprintf(stderr, "AST_END,\n");      break;
    case AST_FUNC_ARGL_LIST: fprintf(stderr, "AST_FUNC_ARGL_LIST,\n");      break;
    case AST_FUNC_BLOCK: fprintf(stderr, "AST_FUNC_BLOCK,\n");      break;
    case AST_FUNC_HEADER: fprintf(stderr, "AST_FUNC_HEADER,\n");      break;
    case AST_FUNC_PAR_LIST: fprintf(stderr, "AST_FUNC_PAR_LIST,\n");      break;
    case AST_FUNC_PAR: fprintf(stderr, "AST_FUNC_PAR,\n");      break;
    case AST_PRINT_LIST: fprintf(stderr, "AST_PRINT_LIST,\n");      break;
    case END_SYMBOL: fprintf(stderr, "END_SYMBOL,\n");      break;
    case PTR_SYMBOL: fprintf(stderr, "PTR_SYMBOL,\n");      break;
    case AST_PRINT: fprintf(stderr, "AST_PRINT,\n");      break;
    case AST_READ: fprintf(stderr, "AST_READ,\n");      break;
    case AST_FUNC_HEADER_CHAR: fprintf(stderr, "AST_FUNC_HEADER_CHAR,\n");      break;
    case AST_FUNC_HEADER_INT: fprintf(stderr, "AST_FUNC_HEADER_INT,\n");      break;
    case AST_FUNC_HEADER_FLOAT: fprintf(stderr, "AST_FUNC_HEADER_FLOAT,\n");      break;
    case AST_FUNC_PAR_INT: fprintf(stderr, "AST_FUNC_PAR_INT,\n");      break;
    case AST_END_VEC_ATRIBUTION: fprintf(stderr, "AST_END_VEC_ATRIBUTION,\n");      break;
    case AST_VARIABLE_PTR_CHAR: fprintf(stderr, "AST_VARIABLE_PTR_CHAR,\n");      break;
    case AST_VARIABLE_PTR_INT: fprintf(stderr, "AST_VARIABLE_PTR_INT,\n");      break;
    case AST_VARIABLE_PTR_FLOAT: fprintf(stderr, "AST_VARIABLE_PTR_FLOAT,\n");      break;
    case AST_VAR_PRINT: fprintf(stderr, "AST_VAR_PRINT,\n");      break;
    case AST_VAR_END: fprintf(stderr, "AST_VAR_END,\n");      break;
    case AST_VAR_PTR: fprintf(stderr, "AST_VAR_PTR,\n");      break;



    default: fprintf(stderr,"UNKNOWN,\n");
  }

  for(i=0; i<MAX_SONS; i++)
    astPrint(node->son[i],level+1);

}
