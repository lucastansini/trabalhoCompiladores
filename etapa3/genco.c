#include <stdio.h>
#include "tac.h"



void genco(TAC *tac){

	FILE *fp;
	fp = fopen("asm.s","rw+");
	if(fp == NULL){
		printf("Erro ao criar arquivo asm.s\n");
		exit(1);
	}else{
		printf("Arquivo asm.s com sucesso.\n");
	}
	int count = 0;
	int count2=0;
	int count3 = 0;
	for(;tac;tac=tac->next){
		switch(tac->type){
			printf("TAC TYPE:%d\n",tac->type);
			case TAC_BEGIN_FUNCTION:{
				if(tac->result){
					fprintf(fp,"\n.globl %s\n .type %s, @function\n %s:\n LFB%d:\n",tac->result->yytext,tac->result->yytext,tac->result->yytext,count);
					count++;
				}
			}
			break;
			case TAC_PRINT_TEXT:{
				if(tac->result){
					fprintf(fp,".LC%d:\n		.string	%s\n",count3,tac->result->yytext);
					fprintf(fp,"\nmovl	$.LC%d, %%edi\n	movl	$0, %%eax\n	call	printf\n",count3);
				}
				count3++;
			}
			break;
			case TAC_END_FUNCTION:
				if(tac->result){
					fprintf(fp,".LFE%d:\n .size %s, .-%s",count2,tac->result->yytext,tac->result->yytext);
					count2++;
				}
			break;
		}
	}
}
