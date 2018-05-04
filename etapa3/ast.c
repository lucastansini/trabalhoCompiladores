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
    case SYMBOL: fprintf(stderr, "AST_SYMBOL,\n");
      break;
    default: fprintf(stderr,"UNKNOWN,\n");
  }

  for(i=0; i<MAX_SONS; i++)
    astPrint(node->son[i],level+1);

}
