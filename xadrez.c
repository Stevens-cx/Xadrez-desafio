#include <stdio.h>

#define TAB_SIZE 8
#define TOTAL_MOVIMENTOS 8

// Movimentos possíveis do cavalo: (deltaLinha, deltaColuna)
const int movimentosCavalo[TOTAL_MOVIMENTOS][2] = {
    {-2, -1},
    {-2,  1},
    {-1, -2},
    {-1,  2},
    { 1, -2},
    { 1,  2},
    { 2, -1},
    { 2,  1}
};

// Função para verificar se a posição está dentro do tabuleiro
int posicao_valida(int linha, int coluna) {
    return (linha >= 0 && linha < TAB_SIZE && coluna >= 0 && coluna < TAB_SIZE);
}

int main() {
    int linha_atual = 4;   // posição inicial do cavalo (exemplo: centro do tabuleiro)
    int coluna_atual = 4;

    printf("Posicao inicial do cavalo: Linha %d, Coluna %d\n\n", linha_atual, coluna_atual);
    printf("Movimentos possiveis do cavalo:\n");

    for (int i = 0; i < TOTAL_MOVIMENTOS; i++) {
        int nova_linha = linha_atual + movimentosCavalo[i][0];
        int nova_coluna = coluna_atual + movimentosCavalo[i][1];

        if (posicao_valida(nova_linha, nova_coluna)) {
            printf("Movimento %d: Mover para Linha %d, Coluna %d\n", i + 1, nova_linha, nova_coluna);

            // Detalha os passos do movimento em direções básicas:
            if (movimentosCavalo[i][0] < 0)
                printf("  %d casa(s) para Cima\n", -movimentosCavalo[i][0]);
            else if (movimentosCavalo[i][0] > 0)
                printf("  %d casa(s) para Baixo\n", movimentosCavalo[i][0]);

            if (movimentosCavalo[i][1] < 0)
                printf("  %d casa(s) para Esquerda\n", -movimentosCavalo[i][1]);
            else if (movimentosCavalo[i][1] > 0)
                printf("  %d casa(s) para Direita\n", movimentosCavalo[i][1]);
        } else {
            printf("Movimento %d: Fora do tabuleiro\n", i + 1);
        }
        printf("\n");
    }

    return 0;
}