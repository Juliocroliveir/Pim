#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<fstream>

int main()
{
	setlocale(LC_ALL, "portuguese");//habilita acentuação para o português
	
	int resp = 1;
	int ingressosCheios = 0;
	int ingressosMeia = 0;
	int ingressosIsentos = 0;
	int valorBaseExposicao = 20; // Valor base de uma Exposição
	int numeroTicket = 1000;	 // Número inicial do ticket

	
	FILE *arquivoTickets = fopen("tickets.csv", "a+");

	while (resp != 0)
	{
		printf("\n1 - Comprar Ingresso\n");
		printf("2 - Dar Baixa no Ticket\n");
		printf("0 - Sair\n");
		scanf("%d", &resp);

		switch (resp)
		{
		case 1:
		{
			int tipoIngresso, numExposicoes;
			printf("Escolha o tipo de ingresso (1 - Inteira, 2 - Meia, 3 - Isento): ");
			scanf("%d", &tipoIngresso);

			if (tipoIngresso < 1 || tipoIngresso > 3)
			{
				printf("Opção de ingresso invalida. Tente novamente.\n");
				break;
			}

			printf("Para quantas exposições você deseja comprar ingressos? ");
			scanf("%d", &numExposicoes);

			for (int i = 0; i < numExposicoes; i++)
			{
				int valorExposicaoAtual = 0;

				if (tipoIngresso == 1)
				{
					valorExposicaoAtual = valorBaseExposicao;
				}
				else if (tipoIngresso == 2)
				{
					valorExposicaoAtual = valorBaseExposicao / 2;
				}
				else if (tipoIngresso == 3)
				{
					valorExposicaoAtual = 0;
				}

				fprintf(arquivoTickets, "Ticket: %d, Tipo de Ingresso: %d, Exposição: %d, Valor Total: %d,\n", numeroTicket, tipoIngresso, i + 1, valorExposicaoAtual);
				printf("Ingresso para a Exposição %d registrado com sucesso. Seu número de ticket é %d.\n", i + 1, numeroTicket);
				numeroTicket++; // Incremento do número do ticket após cada compra de ingresso
			}

			if (tipoIngresso == 1)
			{
				ingressosCheios += numExposicoes;
			}
			else if (tipoIngresso == 2)
			{
				ingressosMeia += numExposicoes;
			}
			else if (tipoIngresso == 3)
			{
				ingressosIsentos += numExposicoes;
			}

			int totalPagar = ingressosCheios * valorBaseExposicao + ingressosMeia * (valorBaseExposicao / 2);
			printf("Total a Pagar: %d\n", totalPagar);

			break;
		}
		case 2:
		{
			printf("Digite o número do ticket que deseja dar baixa: ");
			int numTicket;
			scanf("%d", &numTicket);

			// Utilizamos um arquivo temporario para atualizar os status dos Tickets
			FILE *arquivoTemporario = fopen("temp.txt", "w");
			fseek(arquivoTickets, 0, SEEK_SET);

			char linha[200];
			bool ticketEncontrado = false;

			while (fgets(linha, sizeof(linha), arquivoTickets) != NULL)
			{
				int numeroTicketArquivo, tipoIngresso, exposicao, valorExposicao, status;
				if (sscanf(linha, "Ticket: %d, Tipo de Ingresso: %d, Exposição: %d, Valor Total: %d, Status: %d", &numeroTicketArquivo, &tipoIngresso, &exposicao, &valorExposicao, &status) == 5)
				{
					if (numeroTicketArquivo == numTicket)
					{
						ticketEncontrado = true;
						if (status == 0)
						{
							fprintf(arquivoTemporario, "Ticket: %d, Tipo de Ingresso: %d, Exposição: %d, Valor Total: %d, Status: 1\n", numTicket, tipoIngresso, exposicao, valorExposicao);
							printf("Ticket número %d foi dado baixa no sistema.\n", numTicket);
						}
						else if (status == 1)
						{
							printf("O ticket já foi utilizado.\n");
							fprintf(arquivoTemporario, "%s", linha); // Manter a entrada original no arquivo temporário
						}
					}
					else
					{
						fprintf(arquivoTemporario, "%s", linha); // Manter as outras entradas no arquivo temporário
					}
				}
			}

			if (!ticketEncontrado)
			{
				printf("Ticket não encontrado.\n");
			}

			fclose(arquivoTickets);
			fclose(arquivoTemporario);

			remove("tickets.txt");
			rename("temp.txt", "tickets.txt");

			arquivoTickets = fopen("tickets.txt", "a+");

			break;
		}
		case 0:
			// Código para sair do programa
			fclose(arquivoTickets);
			break;
		default:
			// Código para tratar opçãoo inválida
			printf("Opçãoo inválida. Tente novamente.\n");
			break;
		}
	}

	printf("\nIngressos Vendidos\nCheios: %d, Meia: %d, Isentos: %d\n", ingressosCheios, ingressosMeia, ingressosIsentos);

	return 0;
}
