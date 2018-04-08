

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
%token LIT_INTEGER
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
    |LIT_INTEGER
    |LIT_REAL
    |LIT_CHAR
    |LIT_STRING
    | LIT_INT
    | exp OP exp
    |TK_ID '('')'
    |func_call
    ;

    func_call: '('TK_ID func_args ',' l_func_args')'
    ;

    func_args:TK_ID
    |'#' TK_ID
    |'&' TK_ID
    ;

    l_func_args:func_args l_func_args
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
