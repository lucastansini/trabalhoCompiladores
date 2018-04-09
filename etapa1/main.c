#include<stdio.h>
extern FILE * yyin;

int main(int argc, char **argv)
{
    int tok;
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

    return (0);
}
