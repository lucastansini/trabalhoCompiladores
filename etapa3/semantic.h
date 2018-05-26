#include "ast.h"


void setDeclarations(AST *node);
void checkOperands(AST *node);
void checkSemantic(AST*node);
int validVectorIndex(AST * node, AST* currentNode);
void validVectorAttribution(AST* node, AST* currentNode,int attributeIndex);
void checkAttributions(AST* node);

void checkAttParenthesis(AST *node, AST *currentNode);
int checkDecParenthesis(AST *node);
