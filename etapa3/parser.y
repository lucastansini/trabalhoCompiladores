
//Declarações para pegar o yylval.symbol
%union{
    struct hash_node *symbol;
}


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
%left '*' '/'
%left OPERATOR_AND OPERATOR_OR OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%nonassoc '(' ')'




%{
extern int getLineNumber();
#include<stdio.h>
#include <stdlib.h>
#include "AST.h"
    %}

%%
program: ldec
    ;

ldec: dec ldec
    |
    ;

dec:KW_IF '(' exp ')' KW_THEN lcmd
    |KW_IF '(' exp ')' KW_THEN lcmd KW_ELSE lcmd
    |KW_WHILE '(' exp ')' lcmd
    |KW_FOR '('TK_IDENTIFIER '=' exp KW_TO exp')' lcmd
    |func_dec
    |type TK_IDENTIFIER '=' lit ';'
    |type TK_IDENTIFIER'['exp']'':' vet_dec ';'
    |type TK_IDENTIFIER'['exp']' ';'
    |type '#' TK_IDENTIFIER '=' lit ';'

    ;

reset: ',' func_args reset
    |
    ;
block: '{' lcmd '}'|
    ;

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
    |func_call
    |print
    |read
    |KW_RETURN exp
    |

    ;

type:KW_INT
    |KW_FLOAT
    |KW_CHAR
    ;
lit:LIT_REAL
    |LIT_CHAR
    |LIT_INTEGER
    ;
vet_dec: lit vet_dec
    |lit
    ;
exp:TK_IDENTIFIER
    |TK_IDENTIFIER'['exp']'
    |lit
    |exp op exp
    |TK_IDENTIFIER '('')'
    |func_call
    ;
func_call: TK_IDENTIFIER'(' l_func_args reset')'
    ;

func_args:lit
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

op: '+'
    |'-'
    |'*'
    |'/'
    |'<'
    |'>'
    |'!'
    |OPERATOR_LE
    |OPERATOR_GE
    |OPERATOR_EQ
    |OPERATOR_NE
    |OPERATOR_AND
    |OPERATOR_OR
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
