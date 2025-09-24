#include <stdio.h> // Biblioteca padrão para entrada e saída (como printf)

int main()
{
    // Declarando e preenchendo a Matriz A (4 linhas x 4 colunas)
    int MatrizA[4][4] = {
        {2, 2, 5, 6},
        {2, 3, 1, 2},
        {1, 0, 4, 1},
        {3, 5, 2, 0}
    };

    // Declarando e preenchendo a Matriz B (também 4x4)
    int MatrizB[4][4] = {
        {2, 2, 8, 9},
        {2, 8, 2, 2},
        {1, 2, 3, 4},
        {0, 1, 2, 3}
    };

    // Criando uma nova matriz para guardar o resultado da soma (também 4x4)
    int MatrizC[4][4];

    // Loop externo percorre as linhas (de 0 a 3)
    for (int line = 0; line < 4; line++)
    {
        // Loop interno percorre as colunas (de 0 a 3)
        for (int column = 0; column < 4; column++)
        {
            // Soma os valores da posição atual de A e B, e guarda na matriz C
            MatrizC[line][column] = MatrizA[line][column] + MatrizB[line][column];
            // Mostra o valor somado da posição atual com uma tabulação
            printf("%d \t", MatrizC[line][column]);
        }

        // Após terminar uma linha, pula para a próxima linha na tela para imprimir um resultado mais organizado.
        printf("\n");
    }

    return 0; // Indica que o programa terminou com sucesso
}

