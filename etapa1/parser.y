

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

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token TK_ID
%token LIT_INT
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR


%%

program:
    ;


reset: ',' TK_ID reset
    |
    ;
block: '{' lcmd '}'
    ;


lcmd: cmd lcmd
    |
    ;



cmd:var_dec
    | KW_IF '(' exp ')' KW_THEN cmd
    | KW_IF '(' exp ')' KW_THEN cmd 'else' cmd
    | KW_WHILE '(' exp ')' cmd
    | KW_FOR '('TK_ID '=' exp 'to' exp')' cmd
    | block
    | read
    | print
    ;

var_dec:type TK_ID '=' lit
        |type TK_ID '['exp']'':' vet_dec ';'
        |type '#' TK_ID '=' lit

    ;
type:KW_INT
    |KW_FLOAT
    |KW_CHAR
lit:LIT_REAL
    |"'" LIT_CHAR "'"
    |LIT_INT
vet_dec: lit
        |
        ;
exp:TK_ID
    |lit
    |exp op exp
    |TK_ID '('')'
    |func_call
    ;

func_call: TK_ID'(' func_args  l_func_args')'
    ;

func_args:TK_ID ','
    |'#' TK_ID ','
    |'&' TK_ID ','
    |
    ;

l_func_args:func_args l_func_args
            |
            ;

func_dec:func_header block
        ;

func_header: type TK_ID '(' func_par ')'
        ;  

func_par: type TK_ID
        |
        ;
l_func_par: func_par l_func_par
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

print: KW_PRINT pe lpe


pe: LIT_STRING
    |TK_ID
    ;


lpe:LIT_STRING
    |TK_ID
    |
    ;
read: KW_READ TK_ID
    ;
%%
int yyerror(int code){
    
}
#include "lex.yy.c"
