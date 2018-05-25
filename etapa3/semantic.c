#include "semantic.h"
#include "semanticsymbols.h"
//Se debug for definido como 1, printa todos os debugs
#define DEBUG 0

extern semanticError;



void checkSemantic(AST* node){
  int i;
  AST *node_vec_list = NULL;

  if(!node){
    return;
  }

  for(i=0; i<MAX_SONS; i++){
    checkSemantic(node->son[i]);
  }

  switch(node->type){
    //|KW_INT TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_INT,$2,$4,$7,0,0);}
   /* case AST_VARIABLE_VEC_1_INT:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT);
        fprintf(stderr, "Vector size must be an integer\n");

    break;
    case AST_VARIABLE_VEC_2_INT:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT);
        fprintf(stderr, "Vector size must be an integer\n");

    break;
    case AST_VARIABLE_VEC_1_FLOAT:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT);
        fprintf(stderr, "Vector size must be an integer\n");

    break;
    case AST_VARIABLE_VEC_2_FLOAT:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT);
        fprintf(stderr, "Vector size must be an integer\n");

    break;
    case AST_VARIABLE_VEC_1_CHAR:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT);
        fprintf(stderr, "Vector size must be an integer\n");

    break;
    case AST_VARIABLE_VEC_2_CHAR:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT);
        fprintf(stderr, "Vector size must be an integer\n");

    break;
    case AST_VARIABLE_DEC_INT:
      if(node->son[0]->symbol->type != SYMBOL_LIT_INT){
        fprintf(stderr, "Variable and operand type doesn't match\n");
      }
    break;
    case AST_VARIABLE_DEC_FLOAT:

      if(node->son[0]->symbol->type != SYMBOL_LIT_REAL){
        fprintf(stderr, "Variable and operand type doesn't match\n");
      }
    break;*/
  }


}









void setDeclarations(AST *node){

  int i;
  //Caso nodo seja nulo.
  if(!node){
    return;
  }


  //Se for declaração de variavel INT
  if(node->type == AST_VARIABLE_DEC_INT){
    //|KW_INT TK_IDENTIFIER '=' exp ';' {$$ = astCreate(AST_VARIABLE_DEC_INT,$2,$4,0,0,0);}
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_INTEGER;
      //printf("\nSON0  TYPE = %d\n",node->son[0]->type);
      //printf("\nSON0 SYMBOL YYTEXT = %s\n",node->son[0]->symbol->yytext);
      //printf("\nSON0 SYMBOL TYPE = %d\n",node->son[0]->symbol->type);
      if(node->son[0]->type == SYMBOL){
        if(node->son[0]->symbol->type == SYMBOL_INTEGER)
          node->symbol->dataType = DATATYPE_INT;
        if(node->son[0]->symbol->type == SYMBOL_REAL){
          node->symbol->dataType = DATATYPE_FLOAT;
          printf("DATATYPE = %d\n",  node->symbol->dataType);
        }
      }
      if(node->son[0]->type ==  AST_VARIABLE){
        node->symbol->dataType = node->son[0]->symbol->dataType;
      }
      //printf("SYMBOL %s HAS TYPE '%d' AND DATATYPE '%d'\n",node->symbol->yytext,node->type,node->symbol->dataType);
    }
  }

  //Se for declaração de variavel INT
  if(node->type == AST_VARIABLE_DEC_CHAR){

    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_CHAR;
      if(node->son[0]->type == SYMBOL){
        if(node->son[0]->symbol->type == SYMBOL_INTEGER)
          node->symbol->dataType = DATATYPE_INT;
        if(node->son[0]->symbol->type == SYMBOL_REAL)
          node->symbol->dataType = DATATYPE_FLOAT;
        if(node->son[0]->symbol->type == SYMBOL_CHAR)
          node->symbol->dataType = DATATYPE_CHAR;
      }
      if(node->son[0]->type ==  AST_VARIABLE){
        node->symbol->dataType = node->son[0]->symbol->dataType;
      }
      //printf("SYMBOL %s HAS TYPE '%d' AND DATATYPE '%d'\n",node->symbol->yytext,node->type,node->symbol->dataType);
    }
  }



  if(node->type == SYMBOL){
    switch(node->symbol->type){
      case SYMBOL_INTEGER:
        node->symbol->dataType = DATATYPE_INT;
        break;
      case SYMBOL_CHAR:
        node->symbol->dataType = DATATYPE_CHAR;
        break;
      case SYMBOL_REAL:
        node->symbol->dataType = DATATYPE_FLOAT;
        break;
    }
  }


/*
  if(node->type == AST_VARIABLE_DEC_FLOAT){
    if(DEBUG)
      fprintf(stderr,"ANTES:%d\n",node->symbol->type);
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      if(DEBUG)
        printf("Symbol:%s\n",node->symbol->yytext);
      node->symbol->type = SYMBOL_REAL;
      if(DEBUG)
        printf("DEPOIS:%d\n",node->symbol->type);
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
    }
  }

  //Para os dois tipos de declaração de vetor
  if(node->type == AST_VARIABLE_VEC_1_INT || node->type == AST_VARIABLE_VEC_2_INT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_INTEGER;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
    }
  }

  if(node->type == AST_VARIABLE_VEC_2_FLOAT || node->type == AST_VARIABLE_VEC_1_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_REAL;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
    }
  }

  if(node->type == AST_VARIABLE_DEC_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_CHAR;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
      if(node->son[0]->type == SYMBOL_CHAR)
        node->symbol->dataType =  DATATYPE_CHAR;
    }
  }

  if(node->type == AST_VARIABLE_VEC_1_CHAR || node->type == AST_VARIABLE_VEC_2_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_CHAR;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
      if(node->son[0]->type == SYMBOL_CHAR)
        node->symbol->dataType =  DATATYPE_CHAR;
    }
  }

  if(node->type == AST_VARIABLE_PTR_INT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_INT_PTR;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
      if(node->son[0]->type == SYMBOL_CHAR)
        node->symbol->dataType =  DATATYPE_CHAR;
    }
  }

  if(node->type == AST_VARIABLE_PTR_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_CHAR_PTR;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType = DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType =  DATATYPE_FLOAT;
      if(node->son[0]->type == SYMBOL_CHAR)
        node->symbol->dataType =  DATATYPE_CHAR;
    }
  }

  if(node->type == AST_VARIABLE_PTR_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FLOAT_PTR;
      if(node->son[0]->type == SYMBOL_INTEGER)
        node->symbol->dataType == DATATYPE_INT;
      if(node->son[0]->type == SYMBOL_REAL)
        node->symbol->dataType ==  DATATYPE_FLOAT;
      if(node->son[0]->type == SYMBOL_CHAR)
        node->symbol->dataType ==  DATATYPE_CHAR;
    }
  }

  if(node->type == AST_FUNC_HEADER_INT ){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_INT;
    }
  }

  if(node->type == AST_FUNC_HEADER_CHAR ){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_CHAR;
    }
  }

  if(node->type == AST_FUNC_HEADER_FLOAT ){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_FLOAT;
    }
  }
  if(node->type == AST_INT || node->type == AST_CHAR){
    node->symbol->type = SYMBOL_LIT_INT;
  }
  if(node->type == AST_FLOAT){
    node->symbol->type = SYMBOL_LIT_REAL;
  }
  if(node->type == AST_FUNC_PAR_INT || node->type == AST_FUNC_PAR_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_PAR_INT;
    }
  }
  if(node->type == AST_FUNC_PAR_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_PAR_FLOAT;
    }
  }*/
  //Percorrer todos filhos e declarar.
  for (i = 0; i < MAX_SONS; i++){
    setDeclarations(node->son[i]);
  }



}
void checkOperands(AST *node){
    // int i;
    // if(!node) return;
    // for(i =0;i<MAX_SONS;i++){
    //     checkOperands(node->son[i]);
    // }
    // if(node->type == AST_ADD ||
    //    node->type == AST_SUB ||
    //    node->type == AST_MULT ||
    //    node->type == AST_DIV)
    //     if(node->son[0]->type == AST_ADD ||
    //        node->son[0]->type == AST_SUB ||
    //        node->son[0]->type == AST_MULT ||
    //        node ->son[0]->type == AST_DIV||
    //        (node->son[0]->type == SYMBOL &&
    //         node ->son[0]->symbol == SYMBOL_INTEGER   ||
    //         node->son[0]->symbol == SYMBOL_REAL ||
    //           node ->son[0]->symbol ==  SYMBOL_LIT_REAL ||
    //           node ->son[0]->symbol == SYMBOL_LIT_INT )
    //         && node->son[1]->type == AST_ADD ||
    //         node ->son[1]->type == AST_SUB ||
    //         node ->son[1]->type == AST_MULT ||
    //         node ->son[1]->type == AST_DIV ||
    //         (node->son[1]->type == SYMBOL &&
    //         node ->son[1]->symbol == SYMBOL_INTEGER   ||
    //          node->son[1]->symbol == SYMBOL_REAL ||
    //         node ->son[1]->symbol ==  SYMBOL_LIT_REAL ||
    //          node ->son[1]->symbol == SYMBOL_LIT_INT )){}
    //
    // else fprintf(stderr, "Semantic Error: Invalid operand\n",node->symbol->yytext);
    //
    //
    //

    int i;
    if(!node) return;
    for(i =0;i<MAX_SONS;i++){
        checkOperands(node->son[i]);
    }

    if(node->type == AST_VARIABLE_DEC_INT){
      //printf("NODE SYMBOL DATATYPE %d /// NODE SON0 SYMBOL DATATYPE %d\n",node->symbol->dataType,node->son[0]->symbol->dataType);
      if(node->son[0]->symbol->dataType != DATATYPE_INT){
        fprintf(stderr,"Symbol %s has invalid type operand. Expected type int and was ",node->symbol->yytext);
        switch(node->son[0]->symbol->dataType){
          case DATATYPE_CHAR:
            fprintf(stderr, "char.\n");
            break;
          case DATATYPE_FLOAT:
            fprintf(stderr, "float.\n");
            break;
        }
        exit(4);
      }
    }

    if(node->type == AST_VARIABLE_DEC_CHAR){
      if(node->son[0]->symbol->dataType != DATATYPE_CHAR){
        fprintf(stderr,"Symbol %s has invalid type operand. Expected type char and was ",node->symbol->yytext);
        switch(node->son[0]->symbol->dataType){
          case DATATYPE_INT:
            fprintf(stderr, "int.\n");
            break;
          case DATATYPE_FLOAT:
            fprintf(stderr, "float.\n");
            break;
        }
        exit(4);
      }
    }
}

//void checkUndeclared(void);
