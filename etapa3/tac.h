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
#define TAC_IF_ZERO 18 //Tac auxiliar para controle de fluxo
#define TAC_LABEL 19 //Buffer label para controle de fluxo
#define TAC_JUMP 20
#define TAC_RETURN 21
#define TAC_WHILE 22
#define TAC_PRINT_TEXT 23
#define TAC_CALL 24
#define TAC_READ 25
#define TAC_PUSH 26
#define TAC_BEGIN_FUNCTION 27
#define TAC_END_FUNCTION 28


typedef struct tac{

  int type;
  HASH* result;
  HASH* op1;
  HASH* op2;
  struct tac *next;
  struct tac *previous;
} TAC;

//Tac general functions
TAC *tacCreate(int type, HASH *res, HASH *op1, HASH* op2);
TAC *tacPrintSingle(TAC *tac);
TAC *tacPrintBack(TAC *tac);
TAC *codeGenerator(AST *node);
void tacPrintForward(TAC *tac);
TAC *tacReverse(TAC *tac);
TAC *makeBinOp(int type, TAC *code0, TAC *code1);
TAC *tacJoin(TAC *l1, TAC *l2);

//TAC Special functions (creation of if,while,for)
TAC* makeFunc(TAC *code0,TAC *code1,TAC *code2);
TAC* makeIfThen(TAC *code0, TAC *code1);
TAC* makeIfThenElse(TAC *code0,TAC *code1, TAC *code2);
TAC* makeWhile(TAC *code0, TAC *code1);
TAC* makeFunct(TAC *code0, TAC *code1, TAC *code2);





#endif
