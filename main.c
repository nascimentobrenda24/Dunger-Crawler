#include <stdio.h>
#include <stdlib.h>
#define TAM 10  // Tamanho do tabuleiro

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tab[TAM][TAM]) {
    int i, j; 
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

// Função para mover o jogador
void moverJogador(char tab[TAM][TAM], int *px, int *py, char direcao) {
    int dx = 0, dy = 0;
    switch (direcao) {
        case 'w': // cima
        case 'W': dx = -1; break;
        case 's': // baixo
        case 'S': dx = 1; break;
        case 'a': // esquerda
        case 'A': dy = -1; break;
        case 'd': // direita
        case 'D': dy = 1; break;
    }

    int novo_x = *px + dx;
    int novo_y = *py + dy;
    if (novo_x >= 0 && novo_x < TAM && novo_y >= 0 && novo_y < TAM && tab[novo_x][novo_y] != '*') {
        tab[*px][*py] = ' ';  // Limpa a posição antiga
        *px = novo_x;
        *py = novo_y;
        tab[*px][*py] = '&';  // Move o jogador para a nova posição
    }
}

// Função principal da Fase 1
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
    
    int px = 1, py = 1;  // Posição inicial do jogador
    
    imprimirTabuleiro(tabuleiro);
    
    char comando;
    printf("Use as teclas W, A, S, D para se mover. A tecla 'I' serve para interagir.\n");
    do {
        printf("Digite o seu comando: ");
        scanf(" %c", &comando); // Espaço antes do %c para ignorar whitespace
        if (comando == 'I' || comando == 'i') {
            printf("Interagindo... (funcao não implementada)\n");
        } else {
            moverJogador(tabuleiro, &px, &py, comando);
            imprimirTabuleiro(tabuleiro);
        }
    } while (comando != 'Q' && comando != 'q'); // Adicionado comando para sair do loop
}

// Execução das funções do jogo
int main() {
    int opcao;

    do {
        system("cls"); // Limpar a tela. No Windows use "cls", no Linux ou MacOS use "clear"

        printf("\t\tBem-vindo ao Jogo de Aventura Dungeon Crawler!\n\n");
        printf("\tMenu Principal:\n");
        printf("\t1. Jogar\n");
        printf("\t2. Tutorial\n");
        printf("\t3. Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nIniciando o jogo...\n");
                fase1();
                break;
            case 2:
                printf("\nTutorial:\nAs teclas W, A, S, D movem o jogador (W=Up, A=Left, S=Down, D=Right).\nA tecla 'I' serve para interagir.\n");
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
    } while (1);

    return 0;
}
