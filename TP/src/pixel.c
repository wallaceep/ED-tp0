#include "../include/pixel.h"
#include "../include/imagem.h"
#include "../include/memlog.h"
#include "../include/msgAssert.h"

/*Recebe os pixeis r, g e b da imagem original 
colorida, converte em tons de cinza (y) e retorna
o valor*/
int converterImagem(int r, int g, int b){ 
    int y;
    y = ((0.30*r + 0.59*g + 0.11*b) * 49) / 255;
    return y;
}

/*Lê a imagem original e guarda suas informações na matriz
chamada original*/
void armazenarImagemPPM(char *fpath, int **original){
    
    int nLin, nCol, nMax, pixel;
    char tipo[2];

    FILE *arquivo = abrirImagem(fpath, "r");

    fscanf(arquivo, "%s %d %d %d", tipo, &nCol, &nLin, &nMax);

    for(int i=0; i<nLin; i++){
        for(int j=0; j<nCol; j++){
            fscanf(arquivo, "%d", &pixel);
            original[i][j] = pixel;
            ESCREVEMEMLOG((long int)(&original[i][j]), sizeof(int), 1);
        }
    }

    fclose(arquivo);
}