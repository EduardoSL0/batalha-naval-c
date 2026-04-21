#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Tamanho dos navios

int main() {

    // ==============================
    // 1. Criando o tabuleiro
    // ==============================
    int tabuleiro[TAM][TAM];

    // Inicializando tudo com 0 (água)
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==============================
    // 2. Criando os navios
    // ==============================
    int navio_horizontal[NAVIO] = {3, 3, 3};
    int navio_vertical[NAVIO]   = {3, 3, 3};

    // Coordenadas iniciais
    int linhaH = 2, colunaH = 3; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical

    // ==============================
    // 3. Validação de limites
    // ==============================

    // Verifica se o navio horizontal cabe
    if(colunaH + NAVIO > TAM) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // Verifica se o navio vertical cabe
    if(linhaV + NAVIO > TAM) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ==============================
    // 4. Validação de sobreposição
    // ==============================

    // Verifica horizontal
    for(int i = 0; i < NAVIO; i++) {
        if(tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    }

    // Verifica vertical
    for(int i = 0; i < NAVIO; i++) {
        if(tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }

    // ==============================
    // 5. Posicionando os navios
    // ==============================

    // Navio horizontal
    for(int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
    }

    // Navio vertical
    for(int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
    }

    // ==============================
    // 6. Exibindo o tabuleiro
    // ==============================

    printf("\n=== TABULEIRO ===\n\n");

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}