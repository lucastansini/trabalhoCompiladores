#include<stdio.h>
#include <stdlib.h>
extern FILE * yyin;

extern AST* ast;

int main(int argc, char **argv)
{
    int token;
    FILE    *fd;

    if (argc == 2)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
            yyin = fd;

    }
    else
        printf("Usage: a.out filename\n");


    yyparse();


    astPrint(ast,0);

    exit (0);
}
