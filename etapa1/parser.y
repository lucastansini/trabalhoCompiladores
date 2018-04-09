

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

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR
%{
    
    
    %}

%%

program: ldec
    |
    ;
reset: ',' TK_IDENTIFIER reset
    |
    ;
block: '{' lcmd '}'
    ;
dec:KW_IF '(' exp ')' KW_THEN cmd ';'
    | KW_IF '(' exp ')' KW_THEN cmd 'else' cmd ';'
    | KW_WHILE '(' exp ')' cmd ';'
    | KW_FOR '('TK_ID '=' exp 'to' exp')' cmd
    ;
ldec: dec ldec


lcmd: cmd lcmd
    |
    ;



cmd:var_dec
    | block
    | read
    | print
    ;

var_dec:type TK_IDENTIFIER '=' lit
        |type TK_IDENTIFIER '['exp']'':' vet_dec ';'
        |type '#' TK_IDENTIFIER '=' lit
        ;
type:KW_INT
    |KW_FLOAT
    |KW_CHAR
    ;
lit:LIT_REAL
    |"'" LIT_CHAR "'"
    |LIT_INT
    ;
vet_dec: lit
        |
        ;
exp:TK_IDENTIFIER
    |lit
    |exp op exp
    |TK_IDENTIFIER '('')'
    |func_call
    ;

func_call: TK_IDENTIFIER'(' func_args  l_func_args')'
    ;

func_args:TK_IDENTIFIER ','
    |'#' TK_IDENTIFIER ','
    |'&' TK_IDENTIFIER ','
    |
    ;

l_func_args:func_args l_func_args
            |
            ;

func_dec:func_header block
        ;

func_header: type TK_IDENTIFIER '(' func_par ')'
        ;  

func_par: type TK_IDENTIFIER
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
    |TK_IDENTIFIER
    ;


lpe:LIT_STRING
    |TK_IDENTIFIER
    |
    ;
read: KW_READ TK_IDENTIFIER
    ;
%%
int yyerror(int code){
    printf("Erro na linha %d   ------>",getLineNumber());
    exit(3);
    
}
#include "main.c"
