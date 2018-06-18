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
    case TAC_RETURN:
      fprintf(stderr,"TAC_RETURN");
    break;
    case TAC_ASS:
      fprintf(stderr,"TAC_ASS");
    break;
    case TAC_ATTRIBUTION:
      fprintf(stderr,"TAC_ATTRIBUTION");
    break;
    case TAC_LESS_THEN:
      fprintf(stderr,"TAC_LESS_THEN");
    break;
    case TAC_GREATER_THEN:
      fprintf(stderr,"TAC_GREATER_THEN");
    break;
    case TAC_NOT_EXPRESSION:
      fprintf(stderr,"TAC_NOT_EXPRESSION");
    break;
    case TAC_LESS_EQUAL:
      fprintf(stderr,"TAC_LESS_EQUAL");
    break;
    case TAC_GREATER_EQUAL:
      fprintf(stderr,"TAC_GREATER_EQUAL");
    break;
    case TAC_EQUAL:
      fprintf(stderr,"TAC_EQUAL");
    break;
    case TAC_NOT_EQUAL:
      fprintf(stderr,"TAC_NOT_EQUAL");
    break;
    case TAC_OR:
      fprintf(stderr,"TAC_OR");
    break;
    case TAC_AND:
      fprintf(stderr,"TAC_AND");
    break;
    case TAC_SUB:
      fprintf(stderr,"TAC_SUB");
    break;
    case TAC_DIV:
      fprintf(stderr,"TAC_DIV");
    break;
    case TAC_MULT:
      fprintf(stderr,"TAC_MULT");
    break;
    case TAC_IF_ZERO:
      fprintf(stderr,"TAC_IF_ZERO");
    break;
    case TAC_LABEL:
      fprintf(stderr, "TAC_LABEL");
    break;
    case TAC_JUMP:
      fprintf(stderr, "TAC_JUMP");
    break;
    case TAC_WHILE:
      fprintf(stderr,"TAC_WHILE");
    break;
    case TAC_PRINT_TEXT:
      fprintf(stderr,"TAC_PRINT_TEXT");
    break;
    case TAC_CALL:
      fprintf(stderr,"TAC_CALL");
    break;
    case TAC_READ:
      fprintf(stderr,"TAC_READ");
    break;
    case TAC_PUSH:
      fprintf(stderr,"TAC_PUSH");
    break;
    case TAC_BEGIN_FUNCTION:
      fprintf(stderr,"TAC_BEGIN_FUNCTION");
    break;
    case TAC_END_FUNCTION:
      fprintf(stderr,"TAC_END_FUNCTION");
    break;
    case TAC_VECWRITE:
      fprintf(stderr,"TAC_VECWRITE");
    break;
    case TAC_VECREAD:
      fprintf(stderr,"TAC_VECREAD");
    break;
    case TAC_VEC_DEC_ATR:
      fprintf(stderr,"TAC_VEC_DEC_ATR");
    break;
    case TAC_VECTOR_MEM_INIT:
      fprintf(stderr, "TAC_VECTOR_MEM_INIT");
    break;
    case TAC_FOR_TO:
      fprintf(stderr, "TAC_FOR_TO");
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
  int i = 0;
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
      //fprintf(stderr,"DEBUG: SYMBOL IS%s\n",node->symbol->yytext);
    break;
    case AST_ADD:
      //result = tacJoin(code[0],tacJoin(code[1],tacCreate(TAC_ADD,makeTemp(),code[0]?code[0]->result:0,code[1]?code[1]->result:0)));
      result = makeBinOp(TAC_ADD,code[0],code[1]);
      //printf("TAC TYPE IS= %d\n",result->type);
    break;
    case AST_SUB:
    result = makeBinOp(TAC_SUB,code[0],code[1]);
    break;
    case AST_VARIABLE:
      result = tacCreate(TAC_SYMBOL,node->symbol,0,0);
    break;
    case AST_ATRIBUTION:
      result = tacJoin(code[0],tacCreate(TAC_ASS,node->symbol,code[0]?code[0]->result:0,0));
      //fprintf(stderr,"DEBUG: RESULT IS%d\n",code[0]->result);
    break;
    case AST_MULT:
      result = makeBinOp(TAC_MULT,code[0],code[1]);
    break;
    case AST_DIV:
      result = makeBinOp(TAC_DIV,code[0],code[1]);
    break;
    ////////////////////////////////////////////////////////////////////////
    case AST_VARIABLE_DEC_INT:
    case AST_VARIABLE_PTR_FLOAT:
    case AST_VARIABLE_PTR_CHAR:
    case AST_VARIABLE_PTR_INT:
    case AST_VARIABLE_DEC_CHAR:
    case AST_VARIABLE_DEC_FLOAT:
    case AST_TO_PTR_ATRIBUTION:
    case AST_TO_END_ATRIBUTION:
    case AST_PTR_ATRIBUTION:
    case AST_END_ATRIBUTION:
      result = tacJoin(code[0],tacCreate(TAC_ASS,node->symbol,code[0]?code[0]->result:0,0));
    break;
    case AST_VARIABLE_VEC_2_FLOAT:
    case AST_VARIABLE_VEC_2_CHAR:
    case AST_VARIABLE_VEC_2_INT:
      result = tacJoin(code[0],tacCreate(TAC_VECTOR_MEM_INIT,node->symbol,code[0]?code[0]->result:0,0));
    break;
    ////////////////////////////////////////////////////////////////////////
    case AST_LT:
      result = makeBinOp(TAC_LESS_THEN,code[0],code[1]);
    break;
    case AST_GT:
      result = makeBinOp(TAC_GREATER_THEN,code[0],code[1]);
    break;
    case AST_NOT:
      result = makeBinOp(TAC_NOT_EXPRESSION,code[0],code[1]);
    break;
    case AST_LE:
      result = makeBinOp(TAC_LESS_EQUAL,code[0],code[1]);
    break;
    case AST_GE:
      result = makeBinOp(TAC_GREATER_EQUAL,code[0],code[1]);
    break;
    case AST_EQ:
      result = makeBinOp(TAC_EQUAL,code[0],code[1]);
    break;
    case AST_NE:
      result = makeBinOp(TAC_NOT_EQUAL,code[0],code[1]);
    break;
    case AST_AND:
      result = makeBinOp(TAC_AND,code[0],code[1]);
    break;
    case AST_OR:
      result = makeBinOp(TAC_OR,code[0],code[1]);
    break;
    case AST_IF_THEN:
      result = makeIfThen(code[0],code[1]);
    break;
    case AST_IF_THEN_ELSE:
      result = makeIfThenElse(code[0],code[1],code[2]);
    break;
    case AST_RETURN:
      result = makeBinOp(TAC_RETURN,code[0],code[1]);
    break;
    case AST_WHILE:
      result = makeWhile(code[0],code[1]);
    break;
    case AST_VAR_PRINT:
      result = tacJoin(tacCreate(TAC_PRINT_TEXT,node->symbol,0,0),code[1]);
    break;
    case AST_FUNCTIONCALL:
      result = tacJoin(tacCreate(TAC_CALL,makeTemp(), node->symbol, 0),code[1]);
    break;
    case AST_READ:
      result = tacCreate(TAC_READ,node->symbol,0,0);
    break;
    case AST_FUNC_BLOCK:
      result = makeFunct(tacCreate(TAC_SYMBOL,node->son[0]->symbol,0,0),code[1],code[2]);
    break;
    case AST_FUNC_ARGL_LIST:
      // result = tacJoin(code[1],tacCreate(TAC_PUSH,node->son[0]->symbol,0,0));
      // fprintf(stderr,"SON0SYMBOL%s:\n",node->son[0]->symbol->yytext);
      //VERIFICAR AQUI NAO TA FUNCIONANDO!!
    break;
    case AST_FUNC_RESET:
      result = tacJoin(tacCreate(TAC_PUSH,code[0]?code[0]->result:0,0,0),code[1]);
    break;
    case AST_VEC_ATRIBUTION:
      result = tacJoin(code[1],tacCreate(TAC_VECWRITE,node->symbol,code[0]?code[0]->result:0,code[1]?code[1]->result:0));
    break;
    case READ_VEC:
      result = tacCreate(TAC_VECREAD,makeTemp(),node->symbol,code[0]?code[0]->result:0);
    break;
    case AST_FOR_TO:
      result = makeFor(node->symbol,code[0],code[1],code[2]);
    break;
    // NAO SEI SE PRECISA FAZER ESSA AQUII!!!
    // case AST_VARIABLE_VEC_1_INT:
    //   result = tacCreate(TAC_VEC_DEC_ATR,node->symbol,code[1]?code[1]->result:0,0);
    // break;
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


  aux = l2;
  while(aux->previous){
    aux = aux->previous;
  }

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


TAC* makeIfThen(TAC *code0, TAC *code1){

  TAC *newIfTac = 0;
  TAC *newLabelTac;
  HASH *newLabel = 0;

  newLabel = makeLabel();
  newIfTac = tacCreate(TAC_IF_ZERO,newLabel,code0 ? code0->result:0,0);
  newLabelTac = tacCreate(TAC_LABEL,newLabel,0,0);

  return tacJoin(tacJoin(tacJoin(code0,newIfTac),code1),newLabelTac);
}

TAC *makeIfThenElse(TAC *code0, TAC *code1, TAC *code2){

  TAC *skipTac = 0;
  TAC *elseLabelTac = 0;
  TAC *ifTac = 0;
  TAC *ifLabelTac = 0;

  HASH *ifLabel = makeLabel();
  HASH *elseLabel = makeLabel();

  skipTac = tacCreate(TAC_JUMP,elseLabel,0,0);
  elseLabelTac = tacCreate(TAC_LABEL,elseLabel,0,0);

  ifTac = tacCreate(TAC_IF_ZERO,ifLabel,code0 ? code0->result : 0,0);
  ifLabelTac = tacCreate(TAC_LABEL,ifLabel,0,0);

  return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(code0,ifTac),code1),skipTac),ifLabelTac),code2),elseLabelTac);

}

TAC* makeFor(HASH* nodeSymbol, TAC *code0, TAC *code1, TAC *code2){

    TAC *newIfTac = 0;

    HASH *initLabel = makeLabel();
    HASH *endLabel = makeLabel();
    HASH *newLabel = makeLabel();

    TAC *returnTac = tacCreate(TAC_LABEL,initLabel,0,0);
    TAC *equalTac = tacCreate(TAC_EQUAL,makeTemp(),nodeSymbol, code1 ? code1->result : 0);
    newIfTac = tacCreate(TAC_IF_ZERO,newLabel,equalTac?equalTac->result:0,0);
    TAC *jump = tacCreate(TAC_JUMP,initLabel,0,0);
    TAC *end = tacCreate(TAC_LABEL,newLabel,0,0);

    return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(returnTac,equalTac),newIfTac),code2),jump),end);

}

TAC *makeWhile(TAC *code0, TAC*code1){

  //Tacs para while
  TAC *whileTac;
  TAC *labelWhileTac;
  TAC *jumpLabelTac;
  TAC *jumpTac;

  //Labels
  HASH *whileLabel;
  HASH *jumpLabel;


    whileLabel = makeLabel();
  jumpLabel = makeLabel();

  jumpTac = tacCreate(TAC_JUMP,whileLabel,0,0);
  whileTac = tacCreate(TAC_IF_ZERO,jumpLabel,code0 ? code0->result : 0,0);
  labelWhileTac = tacCreate(TAC_LABEL,whileLabel,0,0);
  jumpLabelTac = tacCreate(TAC_LABEL,jumpLabel,0,0);

  //Ligando todos
  return  tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(labelWhileTac,code0),whileTac),code1),jumpTac),jumpLabelTac);


}

TAC* makeFunct(TAC *code0, TAC *code1, TAC* code2){
  return tacJoin(tacJoin(tacJoin( tacCreate(TAC_BEGIN_FUNCTION, code0->result, 0, 0), code1) , code2 ), tacCreate(TAC_END_FUNCTION, code0->result, 0, 0));
}
