#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

#define FILHOZERO 0
#define FILHOUM 1
#define FILHODOIS 2
#define FILHOTRES 3


AST* astCreate(int Type, HASH*Symbol , AST *Son0 , AST *Son1 , AST *Son2, AST *Son3){


  //Criamos o novo node
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


void astPrint(AST *node, int level, FILE* fileTree){

  int i = 0;
    if (node){
            printf("nivel = %d\n",level);
    }

  if(!node){
     printf("nivel = %d\n",level);
    return;
  }
  for(i; i<level; i++)
    fprintf(stderr, "  ");
  fprintf(stderr,"AST(");
  switch(node->type){

      case SYMBOL: fprintf(stderr, "AST_SYMBOL,\n");
          fprintf(fileTree,"%s",node->symbol->yytext);
          break;
      case AST_ADD: fprintf(stderr, "AST_ADD,\n");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree," + ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_SUB: fprintf(stderr, "AST_SUB,\n");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," - ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_DEC: fprintf(stderr, "AST_DEC,\n");
            if(node){
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
            }
          break;
      case AST_LCMD: fprintf(stderr, "AST_LCMD,\n");
        
          astPrint(node->son[0],level, fileTree);
          astPrint(node->son[1],level, fileTree);
          break;
      case AST_VARIABLE: fprintf(stderr, "AST_VARIABLE,\n");
          astPrint(node->son[0],level,fileTree);
          break;
      case AST_LT: fprintf(stderr, "AST_LT,\n");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," <= ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_GT: fprintf(stderr, "AST_GT,\n");   printf(">");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," > ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_LE: fprintf(stderr, "AST_LE,\n");   printf("<=");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," <= ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_GE: fprintf(stderr, "AST_GE,\n");   printf(">=");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," >= ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_EQ: fprintf(stderr, "AST_EQ,\n");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," == ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_NE: fprintf(stderr, "AST_NE,\n");   printf("!=");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," != ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_AND: fprintf(stderr, "AST_AND,\n"); printf("&&");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," && ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_OR: fprintf(stderr, "AST_OR,\n");   printf("||");
          astPrint(node->son[0], level, fileTree);
          fprintf(fileTree," || ");
          astPrint(node->son[1],level,fileTree);
          break;
      case AST_PARENTHESES: fprintf(stderr, "AST_PARENTHESES,\n");
          fprintf(fileTree,"(");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,")");
          break;
      case AST_FUNCTIONCALL: fprintf(stderr, "AST_FUNCTIONCALL,\n");      break;
      case AST_NOT: fprintf(stderr, "AST_NOT,\n");
          fprintf(fileTree,"!");
          astPrint(node->son[0],level,fileTree);
          break;
    case AST_BLOCK: fprintf(stderr, "AST_BLOCK,\n");
          fprintf(fileTree,"{");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"{");
          break;
    case AST_IF_THEN: fprintf(stderr, "AST_IF_THEN,\n");
          fprintf(fileTree,"(");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,") then");
          astPrint(node->son[1],level,fileTree);
          break;
          
    case AST_IF_THEN_ELSE: fprintf(stderr, "AST_IF_THEN_ELSE,\n");
          fprintf(fileTree,"(");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,") then");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"else");
          astPrint(node->son[2],level,fileTree);
          break;
    case AST_FOR_TO: fprintf(stderr, "AST_FOR_TO,\n");
          fprintf(fileTree,"for(");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"=");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"to");
          astPrint(node->son[2],level,fileTree);
          fprintf(fileTree,")");
          astPrint(node->son[3],level,fileTree);
          break;
    case AST_VARIABLE_VEC_1_INT: fprintf(stderr, "AST_VARIABLE_VEC_1_INT,\n");
          fprintf(fileTree,"int %s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"]");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"] :");
          astPrint(node->son[2],level,fileTree);
          break;

    case AST_VARIABLE_VEC_1_FLOAT: fprintf(stderr, "AST_VARIABLE_VEC_1_FLOAT,\n");
          fprintf(fileTree,"float %s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"]");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"] :");
          astPrint(node->son[2],level,fileTree);
          break;
          
    case AST_VARIABLE_VEC_1_CHAR: fprintf(stderr, "AST_VARIABLE_VEC_1_CHAR,\n");
          fprintf(fileTree,"char %s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"]");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"] :");
          astPrint(node->son[2],level,fileTree);
          break;
    case AST_VARIABLE_VEC_2_INT: fprintf(stderr, "AST_VARIABLE_VEC_2_INT,\n");
          fprintf(fileTree,"int %s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"] ;");
          break;
    case AST_VARIABLE_VEC_2_FLOAT: fprintf(stderr, "AST_VARIABLE_VEC_2_FLOAT,\n");
          fprintf(fileTree,"float %s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"] ;");
          
          break;
    case AST_VARIABLE_VEC_2_CHAR: fprintf(stderr, "AST_FUNC_RESET,\n");
          fprintf(fileTree,"char %s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"] ;");
          break;
    case AST_ATRIBUTION: fprintf(stderr, "AST_ATRIBUTION,\n");
          fprintf(fileTree,"%s =",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          //TK_IDENTIFIER '=' exp
          break;
    case AST_TO_PTR_ATRIBUTION: fprintf(stderr, "AST_TO_PTR_ATRIBUTION,\n");
          fprintf(fileTree,"#%s =",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          break;
    case AST_TO_END_ATRIBUTION: fprintf(stderr, "AST_TO_END_ATRIBUTION,\n");
          fprintf(fileTree,"&%s =",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          //&'TK_IDENTIFIER '='exp
          break;
    case AST_PTR_ATRIBUTION: fprintf(stderr, "AST_PTR_ATRIBUTION,\n");
          fprintf(fileTree,"%s = #",node->symbol->yytext);
          astPrint(node->son[1],level,fileTree);
          break;
    case AST_END_ATRIBUTION: fprintf(stderr, "AST_END_ATRIBUTION,\n");
          fprintf(fileTree,"%s = &",node->symbol->yytext);
          astPrint(node->son[1],level,fileTree);
          //TK_IDENTIFIER '=''&'exp
          break;
    case AST_VEC_ATRIBUTION: fprintf(stderr, "AST_VEC_ATRIBUTION,\n");
          fprintf(fileTree,"%s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf (fileTree,"] = ");
          astPrint(node->son[1],level,fileTree);
          //TK_IDENTIFIER'['exp']' '=' exp
          break;
    case AST_TO_PTR_VEC_ATRIBUTION: fprintf(stderr, "AST_TO_PTR_VEC_ATRIBUTION,\n");
          fprintf(fileTree,"# %s [ ",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"]");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"=");
          break;
    case AST_TO_END_VEC_ATRIBUTION: fprintf(stderr, "AST_TO_END_VEC_ATRIBUTION,\n");
          fprintf(fileTree,"& %s [ ",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"]");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"=");

          //'&'TK_IDENTIFIER'['exp']' '='exp
          break;
    case AST_PTR_VEC_ATRIBUTION: fprintf(stderr, "AST_PTR_VEC_ATRIBUTION,\n");
          fprintf(fileTree,"%s = #",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"[");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"]");
          //TK_IDENTIFIER '=''#'exp '['exp']'
          break;
    case AST_RETURN: fprintf(stderr, "AST_RETURN,\n");
          fprintf(fileTree,"return");
          astPrint(node->son[0],level,fileTree);
          break;
    case AST_INT: fprintf(stderr, "AST_INT,\n");
          fprintf(fileTree,"%s",node->symbol->yytext);
          break;
    case AST_FLOAT: fprintf(stderr, "AST_FLOAT,\n");
          fprintf(fileTree,"%s",node->symbol->yytext);
          break;
    case AST_CHAR: fprintf(stderr, "AST_CHAR,\n");
          fprintf(fileTree,"%s",node->symbol->yytext);
          break;
    case READ_VEC: fprintf(stderr, "READ_VEC,\n");
          fprintf(fileTree,"%s [",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"]");
          //TK_IDENTIFIER'['exp']'
          break;

    case AST_MULT: fprintf(stderr, "AST_MULT,\n");
           astPrint(node->son[0],level,fileTree);
            fprintf(fileTree,"*",node->symbol->yytext);
          astPrint(node->son[1],level,fileTree);

          break;
    case AST_DIV: fprintf(stderr, "AST_DIV,\n");
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"/",node->symbol->yytext);
          astPrint(node->son[1],level,fileTree);
          break;
    case AST_PTR: fprintf(stderr, "AST_END,\n");
          fprintf(fileTree,"# %s",node->symbol->yytext);
          break;
    case AST_END: fprintf(stderr, "AST_END,\n");
          fprintf(fileTree,"& %s",node->symbol->yytext);
          break;
    case AST_FUNC_ARGL_LIST: fprintf(stderr, "AST_FUNC_ARGL_LIST,\n");
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          break;
    case AST_FUNC_BLOCK: fprintf(stderr, "AST_FUNC_BLOCK,\n");
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          break;
    case AST_FUNC_PAR_LIST: fprintf(stderr, "AST_FUNC_PAR_LIST,\n");
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          break;
    case AST_FUNC_PAR: fprintf(stderr, "AST_FUNC_PAR,\n");
          fprintf(fileTree,",");
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          break;
    case AST_PRINT_LIST: fprintf(stderr, "AST_PRINT_LIST,\n");
          fprintf(fileTree,"print");
          astPrint(node->son[0],level,fileTree);
          //KW_PRINT lpe
          break;
    //case END_SYMBOL: fprintf(stderr, "END_SYMBOL,\n");      break;
    //case PTR_SYMBOL: fprintf(stderr, "PTR_SYMBOL,\n");

    case AST_PRINT: fprintf(stderr, "AST_PRINT,\n");
          fprintf(fileTree,"print ");
          astPrint(node->son[0],level,fileTree);
          //KW_PRINT lpe
          break;
    case AST_READ: fprintf(stderr, "AST_READ,\n");
          fprintf(fileTree,"read %s",node->symbol->yytext);
          break;
    case AST_FUNC_HEADER_FLOAT: fprintf(stderr, "AST_FUNC_HEADER_FLOAT,\n");
          fprintf(fileTree,"float %s (",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,")");
          break;
      case AST_FUNC_HEADER_CHAR: fprintf(stderr, "AST_FUNC_HEADER_CHAR,\n");
          fprintf(fileTree,"int %s (",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,")");
          break;
      case AST_FUNC_HEADER_INT: fprintf(stderr, "AST_FUNC_HEADER_INT,\n");
          fprintf(fileTree,"int %s (",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,")");
          break;
          //KW_INT TK_IDENTIFIER '(' l_func_par reset_func_par ')'
    case AST_FUNC_PAR_CHAR: fprintf(stderr, "AST_FUNC_HEADER_FLOAT,\n");
          fprintf(fileTree,"char %s ",node->symbol->yytext);
          break;
    case AST_FUNC_PAR_INT: fprintf(stderr, "AST_FUNC_PAR_INT,\n");
          fprintf(fileTree,"int %s ",node->symbol->yytext);
          //KW_INT TK_IDENTIFIER
          break;
    case AST_FUNC_PAR_FLOAT: fprintf(stderr, "AST_FUNC_PAR_FLOAT,\n");
          fprintf(fileTree,"float %s ",node->symbol->yytext);
          break;
    case AST_END_VEC_ATRIBUTION: fprintf(stderr, "AST_END_VEC_ATRIBUTION,\n");
          fprintf(fileTree,"%s = &",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,"[");
          astPrint(node->son[1],level,fileTree);
          fprintf(fileTree,"]");
          //TK_IDENTIFIER '=''&'exp'['exp']'
          break;
    case AST_VARIABLE_PTR_CHAR: fprintf(stderr, "AST_VARIABLE_PTR_CHAR,\n");
          fprintf(fileTree,"char # %s =",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          break;
    case AST_VARIABLE_PTR_INT: fprintf(stderr, "AST_VARIABLE_PTR_INT,\n");
          fprintf(fileTree,"int # %s =",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          break;
    case AST_VARIABLE_PTR_FLOAT: fprintf(stderr, "AST_VARIABLE_PTR_FLOAT,\n");
          fprintf(fileTree,"float # %s =",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          break;

    case AST_VAR_PRINT: fprintf(stderr, "AST_VAR_PRINT,\n");
          fprintf(fileTree,"%s",node->symbol->yytext);
          break;
    case AST_VAR_END: fprintf(stderr, "AST_VAR_END,\n");
          fprintf(fileTree,"&%s",node->symbol->yytext);
          break;
    case AST_VAR_PTR: fprintf(stderr, "AST_VAR_PTR,\n");
          fprintf(fileTree,"#%s",node->symbol->yytext);
          break;
      case AST_VARIABLE_DEC_INT:fprintf(stderr, "AST_VAR_INT,\n");
          fprintf(fileTree,"int %s = ",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,";");
          break;
      case AST_VARIABLE_DEC_FLOAT:fprintf(stderr, "AST_VAR_FLOAT,\n");
          fprintf(fileTree,"float %s = ",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,";");
          break;
      case AST_VARIABLE_DEC_CHAR:fprintf(stderr, "AST_VAR_CHAR,\n");
          fprintf(fileTree,"char %s = ",node->symbol->yytext);
          astPrint(node->son[0],level,fileTree);
          fprintf(fileTree,";");
          //KW_INT TK_IDENTIFIER '=' exp ';'
          break;


    default: fprintf(stderr,"UNKNOWN,\n");
  }

  for(i=0; i<MAX_SONS; i++)
    astPrint(node->son[i],level+1,fileTree);

}
