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








int checkDecParenthesis(AST*node){

  if(!node){
    return;
  }

  if(node->son[0]->type == AST_PARENTHESES){
    checkDecParenthesis(node->son[0]);
  }else{
    if(node->son[0]->type == SYMBOL){
      if(node->son[0]->symbol->type == SYMBOL_INTEGER){
        return DATATYPE_INT;
      }
      if(node->son[0]->symbol->type == SYMBOL_REAL){
        return DATATYPE_FLOAT;
      }
    }
      if(node->son[0]->type ==  AST_VARIABLE){
        return node->son[0]->symbol->dataType;
      }
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
      if(node->son[0]->type == SYMBOL){
        if(node->son[0]->symbol->type == SYMBOL_INTEGER)
          node->symbol->dataType = DATATYPE_INT;
        if(node->son[0]->symbol->type == SYMBOL_REAL){
          node->symbol->dataType = DATATYPE_FLOAT;
        }
      }
        if(node->son[0]->type ==  AST_VARIABLE){
          node->symbol->dataType = node->son[0]->symbol->dataType;
        }

        if(node->son[0]->type == AST_ADD){

        }

        if(node->son[0]->type == AST_PARENTHESES){
          node->symbol->dataType = checkDecParenthesis(node->son[0]);
        }
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


  //Se for declaração de variavel INT
  if(node->type == AST_VARIABLE_DEC_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_REAL;
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

  //Pronto //TODO Verificiar se pode char!
  //|KW_INT TK_IDENTIFIER'['exp']'':' vet_dec ';'$$ = astCreate(AST_VARIABLE_VEC_1_INT,$2,$4,$7,0,0);}
  if(node->type == AST_VARIABLE_VEC_1_INT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_VET_INT;
      node->symbol->dataType = DATATYPE_INT;
      //Se o index do vetor for válido
      validVectorIndex(node->son[0],node);
      validVectorAttribution(node->son[1],node,1);
    }
  }

  //Aqui a princípio está pronto.
  //|KW_INT TK_IDENTIFIER'['exp']' ';'  {$$ = astCreate(AST_VARIABLE_VEC_2_INT,$2,$4,0,0,0);}
  if(node->type == AST_VARIABLE_VEC_2_INT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_VET_INT;
      node->symbol->dataType = DATATYPE_INT;
      validVectorIndex(node->son[0],node);
    }
  }




  //|KW_FLOAT TK_IDENTIFIER'['exp']' ';'{$$ = astCreate(AST_VARIABLE_VEC_2_FLOAT,$2,$4,0,0,0);}
  if(node->type == AST_VARIABLE_VEC_2_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_VET_FLOAT;
      node->symbol->dataType = DATATYPE_FLOAT;
      //Se o index do vetor for válido
      validVectorIndex(node->son[0],node);
    }
  }

  if(node->type == AST_VARIABLE_VEC_1_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_VET_FLOAT;
      node->symbol->dataType = DATATYPE_FLOAT;
      //Se o index do vetor for válido
      validVectorIndex(node->son[0],node);
      validVectorAttribution(node->son[1],node,1);
    }
  }


  //|KW_CHAR TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_CHAR,$2,$4,$7,0,0);}
  if(node->type == AST_VARIABLE_VEC_1_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_VET_CHAR;
      node->symbol->dataType = DATATYPE_CHAR;
      validVectorIndex(node->son[0],node);
      validVectorAttribution(node->son[1],node,1);
    }
  }


  //|KW_CHAR TK_IDENTIFIER'['exp']' ';'{$$ = astCreate(AST_VARIABLE_VEC_2_CHAR,$2,$4,0,0,0);}
  if(node->type == AST_VARIABLE_VEC_2_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_VET_CHAR;
      node->symbol->dataType = DATATYPE_CHAR;
      validVectorIndex(node->son[0],node);
    }
  }


  if(node->type == AST_FUNC_HEADER_INT ){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_INT;
      node->symbol->dataType = DATATYPE_INT;
    }
  }


  if(node->type == AST_FUNC_HEADER_CHAR ){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_CHAR;
      node->symbol->dataType = DATATYPE_CHAR;
    }
  }



  if(node->type == AST_VARIABLE_PTR_INT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_INT_PTR;
      node->symbol->dataType = DATATYPE_INT;
    }
  }

  if(node->type == AST_VARIABLE_PTR_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_CHAR_PTR;
      node->symbol->dataType = DATATYPE_CHAR;
    }
  }

  if(node->type == AST_VARIABLE_PTR_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FLOAT_PTR;
      node->symbol->dataType = DATATYPE_FLOAT;
    }
  }



  if(node->type == AST_FUNC_HEADER_FLOAT ){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_FLOAT;
      node->symbol->dataType = DATATYPE_FLOAT;
    }
  }

  if(node->type == AST_FUNC_PAR_INT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_PAR_INT;
      node->symbol->dataType = DATATYPE_INT;
    }
  }

  if(node->type == AST_FUNC_PAR_FLOAT){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_PAR_FLOAT;
      node->symbol->dataType = DATATYPE_FLOAT;
    }
  }

  if(node->type == AST_FUNC_PAR_CHAR){
    if(node->symbol->type != SYMBOL_IDENTIFIER){
      fprintf(stderr,"Semantic error: Symbol %s was previously declared at line: %d.\n", node->symbol->yytext,node->symbol->lineNumber);
      semanticError = 1;
    }else{
      node->symbol->type = SYMBOL_FUNC_PAR_CHAR;
      node->symbol->dataType = DATATYPE_CHAR;
    }
  }


  //TODO VERIFICAR AS ATRIBUIÇÕES COM ADD, SUB, MULT, ETC.

  //Percorrer todos filhos e declarar.
  for (i = 0; i < MAX_SONS; i++){
    setDeclarations(node->son[i]);
  }



}

//vet_dec: lit vet_dec {$$ =astCreate(AST_VET_LIST, 0,$1,  $2, 0, 0); }
//Son 0 is always the lit and son 1 ->CAN<- be the next list.
void validVectorAttribution(AST* node, AST*currentNode,int attributeIndex){
  // printf("CURRENT NODE TYPE IS:%d\n",node->type);
  int i;



  //See what vector we are handling, char,float or int.
  switch(currentNode->symbol->dataType){
    case DATATYPE_INT:
    //Handles the LIT attribution
    if(node->symbol){
      if(node->symbol->type != SYMBOL_INTEGER){
        fprintf(stderr,"Invalid type for vector attribution declaration in index %d at line %d.\n",attributeIndex,currentNode->symbol->lineNumber);
        fprintf(stderr,"Expected type was int.\n");
        exit(4);
      }
    }else{
      validVectorAttribution(node->son[0],currentNode,attributeIndex);
      validVectorAttribution(node->son[1],currentNode,attributeIndex+1);
    }
    break;
    case DATATYPE_FLOAT:
    //Handles the LIT attribution
    if(node->symbol){
      if(node->symbol->type != SYMBOL_REAL){
        fprintf(stderr,"Invalid type for vector attribution declaration in index %d at line %d.\n",attributeIndex,currentNode->symbol->lineNumber);
        fprintf(stderr,"Expected type was float.\n");
        exit(4);
      }
    }else{
      validVectorAttribution(node->son[0],currentNode,attributeIndex);
      validVectorAttribution(node->son[1],currentNode,attributeIndex+1);
    }
    break;
    case DATATYPE_CHAR:
    //Handles the LIT attribution
    if(node->symbol){
      // printf("SYMBOL TYPE%d\n",node->symbol->type);
      // printf("SYMBOL YYTEXT%s\n",node->symbol->yytext);
      if(node->symbol->type != SYMBOL_CHAR){
        fprintf(stderr,"Invalid type for vector attribution declaration in index %d at line %d.\n",attributeIndex,currentNode->symbol->lineNumber);
        fprintf(stderr,"Expected type was char.\n");
        exit(4);
      }
    }else{
      validVectorAttribution(node->son[0],currentNode,attributeIndex);
      validVectorAttribution(node->son[1],currentNode,attributeIndex+1);
    }
    break;
  }



}


int validVectorIndex(AST* node,AST * currentNode){
  if(node->symbol){
    if(node->symbol->type != SYMBOL_INTEGER){
      fprintf(stderr,"Invalid vector index at line %d, expected int.\n",currentNode->symbol->lineNumber);
      exit(4);
    }
  }else{
    if(node->type == AST_ADD || node->type == AST_SUB){
      validVectorIndex(node->son[0],currentNode);
      validVectorIndex(node->son[1],currentNode);
      return 1;
    }
  }

  return 1;
}



void checkOperands(AST *node){

    int i;
    if(!node){
      return;
    }
    for(i =0;i<MAX_SONS;i++){
        checkOperands(node->son[i]);
    }



    if(node->type == AST_VARIABLE_DEC_INT){
      //printf("NODE SYMBOL DATATYPE %d /// NODE SON0 SYMBOL DATATYPE %d\n",node->symbol->dataType,node->son[0]->symbol->dataType);

      if(node->son[0]->type == AST_PARENTHESES){
        int findDatatypeOfExp = checkDecParenthesis(node->son[0]);
        if( findDatatypeOfExp != DATATYPE_INT){
          fprintf(stderr,"Symbol %s at Line %d has invalid type operand. Expected type int and was ",node->symbol->yytext, node->symbol->lineNumber);
          switch(findDatatypeOfExp){
            case DATATYPE_CHAR:
              fprintf(stderr, "char.\n");
              break;
            case DATATYPE_FLOAT:
              fprintf(stderr, "float.\n");
              break;
          }
          exit(4);
        }
      }else{
        if(node->son[0]->symbol->dataType != DATATYPE_INT){
          fprintf(stderr,"Symbol %s at Line %d has invalid type operand. Expected type int and was ",node->symbol->yytext, node->symbol->lineNumber);
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
    }

    if(node->type == AST_VARIABLE_DEC_CHAR){
      if(node->son[0]->symbol->dataType != DATATYPE_CHAR){
        fprintf(stderr,"Symbol %s at Line %d has invalid type operand. Expected type char and was ",node->symbol->yytext, node->symbol->lineNumber);
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

    if(node->type == AST_VARIABLE_DEC_FLOAT){
      if(node->son[0]->symbol->dataType != DATATYPE_FLOAT){
        fprintf(stderr,"Symbol %s at Line %d has invalid type operand. Expected type float and was ",node->symbol->yytext, node->symbol->lineNumber);
        switch(node->son[0]->symbol->dataType){
          case DATATYPE_INT:
            fprintf(stderr, "int.\n");
            break;
          case DATATYPE_CHAR:
            fprintf(stderr, "char.\n");
            break;
        }
        exit(4);
      }
    }




}

void checkAttributions(AST* node){

  if (!node){
    return;
  }
  int i;

  // if(node->type == AST_PARENTHESES){
  //   printf("PARENTESIS!\n");
  //   exit(4);
  // }


  if(node->type == AST_ATRIBUTION){
    //printf("AST_ATT DATATYPE = %d\n",node->symbol->dataType);
    //printf("AST_SON0 DATATYPE = %d\n",node->son[0]->symbol->dataType);
    if(node->son[0]->type == AST_PARENTHESES){
      checkAttParenthesis(node->son[0],node);
      return;
    }
    if(node->symbol->dataType != node->son[0]->symbol->dataType){
      fprintf(stderr,"Symbol %s recieved attribution of type ",node->symbol->yytext);
      switch(node->son[0]->symbol->dataType){
        case DATATYPE_INT:
          fprintf(stderr,"int");
        break;
        case DATATYPE_CHAR:
          fprintf(stderr,"char");
        break;
        case DATATYPE_FLOAT:
          fprintf(stderr,"float");
        break;
      }
      fprintf(stderr,". Expected ");
      switch(node->symbol->dataType){
        case DATATYPE_INT:
          fprintf(stderr,"int.");
        break;
        case DATATYPE_CHAR:
          fprintf(stderr,"char.");
        break;
        case DATATYPE_FLOAT:
          fprintf(stderr,"float.");
        break;
      }
      fprintf(stderr,"\n");
      exit(4);
    }
  }


  for(i=0; i< MAX_SONS; i++){
    checkAttributions(node->son[i]);
  }


}

void checkAttParenthesis(AST*node,AST*fatherNode){

  if(!node){
    return;
  }

  //If there are other
  if(node->son[0]->type == AST_PARENTHESES){
    checkAttParenthesis(node->son[0],fatherNode);
  }else{
    if(node->type == AST_ATRIBUTION){
      //PRECISA CHECAR SE FOR + - ETC
      if(fatherNode->symbol->dataType != node->son[0]->symbol->dataType){
        fprintf(stderr,"Symbol %s recieved attribution of type ",fatherNode->symbol->yytext);
        switch(node->son[0]->symbol->dataType){
          case DATATYPE_INT:
            fprintf(stderr,"int");
          break;
          case DATATYPE_CHAR:
            fprintf(stderr,"char");
          break;
          case DATATYPE_FLOAT:
            fprintf(stderr,"float");
          break;
        }
        fprintf(stderr,". Expected ");
        switch(fatherNode->symbol->dataType){
          case DATATYPE_INT:
            fprintf(stderr,"int.");
          break;
          case DATATYPE_CHAR:
            fprintf(stderr,"char.");
          break;
          case DATATYPE_FLOAT:
            fprintf(stderr,"float.");
          break;
        }
        fprintf(stderr,"\n");
        exit(4);
      }
    }
  }

}

//void checkUndeclared(void);
