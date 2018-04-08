%token KW_IF
%token KW_WHILE
%token TK_ID
%token TK_LIT_INT
%token TK_LIT_FLOAT

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
cmd: TK_ID '=' exp
| KW_IF '{'exp ')' cmd cmd
| block
;
exp:TK_ID
| TK_LIT_INT
| exp '+' exp
| exp '-' exp
TK_ID '('')'
;
%%
int yyerror(int code){
    
}
