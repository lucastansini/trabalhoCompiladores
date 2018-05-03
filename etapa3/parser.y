
//Declarações para pegar o yylval.symbol
%union{
    struct hash_node *symbol;
    struct ast_node *ast;
}


%type<ast> dec
%type<ast> ldec
%type<ast> program


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

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR


%left ','
%left '='
%left '+' '-'
%left '*' 
%left '/'
%left '!' '<' '>' OPERATOR_AND OPERATOR_OR OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
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

dec:KW_IF '(' exp ')' KW_THEN lcmd 
    |KW_IF '(' exp ')' KW_THEN lcmd KW_ELSE lcmd
    |KW_WHILE '(' exp ')' lcmd
    |KW_FOR '('TK_IDENTIFIER '=' exp KW_TO exp')' lcmd
    |func_dec
    |type TK_IDENTIFIER '=' LIT_REAL ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |type TK_IDENTIFIER '=' LIT_CHAR ';'
    |type TK_IDENTIFIER '=' LIT_INTEGER ';'
    |type TK_IDENTIFIER'['exp']'':' vet_dec ';'
    |type TK_IDENTIFIER'['exp']' ';'
    |type '#' TK_IDENTIFIER '=' LIT_REAL ';'
    |type '#' TK_IDENTIFIER '=' LIT_CHAR ';'
    |type '#' TK_IDENTIFIER '=' LIT_INTEGER ';'
    ;

reset: ',' func_args reset
    |
    ;
block: '{' lcmd '}'|
    ;



lcmd: cmd  ';'lcmd
    |dec
    |
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

type:KW_INT
    |KW_FLOAT
    |KW_CHAR
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
    |exp '+' exp
    |exp '-' exp 	
    |exp '*' exp
    |exp '/' exp
    |exp '<' exp
    |exp '>' exp
    |exp '!' exp
    |exp OPERATOR_LE exp
    |exp OPERATOR_GE exp
    |exp OPERATOR_EQ exp
    |exp OPERATOR_NE exp
    |exp OPERATOR_AND exp
    |exp OPERATOR_OR exp
    |TK_IDENTIFIER '('')'
    |TK_IDENTIFIER '(' l_func_args reset ')'
    |'(' exp ')'
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
read:KW_READ TK_IDENTIFIER
;
%%
int yyerror(int code){
    printf("O analisador encontrou um erro na linha %d\n",getLineNumber());
    exit(3);

}
#include "main.c"
