#include <stdio.h>
#include "tac.h"
// #include "ast.h"

TAC* tacCreate(int type, HASH *res, HASH *Op1, HASH *Op2){

  TAC *newTac = 0;
  newTac = (TAC*) calloc(1,sizeof(TAC));
  newTac->result = res;
  newTac->op1 = Op1;
  newTac->op2 = Op2;
  newTac->previous = 0;
  newTac->next = 0;

  return newTac;
}


TAC* tacPrintSingle(TAC *tac){
  printf("Entered tac printSingle.\n");
  if(!tac){
    return;
  }
  fprintf(stderr,"TAC(");
  if(tac->type == TAC_SYMBOL) return;

  switch(tac->type){
    case TAC_SYMBOL:  fprintf(stderr,"TAC_SYMBOL"); break;
    case TAC_ADD:  fprintf(stderr,"TAC_ADD"); break;
    default: fprintf(stderr,"TAC_UNKOWN"); break;
  }

  if(tac->result) fprintf(stderr,",%s",tac->result->next);
  else fprintf(stderr,",0");
  if(tac->op1) fprintf(stderr,",%s",tac->op1->next);
  else fprintf(stderr,",0");
  if(tac->op2) fprintf(stderr,",%s",tac->op2->next);
  else fprintf(stderr,",0");
  fprintf(stderr,")\n");
  printf("Exited tac printSingle.\n");

}

TAC *tacPrintBack(TAC *tac){

  if(!tac){
    return;
  }
  tacPrintSingle(tac);
  tacPrintBack(tac->previous);
}




TAC *codeGenerator(AST *node){
  printf("Entered code generator.\n");
  int i;
  TAC *result;
  TAC* code[MAX_SONS];

  if(!node){
    return;
  }


  for(i=0 ; i < MAX_SONS ; i++){
    codeGenerator(node->son[i]);
  }

  switch (node->type) {
    case SYMBOL:
      result = tacCreate(TAC_SYMBOL,node->symbol,0,0);
    break;
    case AST_ADD:
      result = makeBinOp(TAC_ADD,code[0],code[1]);
    break;
    default:
      fprintf(stderr,"UNKOWN\n");
    break;
  }

  printf("Exited code generator.\n");
  return result;

}
TAC *tacJoin(TAC *l1, TAC *l2){
  printf("Entered tac join.\n");
  TAC *aux = 0;

  if(!l1){
    printf("Exited tacJoin via l2\n");
    return l2;
  }

  if(!l2){
    printf("Exited tacJoin via l1\n");
    return l1;
  }


  for(aux = l1;aux->previous; aux=aux->previous);

  //FOr tem seg fault.
  aux->previous = l1;


  printf("Exited tac join.\n");
  return l2;

}

TAC* tacReverse(TAC* last){
  TAC *tac = 0;
  printf("Entered tac reverse.\n");
  for(tac = last; tac->previous; tac = tac->previous)
    tac->previous->next = tac;

  printf("Exited tac reverse.\n");

  return tac;
}


void tacPrintForward(TAC *tac){
  if(!tac) return;
  tacPrintSingle(tac);
  tacPrintForward(tac->next);
}


TAC *makeBinOp(int type, TAC *code0, TAC *code1){

  printf("Entered make BinOP\n");

  TAC *newTac = tacCreate(type,makeTemp(),code0 ? code0->result : 0, code1 ? code1->result : 0);
  return tacJoin(code0,tacJoin(code1,newTac));

  printf("Exited make BinOP\n");
}
