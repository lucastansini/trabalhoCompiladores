#include <stdio.h>
#include "tac.h"
// #include "ast.h"

TAC* tacCreate(int Type, HASH *res, HASH *Op1, HASH *Op2){

  TAC *newTac = 0;
  newTac = (TAC*) calloc(1,sizeof(TAC));
  newTac->result = res;
  newTac->op1 = Op1;
  newTac->op2 = Op2;
  newTac->previous = 0;
  newTac->next = 0;
  newTac->type = Type;
  // printf("Exited tacCreate.\n");
  return newTac;
}


TAC* tacPrintSingle(TAC *tac){
  // printf("Entered tac printSingle.\n");
  if(!tac){
    return;
  }
  if(tac->type == TAC_SYMBOL) return;
  fprintf(stderr,"TAC(");
  switch(tac->type){
    case TAC_ADD:
      fprintf(stderr,"TAC_ADD");
    break;
    case TAC_ASS:
      fprintf(stderr,"TAC_ASS");
    break;
    case TAC_ATTRIBUTION:
      fprintf(stderr,"TAC_ATTRIBUTION");
    break;
    default:
      fprintf(stderr,"TAC_UNKOWN");
    break;
  }

  if(tac->result) fprintf(stderr,",%s",tac->result->yytext);
  else fprintf(stderr,",0");
  if(tac->op1) fprintf(stderr,",%s",tac->op1->yytext);
  else fprintf(stderr,",0");
  if(tac->op2) fprintf(stderr,",%s",tac->op2->yytext);
  else fprintf(stderr,",0");
  fprintf(stderr,")\n");
  // printf("Exited tac printSingle.\n");

}

TAC *tacPrintBack(TAC *tac){

  if(!tac){
    return;
  }
  tacPrintSingle(tac);
  tacPrintBack(tac->previous);
}




TAC *codeGenerator(AST *node){
  // printf("Entered code generator.\n");
  int i;
  TAC *result = 0;
  TAC* code[MAX_SONS];

  if(!node){
    return 0;
  }


  for(i=0 ; i < MAX_SONS ; i++){
    code[i] = codeGenerator(node->son[i]);
  }

  switch (node->type) {
    case SYMBOL:
      //printf("SYMBOL IS=%s\n",node->symbol->yytext);
      result = tacCreate(TAC_SYMBOL,node->symbol,0,0);
    break;
    case AST_ADD:
      //result = tacJoin(code[0],tacJoin(code[1],tacCreate(TAC_ADD,makeTemp(),code[0]?code[0]->result:0,code[1]?code[1]->result:0)));
      result = makeBinOp(TAC_ADD,code[0],code[1]);
      //printf("TAC TYPE IS= %d\n",result->type);
    break;
    case AST_ATRIBUTION:
      result = tacJoin(code[0],tacCreate(TAC_ASS,node->symbol,code[0]?code[0]->result:0,0));
    break;
    case AST_VARIABLE_DEC_INT:
      result = tacJoin(code[0],tacCreate(TAC_ASS,node->symbol,code[0]?code[0]->result:0,0));
    break;
    //DECLARATION????? caso do a + 6 + 3;
    default:
      result = tacJoin(tacJoin(tacJoin(code[0],code[1]),code[2]),code[3]);
    break;
  }

  // printf("Exited code generator.\n");
  return result;

}
TAC *tacJoin(TAC *l1, TAC *l2){
  // printf("Entered tac join.\n");
  TAC *aux;

  if(!l1){
    // printf("Exited tacJoin via l2\n");
    return l2;
  }

  if(!l2){
    // printf("Exited tacJoin via l1\n");
    return l1;
  }


  for(aux = l2;aux->previous; aux=aux->previous);

  //FOr tem seg fault.
  aux->previous = l1;


  // printf("Exited tac join.\n");
  return l2;

}

TAC* tacReverse(TAC *node){
  TAC *tac ;
  // printf("Entered tac reverse.\n");
  for(tac = node; tac->previous; tac = tac->previous){
    tac->previous->next = tac;
  }

  // printf("Exited tac reverse.\n");

  return tac;
}


void tacPrintForward(TAC *tac){
  if(!tac) return;
  tacPrintSingle(tac);
  tacPrintForward(tac->next);
}


TAC *makeBinOp(int type, TAC *code0, TAC *code1){

  // printf("Entered make BinOP\n");

  TAC *newTac = tacCreate(type,makeTemp(),code0 ? code0->result : 0, code1 ? code1->result : 0);
  // printf("TYPE IS=%d",newTac->type);
  // printf("Exited make BinOP\n");
  return tacJoin(code0,tacJoin(code1,newTac));

}
