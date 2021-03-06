#include <stdio.h>
#include "tac.h"
#define MAX_VECTOR_PRINT_SIZE 100
#define MAX_VECTOR_PARAM_LIST 17



int digitoSegundo(TAC*tac){
	int i = 0;
	while(*tac->op2->yytext){
		if(isdigit(*tac->op2->yytext++)==0){
			//restore one position
			*tac->op2->yytext--;
			return 0;
		}
		i++;
	}
	for(i;i>0;i--){
		*tac->op2->yytext--;
	}
	return 1;
}

int digitoPrimeiro(TAC* tac){
	int i = 0;
	while(*tac->op1->yytext){
		if(isdigit(*tac->op1->yytext++)==0){
			//restore one position
			*tac->op1->yytext--;
			return 0;
		}
		i++;
	}
	//Restore the pointer.
	for(i;i>0;i--){
		*tac->op1->yytext--;
	}
	//printf("i is equalt to:%d\n",i);
	return 1;
}

int digitoResult(TAC* tac){
	int i = 0;
	while(*tac->result->yytext){
		if(isdigit(*tac->result->yytext++)==0){
			//restore one position
			*tac->result->yytext--;
			return 0;
		}
		i++;
	}
	//Restore the pointer.
	for(i;i>0;i--){
		*tac->result->yytext--;
	}
	//printf("i is equalt to:%d\n",i);
	return 1;
}

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
	int paramCont=0;
	int paramContPush = 0;
	int insideFunction = 0;
	int countLabelAndLeite = 0;
	int isCalled = 0;
	char *paramVectorList[MAX_VECTOR_PARAM_LIST];

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
		//	Assinalamento de variáveis, assumindo todas como float.
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
						if(!strcmp(tac->op1->yytext,"0")){
							//.comm	VARIAVEL,4,4
							fprintf(fp,"\t.comm %s,4,4\n",tac->result->yytext);
							vectorGlobalAssing[vectorGlobalIndex] = tac->result->yytext;
							vectorGlobalIndex++;
						}else {
							fprintf(fp,".globl %s\n\t.data\n \t.align 4\n  \t.type %s, @object\n  \t.size %s, 4\n%s:\n  \t.long %s\n",tac->result->yytext,tac->result->yytext,tac->result->yytext,tac->result->yytext,tac->op1->yytext);
							vectorGlobalAssing[vectorGlobalIndex] = tac->result->yytext;
							vectorGlobalIndex++;
						}
					}
				}
			}
			break;
			case TAC_ADD:
			case TAC_EQUAL:
			case TAC_VECREAD:
			case TAC_MULT:
			case TAC_CALL:
			case TAC_RETURN:
			case TAC_LESS_THEN:
				fprintf(fp,"\t.comm %s,4,4\n",tac->result->yytext);
			break;


			/*For vectors, we have different types, though the mem allocated will be always 32 to simplify the process.
			1 int	v[10] = .comm 10*4,32
			2 char v[10] = .comm	v,8,32  (8 is the index of array and 32 is the mem allocated.)
			3 float v[10] = = .comm 10*4,32*/
			case TAC_VECTOR_MEM_INIT:{
				int valueIndex = atoi(tac->op1->yytext) * 4;
				fprintf(fp,"\t.comm	%s,%d,32\n",tac->result->yytext,valueIndex);
			}
		}
	}


	//LC9999999 é utilizado para printar floats.
	fprintf(fp,".LC9999999:\n	\t.string	\"%%");
	fprintf(fp,"d");
	fprintf(fp,"\"");



	while(initialTac = initialTac->next){
		switch(initialTac->type){
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
					insideFunction = 1;
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
					if(isCalled){
						fprintf(fp,"\t.cfi_def_cfa 7, 8\n\tret\n");
						fprintf(fp,".cfi_endproc\n .LFE%d:\n \t.size %s, .-%s",count2,initialTac->result->yytext,initialTac->result->yytext);
						//Warnings do compilador exigem uma newline no final do arquivo.
						fprintf(fp,"\n");
						isCalled = 0;
					}else{
						fprintf(fp,"\tmovl $0, %%eax\n");
						fprintf(fp,"\tpopq %%rbp\n\t.cfi_def_cfa 7, 8\n\tret\n");
						fprintf(fp,".cfi_endproc\n .LFE%d:\n \t.size %s, .-%s",count2,initialTac->result->yytext,initialTac->result->yytext);
						//Warnings do compilador exigem uma newline no final do arquivo.
						fprintf(fp,"\n");
					}

					count2++;
					insideFunction = 0;
				}
			break;

			case TAC_ADD:{
				char* savedOp1 = initialTac->op1->yytext;
				char* savedOp2 = initialTac->op2->yytext;
				char* savedResult = initialTac->result->yytext;
				TAC* auxTac = initialTac;
				// printf("OP1ADRESSTAC:%d\n",initialTac->op1);
				// printf("YYTEXTINITIALTAC:%s\n",initialTac->op1->yytext);
				// printf("OP1SYMBOL:%s\n",savedOp1);
				if(initialTac->result){
				 	if(digitoPrimeiro(initialTac)){
						fprintf(fp,"\tmovl	$%s, %%edx\n",savedOp1);
					}else{
						int i = 0;
						int indexOnStack = 0;
						int isLocal = 0;
						for(i=0;i<MAX_VECTOR_PARAM_LIST;i++){
							if( paramVectorList[i] == savedOp1){
								indexOnStack = i;
								isLocal = 1;
							}
						}
						if(isLocal){
							fprintf(fp,"\tmovl -%d(%%rbp), %%edx\n",indexOnStack);
						}else{
							fprintf(fp,"\tmovl	%s(%%rip), %%edx\n",savedOp1);
						}
					}
					if(digitoSegundo(initialTac)){
						fprintf(fp,"\tmovl $%s, %%eax\n",savedOp2);
					}else{
						int i = 0;
						int indexOnStack = 0;
						int isLocal = 0;
						for(i=0;i<MAX_VECTOR_PARAM_LIST;i++){
							if( paramVectorList[i] == savedOp2){
								indexOnStack = i;
								isLocal = 1;
							}
						}
						if(isLocal){
							fprintf(fp,"\tmovl -%d(%%rbp), %%eax\n",indexOnStack);
						}else{
							fprintf(fp,"\tmovl	%s(%%rip), %%eax\n",savedOp2);
						}
					}
					fprintf(fp,"\taddl %%eax,%%edx\n"); //edx guarda o resultado da soma!
					fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
				}
			}
			break;
			case TAC_RETURN:{
				if(digitoPrimeiro(initialTac)){
					fprintf(fp,"\tmovl $%s, %s(%%rip)\n",initialTac->op1->yytext,initialTac->result->yytext);
					fprintf(fp,"\tpopq %%rbp\n");
				}else{
					fprintf(fp,"\tmovl %s(%%rip), %%edx\n",initialTac->op1->yytext);
					fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",initialTac->result->yytext);
					fprintf(fp,"\tmovl %s(%%rip), %%eax\n",initialTac->result->yytext);
					fprintf(fp,"\tpopq %%rbp\n");
				}
			}break;
			/*movl	a(%rip), %edx
				movl	b(%rip), %eax
				imull	%edx, %eax*/
			case TAC_MULT:{
				TAC* auxTac = initialTac;
				printf("Teste:%s\n",initialTac->op1->yytext);
				// while(*initialTac->op1->yytext){
				// 	*savedOp1 = *initialTac->op1->yytext;
				// 	printf("Teste:%s\n",initialTac->op1->yytext);
				// }
				char* savedOp1 = initialTac->op1->yytext;
				char* savedOp2 = initialTac->op2->yytext;
				char* savedResult = initialTac->result->yytext;
				if(initialTac->result){

					if(digitoPrimeiro(initialTac)){
						fprintf(fp,"\tmovl $%s, %%edx\n",savedOp1);
					}else{
						fprintf(fp,"\tmovl %s(%%rip), %%edx\n",savedOp1);
					}

					if(digitoSegundo(initialTac)){
						fprintf(fp,"\tmovl $%s, %%eax\n",savedOp2);
					}else{
						fprintf(fp,"\tmovl %s(%%rip), %%eax\n",savedOp2);
					}
					fprintf(fp,"\timull %%edx, %%eax\n");
					fprintf(fp,"\tmovl %%eax, %s(%%rip)\n",savedResult);
				}
			}
			break;
			/*movl	a(%rip), %eax
			movl	%eax, c(%rip)*/
			case TAC_ASS:{
				char* savedOp1 = initialTac->op1->yytext;
				char* savedResult = initialTac->result->yytext;
				// printf("OP1ADRESSTAC:%d\n",initialTac->op1);
				// printf("YYTEXTINITIALTAC:%s\n",initialTac->op1->yytext);
				// printf("OP1SYMBOL:%s\n",savedOp1);

				if(initialTac->result){
					if(insideFunction){
						if(digitoPrimeiro(initialTac)){
							fprintf(fp,"\tmovl $%s, %s(%%rip)\n",savedOp1,savedResult);
						}else{
							fprintf(fp,"\tmovl %s(%%rip), %%eax\n",savedOp1);
							fprintf(fp,"\tmovl %%eax, %s(%%rip)\n",savedResult);
						}
					}
				}
							// printf("RESULT:%s\n",savedResult);
							// printf("OP1:%s\n",savedOp1);
			}
			break;
			/*IF COM DUAS VARIAVEIS
			movl	a(%rip), %edx
			movl	b(%rip), %eax
			cmpl	%eax, %edx
			jne	.L2*/
			/*IF A == 2
			movl	a(%rip), %eax
			cmpl	$2, %eax*/
			case TAC_EQUAL:{
				char* savedOp1 = initialTac->op1->yytext;
				char* savedOp2 = initialTac->op2->yytext;
				char* savedResult = initialTac->result->yytext;
				if(insideFunction){
					if(initialTac->result){
						if(digitoPrimeiro(initialTac)){
							fprintf(fp,"\tmovl $%s, %%edx\n",savedOp1);
						}else{
							fprintf(fp,"\tmovl %s(%%rip), %%edx\n",savedOp1);
						}

						if(digitoSegundo(initialTac)){
							fprintf(fp,"\tmovl $%s, %%eax\n",savedOp2);
						}else{
							fprintf(fp,"\tmovl %s(%%rip), %%eax\n",savedOp2);
						}
						fprintf(fp,"\tcmpl %%eax,%%edx\n");
						// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
						fprintf(fp,"\tjz LabelTeste_ParavVEerLuuL1KKAKSSszz12345a%d\n",countLabelAndLeite);
						fprintf(fp,"\tmovl $1, %s(%%rip)\n",savedResult);
						fprintf(fp,"\tjmp Leeeeiteeeee%d\n",countLabelAndLeite);
						fprintf(fp,"LabelTeste_ParavVEerLuuL1KKAKSSszz12345a%d:\n",countLabelAndLeite);
						fprintf(fp,"\tmovl $0, %s(%%rip)\n",savedResult);
						fprintf(fp,"Leeeeiteeeee%d:\n",countLabelAndLeite);
						countLabelAndLeite++;
					}
				}
			}break;
			/*Com variáveis para fazer a comparação
				movl	a(%rip), %edx
				movl	b(%rip), %eax
				Com números
				movl	a(%rip), %eax
				cmpl	$1, %eax*/
			case TAC_LESS_THEN:{
				char* savedOp1 = initialTac->op1->yytext;
				char* savedOp2 = initialTac->op2->yytext;
				char* savedResult = initialTac->result->yytext;
				if(insideFunction){
					if(initialTac->result){
						if(digitoPrimeiro(initialTac)){
							fprintf(fp,"\tmovl $%s, %%edx\n",savedOp1);
						}else{
							fprintf(fp,"\tmovl %s(%%rip), %%edx\n",savedOp1);
						}

						if(digitoSegundo(initialTac)){
							fprintf(fp,"\tmovl $%s, %%eax\n",savedOp2);
						}else{
							fprintf(fp,"\tmovl %s(%%rip), %%eax\n",savedOp2);
						}
						fprintf(fp,"\tcmpl %%eax,%%edx\n");
						// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
						fprintf(fp,"\tjl LabelTeste_ParavVEerLuuL1KKAKSSszz12345a%d\n",countLabelAndLeite);
						fprintf(fp,"\tmovl $1, %s(%%rip)\n",savedResult);
						fprintf(fp,"\tjmp Leeeeiteeeee%d\n",countLabelAndLeite);
						fprintf(fp,"LabelTeste_ParavVEerLuuL1KKAKSSszz12345a%d:\n",countLabelAndLeite);
						fprintf(fp,"\tmovl $0, %s(%%rip)\n",savedResult);
						fprintf(fp,"Leeeeiteeeee%d:\n",countLabelAndLeite);
						countLabelAndLeite++;
					}
				}
			}break;
			case TAC_IF_ZERO:{
				if(insideFunction){
					if(initialTac->result){
						fprintf(fp,"\tmovl %s(%%rip), %%eax\n",initialTac->op1->yytext);
						fprintf(fp,"\tcmpl	$0, %%eax\n");
						fprintf(fp,"\tjnz	%s\n",initialTac->result->yytext);
					}
				}
			}break;
			case TAC_IF_ZERO_FOR:{
				if(insideFunction){
					if(initialTac->result){
						fprintf(fp,"\tmovl %s(%%rip), %%eax\n",initialTac->op1->yytext);
						fprintf(fp,"\tcmpl	$0, %%eax\n");
						fprintf(fp,"\tjz	%s\n",initialTac->result->yytext);
					}
				}
			}break;
			case TAC_LABEL:{
				if(insideFunction){
					fprintf(fp,"%s:\n",initialTac->result->yytext);
				}
			}break;
			case TAC_JUMP:{
				if(insideFunction){
					fprintf(fp,"\tjmp %s\n",initialTac->result->yytext);
				}
			}break;
			/*Com variáveis movl	c(%rip), %eax
											cltq
											movl	$55, a(,%rax,4)*/
			case TAC_VECWRITE:{
				//Se for dígito no index
				if(digitoPrimeiro(initialTac)){
					int indexToStore = atoi(initialTac->op1->yytext) * 4;
					fprintf(fp,"\tmovl $%s, %s+%d(%%rip)\n",initialTac->op2->yytext,initialTac->result->yytext,indexToStore);
				}else{
					fprintf(fp,"\tmovl %s(%%rip), %%eax\n",initialTac->op1->yytext);
					fprintf(fp,"\tcltq\n");
					fprintf(fp,"\tmovl $%s, %s(,%%rax,4)\n",initialTac->op2->yytext,initialTac->result->yytext);
				}
			}break;
			/*Se for c = a[2]
				movl	a+8(%rip), %eax
			  movl	%eax, c(%rip)
				----------------------
				Se for c = a[b] por Exemplo
				movl	b(%rip), %eax
				cltq
				movl	a(,%rax,4), %eax
				movl	%eax, c(%rip)*/
			case TAC_VECREAD:{
				if(digitoSegundo(initialTac)){
					int valueToAdd = atoi(initialTac->op2->yytext) * 4;
					fprintf(fp,"\tmovl %s+%d(%%rip), %%eax\n",initialTac->op1->yytext,valueToAdd);
					fprintf(fp,"\tmovl %%eax, %s(%%rip)\n",initialTac->result->yytext);
				}else{
					fprintf(fp,"\tmovl %s(%%rip), %%eax\n", initialTac->op2->yytext);
					fprintf(fp,"\tcltq\n");
					fprintf(fp,"\tmovl %s(,%%rax,4), %%eax\n",initialTac->op1->yytext);
					fprintf(fp,"\tmovl %%eax, %s(%%rip)\n",initialTac->result->yytext);
				}
			}break;
			/*movl	$a, %esi
			movl	$.LC0, %edi
			movl	$0, %eax
			call	__isoc99_scanf*/
			case TAC_READ:{
				fprintf(fp,"\tmovl $%s, %%esi\n",initialTac->result->yytext);
				fprintf(fp,"\tmovl $.LC9999999, %%edi\n");
				fprintf(fp,"\tmovl $0, %%eax\n");
				fprintf(fp,"\tcall __isoc99_scanf\n");
			}break;
			case TAC_INC:{
				fprintf(fp,"\tmovl %s(%%rip), %%edx\n",initialTac->result->yytext);
				fprintf(fp,"\tmovl $1, %%eax\n");
				fprintf(fp,"\taddl %%eax, %%edx\n");
				fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",initialTac->result->yytext);
			}break;
			case TAC_CALL:{
				fprintf(fp,"\tcall %s\n",initialTac->op1->yytext);
				fprintf(fp,"\tmovl %%eax, %s(%%rip)\n",initialTac->result->yytext);
			}break;
			case TAC_PUSH:{
				if(digitoResult(initialTac)){
					fprintf(fp,"\tmovl $%s, ",initialTac->result->yytext);
				}else{
					fprintf(fp,"\tmovl %s(%%rip), %%edx\n",initialTac->result->yytext);
					fprintf(fp,"\tmovl %%edx, ");
				}
				switch(paramContPush){
				case 0:{
					fprintf(fp,"%%edi\n"); //esi
				}break;
				case 1:{
					fprintf(fp,"%%esi\n"); //ecx
				}break;
				case 2:{
					fprintf(fp,"%%ecx\n"); //edx
				}break;
				case 3:{
					fprintf(fp,"%%esi\n"); //esi
				}break;
				default:
				break;
			}
				paramContPush++;
			}break;
			case TAC_PAR_LIST:{
				/*movl	%edi, -4(%rbp)
					movl	%esi, -8(%rbp)
					movl	%edx, -12(%rbp)
					movl	%ecx, -16(%rbp)
					movl	%r8d, -20(%rbp)
					De acordo com quantos parametros temos, precisamos usar um numero
					x de registradores.*/
					isCalled = 1;
				switch (paramCont){
					case 0:{
						fprintf(fp,"\tmovl %%edi, -4(%%rbp)\n");
						paramVectorList[4] = initialTac->result->yytext;
						// printf("%s\n",paramVectorList[4]);
					}break;
					case 1:{
						fprintf(fp,"\tmovl %%esi, -8(%%rbp)\n");
						paramVectorList[8] = initialTac->result->yytext;
					}break;
					case 2:{
						fprintf(fp,"\tmovl %%ecx, -12(%%rbp)\n");
						paramVectorList[12] = initialTac->result->yytext;
					}break;
					case 3:{
						fprintf(fp,"\tmovl %%r8d, -16(%%rbp)\n");
						paramVectorList[16] = initialTac->result->yytext;
					}break;
					default:
					break;
				}
					paramCont++;
			}break;
		}
	}
}
