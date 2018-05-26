
%{
#include "ast.c"
#include "semantic.c"
extern int getLineNumber();
#include<stdio.h>
#include <stdlib.h>
AST *ast_Geral;
extern FILE *saida;
extern semanticError;
    %}


//Declarações para pegar o yylval.symbol
%union{

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
%type <ast> lit
%type <ast> vet_dec



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

%nonassoc '(' ')'  //ver aqui se precisa.





%%
program: ldec {
               astToFile(0,$1,saida);
               //hashPrint();
               setDeclarations($1);
               checkSemantic($1);
               checkOperands($1);
               checkUndeclared();
               checkAttributions($1);
               if(semanticError){
                 printf("Exit 4 due to semantic error!\n");
                 exit(4);
               }
              }
    ;

ldec:dec ldec {$$ = astCreate(AST_DEC,0,$1,$2,0,0);}
    | {$$ = 0;}
    ;

dec:KW_IF '(' exp ')' KW_THEN lcmd  { $$ = astCreate(AST_IF_THEN, 0, $3, $6, 0, 0); }
|KW_IF '(' exp ')' KW_THEN lcmd KW_ELSE lcmd { $$ = astCreate(AST_IF_THEN_ELSE, 0, $3, $6, $8, 0); }
|KW_WHILE '(' exp ')' lcmd  { $$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0); }
|KW_FOR '('TK_IDENTIFIER '=' exp KW_TO exp')' lcmd   { $$ = astCreate(AST_FOR_TO, $3, $5, $7, $9, 0); }
|func_dec {$$ = $1;}
|KW_FLOAT TK_IDENTIFIER '=' exp ';' {$$ = astCreate(AST_VARIABLE_DEC_FLOAT,$2,$4,0,0,0);}
|KW_CHAR TK_IDENTIFIER '=' exp ';' {$$ = astCreate(AST_VARIABLE_DEC_CHAR,$2,$4,0,0,0);}
|KW_INT TK_IDENTIFIER '=' exp ';' {$$ = astCreate(AST_VARIABLE_DEC_INT,$2,$4,0,0,0);}
|KW_INT TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_INT,$2,$4,$7,0,0);}
|KW_INT TK_IDENTIFIER'['exp']' ';'  {$$ = astCreate(AST_VARIABLE_VEC_2_INT,$2,$4,0,0,0);}
|KW_FLOAT TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_FLOAT,$2,$4,$7,0,0);}
|KW_FLOAT TK_IDENTIFIER'['exp']' ';'{$$ = astCreate(AST_VARIABLE_VEC_2_FLOAT,$2,$4,0,0,0);}
|KW_CHAR TK_IDENTIFIER'['exp']'':' vet_dec ';'{$$ = astCreate(AST_VARIABLE_VEC_1_CHAR,$2,$4,$7,0,0);}
|KW_CHAR TK_IDENTIFIER'['exp']' ';'{$$ = astCreate(AST_VARIABLE_VEC_2_CHAR,$2,$4,0,0,0);}

|KW_FLOAT '#' TK_IDENTIFIER '=' exp ';'{$$ = astCreate(AST_VARIABLE_PTR_FLOAT,$3,$5,0,0,0);}
|KW_CHAR '#' TK_IDENTIFIER '=' exp ';'{$$ = astCreate(AST_VARIABLE_PTR_CHAR,$3,$5,0,0,0);}
|KW_INT '#' TK_IDENTIFIER '=' exp ';'{$$ = astCreate(AST_VARIABLE_PTR_INT,$3,$5,0,0,0);}
;

reset: ',' func_args reset  {$$ =astCreate(AST_FUNC_RESET, 0, $2, $3, 0, 0); }
    |{$$ = 0;}
    ;
block: '{' lcmd '}' { $$ = astCreate(AST_BLOCK, 0, $2, 0, 0, 0); }

    |{$$ = 0;}     ;


lcmd: cmd  ';'lcmd { $$ = astCreate(AST_LCMD, 0, $1, $3, 0, 0);}
    | cmd ';' cmd lcmd { $$ = astCreate(AST_LCMD2, 0, $1, $3,$4, 0);}
    |dec {$$ = $1;}
| {$$ =0;}
;




cmd:block {$$ = $1;}
    | TK_IDENTIFIER '=' exp  {$$ = astCreate(AST_ATRIBUTION,$1,$3, 0,0,0);}
    | '#'TK_IDENTIFIER '='exp {$$ = astCreate(AST_TO_PTR_ATRIBUTION,$2, $4,0,0,0);}
    | '&'TK_IDENTIFIER '='exp {$$ = astCreate(AST_TO_END_ATRIBUTION,$2, $4,0,0,0);}
    | TK_IDENTIFIER '=''#'exp {$$ = astCreate(AST_PTR_ATRIBUTION,$1,$4,0 ,0,0);}
    | TK_IDENTIFIER '=''&'exp {$$ = astCreate(AST_END_ATRIBUTION,$1,$4, 0,0,0);}
    | TK_IDENTIFIER'['exp']' '=' exp {$$ = astCreate(AST_VEC_ATRIBUTION,$1,$3,$6,0 ,0);}
    | '#'TK_IDENTIFIER'['exp']' '='exp {$$ = astCreate(AST_TO_PTR_VEC_ATRIBUTION,$2,$4,$7,0 ,0);}
    | '&'TK_IDENTIFIER'['exp']' '='exp {$$ =astCreate(AST_TO_END_VEC_ATRIBUTION,$2,$4,$7,0, 0);}
    | TK_IDENTIFIER '=''#'exp '['exp']' {$$ =astCreate(AST_PTR_VEC_ATRIBUTION,$1,$4,$6,0, 0);}
    | TK_IDENTIFIER '=''&'exp'['exp']' {$$ =astCreate(AST_END_VEC_ATRIBUTION, $1,$4,$6,0,0);}
    |TK_IDENTIFIER'(' l_func_args reset')' {$$ =astCreate(AST_FUNCTIONCALL,$1,$3,$4,0,0);}
    |print  {$$ = $1;}
    |read  {$$ = $1;}
    |KW_RETURN exp {$$ =astCreate(AST_RETURN,0,$2,0,0,0);}
    ;

lit:LIT_INTEGER {$$ =astCreate(AST_INT, $1,0,  0, 0, 0); }
    |LIT_REAL {$$ =astCreate(AST_FLOAT, $1,0, 0, 0, 0); }
    |LIT_CHAR  {$$ =astCreate(AST_CHAR, $1,0,  0, 0, 0); }
    ;

vet_dec: lit vet_dec {$$ =astCreate(AST_VET_LIST, 0,$1,  $2, 0, 0); }
|lit {$$ = $1;}
;


exp:TK_IDENTIFIER { $$ = astCreate(AST_VARIABLE,$1, 0,  0, 0, 0); }
    |TK_IDENTIFIER'['exp']' { $$ = astCreate(READ_VEC, $1, $3, 0, 0, 0); }
    |LIT_CHAR { $$ = astCreate(SYMBOL, $1,0,  0, 0, 0); }
    |LIT_REAL { $$ = astCreate(SYMBOL,$1, 0,  0, 0, 0); }
    |LIT_INTEGER { $$ = astCreate(SYMBOL, $1, 0,  0, 0, 0); }
    |exp '+' exp  { $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
    |exp '-' exp  { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
    |exp '*' exp  { $$ = astCreate(AST_MULT, 0, $1, $3, 0, 0); }
    |exp '/' exp  { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
    |exp '<' exp  { $$ = astCreate(AST_LT, 0, $1, $3, 0, 0); }
    |exp '>' exp  { $$ = astCreate(AST_GT, 0, $1, $3, 0, 0); }
    |'!' exp  { $$ = astCreate(AST_NOT, 0, $2, 0, 0, 0); }
    |exp OPERATOR_LE exp { $$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_GE exp { $$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_EQ exp { $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }
    |exp OPERATOR_NE exp { $$ = astCreate(AST_NE, 0, $1, $3, 0, 0); }
    |exp OPERATOR_AND exp { $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
    |exp OPERATOR_OR exp { $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
    |TK_IDENTIFIER '(' l_func_args reset ')' { $$ = astCreate(AST_FUNCTIONCALL, $1, $3, $4,0,  0); }
    |'(' exp ')'  { $$ = astCreate(AST_PARENTHESES, 0, $2, 0, 0, 0); }
    ;

func_args: LIT_REAL { $$ = astCreate(SYMBOL, $1,0,  0, 0, 0); }
    |LIT_CHAR  { $$ = astCreate(SYMBOL, $1,0,  0, 0, 0); }
    |LIT_INTEGER { $$ = astCreate(SYMBOL, $1,0,  0, 0, 0); }
    |TK_IDENTIFIER  { $$ = astCreate(SYMBOL, $1,0,  0, 0, 0); }
    |'#' TK_IDENTIFIER  { $$ = astCreate(AST_PTR, $2, 0, 0, 0, 0);}
    |'&' TK_IDENTIFIER  { $$ = astCreate(AST_END, $2, 0, 0, 0, 0);}
    ;

l_func_args:func_args l_func_args {$$ = astCreate(AST_FUNC_ARGL_LIST, 0, $1, $2, 0, 0); }
    |{$$ = 0;}
    ;

func_dec:func_header block {$$ = astCreate(AST_FUNC_BLOCK, 0, $1, $2, 0, 0); }
    ;

func_header: KW_INT TK_IDENTIFIER '(' l_func_par reset_func_par ')' {$$ = astCreate(AST_FUNC_HEADER_INT, $2, $4, $5, 0, 0); }
|KW_FLOAT TK_IDENTIFIER '(' l_func_par reset_func_par ')' {$$ = astCreate(AST_FUNC_HEADER_FLOAT, $2, $4, $5, 0, 0); }
|KW_CHAR TK_IDENTIFIER '(' l_func_par reset_func_par ')' {$$ = astCreate(AST_FUNC_HEADER_CHAR, $2, $4, $5, 0, 0); }
;

func_par: KW_INT TK_IDENTIFIER {$$ = astCreate(AST_FUNC_PAR_INT, $2,0,  0, 0, 0); }
|KW_FLOAT TK_IDENTIFIER {$$ = astCreate(AST_FUNC_PAR_FLOAT, $2, 0, 0, 0, 0); }
|KW_CHAR TK_IDENTIFIER {$$ = astCreate(AST_FUNC_PAR_CHAR,$2, 0,  0, 0, 0); }
    ;
l_func_par: func_par l_func_par {$$ =astCreate(AST_FUNC_PAR_LIST, 0, $1, $2, 0, 0); }
    |{$$ = 0;}
    ;
reset_func_par: ',' func_par reset_func_par {$$ = astCreate(AST_FUNC_PAR, 0, $2, $3, 0, 0); }
    |{$$ = 0;}
    ;


print:KW_PRINT lpe {$$ = astCreate(AST_PRINT_LIST, 0, $2,0 , 0, 0); }
;


pe:LIT_STRING { $$ = astCreate(AST_VAR_PRINT, $1,0,  0, 0, 0); }
|TK_IDENTIFIER { $$ = astCreate(AST_VAR_PRINT,$1, 0,  0, 0, 0); }
|'&'TK_IDENTIFIER { $$ = astCreate(AST_VAR_END, $2,0,  0, 0, 0); }
|'#'TK_IDENTIFIER { $$ = astCreate(AST_VAR_PTR, $2, 0,  0, 0, 0); }
;



lpe: pe lpe {$$ = astCreate(AST_PRINT, 0, $1, $2, 0, 0); }
|{$$ = 0;}
;
read:KW_READ TK_IDENTIFIER { $$ = astCreate(AST_READ, $2, 0, 0, 0, 0); }
;
%%
int yyerror(int code){
    printf("O analisador encontrou um erro na linha %d\n",getLineNumber());
    exit(3);

}
#include "main.c"
