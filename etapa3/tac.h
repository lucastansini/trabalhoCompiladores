#ifndef TAC_HEADER
#define TAC_HEADER

#include <stdio.h>

//Symbols for tac instructions

#define TAC_SYMBOL 1
#define TAC_ADD    2
#define TAC_SUB    3
#define TAC_MULT   4
#define TAC_DIV    5
#define TAC_ASS    6 //Assinalamento
#define TAC_ATTRIBUTION 7 //Atribuição
#define TAC_DECLARATION 8
#define TAC_LESS_THEN 9
#define TAC_GREATER_THEN 10
#define TAC_NOT_EXPRESSION 11
#define TAC_LESS_EQUAL 12
#define TAC_GREATER_EQUAL 13
#define TAC_EQUAL 14
#define TAC_NOT_EQUAL 15
#define TAC_OR 16
#define TAC_AND 17



typedef struct tac{

  int type;
  HASH* result;
  HASH* op1;
  HASH* op2;
  struct tac *next;
  struct tac *previous;
} TAC;

//Tac functions

TAC *tacCreate(int type, HASH *res, HASH *op1, HASH* op2);
TAC *tacPrintSingle(TAC *tac);
TAC *tacPrintBack(TAC *tac);
TAC *codeGenerator(AST *node);
void tacPrintForward(TAC *tac);
TAC *tacReverse(TAC *tac);
TAC *makeBinOp(int type, TAC *code0, TAC *code1);
TAC *tacJoin(TAC *l1, TAC *l2);










#endif