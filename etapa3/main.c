#include<stdio.h>
#include <stdlib.h>
extern FILE * yyin;

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


    hashPrint();

    exit (0);
}
