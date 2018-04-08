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
cmd:TK_ID '=' exp
    |TK_ID '['TK_LIT_INT']' exp
    | KW_IF '('exp ')' 'then' cmd
    | KW_IF ( exp ) 'then' cmd
    | KW_IF ( exp ) 'then' cmd 'else' cmd
    | KW_WHILE ( exp ) cmd
    | KW_FOR (TK_ID = exp 'to' exp) cmd
    | block
    | read
    | print
    ;
exp:TK_ID
    | TK_LIT_INT
    | exp '+' exp
    | exp '-' exp
    TK_ID '('')'
    ;
print: KW_PRINT pe lpe
pe: string
    |TK_ID
    ;
lpe:string
    |TK_ID
    |
    ;
read KW_READ TK_ID
    ;
%%
int yyerror(int code){
    
}
