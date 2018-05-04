#include<stdio.h>
#include <stdlib.h>
extern FILE * yyin;
extern int yydebug;
extern AST* ast_Geral;

int main(int argc, char **argv)
{



   FILE *saida = fopen("saida.txt","w+");
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


//astPrint();


    astPrint(ast_Geral,0,saida);



    exit (0);
}
