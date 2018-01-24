//
//  main.c
//  IP_TP2
//
//  Created by Fernando Carvalho on 16/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libveiculo.h"

void menu(void);//menu geral
void menuveiculos(void);//função menu dos veiculos
void menuviaturas(void);//função menu das viaturas
void menumotoristas(void);//função menu dos motoristas
void menuviagens(void);//função menu de viagens
void menuestatistica(void);//função do menu de estatisticas

void registaveiculo(void);// função registo de veiculos

void menu(){
	char opcao = ' ';

	do {
		printf("\nGestao de Veiculos do Quartel de Bombeiros XTPOZ");
		printf("\nOpcoes");
		printf("\nA - Veiculos");
		printf("\nB - Motoristas");
		printf("\nC - Viagens");
		printf("\nD - Estatistica");
		printf("\nQ - Sai\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
		case 'a':;
		case 'A':
				menuveiculos();
				break;
		case 'b':;
		case 'B':
				menumotoristas();
				break;
		case 'c':;
		case 'C':
				menuviagens();
				break;
		case 'd':;
		case 'D':
				menuestatistica();
				break;
			case 'q':;
			case 'Q': return;
		default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

void menuveiculos(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Veiculos");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Alterar");
		printf("\nC - Apagar");
		printf("\nD - Listar");
		printf("\nE - Tipo de veiculos");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'a':;
			case 'A':
				registaveiculo();
				break;
			case 'B':
				break;
			case 'c':;
			case 'C':eliminaveiculo();
				break;
			case 'd':;
			case 'D':listaveiculo();
				break;
			case 'E':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

void menumotoristas(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Motoristas");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Alterar");
		printf("\nC - Apagar");
		printf("\nD - Listar");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

void menuviagens(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Viagens");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Listar");
		printf("\nC - Tipo de Viagem");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

void menuestatistica(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Estatistica");
		printf("\nOpcoes");
		printf("\nA - Numero total de viagens e Km (Veiculos e motoristas)");
		printf("\nB - Numero medio de Km por viagem (Veiculos)");
		printf("\nC - Custo medio por viagem (Veiculos)");
		printf("\nD - Distancia");
		printf("\nE - Viagens");
		printf("\nF - Viagens");
		printf("\nG - Estatistica");
		printf("\nQ - Sai\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'A':				
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'E':
				break;
			case 'F':
				break;
			case 'G':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

void registaveiculo(){
	char opcao = ' ';
	veiculo veiculos[1000];
	int i = 0, j = 0, resultado = 0;
	
	do {
		printf("\nID: ");
		scanf("%d", &veiculos[i].idveiculo);
		printf("\nTipo de veiculo: ");
		scanf("%d", &veiculos[i].tipoveiculo);
		printf("\nMarca: ");
		scanf("%s", veiculos[i].marca);
		printf("\nModelo: ");
		scanf("%s", veiculos[i].modelo);
		printf("\nMatricula (xx-xx-xx): ");
		scanf("%s", veiculos[i].matricula);
		printf("\nData da matricula (ddmmaaaa): ");
		scanf("%d", &veiculos[i].datamatricula);
		printf("\nCusto por Km: ");
		scanf("%f", &veiculos[i].custopkm);
		printf("\nValor da reserva de combustivel: ");
		scanf("%f", &veiculos[i].valorreservacombustivel);
		printf("\nConsumo medio: ");
		scanf("%f", &veiculos[i].consumomedio);
		i++;
		printf("\nDeseja continuar a registar veiculos? (s/n): ");
		scanf(" %c", &opcao);
	} while (opcao != 'n');
	
	if (i > 0) {
		for (j = 0; j < i; j++) {
			resultado = insereveiculo(veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, veiculos[j].datamatricula, veiculos[j].custopkm, veiculos[j].valorreservacombustivel, veiculos[j].consumomedio);
			
			if (resultado != 0) {
				printf("\nProblema no registo do veiculo %d", veiculos[j].idveiculo);
			}
		}
	}
	return;
}

int main() {
	menu();
	return 0;
}
