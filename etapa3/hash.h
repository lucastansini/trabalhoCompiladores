#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 997

#define DATATYPE_INT 1000
#define DATATYPE_FLOAT 1001
#define DATATYPE_CHAR 1002


typedef struct hash_node{
  int type;
  int dataType;
  char *yytext;
  int lineNumber;
  struct hash_node *next;
} HASH;

void hashInit();
int hashAddress(char *text);
HASH* hashInsert(int type, char *text);
void hashPrint(void);
//Funcao para percorrer a Hash e achar se um novo symbol já está nela.
HASH* alreadyInHash(char *text);
//Funcao para ver se existe algum simbolo não declarado na hash.
void checkUndeclared(void);

#endif
