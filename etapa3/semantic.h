#include "ast.h"


void setDeclarations(AST *node);
void checkOperands(AST *node);
void checkSemantic(AST*node);
int validVectorIndex(AST * node, AST* currentNode);
