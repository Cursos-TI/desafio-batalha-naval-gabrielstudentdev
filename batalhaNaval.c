#include <stdio.h>

#define TAM 10    // Tamanho do tabuleiro
#define H 5       // Tamanho das matrizes de habilidade (5x5)

// Inicializa o tabuleiro com água (0) e adiciona navios (3)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Adicionando alguns navios
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[5][5] = 3;
}

// Cria a matriz Cone (em forma de V invertido, apontando para baixo)
void gerarCone(int habilidade[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= H / 2 - i && j <= H / 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria a matriz Cruz (linhas e colunas centrais marcadas)
void gerarCruz(int habilidade[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            habilidade[i][j] = (i == H / 2 || j == H / 2) ? 1 : 0;
        }
    }
}

// Função própria para valor absoluto (sem stdlib.h)
int meuAbs(int x) {
    return (x < 0) ? -x : x;
}

// Cria a matriz Octaedro (forma de losango)
void gerarOctaedro(int habilidade[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int dist = meuAbs(i - H / 2) + meuAbs(j - H / 2);
            habilidade[i][j] = (dist <= H / 2) ? 1 : 0;
        }
    }
}

// Sobrepõe a habilidade ao tabuleiro no ponto central dado
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[H][H], int linha, int coluna) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            int tabLinha = linha - H / 2 + i;
            int tabColuna = coluna - H / 2 + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (tabLinha >= 0 && tabLinha < TAM && tabColuna >= 0 && tabColuna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[tabLinha][tabColuna] == 0) {
                    tabuleiro[tabLinha][tabColuna] = 5; // Marca área afetada
                }
            }
        }
    }
}

// Mostra o tabuleiro na tela com os símbolos apropriados
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("=== TABULEIRO ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            switch (tabuleiro[i][j]) {
                case 0: printf("~ "); break; // Água
                case 3: printf("N "); break; // Navio
                case 5: printf("* "); break; // Área de habilidade
                default: printf("? "); break; // Caso inesperado
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[H][H], cruz[H][H], octaedro[H][H];

    inicializarTabuleiro(tabuleiro);
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 3, 3);       // Cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro no canto inferior direito

    exibirTabuleiro(tabuleiro);

    return 0;
}
