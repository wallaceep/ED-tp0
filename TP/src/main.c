#include "../include/imagem.h"
#include "../include/pixel.h"
#include "../include/msgAssert.h"
#include "../include/memlog.h"
#include <string.h>
#include <getopt.h>

// variaveis globais para opcoes
char lognome[100], saida[100], entrada[100];
int regmem = 1;
extern char *optarg;

int main(int argc,char **argv){
    FILE *novaImg;
    Pixel pixel;
    Imagem img;
    int **PeB, **original, op;
    char nomeEntrada[50], nomeSaida[50];

  while ((op = getopt(argc, argv, ":i:o:pl")) != EOF){
    switch(op){
      case 'i':
        strcpy(entrada, optarg);
        break;
      case 'o':
        strcpy(saida, optarg);
        break;
      case 'p':
        strcpy(lognome,"log.out");
        break;
      case 'l': 
        regmem = 1;
        break;
      default:
        exit(1);
    }
  }
    iniciaMemLog(lognome);
    
    if(regmem)
      ativaMemLog();
    else  
      desativaMemLog();

    FILE *imgOriginal = abrirImagem(entrada,"r");

    /*lê o cabeçalho da imagem e armazena as informações*/
    fscanf(imgOriginal, "%s %d %d %d", img.cabecalho, &img.col, &img.lin, &img.max);

    /*aloca matrizes que irão receber dados das imagens original
    e em escala de cinza*/
    PeB = alocarImagem(img.lin, img.col);
    original = alocarImagem(img.lin, img.col);

    /*lê a imagem e armazena a original*/
    lerImagem(imgOriginal, img.lin, img.col, PeB);
    armazenarImagemPPM(entrada, original);

    /*abre o arquivo no modo de escrita e escreve a imagem nova*/
    novaImg = abrirImagem(saida, "w");
    novaImg = escreverImagem(saida, img.lin, img.col, PeB);

    /*fecha os arquivos das imagens de entrada e de saída*/
    fclose(imgOriginal);
    fclose(novaImg);

    /*libera memória das matrizes usadas para armazenar as
    informações das matrizes*/
    liberarImagem(PeB, img.lin);
    liberarImagem(original, img.lin);

    /*return 0*/
    return EXIT_SUCCESS;
}