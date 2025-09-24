#include <stdio.h>

// Declaração prévia da função.
int SomaTridimensional();

int main() {
    // Declarando uma matriz 3D com tamanho 2x2x2
    int MatrizA[2][2][2] = {
        { {3, 3}, {4, 3} },  // Bloco 0
        { {1, 2}, {5, 7} }   // Bloco 1
    };

    printf("Valores do vetor tridimensional (2x2x2): \n\n");

    // Percorrendo todos os elementos da matriz 3D
    for (int Bloco = 0; Bloco < 2; Bloco++) {       // Percorre os blocos
        for (int Linha = 0; Linha < 2; Linha++) {    // Percorre as linhas dentro do bloco
            for (int Coluna = 0; Coluna < 2; Coluna++) {  // Percorre as colunas
                // Exibe o valor atual com sua posição
                printf("MatrizA[%d][%d][%d] = %d\n", Bloco, Linha, Coluna, MatrizA[Bloco][Linha][Coluna]);
            }
        }
        printf("\n");  // Linha em branco entre blocos
    }

    printf("==========================================\n");
    int success = SomaTridimensional();

    return 0;
}

int SomaTridimensional() {
    // Soma de duas Matrizes
    int MatrizA[2][2][2] = {
        { {3, 3}, {4, 3} },
        { {1, 2}, {5, 7} }
    };
    int MatrizB[2][2][2] = {
        { {3, 3}, {4, 3} },
        { {1, 2}, {5, 7} }  
    };
    int MatrizC[2][2][2];

    printf("Valores do vetor tridimensional (2x2x2): \n\n");

    for (int Bloco = 0; Bloco < 2; Bloco++) {
        for (int Linha = 0; Linha < 2; Linha++) {
            for (int Coluna = 0; Coluna < 2; Coluna++) {
                MatrizC[Bloco][Linha][Coluna] = MatrizA[Bloco][Linha][Coluna] + MatrizB[Bloco][Linha][Coluna];
            }
        }
    }

    printf("Resultado das Somas: \n");
    for (int Bloco = 0; Bloco < 2; Bloco++) {
        for (int Linha = 0; Linha < 2; Linha++) {
            for (int Coluna = 0; Coluna < 2; Coluna++) {
                printf("MatrizC[%d][%d][%d] = %d\n", Bloco, Linha, Coluna, MatrizC[Bloco][Linha][Coluna]);
            }
        }
        printf("\n");
    }
    return 0;
}
