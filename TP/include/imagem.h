#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pixel.h"

typedef struct{
    int lin, col, max;
    char tipo[2];
    char cabecalho[50];
} Imagem;

int **alocarImagem(int lin, int col);
int setCabecalho(char *fpath);
void lerImagem(FILE *arquivo, int lin, int col, int **PeB);
void liberarImagem(int **ptr, int lin);
FILE *abrirImagem(char *fpath, char *modo);
FILE *escreverImagem(char *nomeImg, int lin, int col, int **PeB);

#endif