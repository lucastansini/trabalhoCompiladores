#include<stdio.h>
#include <stdlib.h>
extern FILE * yyin;
extern int yydebug;
extern AST* ast_Geral;
FILE * saida;
int main(int argc, char **argv)
{



    saida = fopen(argv[2],"w+");
    int token;
    FILE    *fd;

    //Colocar 'argc==3' para rodar etapa3.
    if (argc == 3)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
            yyin = fd;

    }
    else{
        printf("Usage: a.out filename\n");
	   return 0;	
	}


    hashInit();
    yyparse();


//astPrint();




    exit (0);
}
