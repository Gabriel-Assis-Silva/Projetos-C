#include <stdio.h>

int main()
{
    int MatrizA[3][2] = {
        {2, 1},
        {3, 4},
        {1, 2}
    };

    // Criando uma nova matriz 2x3 para armazenar a transposta de MatrizA
    int MatrizT[2][3];

    // Percorrendo MatrizA para gerar sua transposta
    for (int Linha = 0; Linha < 3; Linha++) {         // Percorre as linhas de MatrizA
        for (int Coluna = 0; Coluna < 2; Coluna++) {     // Percorre as colunas de MatrizA
            // A transposta inverte linha por coluna:
            // Elemento que está em [i][j] vai para [j][i]
            MatrizT[Coluna][Linha] = MatrizA[Linha][Coluna];
        }
    }

    // Exibindo a matriz transposta
    printf("Matriz Transposta: \n");

    for (int Linha = 0; Linha < 2; Linha++) {         // Percorre as linhas da matriz transposta
        for (int Coluna = 0; Coluna < 3; Coluna++) {     // Percorre as colunas da matriz transposta
            printf("%d \t", MatrizT[Linha][Coluna]);  // Exibe cada valor com uma tabulação
        }
        printf("\n");  // Pula para a próxima linha após imprimir uma linha completa
    }

    return 0;  // Fim do programa
}
