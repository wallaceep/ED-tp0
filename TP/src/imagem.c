#include "../include/imagem.h"
#include "../include/pixel.h"
#include "../include/msgAssert.h"
#include "../include/memlog.h"

/*faz a alocação dinâmica da matriz que irá armazenar
a imagem*/
int **alocarImagem(int lin, int col){
    int **ptr = (int **)malloc(sizeof(int *)*lin);
    for(int i=0; i<lin; i++)
        ptr[i] = (int *)malloc(sizeof(int)*col);
    return ptr;
}

/*libera memória da matriz que armazenou a imagem*/
void liberarImagem(int **ptr, int lin){
    for(int i = 0; i < lin; i++)
        free(ptr[i]);
    free(ptr);
}

/*abre a imagem, e, caso não consiga abri-la,
emite uma mensagem de erro*/
FILE *abrirImagem(char *fpath, char *modo){
    FILE *imagem = fopen(fpath, modo);
    if(imagem==NULL){
        perror("Não consegui abrir a imagem");
        exit(EXIT_FAILURE);
    }
    return imagem;
}

/*lê o arquivo PPM da imagem, envia seus pixels para 
função que converte em tons de cinza e armazena na matriz
PeB*/
void lerImagem(FILE *arquivo, int lin, int col, int **PeB){
    Pixel pix;
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            fscanf(arquivo, "%d %d %d", &pix.r, &pix.g, &pix.b);
            PeB[i][j] = converterImagem(pix.r, pix.g, pix.b);
            ESCREVEMEMLOG((long int)(&PeB[i][j]), sizeof(int), 0);
        }
    }
}

/*cria um novo arquivo em modo de escrita e escreve o cabeçalho
e as informações armazenadas na matriz PeB, e retorna o arquivo
já escrito*/
FILE *escreverImagem(char *nomeImg, int lin, int col, int **PeB){
    FILE *novaImagem = abrirImagem(nomeImg, "w"); 
    fprintf(novaImagem,"P2\n%d %d\n49\n",col, lin);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            fprintf(novaImagem, "%d ", PeB[i][j]);
        }
        fprintf(novaImagem, "\n");
    }
    return novaImagem;
}