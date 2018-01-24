//
//  libveiculo.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#include "libcomum.h"
#define MAXVEICULOS 1000

typedef struct veiculo{
	int idveiculo;
	int tipoveiculo;
	char marca[50];
	char modelo[50];
	char matricula[9];
	int datamatricula;
	float custopkm;
	float valorreservacombustivel;
	float consumomedio;
} veiculo, *ptrveiculo;

int insereveiculo(int, int, char[], char[], char[], int, float, float, float);//inserir veiculo a receber um int e devolve os parametros
int alteraveiculo(int);//alterar o veiculo
void eliminaveiculo(void);//eliminar o veiculo
void listaveiculo(void);// lista dos veiculos

int insereveiculo(int idveiculo, int tipoveiculo, char marca[], char modelo[], char matricula[], int datamatricula, float custopkm, float valorreservacombustivel, float consumomedio){
	FILE *ficheiro;
	
	ficheiro = fopen("veiculobd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("veiculobd.txt", "w");
	}
	
	fprintf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", idveiculo, tipoveiculo, marca, modelo, matricula, datamatricula, custopkm, valorreservacombustivel, consumomedio);
	fclose(ficheiro);
	return 0;
}

void listaveiculo(){
	FILE *ficheiro;
	int i = 0, j = 0;
	
	ficheiro = fopen("veiculobd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			veiculo veiculos[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", &veiculos[j].idveiculo, &veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
			}
			
			unsigned long tamanhoarray = sizeof(veiculos)/sizeof(veiculos[0]);
			
			if (tamanhoarray > 0) {
				printf("\nidveiculo tipoveiculo marca modelo matricula datamatricula custopkm valorreservacombustivel consumomedio\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i %i %s %s %s %i %.2f %.2f %.2f\n", veiculos[x].idveiculo, veiculos[x].tipoveiculo, veiculos[x].marca, veiculos[x].modelo, veiculos[x].matricula, veiculos[x].datamatricula, veiculos[x].custopkm, veiculos[x].valorreservacombustivel, veiculos[x].consumomedio);
				}
			}
			else{
				printf("Não há registos para mostrar!");
			}
		}
		else{
			printf("Não há nada registado no ficheiro!");
		}
	}
	
	fclose(ficheiro);
}

void eliminaveiculo(){
	FILE *ficheiro;
	int i = 0, j = 0, registo = 0;
	char confirma = ' ';
	
	ficheiro = fopen("veiculobd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			veiculo veiculos[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", &veiculos[j].idveiculo, &veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
			}
			
			int tamanhoarray = sizeof(veiculos)/sizeof(veiculos[0]);
			
			if (tamanhoarray > 0) {
				printf("\nid idveiculo tipoveiculo marca modelo matricula datamatricula custopkm valorreservacombustivel consumomedio\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i %i %i %s %s %s %i %.2f %.2f %.2f\n", x, veiculos[x].idveiculo, veiculos[x].tipoveiculo, veiculos[x].marca, veiculos[x].modelo, veiculos[x].matricula, veiculos[x].datamatricula, veiculos[x].custopkm, veiculos[x].valorreservacombustivel, veiculos[x].consumomedio);
				}
			}
			else{
				printf("Não há registos para mostrar!");
			}
			
			printf("\nInsira o id do registo a eliminar: ");
			scanf("%i", &registo);
			
			printf("\n%i %i %i %s %s %s %i %.2f %.2f %.2f\n", registo, veiculos[registo].idveiculo, veiculos[registo].tipoveiculo, veiculos[registo].marca, veiculos[registo].modelo, veiculos[registo].matricula, veiculos[registo].datamatricula, veiculos[registo].custopkm, veiculos[registo].valorreservacombustivel, veiculos[registo].consumomedio);
			printf("\nDeseja realmente eliminar o registo? (s/n): ");
			scanf(" %c", &confirma);
			
			if (confirma == 's' || confirma == 'S') {
				if (registo >= tamanhoarray || registo < 0) {
					printf("Hm...! Esse registo nao existe, que tal um entre 0 e %i", tamanhoarray);
				} else {
					j = 0;
					for (i = 0; i < tamanhoarray; i++) {
						if (registo == i) {
							continue;
						}
						veiculos[j] = veiculos[i];
						j++;
					}
					tamanhoarray--;
				}
			}
			else{
				printf("Record não 'terminated'");
			}
			
			fclose(ficheiro);
			ficheiro = fopen("veiculobd.txt", "w");
			for (j = 0; j < tamanhoarray; j++) {
				fprintf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, veiculos[j].datamatricula, veiculos[j].custopkm, veiculos[j].valorreservacombustivel, veiculos[j].consumomedio);
			}
		}
		else{
			printf("Não há nada registado no ficheiro!");
		}
	}
	
	fclose(ficheiro);
}
