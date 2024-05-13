#include <stdio.h>
#include <stdlib.h>
#define TAM 10  // Tamanho do tabuleiro

// Fun��o para imprimir o tabuleiro
void imprimirTabuleiro(char tab[TAM][TAM]) {
    int i, j; // Declarar os contadores
    // Desenhando o tabuleiro: Laço for começa quando i for 0 e incrementa um até quando i for menor que o Tamanho do tabuleiro
    for (i = 0; i < TAM; i++) { 
        for (j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

// Fun��o para mover o jogador
// Definindo a posição
void moverJogador(char tab[TAM][TAM], int *px, int *py, char direcao) {
    int dx = 0, dy = 0;
    switch (direcao) {
        case 'W': dx = -1; break; // Cima
        case 'S': dx = 1; break;  // Baixo
        case 'A': dy = -1; break; // Esquerda
        case 'D': dy = 1; break;  // Direita
    }

    int novo_x = *px + dx, novo_y = *py + dy;
    if (novo_x >= 0 && novo_x < TAM && novo_y >= 0 && novo_y < TAM && tab[novo_x][novo_y] != '*') {
        tab[*px][*py] = ' ';  // Limpa a posi��o antiga
        *px = novo_x;
        *py = novo_y;
        tab[*px][*py] = '&';  // Move o jogador para a nova posi��o
    }
}

// Fun��o principal da Fase 1
void fase1() {
    char tabuleiro[TAM][TAM] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', '*', '*', ' ', '*', '*', ' ', ' ', '*'},
        {'*', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*'},
        {'*', ' ', '*', '*', '*', '@', '*', '*', ' ', '*'},
        {'*', 'X', ' ', ' ', '*', 'D', '*', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };
    
    int px = 1, py = 1;  // Posi��o inicial do jogador
    
    imprimirTabuleiro(tabuleiro);
    
    char comando;
    printf("Use as teclas W, A, S, D para se mover. A tecla 'I' serve para interagir.\n");
    while (1) {
        printf("Digite o seu comando: ");
        scanf(" %c", &comando);
        if (comando == 'I') {
            // Implementar intera��o (abrir porta, pegar chave, etc.)
        } else {
            moverJogador(tabuleiro, &px, &py, comando);
            imprimirTabuleiro(tabuleiro);
        }
    }
}

// Execu��o das fun��es do jogo
int main() {
    int opcao;

    while (1) {
        // Limpar a tela. No Windows, use "cls", no Linux ou MacOS, use "clear"
        system("cls");

        // Exibir o menu principal
        printf("Bem-vindo ao Jogo de Aventura Dunger Crawler'!\n\n");
        printf("Menu Principal:\n");
        printf("1. Jogar\n");
        printf("2. Tutorial\n");
        printf("3. Sair\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nIniciando o jogo...\n");
                fase1();
                break;
            case 2:
                printf("\nTutorial:\n");
                printf("As teclas W, A, S, D para mover o jogador(&) para: CIMA,ESQUERDA,BAIXO E DIREITA\n A Tecla 'I' serve para interagir com a chave (@).\nUse suas habilidades para resolver os desafios e progredir!\n");
                system("pause");
                break;
            case 3:
                printf("\nSaindo do jogo...\n");
                return 0;
            default:
                printf("\nOp��o inv�lida! Por favor, tente novamente.\n");
                system("pause");
                break;
        }
    }

    return 0;
}

