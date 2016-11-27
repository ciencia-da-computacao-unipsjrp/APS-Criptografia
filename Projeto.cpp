#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Variaveis globais
int i;
char arquivo [10000];
FILE *fp;

//Fun��o Criptografar
int criptografar()
{
	fp = fopen ("Arquivo.txt", "w");
    if (fp == NULL) 
	{
       printf ("Houve um erro ao abrir o arquivo.\n");
       return 1;
    }
	fflush(stdin);		    
    printf("Digite o que deseja gravar:\n");  
    gets(arquivo);			    
    for( i = 0; i < strlen(arquivo); i++ )
    {
        arquivo[i] += 50;
    }			
    printf(">> Arquivo Gerado: %s\n\n ", arquivo);			    
    for(i=0; arquivo[i]; i++)
	{
		fputc(arquivo[i], fp);
	}	
    printf ("Arquivo criado com sucesso.\n");
    fclose(fp);
    printf("Digite qualquer tecla para voltar ao menu principal!");
	getchar();	
	system("cls");
}

//Fun��o Descriptografar
int descriptografar()
{
	fflush(stdin);
	int i;
	FILE *file;
	file = fopen("Arquivo.txt", "r");		
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo!!\n");
		getchar();
	}				
	system("cls");			 	
	while(fgets(arquivo, 1000, file) != NULL)
 	{
 		for( i = 0; i < strlen(arquivo); i++ )
		    {
		        arquivo[i] -= 50;
		    }
 		printf("%s", arquivo);
	}
	printf("\n\nDigite qualquer tecla para voltar ao menu principal!");
	getchar();
	system("cls");
}


int main()
{
int escolha=0;
	
	while(escolha < 3)
	{
		printf("Bem Vindo ao sistema de criptografia!\n\n\n");
		printf("Digite 1:\nPara criptografar um arquivo.\n\nDigite 2:\nPara descriptografar um arquivo.\n\nDigite3:\nPara Sair.\n");
		scanf("%d",& escolha);
		switch(escolha)
		{			
			case 1:				
				criptografar();		    
			break;
			case 2:				
			 	descriptografar();
			break;
			case 3:
				exit(0);
			break;			
		}
	}
}
