#include <stdio.h>
#include <stdlib.h>
#define TAM 10  // Tamanho do tabuleiro

void imprimirTabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

void moverJogador(char tab[TAM][TAM], int *px, int *py, char direcao) {
    int dx = 0, dy = 0;
    switch (direcao) {
        case 'W': dx = -1; break;
        case 'S': dx = 1; break;
        case 'A': dy = -1; break;
        case 'D': dy = 1; break;
    }

    int novo_x = *px + dx;
    int novo_y = *py + dy;
    if (novo_x >= 0 && novo_x < TAM && novo_y >= 0 && novo_y < TAM) {
        if (tab[novo_x][novo_y] != '*') {
            tab[*px][*py] = ' ';
            *px = novo_x;
            *py = novo_y;
            tab[*px][*py] = '&';
        }
    }
}

void fase1() {
    char tabuleiro[TAM][TAM] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', '*', '*', ' ', '*', '*', ' ', ' ', '*'},
        {'*', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*'},
        {'*', ' ', '*', '*', '*', '@', '*', '*', ' ', '*'},
        {'*', ' ', ' ', ' ', '*', 'D', '*', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };
    
    int px = 1, py = 1;
    imprimirTabuleiro(tabuleiro);
    char comando;
    printf("Use as teclas W, A, S, D para se mover. A tecla 'I' serve para interagir.\n");
    while (1) {
        printf("Digite o seu comando: ");
        scanf(" %c", &comando);
        system("cls"); // Limpa a tela antes de imprimir novamente o tabuleiro
        if (comando == 'I') {
            // Implementação da interação aqui
        } else {
            moverJogador(tabuleiro, &px, &py, comando);
            imprimirTabuleiro(tabuleiro);
        }
    }
}

int main() {
    int opcao;
    while (1) {
        system("cls");
        printf("Bem-vindo ao Jogo de Aventura Dunger Crawler'!\n\n");
        printf("Menu Principal:\n");
        printf("1. Jogar\n");
        printf("2. Tutorial\n");
        printf("3. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nIniciando o jogo...\n");
                fase1();
                break;
            case 2:
                printf("\nTutorial:\n");
                printf("As teclas W, A, S, D movem o jogador (&). 'I' para interagir.\n");
                system("pause");
                break;
            case 3:
                printf("\nSaindo do jogo...\n");
                return 0;
            default:
                printf("\nOpção inválida! Por favor, tente novamente.\n");
                system("pause");
                break;
        }
    }
    return 0;
}

