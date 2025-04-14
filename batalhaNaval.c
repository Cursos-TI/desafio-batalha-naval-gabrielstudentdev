#include <stdio.h>

int main() {
    // Matriz 10x10 do tipo string (ponteiros para char)
    char *tabuleiro[10][10];

    // Inicializa o tabuleiro com "0" (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = "0";
        }
    }

    // Posiciona navio horizontal de tamanho 3 (linha 1, colunas 0 a 2)
    tabuleiro[0][0] = "3";
    tabuleiro[0][1] = "3";
    tabuleiro[0][2] = "3";

    // Posiciona navio vertical de tamanho 3 (coluna 0, linhas 7 a 9)
    tabuleiro[6][0] = "3";
    tabuleiro[7][0] = "3";
    tabuleiro[8][0] = "3";

    // Impressão do cabeçalho
    printf("TABULEIRO BATALHA NAVAL\n  A B C D E F G H I J\n");

    // Imprime o tabuleiro com os índices das linhas
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);  // número da linha
        for (int j = 0; j < 10; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
