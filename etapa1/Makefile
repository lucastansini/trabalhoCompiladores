#
# UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2: main.o lex.yy.o parser.tab.o 
	gcc -o etapa2 parser.tab.o lex.yy.o hash.o main.o

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

parser.tab.o: parser.tab.c
	gcc -c parser.tab.c

clean:
	rm lex.yy.c etapa1


