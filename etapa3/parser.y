
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
%type <ast> type
%type <ast> reset
%type <ast> l_func_args
%type <ast> lpe
%type <ast> print
%type <ast> reset_func_par
%type <ast> l_func_par
%type <ast> func_header
%type <ast> func_dec
%type <ast> func_args
%type <ast> pe
%type <ast> func_par





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
    |KW_WHILE '(' exp ')' lcmd  { $$ = astreeCreate(AST_IF_THEN, 0, $3, $5, 0, 0); }
    |KW_FOR '('TK_IDENTIFIER '=' exp KW_TO exp')' lcmd   { $$ = astreeCreate(AST_FOR_TO, $3, $5, $7, $9, 0); }
    |func_dec {$$ = $1;}
    |type TK_IDENTIFIER '=' LIT_REAL ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |type TK_IDENTIFIER '=' LIT_CHAR ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |type TK_IDENTIFIER '=' LIT_INTEGER ';' {$$ = astCreate(AST_VARIABLE,0,$1,0,$4,0);}
    |KW_INT TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_INT,0,$2,$4,0,0);}
    |KW_INT TK_IDENTIFIER'['exp']' ';' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_2_INT,0,$2,$4,0,0);}
    |KW_FLOAT TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_FLOAT,0,$2,$4,0,0);}
    |KW_FLOAT TK_IDENTIFIER'['exp']' ';' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_2_FLOAT,0,$2,$4,0,0);}
    |KW_CHAR TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_CHAR,0,$2,$4,0,0);}
    |KW_CHAR TK_IDENTIFIER'['exp']' ';' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_2_CHAR,0,$2,$4,0,0);}

    |type '#' TK_IDENTIFIER '=' LIT_INTEGER ';'
    ;


reset: ',' func_args reset  {(AST_FUNC_RESET, 0, $2, $3, 0, 0); }
    |{$$ = 0;}
    ;
block: '{' lcmd '}' { $$ = astreeCreate(ASTREE_BLOCK, 0, $2, 0, 0, 0); }

    |{$$ = 0;}     ;




lcmd: cmd  ';'lcmd { $$ = astreeCreate(ASTREE_LCMD, 0, $1, $3, 0, 0);}
|{$$ = 0;}
| cmd ';'cmd lcmd { $$ = astreeCreate(ASTREE_LCMD, 0, $1, $3, $4, 0);}
    |dec {$$ = $1;}
;




cmd:block
    | TK_IDENTIFIER '=' exp  {$$ = astreeCreate(AST_ATRIBUTION,0, $1,$3,0,0);}
    | '#'TK_IDENTIFIER '='exp {$$ = astreeCreate(AST_TO_PTR_ATRIBUTION,0, $2,$4,0,0);}
    | '&'TK_IDENTIFIER '='exp {$$ = astreeCreate(AST_TO_END_ATRIBUTION,0, $2,$4,0,0);}
    | TK_IDENTIFIER '=''#'exp {$$ = astreeCreate(AST_PTR_ATRIBUTION,0, $1,$4,0,0);}
    | TK_IDENTIFIER '=''&'exp {$$ = astreeCreate(AST_END_ATRIBUTION,0, $1,$4,0,0);}
    | TK_IDENTIFIER'['exp']' '=' exp {$$ = astreeCreate(AST_VEC_ATRIBUTION,0, $1,$3,$6,0);}
    | '#'TK_IDENTIFIER'['exp']' '='exp {$$ = astreeCreate(AST_TO_PTR_VEC_ATRIBUTION,0, $2,$4,$7,0);}
    | '&'TK_IDENTIFIER'['exp']' '='exp {astreeCreate(AST_TO_END VEC_ATRIBUTION,0, $2,$4,$7,0);}
    | TK_IDENTIFIER '=''#'exp '['exp']' {astreeCreate(AST_PTR_VEC_ATRIBUTION,0, $1,$4,$6,0);}
    | TK_IDENTIFIER '=''&'exp'['exp']' {astreeCreate(AST_END_VEC_ATRIBUTION,0, $1,$4,$6,0);}
    |TK_IDENTIFIER'(' l_func_args reset')' {astreeCreate(AST_FUNC_CALL,0,$1,$3,$4,0);}
    |print  {$$ = $1;}
    |read  {$$ = $1;}
    |KW_RETURN exp {astreeCreate(AST_RETURN,0,$2,0,0,0);}
    ;

type:LIT_INTEGER {(AST_INT, 0, $1, 0, 0, 0); }
    |LIT_REAL {(AST_FLOAT, 0, $1, 0, 0, 0); }
    |LIT_CHAR  {(AST_CHAR, 0, $1, 0, 0, 0); }
    ;

vet_dec: KW_FLOAT vet_dec
    |KW_CHAR	vet_dec
    |KW_INT vet_dec
    ;

exp:TK_IDENTIFIER { $$ = astreeCreate(SYMBOL, 0, $1, 0, 0, 0); }
    |TK_IDENTIFIER'['exp']' { $$ = astreeCreate(READ_VEC, 0, $1, $3, 0, 0); }
    |LIT_CHAR { $$ = astreeCreate(SYMBOL, 0, $1, 0, 0, 0); }
    |LIT_REAL { $$ = astreeCreate(SYMBOL, 0, $1, 0, 0, 0); }
    |LIT_INTEGER { $$ = astreeCreate(SYMBOL, 0, $1, 0, 0, 0); }
    |exp '+' exp  { $$ = astreeCreate(AST_SUB, 0, $1, $3, 0, 0); }
    |exp '-' exp  { $$ = astreeCreate(AST_SUB, 0, $1, $3, 0, 0); }
    |exp '*' exp  { $$ = astreeCreate(AST_MULT, 0, $1, $3, 0, 0); }
    |exp '/' exp  { $$ = astreeCreate(AST_DIV, 0, $1, $3, 0, 0); }
    |exp '<' exp  { $$ = astreeCreate(AST_LT, 0, $1, $3, 0, 0); }
    |exp '>' exp  { $$ = astreeCreate(AST_GT, 0, $1, $3, 0, 0); }
    |'!' exp  { $$ = astreeCreate(AST_NOT, 0, $2, 0, 0, 0); }
    |exp OPERATOR_LE exp { $$ = astreeCreate(AST_LE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_GE exp { $$ = astreeCreate(AST_GE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_EQ exp { $$ = astreeCreate(AST_EQ, 0, $1, $3, 0, 0); }
    |exp OPERATOR_NE exp { $$ = astreeCreate(AST, 0, $1, $3, 0, 0); }
    |exp OPERATOR_AND exp { $$ = astreeCreate(ASTAND, 0, $1, $3, 0, 0); }
    |exp OPERATOR_OR exp { $$ = astreeCreate(AST_OR, 0, $1, $3, 0, 0); }
    |TK_IDENTIFIER '(' l_func_args reset ')' { $$ = astreeCreate(FUNC_CALL, 0, $1, $3, $4, 0); }
    |'(' exp ')'  { $$ = astreeCreate(AST_PARENTHESES, 0, $2, 0, 0, 0); }
    ;

func_args: LIT_REAL {$$ = $1;}
    |LIT_CHAR  {$$ = $1;}
    |LIT_INTEGER  {$$ = $1;}
    |TK_IDENTIFIER  {$$ = $1;}
    |'#' TK_IDENTIFIER  { $$ = astreeCreate(AST_PTR, 0, $2, 0, 0, 0);}
    |'&' TK_IDENTIFIER  { $$ = astreeCreate(AST_END, 0, $2, 0, 0, 0);}
    ;

l_func_args:func_args l_func_args {$$ = astreeCreate(AST_FUNC_ARGL_LIST, 0, $1, $2, 0, 0); }
    |{$$ = 0;}
    ;

func_dec:func_header block {$$ = astreeCreate(AST_FUNC_BLOCK, 0, $1, 0, 0, 0); }
    ;

func_header: type TK_IDENTIFIER '(' l_func_par reset_func_par ')' {$$ = astreeCreate(AST_FUNC_HEADER, 0, $4, $5, 0, 0); }
    ;

func_par: type TK_IDENTIFIER
    ;
l_func_par: func_par l_func_par {$$ = astreeCreate(AST_FUNC_PAR_LIST, 0, $1, $2, 0, 0); }
    |{$$ = 0;}
    ;
reset_func_par: ',' func_par reset_func_par {$$ = astreeCreate(AST_FUNC_PAR, 0, $2, $3, 0, 0); }
    |{$$ = 0;}
    ;


print:KW_PRINT lpe {$$ = astreeCreate(AST_PRINT_LIST, 0, 0, $2, 0, 0); }
;


pe:LIT_STRING { $$ = astreeCreate(SYMBOL, 0, $1, 0, 0, 0); }
|TK_IDENTIFIER { $$ = astreeCreate(SYMBOL, 0, $1, 0, 0, 0); }
|'&'TK_IDENTIFIER { $$ = astreeCreate(END_SYMBOL, 0, $2, 0, 0, 0); }
|'#'TK_IDENTIFIER { $$ = astreeCreate(PTR_SYMBOL, 0, $2, 0, 0, 0); }
;



lpe: pe lpe {$$ = astreeCreate(AST_PRINT, 0, $1, $2, 0, 0); }
|{$$ = 0;}
;
read:KW_READ TK_IDENTIFIER { $$ = astreeCreate(AST_READ, $2, 0, 0, 0, 0); }
;
%%
int yyerror(int code){
    printf("O analisador encontrou um erro na linha %d\n",getLineNumber());
    exit(3);

}
#include "main.c"
