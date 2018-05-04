
//Declarações para pegar o yylval.symbol
%union{
    #inclde<ast.h>
    struct hash_node *symbol;
    struct ast_node *ast;
    
}


%type <ast> dec
%type <ast> ldec
%type <ast> program
%type <ast> exp
%type <ast> cmd
%type <ast>lcmd
%type <ast> read
%type <ast> block

%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_RETURN
%token KW_PRINT
%token KW_TO

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INTEGER
%token<symbol> LIT_REAL
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING
%token TOKEN_ERROR

%left '!' '<' '>'  OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left OPERATOR_AND OPERATOR_OR
%left ','
%left '='
%left '+' '-'
%left '*' 
%left '/'

//%nonassoc '(' ')'  //ver aqui se precisa.



%{
extern int getLineNumber();
#include<stdio.h>
#include <stdlib.h>
#include "AST.h"

    %}

%%
program: ldec {$$ = $1; astPrint($1);}
    ;

ldec: dec ldec {$$ = astCreate(AST_DEC,0,$1,$2,0,0);}
    | {$$ = 0;}
    ;

dec:KW_IF '(' exp ')' KW_THEN lcmd  { $$ = astreeCreate(AST_IF_THEN, 0, $3, $6, 0, 0); }
|KW_IF '(' exp ')' KW_THEN lcmd KW_ELSE lcmd { $$ = astreeCreate(AST_IF_THEN_ELSE, 0, $3, $6, $8, 0); }
;
    |KW_WHILE '(' exp ')' lcmd
    |KW_FOR '('TK_IDENTIFIER '=' exp KW_TO exp')' lcmd   { $$ = astreeCreate(AST_FOR_TO, $3, $5, $7, $9, 0); }
    |func_dec
    |type TK_IDENTIFIER '=' LIT_REAL ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |type TK_IDENTIFIER '=' LIT_CHAR ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |type TK_IDENTIFIER '=' LIT_INTEGER ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |type TK_IDENTIFIER'['exp']'':' vet_dec ';'
    |type TK_IDENTIFIER'['exp']' ';'
    |type '#' TK_IDENTIFIER '=' LIT_REAL ';'
    |type '#' TK_IDENTIFIER '=' LIT_CHAR ';'
    |type '#' TK_IDENTIFIER '=' LIT_INTEGER ';'
    ;

reset: ',' func_args reset
    |
    ;
block: '{' lcmd '}' { $$ = astreeCreate(ASTREE_BLOCK, 0, $2, 0, 0, 0); }

    |     ;




lcmd: cmd  ';'lcmd
|
| cmd ';'cmd lcmd
|dec
;




cmd:block
    | TK_IDENTIFIER '=' exp
    | '#'TK_IDENTIFIER '='exp
    | '&'TK_IDENTIFIER '='exp
    | TK_IDENTIFIER '=''#'exp
    | TK_IDENTIFIER '=''&'exp
    | TK_IDENTIFIER'['exp']' '=' exp
    | '#'TK_IDENTIFIER'['exp']' '='exp
    | '&'TK_IDENTIFIER'['exp']' '='exp
    | TK_IDENTIFIER '=''['exp']''#'exp
    | TK_IDENTIFIER '=''['exp']''&'exp
    |TK_IDENTIFIER'(' l_func_args reset')'
    |print
    |read
    |KW_RETURN exp
    ;

type:KW_INT {$$ = $1;}
    |KW_FLOAT {$$ = $1;}
    |KW_CHAR {$$ = $1;}
    ;

vet_dec: LIT_REAL vet_dec
    |LIT_CHAR	vet_dec
    |LIT_INTEGER vet_dec
    |LIT_REAL
    |LIT_CHAR
    |LIT_INTEGER
    ;

exp:TK_IDENTIFIER
    |TK_IDENTIFIER'['exp']'
    |LIT_CHAR
    |LIT_REAL
    |LIT_INTEGER
    |exp '+' exp  { $$ = astreeCreate(AST_SUB, 0, $1, $3, 0, 0); }
    |exp '-' exp  { $$ = astreeCreate(AST_SUB, 0, $1, $3, 0, 0); }
    |exp '*' exp  { $$ = astreeCreate(AST_MULT, 0, $1, $3, 0, 0); }
    |exp '/' exp  { $$ = astreeCreate(AST_DIV, 0, $1, $3, 0, 0); }
    |exp '<' exp  { $$ = astreeCreate(AST_LT, 0, $1, $3, 0, 0); }
    |exp '>' exp  { $$ = astreeCreate(AST_GT, 0, $1, $3, 0, 0); }
    |exp '!' exp  { $$ = astreeCreate(AST_NOT, 0, $2, 0, 0, 0); }
    |exp OPERATOR_LE exp { $$ = astreeCreate(AST_LE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_GE exp { $$ = astreeCreate(AST_GE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_EQ exp { $$ = astreeCreate(AST_EQ, 0, $1, $3, 0, 0); }
    |exp OPERATOR_NE exp { $$ = astreeCreate(AST, 0, $1, $3, 0, 0); }
    |exp OPERATOR_AND exp { $$ = astreeCreate(ASTAND, 0, $1, $3, 0, 0); }
    |exp OPERATOR_OR exp { $$ = astreeCreate(AST_OR, 0, $1, $3, 0, 0); }
    |TK_IDENTIFIER '('')'
    |TK_IDENTIFIER '(' l_func_args reset ')'
    |'(' exp ')'  { $$ = astreeCreate(AST_PARENTHESES, 0, $2, 0, 0, 0); }
    ;

func_args: LIT_REAL
    |LIT_CHAR
    |LIT_INTEGER
    |TK_IDENTIFIER
    |'#' TK_IDENTIFIER
    |'&' TK_IDENTIFIER
    ;

l_func_args:func_args l_func_args
    |
    ;

func_dec:func_header block
    ;

func_header: type TK_IDENTIFIER '(' l_func_par reset_func_par ')'
    ;

func_par: type TK_IDENTIFIER
    ;
l_func_par: func_par l_func_par
    |
    ;
reset_func_par: ',' func_par reset_func_par
    |
    ;


print:KW_PRINT lpe
;


pe:LIT_STRING
|TK_IDENTIFIER
|'&'TK_IDENTIFIER
|'#'TK_IDENTIFIER
;



lpe: pe lpe
|
;
read:KW_READ TK_IDENTIFIER { $$ = astreeCreate(AST_READ, $2, 0, 0, 0, 0); }
;
%%
int yyerror(int code){
    printf("O analisador encontrou um erro na linha %d\n",getLineNumber());
    exit(3);

}
#include "main.c"
