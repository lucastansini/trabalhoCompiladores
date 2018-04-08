{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf830
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red28\green0\blue207;\red170\green13\blue145;
}
{\*\expandedcolortbl;;\csgenericrgb\c0\c0\c0;\csgenericrgb\c11000\c0\c81000;\csgenericrgb\c66500\c5200\c56900;
}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab543
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \CocoaLigature0 %token KW_IF\
%token KW_WHILE\
%token TK_ID\
%token TK_LIT_INT\
%token TK_LIT_FLOAT\
\
%%\
\
program:\
    ;\
reset: \cf3 ','\cf2  TK_ID reset\
    |\
    ;\
block: \cf3 '\{'\cf2  lcmd \cf3 '\}'\cf2 \
    ;\
lcmd: cmd lcmd\
    |\
    ;\
cmd: TK_ID \cf3 '='\cf2  exp\
    | KW_IF \cf3 '\{'\cf2 exp \cf3 ')'\cf2  cmd cmd\
    | block\
    ;\
exp:TK_ID\
    | TK_LIT_INT\
    | exp \cf3 '+'\cf2  exp\
    | exp \cf3 '-'\cf2  exp\
    TK_ID \cf3 '('')'\cf2 \
    ;\
%%\
\cf4 int\cf2  yyerror(\cf4 int\cf2  code)\{\
    \
\}}