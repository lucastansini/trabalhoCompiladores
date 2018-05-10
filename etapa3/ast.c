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



void astToFile(int level,AST *node, FILE* fileTree){
  int i = 0;

  for(i; i<level; i++)
   fprintf(stderr, "  ");
  if(!node){
    return;
  }else{
    switch(node->type){
        case SYMBOL: fprintf(stderr, "AST_SYMBOL,\n");
            fprintf(fileTree,"%s",node->symbol->yytext);
            break;
        case AST_ADD: fprintf(stderr, "AST_ADD,\n");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree," + ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_SUB: fprintf(stderr, "AST_SUB,\n");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," - ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_DEC: fprintf(stderr, "AST_DEC,\n");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_LCMD: fprintf(stderr, "AST_LCMD,\n");

            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree, ";\n");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_LCMD2: fprintf(stderr, "AST_LCMD,\n");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree, ";\n");
            astToFile(level+1,node->son[1],fileTree);
            astToFile(level+1,node->son[2],fileTree);
            break;
        case AST_VARIABLE: fprintf(stderr, "AST_VARIABLE,\n");
            fprintf(fileTree,"%s",node->symbol->yytext);
            break;
        case AST_LT: fprintf(stderr, "AST_LT,\n");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," <");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_GT: fprintf(stderr, "AST_GT,\n");   printf(">");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," > ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_LE: fprintf(stderr, "AST_LE,\n");   printf("<=");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," <= ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_GE: fprintf(stderr, "AST_GE,\n");   printf(">=");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," >= ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_EQ: fprintf(stderr, "AST_EQ,\n");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," == ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_NE: fprintf(stderr, "AST_NE,\n");   printf("!=");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," != ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_AND: fprintf(stderr, "AST_AND,\n"); printf("&&");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," && ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_OR: fprintf(stderr, "AST_OR,\n");   printf("||");
            astToFile(level+1,node->son[0], fileTree);
            fprintf(fileTree," || ");
            astToFile(level+1,node->son[1],fileTree);
            break;
        case AST_PARENTHESES: fprintf(stderr, "AST_PARENTHESES,\n");
            fprintf(fileTree,"(");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,")");
            break;
        case AST_FUNCTIONCALL: fprintf(stderr, "AST_FUNCTIONCALL,\n");
            fprintf(fileTree,"%s (",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,")");
            break;
        case AST_NOT: fprintf(stderr, "AST_NOT,\n");
            fprintf(fileTree,"!");
            astToFile(level+1,node->son[0],fileTree);
            break;
      case AST_BLOCK: fprintf(stderr, "AST_BLOCK,\n");
            fprintf(fileTree,"{\n");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"}");
            break;
      case AST_IF_THEN: fprintf(stderr, "AST_IF_THEN,\n");
            fprintf(fileTree,"if (");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,") then ");
            astToFile(level+1,node->son[1],fileTree);
            break;

      case AST_IF_THEN_ELSE: fprintf(stderr, "AST_IF_THEN_ELSE,\n");
            fprintf(fileTree,"if (");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,") then ");
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,"else");
            astToFile(level+1,node->son[2],fileTree);
            break;

      case AST_FOR_TO: fprintf(stderr, "AST_FOR_TO,\n");
            fprintf(fileTree,"for(");
            fprintf(fileTree,"%s",node->symbol->yytext);
            fprintf(fileTree," = ");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree," to ");
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,")");
            astToFile(level+1,node->son[2],fileTree);
            break;
      case AST_VARIABLE_VEC_1_INT: fprintf(stderr, "AST_VARIABLE_VEC_1_INT,\n");
            fprintf(fileTree,"int %s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"]:");
            astToFile(level+1,node->son[1],fileTree);
            astToFile(level+1,node->son[2],fileTree);
              fprintf(fileTree,";\n");
            break;
      case AST_WHILE:
            fprintf(stderr,"AST_WHILE\n");
            fprintf(fileTree,"while (");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,")");
            astToFile(level+1,node->son[1],fileTree);
            break;
            //(AST_WHILE, 0, $3, $5, 0, 0)

      case AST_VARIABLE_VEC_1_FLOAT: fprintf(stderr, "AST_VARIABLE_VEC_1_FLOAT,\n");
            fprintf(fileTree,"float %s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"]:");
            astToFile(level+1,node->son[1],fileTree);
            astToFile(level+1,node->son[2],fileTree);
              fprintf(fileTree,";\n");
            break;

      case AST_VARIABLE_VEC_1_CHAR: fprintf(stderr, "AST_VARIABLE_VEC_1_CHAR,\n");
            fprintf(fileTree,"char %s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"]:");
            astToFile(level+1,node->son[1],fileTree);
            astToFile(level+1,node->son[2],fileTree);
            fprintf(fileTree,";\n");
            break;
      case AST_VARIABLE_VEC_2_INT: fprintf(stderr, "AST_VARIABLE_VEC_2_INT,\n");
            fprintf(fileTree,"int %s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"];\n");
            break;
      case AST_VARIABLE_VEC_2_FLOAT: fprintf(stderr, "AST_VARIABLE_VEC_2_FLOAT,\n");
            fprintf(fileTree,"float %s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"];\n");

            break;
      case AST_VARIABLE_VEC_2_CHAR: fprintf(stderr, "AST_VARIABLE_VEC_2_CHAR,\n");
            fprintf(fileTree,"char %s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"];\n");
            break;
      case AST_FUNC_RESET: fprintf(stderr, "AST_FUNC_RESET,\n");
            fprintf(fileTree,",");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            break;
      case AST_ATRIBUTION: fprintf(stderr, "AST_ATRIBUTION,\n");
            fprintf(fileTree,"%s =",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            //TK_IDENTIFIER '=' exp
            break;
      case AST_TO_PTR_ATRIBUTION: fprintf(stderr, "AST_TO_PTR_ATRIBUTION,\n");
            fprintf(fileTree,"#%s =",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            break;
      case AST_TO_END_ATRIBUTION: fprintf(stderr, "AST_TO_END_ATRIBUTION,\n");
            fprintf(fileTree,"& %s =",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);

            break;
      case AST_PTR_ATRIBUTION: fprintf(stderr, "AST_PTR_ATRIBUTION,\n");
            fprintf(fileTree,"%s = #",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);

            break;
      case AST_END_ATRIBUTION: fprintf(stderr, "AST_END_ATRIBUTION,\n");
            fprintf(fileTree,"%s = &",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            break;
      case AST_VEC_ATRIBUTION: fprintf(stderr, "AST_VEC_ATRIBUTION,\n");
            fprintf(fileTree,"%s [",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf (fileTree,"] = ");
            astToFile(level+1,node->son[1],fileTree);
            //TK_IDENTIFIER'['exp']' '=' exp
            break;
      case AST_TO_PTR_VEC_ATRIBUTION: fprintf(stderr, "AST_TO_PTR_VEC_ATRIBUTION,\n");
            fprintf(fileTree,"# %s [ ",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"]");
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,"=");
            break;
      case AST_TO_END_VEC_ATRIBUTION: fprintf(stderr, "AST_TO_END_VEC_ATRIBUTION,\n");
            fprintf(fileTree,"& %s [ ",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"]");
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,"=");

            //'&'TK_IDENTIFIER'['exp']' '='exp
            break;
      case AST_PTR_VEC_ATRIBUTION: fprintf(stderr, "AST_PTR_VEC_ATRIBUTION,\n");
            fprintf(fileTree,"%s = #",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"[");
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,"]");
            //TK_IDENTIFIER '=''#'exp '['exp']'
            break;
      case AST_RETURN: fprintf(stderr, "AST_RETURN,\n");
            fprintf(fileTree,"return ");
            astToFile(level+1,node->son[0],fileTree);
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
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"]");
            //TK_IDENTIFIER'['exp']'
            break;

      case AST_MULT: fprintf(stderr, "AST_MULT,\n");
             astToFile(level+1,node->son[0],fileTree);
              fprintf(fileTree,"*");
            astToFile(level+1,node->son[1],fileTree);

            break;
      case AST_DIV: fprintf(stderr, "AST_DIV,\n");
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"/");
            astToFile(level+1,node->son[1],fileTree);
            break;
      case AST_PTR: fprintf(stderr, "AST_END,\n");
            fprintf(fileTree,"# %s",node->symbol->yytext);
            break;
      case AST_END: fprintf(stderr, "AST_END,\n");
            fprintf(fileTree,"& %s",node->symbol->yytext);
            break;
      case AST_FUNC_ARGL_LIST: fprintf(stderr, "AST_FUNC_ARGL_LIST,\n");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            break;
      case AST_FUNC_BLOCK: fprintf(stderr, "AST_FUNC_BLOCK,\n");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            break;
      case AST_FUNC_PAR_LIST: fprintf(stderr, "AST_FUNC_PAR_LIST,\n");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            break;
      case AST_FUNC_PAR: fprintf(stderr, "AST_FUNC_PAR,\n");
            fprintf(fileTree,",");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            break;
      case AST_PRINT_LIST: fprintf(stderr, "AST_PRINT_LIST,\n");
            fprintf(fileTree,"print ");
            astToFile(level+1,node->son[0],fileTree);
            //KW_PRINT lpe
            break;

      case AST_PRINT: fprintf(stderr, "AST_PRINT,\n");

            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            //KW_PRINT lpe
            break;
      case AST_READ: fprintf(stderr, "AST_READ,\n");
            fprintf(fileTree,"read %s",node->symbol->yytext);
            break;
      case AST_FUNC_HEADER_FLOAT: fprintf(stderr, "AST_FUNC_HEADER_FLOAT,\n");
            fprintf(fileTree,"float %s (",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,")");
            break;
        case AST_FUNC_HEADER_CHAR: fprintf(stderr, "AST_FUNC_HEADER_CHAR,\n");
            fprintf(fileTree,"int %s (",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,")");
            break;
        case AST_FUNC_HEADER_INT: fprintf(stderr, "AST_FUNC_HEADER_INT,\n");
            fprintf(fileTree,"int %s (",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,")");
            break;
            //KW_INT TK_IDENTIFIER '(' l_func_par reset_func_par ')'
      case AST_FUNC_PAR_CHAR: fprintf(stderr, "AST_FUNC_HEADER_CHAR,\n");
            fprintf(fileTree,"char %s ",node->symbol->yytext);
            break;
      case AST_FUNC_PAR_INT: fprintf(stderr, "AST_FUNC_PAR_INT,\n");
            fprintf(fileTree,"int %s ",node->symbol->yytext);
            //KW_INT TK_IDENTIFIER
            break;
      case AST_FUNC_PAR_FLOAT: fprintf(stderr, "AST_F  astToFile(level+1,node->son[0],fileTree);UNC_PAR_FLOAT,\n");
            fprintf(fileTree,"float %s ",node->symbol->yytext);
            break;
      case AST_END_VEC_ATRIBUTION: fprintf(stderr, "AST_END_VEC_ATRIBUTION,\n");
            fprintf(fileTree,"%s = &",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,"[");
            astToFile(level+1,node->son[1],fileTree);
            fprintf(fileTree,"]");
            //TK_IDENTIFIER '=''&'exp'['exp']'
            break;
      case AST_VARIABLE_PTR_CHAR: fprintf(stderr, "AST_VARIABLE_PTR_CHAR,\n");
            fprintf(fileTree,"char # %s =",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree, ";\n");

            break;
      case AST_VARIABLE_PTR_INT: fprintf(stderr, "AST_VARIABLE_PTR_INT,\n");
            fprintf(fileTree,"int # %s =",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree, ";\n");
            break;
      case AST_VARIABLE_PTR_FLOAT: fprintf(stderr, "AST_VARIABLE_PTR_FLOAT,\n");
            fprintf(fileTree,"float # %s =",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree, ";\n");
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
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,";\n");
            break;
        case AST_VARIABLE_DEC_FLOAT:fprintf(stderr, "AST_VAR_FLOAT,\n");
            fprintf(fileTree,"float %s = ",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,";\n");
            break;
        case AST_VARIABLE_DEC_CHAR:fprintf(stderr, "AST_VAR_CHAR,\n");
            fprintf(fileTree,"char %s = ",node->symbol->yytext);
            astToFile(level+1,node->son[0],fileTree);
            fprintf(fileTree,";\n");
            //KW_INT TK_IDENTIFIER '=' exp ';'
            break;

        case AST_VET_LIST:fprintf(stderr, "AST_VET_LIST,\n");
            astToFile(level+1,node->son[0],fileTree);
            astToFile(level+1,node->son[1],fileTree);
            //KW_INT TK_IDENTIFIER '=' exp ';'
            break;

      default: fprintf(stderr,"UNKNOWN,\n");

  }
}
}
