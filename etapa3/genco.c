#include <stdio.h>
#include "tac.h"
#define MAX_VECTOR_PRINT_SIZE 100


void genco(TAC *tac){

	//Guarda o tac inicial
	TAC *initialTac = tac;

	FILE *fp;
	fp = fopen("asm.s","w+");
	if(fp == NULL){
		printf("Erro ao criar arquivo asm.s\n");
		exit(1);
	}else{
		printf("Arquivo asm.s com sucesso.\n");
	}
	int count = 0;
	int count2=0;
	int count3 = 0;

	//variável inicial para controle do vetor que armazena na posição vectorIndex, uma string "xxx", correspondente aquele index em assembly.
	//Exemplo, LC0 - > aaa , então a[0] = "aaa"
	int vectorIndex = 0;
	char *vectorPrint[MAX_VECTOR_PRINT_SIZE];



	for(;tac;tac=tac->next){
		switch(tac->type){
			case TAC_PRINT_TEXT:{
				if(tac->result){
					fprintf(fp,".LC%d:\n		.string	%s\n",vectorIndex,tac->result->yytext);
					vectorPrint[vectorIndex] = tac->result->yytext;
					vectorIndex++;
				}
			}
			break;
		}
	}


	for(;initialTac;initialTac=initialTac->next){
		switch(initialTac->type){
			printf("TAC TYPE:%d\n",tac->type);
			case TAC_BEGIN_FUNCTION:{
				if(initialTac->result){
					fprintf(fp,"\n.globl %s\n .type %s, @function\n %s:\n LFB%d:\n .cfi_startproc\n",initialTac->result->yytext,initialTac->result->yytext,initialTac->result->yytext,count);
					count++;
				}
			}
			break;
			case TAC_PRINT_TEXT:{
				if(initialTac->result){
					int aux = 0;
					int index = 0;
					for(aux; aux < MAX_VECTOR_PRINT_SIZE ; aux++){
						if(vectorPrint[aux] == initialTac->result->yytext){
							index = aux;
						}
					}
					fprintf(fp,"\nmovl	$.LC%d, %%edi\n	movl	$0, %%eax\n	call	printf\n",index);
				}
			}
			break;
			case TAC_END_FUNCTION:
				if(initialTac->result){
					fprintf(fp,".cfi_endproc\n .LFE%d:\n .size %s, .-%s",count2,initialTac->result->yytext,initialTac->result->yytext);
					count2++;
				}
			break;
		}
	}
}
