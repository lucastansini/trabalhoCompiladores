#
# UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2: main.o lex.yy.o y.tab.o
	gcc -o etapa2 y.tab.o lex.yy.o main.o

#hash.o: hash.c
#	gcc -c hash.c

main.o: main.c
	gcc -c main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l

parser.tab.c: parser.y
	yacc parser.y

y.tab.o: y.tab.c
	gcc -c y.tab.c

clean:
	rm lex.yy.c etapa1
