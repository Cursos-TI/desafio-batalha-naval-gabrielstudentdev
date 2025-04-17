#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("3 "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("5 "); // Área afetada pela habilidade
        }
        printf("\n");
    }
}

// Função para aplicar a matriz de cone ao tabuleiro
void aplicarCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = { 
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Sobrepondo a matriz de cone no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = origemX + i - TAMANHO_HABILIDADE / 2;
            int y = origemY + j - TAMANHO_HABILIDADE / 2;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && cone[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca as posições afetadas pela habilidade
            }
        }
    }
}

// Função para aplicar a matriz de cruz ao tabuleiro
void aplicarCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = { 
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Sobrepondo a matriz de cruz no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = origemX + i - TAMANHO_HABILIDADE / 2;
            int y = origemY + j - TAMANHO_HABILIDADE / 2;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && cruz[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca as posições afetadas pela habilidade
            }
        }
    }
}

// Função para aplicar a matriz de octaedro ao tabuleiro
void aplicarOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = { 
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Sobrepondo a matriz de octaedro no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = origemX + i - TAMANHO_HABILIDADE / 2;
            int y = origemY + j - TAMANHO_HABILIDADE / 2;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && octaedro[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca as posições afetadas pela habilidade
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo alguns navios no tabuleiro
    tabuleiro[2][3] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][7] = 3;

    // Definindo a origem das habilidades
    int origemConeX = 5, origemConeY = 5;
    int origemCruzX = 3, origemCruzY = 3;
    int origemOctaedroX = 7, origemOctaedroY = 7;

    // Aplicando as habilidades no tabuleiro
    aplicarCone(tabuleiro, origemConeX, origemConeY);
    aplicarCruz(tabuleiro, origemCruzX, origemCruzY);
    aplicarOctaedro(tabuleiro, origemOctaedroX, origemOctaedroY);

    // Exibindo o tabuleiro com as áreas afetadas
    exibirTabuleiro(tabuleiro);

    return 0;
}