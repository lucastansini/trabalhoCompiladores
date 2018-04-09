#
# UFRGS - Compiladores B - Marcelo Johann - 2018/1 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2:      parser.tab.o lex.yy.o
	gcc -o etapa2  parser.tab.o 
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex scanner.l

parser.tab.c: parser.y
	bison -d -v parser.y

parser.tab.o: parser.tab.c
	gcc -c parser.tab.c

clean:
	rm lex.yy.c etapa2 
