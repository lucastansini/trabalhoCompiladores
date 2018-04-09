etapa2: parser.tab.c lex.yy.c
	cc -o etapa2 lex.yy.c parser.tab.c

parser.tab.c: parser.y
	bison -d -v parser.y
	
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c y.tab.h y.output etapa2