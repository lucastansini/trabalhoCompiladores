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
	int vectorGlobalIndex = 0;
	char *vectorPrint[MAX_VECTOR_PRINT_SIZE];
	char *vectorGlobalAssing[MAX_VECTOR_PRINT_SIZE];
	int alreadyPrintedAssing = 0;

	//Enquanto tiver tacnext
	while((tac=tac->next)){
		switch(tac->type){
			case TAC_PRINT_TEXT:{
				if((tac->result) && (tac->result->yytext[0] == '"')){
					fprintf(fp,".LC%d:\n		.string	%s\n",vectorIndex,tac->result->yytext);
					vectorPrint[vectorIndex] = tac->result->yytext;
					vectorIndex++;
				}
			}
			break;
			//Assinalamento de variáveis, assumindo todas como float.
			case TAC_ASS:{
				alreadyPrintedAssing = 0;
				if(tac->result){
					int aux2=0;
					for(aux2; aux2 < MAX_VECTOR_PRINT_SIZE ; aux2++){
						if(vectorGlobalAssing[aux2] == tac->result->yytext){
							alreadyPrintedAssing = 1;
						}
					}
					if(alreadyPrintedAssing == 0){
						fprintf(fp,".globl %s\n \t.align 4\n  \t.type %s, @object\n  \t.size %s, 4\n%s:\n  \t.long %s\n",tac->result->yytext,tac->result->yytext,tac->result->yytext,tac->result->yytext,tac->op1->yytext);
						vectorGlobalAssing[vectorGlobalIndex] = tac->result->yytext;
						vectorGlobalIndex++;
					}
				}
			}
			break;
		}
	}


	//LC9999999 é utilizado para printar floats.
	fprintf(fp,".LC9999999:\n	\t.string	\"%%");
	fprintf(fp,"d");
	fprintf(fp,"\"");



	for(;initialTac;initialTac=initialTac->next){
		switch(initialTac->type){
			printf("TAC TYPE:%d\n",tac->type);
			case TAC_BEGIN_FUNCTION:{
				if(initialTac->result){
					fprintf(fp,"\n.globl %s\n .type %s, @function\n %s:\n LFB%d:\n .cfi_startproc\n",initialTac->result->yytext,initialTac->result->yytext,initialTac->result->yytext,count);
					/*pushq	%rbp
						.cfi_def_cfa_offset 16
						.cfi_offset 6, -16
						movq	%rsp, %rbp
						.cfi_def_cfa_register 6*/
					fprintf(fp,"\tpushq %%rbp\n\t.cfi_def_cfa_offset 16\n\t.cfi_offset 6, -16\n\tmovq	%%rsp, %%rbp\n\t.cfi_def_cfa_register 6\n");
					count++;
				}
			}
			break;
			case TAC_PRINT_TEXT:{
				if(initialTac->result){
					//Precisamos saber se é string ou variável. Para saber se é string, olharemos para o primeiro caractere, que deve ser ", senao é variável.
					char *auxPrint = initialTac->result->yytext;
					if(auxPrint[0] == '"'){
						int aux = 0;
						int index = 0;
						for(aux; aux < MAX_VECTOR_PRINT_SIZE ; aux++){
							if(vectorPrint[aux] == initialTac->result->yytext){
								index = aux;
							}
						}
						fprintf(fp,"\nmovl	$.LC%d, %%edi\n	movl	$0, %%eax\n	call	printf\n",index);
					}else{
						//printar variavel
	// 					movl	i(%rip), %eax
 // movl	%eax, %esi
 // movl	$.LC0, %edi
 // movl	$0, %eax
 // call	printf
							fprintf(fp,"\tmovl %s(%%rip),%%eax\nmovl %%eax, %%esi\n\tmovl $.LC9999999, %%edi\n\tmovl $0, %%eax\n\tcall printf\n",initialTac->result->yytext);
					}
				}
			}
			break;
			case TAC_END_FUNCTION:
				if(initialTac->result){
					/*movl	$0, %eax
					popq	%rbp
					.cfi_def_cfa 7, 8
					ret*/
					fprintf(fp,"\tmovl $0, %%eax\n\tpopq %%rbp\n\t.cfi_def_cfa 7, 8\n\tret\n");
					fprintf(fp,".cfi_endproc\n .LFE%d:\n .size %s, .-%s",count2,initialTac->result->yytext,initialTac->result->yytext);
					count2++;
				}
			break;
		}
	}
}
