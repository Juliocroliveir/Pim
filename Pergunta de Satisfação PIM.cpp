#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fstream>
#include<iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "portuguese");//habilita acentua��o para o portugu�s
	
	ofstream arquivo;
	
	arquivo.open("PesquisaDeSatisfacao.txt", ios::app);//abre o arquivo exixtente, caso n�o exista um novo � criado/ios::app salva sem sobrescrever
	char nome[50];
	
	printf("Digite seu Nome: ");
	gets(nome);
	printf("Ol� %s!",nome);
	arquivo << "\n\nPesquisa feita com:\n"<<nome;
	
	int num1 = -1,num2 = -2,num3 = -3,num4 = -4,num5 = -5,num6 = -6,resp6;
	char input[50];

	

	printf("\n\nA seguir um breve question�rio de avalia��o do evento, com notas de 0 a 5, sendo 0 insatisfeito e 5 totalmente satisfeito");

	while (num1 < 0 || num1 > 5)
	{
		printf("\n\nQual foi seu n�vel de satisfa��o sobre o tema do museu?\n");
		fgets(input, sizeof(input), stdin);

		// Verifica se a entrada � um n�mero
		if (sscanf(input, "%d", &num1) != 1 || num1 < 0 || num1 > 5)
		{
			printf("Informe uma nota de 0 a 5\n");
		}
		else 
		{
			arquivo << "\n\nQual foi seu n�vel de satisfa��o sobre o tema do museu?\n"<<num1;
		}
	}
	
	while (num2 < 0 || num2 > 5)
	{
		printf("\n\nQual o n�vel de compreens�o do tema abordado?\n");
		fgets(input, sizeof(input), stdin);

		// Verifica se a entrada � um n�mero
		if (sscanf(input, "%d", &num2) != 1 || num2 < 0 || num2 > 5)
		{
			printf("Informe uma nota de 0 a 5\n");
		}
		else 
		{
			arquivo << "\n\nQual o n�vel de compreens�o do tema abordado?\n"<<num2;
		}
	}
	
	while (num3 < 0 || num3 > 5)
	{
		printf("\n\nQual nota daria sobre as instala��es?\n");
		fgets(input, sizeof(input), stdin);

		// Verifica se a entrada � um n�mero
		if (sscanf(input, "%d", &num3) != 1 || num3 < 0 || num3 > 5)
		{
			printf("Informe uma nota de 0 a 5\n");
		}
		else 
		{
			arquivo << "\n\nQual nota daria sobre as instala��es?\n"<<num3;
		}
	}	
	
	while (num4 < 0 || num4 > 5)
	{
		printf("\n\nQual nota voce daria para a organiza��o do evento?\n");
		fgets(input, sizeof(input), stdin);

		// Verifica se a entrada � um n�mero
		if (sscanf(input, "%d", &num4) != 1 || num4 < 0 || num4 > 5)
		{
			printf("Informe uma nota de 0 a 5\n");
		}
		else 
		{
			arquivo << "\n\nQual nota voce daria para a organiza��o do evento?\n"<<num4;
		}
	}

	while (num5 < 0 || num5 > 5)
	{
		printf("\n\nQual o n�vel de atendimento?\n");
		fgets(input, sizeof(input), stdin);

		// Verifica se a entrada � um n�mero
		if (sscanf(input, "%d", &num5) != 1 || num5 < 0 || num5 > 5)
		{
			printf("Informe uma nota de 0 a 5\n");
		}
		else 
		{
			arquivo << "\n\nQual o n�vel de atendimento?\n"<<num5;
		}
	}
	
	while (num6 < 0 || num6 > 5)
	{
		printf("\n\nQual a possibilidade de indicar a visita ao museu?\n");
		fgets(input, sizeof(input), stdin);

		// Verifica se a entrada � um n�mero
		if (sscanf(input, "%d", &num6) != 1 || num6 < 0 || num6 > 5)
		{
			printf("Informe uma nota de 0 a 5\n");
		}
		else 
		{
			resp6=(num6*20);
			arquivo << "\n\nQual a possibilidade de indicar a visita ao museu?\n"<<num6<<"\n"<<resp6<<"%";
		}
	}
	
	system("pause");
	return 0;
}
