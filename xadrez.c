#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para criar o tabuleiro
void criarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ♝ Bispo: 5 casas na diagonal direita para cima - recursão + loops aninhados
void moverBispo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int passos) {
    if (passos == 0 || x >= TAMANHO_TABULEIRO || y < 0) {
        return;
    }

    for (int dx = 1; dx < 2; dx++) {  // Loop aninhado simbólico
        for (int dy = 1; dy < 2; dy++) {
            int novo_x = x + dx;
            int novo_y = y - dy;
            if (novo_x >= 0 && novo_x < TAMANHO_TABULEIRO && novo_y >= 0 && novo_y < TAMANHO_TABULEIRO) {
                tabuleiro[novo_y][novo_x] = '♝';
                moverBispo(tabuleiro, novo_x, novo_y, passos - 1);
            }
        }
    }
}

// ♜ Torre: 5 casas para a direita - loop simples
void moverTorre(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 1; i <= 5; i++) {
        if (x + i < TAMANHO_TABULEIRO) {
            tabuleiro[y][x + i] = '♜';
        }
    }
}

// ♛ Rainha: 8 casas para a esquerda - loop simples
void moverRainha(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 1; i <= 8; i++) {
        if (x - i >= 0) {
            tabuleiro[y][x - i] = '♛';
        }
    }
}

// ♞ Cavalo: L para cima à direita - loop com múltiplas condições e break/continue
void moverCavalo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int movimentos[2][2] = {{2, -1}, {1, -2}};  // L para cima à direita
    for (int i = 0; i < 2; i++) {
        int nx = x + movimentos[i][0];
        int ny = y + movimentos[i][1];
        if (nx >= TAMANHO_TABULEIRO || ny < 0) {
            continue;
        }
        if (tabuleiro[ny][nx] != '.') {
            break;
        }
        tabuleiro[ny][nx] = '♞';
        break;
    }
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Criar o tabuleiro
    criarTabuleiro(tabuleiro);

    // Posição inicial (pode mudar)
    int x = 3, y = 6;
    tabuleiro[y][x] = '●';  // Marca de início

    // Aplicar movimentos
    moverBispo(tabuleiro, x, y, 5);
    moverTorre(tabuleiro, x, y);
    moverRainha(tabuleiro, x, y);
    moverCavalo(tabuleiro, x, y);

    // Exibir resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
