%{

#include<stdio.h>
#include<stdlib.h>
#include "scanner.h"
#include "hash.h"
#include "astree.h"



extern FILE *yyin;
%}

%union
{
    struct hash_node *symbol;
    struct s_astree *astree;
}

%type<astree> program
%type<astree> decl
%type<astree> dec
%type<astree> decvar
%type<astree> decvetor
%type<astree> decfunction
%type<astree> decpointer
%type<astree> decv
%type<astree> typevar
%type<astree> literal
%type<astree> paramlist
%type<astree> rest
%type<astree> cmd
%type<astree> body
%type<astree> lcmd
%type<astree> attribution
%type<astree> flux_control
%type<astree> inout
%type<astree> exp
%type<astree> print_elem


%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_TO
%token KW_READ
%token KW_RETURN
%token KW_PRINT

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR

%left ','
%left '='
%left OPERATOR_AND OPERATOR_OR
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'
%nonassoc '(' ')'

%%

program: decl {$$ = $1; astreePrint($1); root = $$;}
;

decl: dec decl    {$$ = astreeCreate(AST_DECLARACAO, 0, $1, $2, 0, 0);}
| {$$ = 0;}
;

dec: decvar       {$$ = astreeCreate(AST_DECLARACAO, 0, $1, 0, 0, 0);}
| decvetor        {$$ = astreeCreate(AST_DECLARACAO, 0, $1, 0, 0, 0);}
| decfunction     {$$ = astreeCreate(AST_DECLARACAO, 0, $1, 0, 0, 0);}
| decpointer      {$$ = astreeCreate(AST_DECLARACAO, 0, $1, 0, 0, 0);}
;

decvar: typevar TK_IDENTIFIER '=' literal ';'       {$$ = astreeCreate(AST_VAR, 0, $1, 0, $4, 0);}
;

decvetor: typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ':' decv ';'    {$$ = astreeCreate(AST_EXPR_VECTOR, 0, $1, 0, 0, $7);}
| typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ';'                     {$$ = astreeCreate(AST_EXPR_VECTOR, 0, $1, 0, 0, 0);}
;

decfunction: typevar TK_IDENTIFIER '(' paramlist ')' body    {$$ = astreeCreate(AST_FUNC_PARAM, 0, $1, 0, $4, $6);}

decpointer: typevar '#' TK_IDENTIFIER '=' literal ';'    {$$ = astreeCreate(AST_DECLARACAO, 0, $1, 0, $5, 0);}

decv:	LIT_INTEGER decv  {$$ = astreeCreate(AST_SYMBOL, 0, $2, 0, 0, 0);}
| LIT_CHAR decv           {$$ = astreeCreate(AST_SYMBOL, 0, $2, 0, 0, 0);}
| LIT_REAL decv           {$$ = astreeCreate(AST_SYMBOL, 0, $2, 0, 0, 0);}
| ' ' decv                {$$ = astreeCreate(AST_SYMBOL, 0, $2, 0, 0, 0);}
| {$$ = 0;}
;

typevar: KW_CHAR   // {$$ = astreeCreate(AST_CHAR, 0, 0, , 0, 0);}
| KW_INT           // {$$ = astreeCreate(AST_INT, 0, 0, 0, 0, 0);}
| KW_FLOAT         // {$$ = astreeCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
;

literal: LIT_INTEGER // {$$ = astreeCreate(AST_SYMBOL, 0, $1, 0, 0, 0);}
| LIT_CHAR           // {$$ = astreeCreate(AST_SYMBOL, 0, $1, 0, 0, 0);}
| LIT_REAL           // {$$ = astreeCreate(AST_SYMBOL, 0, $1, 0, 0, 0);}
;

paramlist: typevar TK_IDENTIFIER rest // {$$ = astreeCreate(AST_PARAML, 0, $1, $2, $3, 0);}
| literal rest                        // {$$ = astreeCreate(AST_PARAML, 0, $1, $2, 0, 0);}
| TK_IDENTIFIER rest                  // {$$ = astreeCreate(AST_PARAML, 0, $1, $2, 0, 0);}
| {$$ = 0;}
;

rest: ',' typevar TK_IDENTIFIER rest  //  {$$ = astreeCreate(AST_REST, 0, $2, $3, $4, 0);}
| ',' literal rest                    //  {$$ = astreeCreate(AST_REST, 0, $2, $3, 0, 0);}
| ',' TK_IDENTIFIER rest              //  {$$ = astreeCreate(AST_REST, 0, $2, $3, 0, 0);}
| {$$ = 0;}
;


cmd: attribution // {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
| flux_control   // {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
| inout          // {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
| body           // {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
| {$$ = 0;}
;

body: '{' lcmd '}'  //{$$ = astreeCreate(AST_BLOCO, 0, $2, 0, 0, 0);}
;

lcmd: cmd ';' lcmd //   {$$ = astreeCreate(AST_CMDLIST, 0, $1, $3, 0, 0);}
| dec lcmd         //   {$$ = astreeCreate(AST_CMDLIST, 0, $1, $2, 0, 0);}
| cmd              //   {$$ = astreeCreate(AST_CMDLIST, 0, $1, 0, 0, 0);}
;

attribution: TK_IDENTIFIER '=' exp        //    {$$ = astreeCreate(AST_ATTRIBUTION, 0, $1, $3, 0, 0);}
| TK_IDENTIFIER '[' exp ']' '=' exp       //    {$$ = astreeCreate(AST_ATTRIBUTION, 0, $1, $3, $6, 0);}
;

flux_control: KW_IF '(' exp ')' KW_THEN cmd          // {$$ = astreeCreate(AST_IF, 0, $3, $6, 0, 0);}
| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd          // {$$ = astreeCreate(AST_ELSE, 0, $3, $6, $8, 0);}
| KW_WHILE '(' exp ')' cmd                           // {$$ = astreeCreate(AST_WHILE, 0, $3, $5, 0, 0);}
| KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp')' cmd  // {$$ = astreeCreate(AST_FOR, 0, $3, $5, $7, $9);}
;

inout: KW_PRINT print_elem       //  {$$ = astreeCreate(AST_CMDLIST, 0, $1, $2, 0, 0);}
| KW_READ TK_IDENTIFIER          //  {$$ = astreeCreate(AST_CMDLIST, 0, $1, $2, 0, 0);}
| KW_RETURN exp                  //  {$$ = astreeCreate(AST_CMDLIST, 0, $1, $2, 0, 0);}
;

print_elem: LIT_STRING           // {$$ = astreeCreate(AST_PRINT, 0, $1, 0, 0, 0);}
| LIT_STRING print_elem          // {$$ = astreeCreate(AST_PRINT, 0, $1, $2, 0, 0);}
| LIT_STRING ' ' print_elem      // {$$ = astreeCreate(AST_PRINT, 0, $1, $3, 0, 0);}
| exp                            // {$$ = astreeCreate(AST_PRINT, 0, $1, 0, 0, 0);}
| exp print_elem                 // {$$ = astreeCreate(AST_PRINT, 0, $1, $2, 0, 0);}
| exp ' ' print_elem             // {$$ = astreeCreate(AST_PRINT, 0, $1, $3, 0, 0);}
;

exp: TK_IDENTIFIER                 //  {$$ = $1;}
| TK_IDENTIFIER '[' exp ']'        //  {$$ = astreeCreate(AST_EXPR_VECTOR, 0, $1, $3, 0, 0);}
| '#'TK_IDENTIFIER                 //  {$$ = astreeCreate(AST_HASHTAG, 0, $2, 0, 0, 0);}
| '&'TK_IDENTIFIER                 //  {$$ = astreeCreate(AST_E, 0, $2, 0, 0, 0);}
| LIT_INTEGER                      //  {$$ = astreeCreate(AST_SYMBOL, 0, $1, 0, 0, 0); }
| LIT_CHAR                         //  {$$ = astreeCreate(AST_SYMBOL, 0, $1, 0, 0, 0); }
| exp '+' exp                      //  {$$ = astreeCreate(AST_ADD, 0, $1, $3, 0, 0);}
| exp '-' exp                      //  {$$ = astreeCreate(AST_SUB, 0, $1, $3, 0, 0);}
| exp '*' exp                      //  {$$ = astreeCreate(AST_MULT, 0, $1, $3, 0, 0);}
| exp '/' exp                      //  {$$ = astreeCreate(AST_DIV, 0, $1, $3, 0, 0);}
| exp '<' exp                      //  {$$ = astreeCreate(AST_LESS, 0, $1, $3, 0, 0);}
| exp '>' exp                      //  {$$ = astreeCreate(AST_GREATER, 0, $1, $3, 0, 0);}
| '!' exp                          //  {$$ = astreeCreate(AST_NEG, 0, $2, 0 , 0, 0);}
| '(' exp ')'                      //  {$$ = astreeCreate(AST_EXPR, 0, $2, 0 , 0, 0);}
| exp OPERATOR_LE exp              //  {$$ = astreeCreate(AST_LE, 0, $1, $3, 0, 0);}
| exp OPERATOR_GE exp              //  {$$ = astreeCreate(AST_GE, 0, $1, $3, 0, 0);}
| exp OPERATOR_EQ exp              //  {$$ = astreeCreate(AST_EQ, 0, $1, $3, 0, 0);}
| exp OPERATOR_NE exp              //  {$$ = astreeCreate(AST_NE, 0, $1, $3, 0, 0);}
| exp OPERATOR_AND exp             //  {$$ = astreeCreate(AST_AND, 0, $1, $3, 0, 0);}
| exp OPERATOR_OR exp              //  {$$ = astreeCreate(AST_OR, 0, $1, $3, 0, 0);}
| TK_IDENTIFIER '(' paramlist ')'  //  {$$ = astreeCreate(AST_EXPR_FUNC, 0, $1, $3, 0, 0);}
;


%%

int main(int argc, char* argv[])
{
  if (argc > 1 && (yyin = fopen(argv[1], "r")))
  {
  initMe();
 	 yydebug = 0;
    if(yyparse() == 0)
    {
      printf("Sucess, this is a program!\nLines: %d\n", getLineNumber());
        hashPrint();
        exit(0);
    }
  } else {
    printf("Usage: ./etapa2 input_filepath\n");
  }
  if(!(FileTree = fopen(argv[2],"w")))
  {
    fprintf(stderr, "Cannot Create: %s \n",argv[2]);
    exit(2);
  }
}

  int yyerror(char *s)
  {
    fprintf(stderr, "line %d: %s\n", getLineNumber(), s);
//    hashPrint();
    exit(3);
  }