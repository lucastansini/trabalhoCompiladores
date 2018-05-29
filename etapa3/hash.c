#include "hash.h"
#include "semanticsymbols.h"

HASH* table[HASH_SIZE];

int semanticError = 0;


/*Inicialização da hash table com zero em todas posições*/
void hashInit(void){
  int i = 0;
  for(i = 0 ; i<HASH_SIZE ; i++){
    table[i] = 0;
  }
}

HASH *makeLabel(){
  static int serialNumber = 0;
  static char buffer[64];

  fprintf(buffer,"_LabelLuyka634%d",serialNumber++);
  return hashInsert(SYMBOL_LABEL,buffer);
}

HASH* makeTemp(){
  static int serialNumber = 0;
  static char buffer[64];

  fprintf(stderr,"_TempLUka631%d",serialNumber++);
  return hashInsert(SYMBOL_SCALAR,buffer);
}


void checkUndeclared(void){
  HASH* aux;

  int i = 0;
  for(i = 0 ; i<HASH_SIZE; i++){
    for(aux = table[i]; aux ; aux=aux->next){
      if(aux->type == SYMBOL_IDENTIFIER){
        fprintf(stderr,"Symbol %s is undeclared at line %d.\n",aux->yytext, getLineNumber());
        semanticError = 1;
      }
    }
  }

}

/*Cálculo do endereço do elemento hash*/
int hashAddress(char *text){
  int address = 1;
  int i=0;
  for(i = 0; i<strlen(yytext) ; i++){
    address = (address*text[i])%HASH_SIZE + 1;
  }
  return address-1;
}

//Acha se já tem na HASH
HASH* alreadyInHash(char *text){
  int endereco = hashAddress(text);
  HASH* aux;
  //percorrer toda hash até achar
  for(aux = table[endereco] ; aux ; aux = aux->next){
    if(!strcmp(text,aux->yytext)){
      return aux;
    }
  }
  return 0;
}

/*Inserção de um elemento na HASH*/
HASH* hashInsert(int type, char *text){

  int address;
  HASH* newNode = 0;

  if(newNode = alreadyInHash(text)){
    return newNode;
  }

  newNode = (HASH*) calloc(1,sizeof(HASH));
  address = hashAddress(text);
  newNode->type = type;
  newNode->yytext = calloc(strlen(yytext)+1,sizeof(char));
  strcpy(newNode->yytext,text);
  newNode->next = table[address];
  table[address] = newNode;
  //Se for declaração de variável
  if(newNode->type == SYMBOL_IDENTIFIER){
    newNode->lineNumber = getLineNumber();
    //printf("LINE OF THE SYMBOL %s and type %d is %d\n",newNode->yytext,newNode->type,newNode->lineNumber);
  }
  return newNode;

}


/*Print de toda hashtable*/
void hashPrint(){
  HASH* print_node;

  int i = 0;
  for(i = 0 ; i<HASH_SIZE; i++){
    for(print_node = table[i]; print_node ; print_node=print_node->next){
      switch(print_node->type){
          case SYMBOL_IDENTIFIER:
              printf("HashTable[%d] contains %s and is TK_IDENTIFIER\n",i,print_node->yytext);
              break;
          case LIT_CHAR:
            printf("HashTable[%d] contains %s and is LIT_CHAR\n",i,print_node->yytext);
            break;
          case LIT_STRING:
            printf("HashTable[%d] contains %s and is LIT_STRING\n",i,print_node->yytext);
            break;
          case LIT_REAL:
            printf("HashTable[%d] contains %s and is LIT_REAL\n",i,print_node->yytext);
            break;
          case LIT_INTEGER:
            printf("HashTable[%d] contains %s and is LIT_INTEGER\n",i,print_node->yytext);
            break;
          default:
            printf("Not identified!");
      }

    }
  }

}
