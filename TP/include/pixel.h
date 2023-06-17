#ifndef PIXEL_H
#define PIXEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int r, g, b;
} Pixel;

void armazenarImagemPPM(char *fpath, int **original);
int converterImagem(int r, int g, int b);

#endif