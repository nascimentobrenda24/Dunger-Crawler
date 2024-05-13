#include <stdio.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD
// Fun��o para imprimir o tabuleiro
void imprimirTabuleiro(char tab[TAM][TAM]) {
    int i, j; // Declarar os contadores
    // Desenhando o tabuleiro: Laço for começa quando i for 0 e incrementa um até quando i for menor que o Tamanho do tabuleiro
    for (i = 0; i < TAM; i++) { 
        for (j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
=======
#define TAMANHO_MAPA 10
#define TAMANHO_MAPA2 20
#define TAMANHO_MAPA3 40
#define NUM_OBSTACULOS 50
#define POSICAO_INICIAL_V_X 1
#define POSICAO_INICIAL_V_Y 4


int ehObstaculo(int x, int y, int obstaculosX[], int obstaculosY[], int numObstaculos);

int dentroLimites(int x, int y, int tamanhoMapa) {
    return x >= 0 && x < tamanhoMapa && y >= 0 && y < tamanhoMapa;
}

int ehObstaculo(int x, int y, int obstaculosX[], int obstaculosY[], int numObstaculos) {
    for (int i = 0; i < numObstaculos; i++) {
        if (x == obstaculosX[i] && y == obstaculosY[i]) {
            return 1;
>>>>>>> 45851e366bceb3de44eaa881ecdcfadafd668a5f
        }
    }
    return 0;
}

<<<<<<< HEAD
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
=======
void moverX(int *posX, int *posY, char mapa[][TAMANHO_MAPA]) { // Alteração aqui
    int deltaX, deltaY;
    do {
        deltaX = rand() % 3 - 1;
        deltaY = rand() % 3 - 1;
    } while (!dentroLimites(*posX + deltaX, *posY + deltaY, TAMANHO_MAPA) || mapa[*posX + deltaX][*posY + deltaY] == '*' || mapa[*posX + deltaX][*posY + deltaY] == '#' || mapa[*posX + deltaX][*posY + deltaY] == 'D' || mapa[*posX + deltaX][*posY + deltaY] == '@'|| mapa[*posX + deltaX][*posY + deltaY] == '=');

    mapa[*posX][*posY] = ' ';
    *posX += deltaX;
    *posY += deltaY;
    mapa[*posX][*posY] = 'X';
}

void moverX2(int *posX, int *posY, char mapa[][TAMANHO_MAPA2]) { // Alteração aqui
    int deltaX, deltaY;
    do {
        deltaX = rand() % 3 - 1;
        deltaY = rand() % 3 - 1;
    } while (!dentroLimites(*posX + deltaX, *posY + deltaY, TAMANHO_MAPA2) || mapa[*posX + deltaX][*posY + deltaY] == '*' || mapa[*posX + deltaX][*posY + deltaY] == '#' || mapa[*posX + deltaX][*posY + deltaY] == 'D' || mapa[*posX + deltaX][*posY + deltaY] == '@'|| mapa[*posX + deltaX][*posY + deltaY] == '=');

    mapa[*posX][*posY] = ' ';
    *posX += deltaX;
    *posY += deltaY;
    mapa[*posX][*posY] = 'X';
}
void moverAnd(int *posX, int *posY, char mapa[][TAMANHO_MAPA3], char movimento) {
    int deltaX = 0, deltaY = 0;
    
    // Definir o movimento baseado na tecla pressionada
    if (movimento == 'w') {
        deltaX = -1;
    } else if (movimento == 'a') {
        deltaY = -1;
    } else if (movimento == 's') {
        deltaX = 1;
    } else if (movimento == 'd') {
        deltaY = 1;
    }

    // Verificar se o próximo movimento é válido
    if (dentroLimites(*posX + deltaX, *posY + deltaY, TAMANHO_MAPA3) && mapa[*posX + deltaX][*posY + deltaY] != '*') {
        mapa[*posX][*posY] = ' '; // Limpar a posição atual
        *posX += deltaX; // Atualizar a posição em X
        *posY += deltaY; // Atualizar a posição em Y
        mapa[*posX][*posY] = '&'; // Atualizar a posição no mapa
    }
}
void moverV(int* posVX, int* posVY, int posAndX, int posAndY, char mapa[TAMANHO_MAPA3][TAMANHO_MAPA3]) {
    // Limpar a posição anterior do personagem 'V'
    mapa[*posVX][*posVY] = ' ';

    // Calcular o movimento do personagem 'V' em direção ao '&'
    int movimentoX = (posAndX > *posVX) ? 1 : (posAndX < *posVX) ? -1 : 0;
    int movimentoY = (posAndY > *posVY) ? 1 : (posAndY < *posVY) ? -1 : 0;

    // Verificar se a próxima posição é válida e não está ocupada
    if (movimentoX != 0 && dentroLimites(*posVX + movimentoX, *posVY, TAMANHO_MAPA3) && mapa[*posVX + movimentoX][*posVY] != '*' && mapa[*posVX + movimentoX][*posVY] != 'X') {
        // Atualizar a posição do personagem 'V' de acordo com o movimento na horizontal
        *posVX += movimentoX;
    } else if (movimentoY != 0 && dentroLimites(*posVX, *posVY + movimentoY, TAMANHO_MAPA3) && mapa[*posVX][*posVY + movimentoY] != '*' && mapa[*posVX][*posVY + movimentoY] != 'X') {
        // Atualizar a posição do personagem 'V' de acordo com o movimento na vertical
        *posVY += movimentoY;
    }

    // Desenhar o personagem 'V' na nova posição
    mapa[*posVX][*posVY] = 'V';
}



void fase1() {
    char mapa[TAMANHO_MAPA][TAMANHO_MAPA];
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            mapa[i][j] = ' ';
        }
    }

    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            if (i == 0 || i == TAMANHO_MAPA - 1 || j == 0 || j == TAMANHO_MAPA - 1) {
                mapa[i][j] = '*';
            }
        }
    }

    int obstaculosX[NUM_OBSTACULOS] = {1, 3, 4, 5, 5, 5, 7, 8, 8, 7, 2, 4, 3, 3};
    int obstaculosY[NUM_OBSTACULOS] = {2, 4, 4, 2, 3, 7, 8, 5, 2, 2, 8, 7, 5, 6};

    for (int i = 0; i < NUM_OBSTACULOS; i++) {
        mapa[obstaculosX[i]][obstaculosY[i]] = '*';
    }

    int posX = 1;
    int posY = 1;
    mapa[8][1] = 'X';
    mapa[8][8] = '@';
    mapa[5][5] = 'D';
    int posAnteriorX = 8;
    int posAnteriorY = 1;
    int passouPorAt = 0;
    int venceu = 0;

    char movimento;

    while (!venceu) {
        mapa[posX][posY] = '&';

        system("cls");
        printf("Fase 1:\n");
        for (int i = 0; i < TAMANHO_MAPA; i++) {
            for (int j = 0; j < TAMANHO_MAPA; j++) {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        scanf(" %c", &movimento);
        int novaPosX = posX;
        int novaPosY = posY;
        if (movimento == 'd' && posY < TAMANHO_MAPA - 2) {
            novaPosY++;
        } else if (movimento == 'a' && posY > 1) {
            novaPosY--;
        } else if (movimento == 'w' && posX > 1) {
            novaPosX--;
        } else if (movimento == 's' && posX < TAMANHO_MAPA - 2) {
            novaPosX++;
        }

        if ((mapa[novaPosX][novaPosY] == 'D' || (mapa[novaPosX][novaPosY] == '=' && passouPorAt == 0)) || ehObstaculo(novaPosX, novaPosY, obstaculosX, obstaculosY, NUM_OBSTACULOS)) {
            novaPosX = posX;
            novaPosY = posY;
        }

        mapa[posX][posY] = ' ';
        posX = novaPosX;
        posY = novaPosY;

        if (!passouPorAt && mapa[posX][posY] == '@') {
            passouPorAt = 1;
        }

        if (mapa[posX][posY] == '=' && passouPorAt) {
            printf("Boa irmao, deitou!\n");
            venceu = 1;
            system("pause") ;
        	fase2() ;
        }

       if (posX == posAnteriorX && posY == posAnteriorY) {
		    printf("Foi ruinzao mano, game over\n");
		    system("pause");
		    system("cls");
		    mapa[posX][posY] = ' '; // Remover o 'X' da posição anterior
		    posX = 1;
		    posY = 1;
		    posAnteriorX = 8;
		    posAnteriorY = 1;
		    mapa[8][1] = 'X'; // Resetar a posição do 'X' após o reinício da fase
		    continue;
		}	

        if (movimento == 'i' && passouPorAt) {
            if ((posX == 5 && (posY == 4 || posY == 6)) || ((posX == 4 || posX == 6) && posY == 5)) {
                mapa[5][5] = '=';
            } else {
                printf("Ta afobado mano? so pode transformar do lado\n");
                system("pause");
            }
        }

        moverX(&posAnteriorX, &posAnteriorY, mapa); // Mover o 'X' após o movimento do jogador
                                                     // Verificar se o jogador e o '&' estão na mesma posição
        if (posX == posAnteriorX && posY == posAnteriorY) {
            printf("Voce foi pego pelo &! Reiniciando a fase...\n");
            // Redefinir as posições iniciais do jogador e do 'X'

            // Outras redefinições necessárias...
            continue; // Continuar para a próxima iteração do loop
        }
    }
}






void fase2() {
    // Criar matriz para representar o mapa
            char mapa[TAMANHO_MAPA2][TAMANHO_MAPA2];

            // Inicializar o mapa com espaços em branco
            for (int i = 0; i < TAMANHO_MAPA2; i++) {
                for (int j = 0; j < TAMANHO_MAPA2; j++) {
                    mapa[i][j] = ' ';
                }
            }

            // Adicionar as bordas do mapa
            for (int i = 0; i < TAMANHO_MAPA2; i++) {
                for (int j = 0; j < TAMANHO_MAPA2; j++) {
                    if (i == 0 || i == TAMANHO_MAPA2 - 1 || j == 0 || j == TAMANHO_MAPA2 - 1) {
                        mapa[i][j] = '*';
                    }
                }
            }

            // Adicionar as paredes
            mapa[2][2] = '*';
            mapa[5][5] = '*';
            mapa[7][14] = '*';
            mapa[8][18] = '*';

            // Adicionar os espinhos
            int posEspinhoX[NUM_OBSTACULOS]; // Posições X dos espinhos
            int posEspinhoY[NUM_OBSTACULOS]; // Posições Y dos espinhos

            for (int i = 0; i < NUM_OBSTACULOS; i++) {
                int x = rand() % (TAMANHO_MAPA2 - 2) + 1;
                int y = rand() % (TAMANHO_MAPA2 - 2) + 1;
                posEspinhoX[i] = x;
                posEspinhoY[i] = y;
                mapa[x][y] = '#'; // Adicionar espinho na posição (x, y)
            }

            // Definir a posição inicial do jogador
            int posJogadorX = 1; // Escolha a posição inicial em X
            int posJogadorY = 1; // Escolha a posição inicial em Y

            // Definir a posição inicial do 'X'
            int posX = 1; // Posição inicial em X do 'X'
            int posY = 18; // Posição inicial em Y do 'X'

            // Contador de toques no espinho
            int contadorEspinho = 0;

            // Variável para controlar se o jogador passou pelo caractere "@"
            int passouPorAt = 0;

            // Loop principal para mover o jogador e o 'X'
            char movimento;

            while (1) {
            	if (posJogadorX == posX && posJogadorY == posY) {
			        printf("De novo KKKKKKKKKKKKKKKK ruinzao");
			        // Redefinir as posições iniciais do jogador e do 'X'
			        mapa[posX][posY] = ' '; // Remover o 'X' da posição anterior
			        posJogadorX = 1;
			        posJogadorY = 1;
			        posX = 1;
			        posY = 18;
			        mapa[1] [18] = 'X' ;
			        // Outras redefinições necessárias...
			        continue; // Continuar para a próxima iteração do loop
			    }
            	
                // Movimento do caractere 'X'
                moverX2(&posX, &posY, mapa);

                // Limpar a tela e exibir o mapa atualizado
                system("cls"); // Limpar a tela (Windows)
                printf("Fase 2:\n");
                for (int i = 0; i < TAMANHO_MAPA2; i++) {
                    for (int j = 0; j < TAMANHO_MAPA2; j++) {
                        if (i == posJogadorX && j == posJogadorY) {
                            printf("& ");
                        } else if (i == posX && j == posY) {
                            printf("X ");
                        } else if (i == 18 && j == 1) {
                            printf("O "); // Imprimir o caractere "O"
                        } else {
                            printf("%c ", mapa[i][j]);
                        }
                    }
                    printf("\n");
                }

                // Capturar o movimento do jogador
                scanf(" %c", &movimento);
                int novaPosJogadorX = posJogadorX;
                int novaPosJogadorY = posJogadorY;

                // Verificar se o jogador pressionou "i" e se ele passou pelo caractere "@"
                if (movimento == 'i' && passouPorAt) {
                    // Verificar se o jogador está adjacente ao caractere "D" (nas posições 17,2 17,4 16,3 18,3)
                    if ((posJogadorX == 17 && (posJogadorY == 2 || posJogadorY == 4)) || ((posJogadorX == 16 || posJogadorX == 18) && posJogadorY == 3)) {
                        mapa[17][3] = '='; // Trocar o caractere "D" por "="
                    } else {
                        printf("Bora la parceiro, segundo mapa ja\n");
                        system("pause");
                    }
                }

                // Atualizar a posição do jogador de acordo com o movimento
                if (movimento == 'd' && posJogadorY < TAMANHO_MAPA2 - 2 && mapa[novaPosJogadorX][novaPosJogadorY + 1] != '*') {
                    novaPosJogadorY++;
                } else if (movimento == 'a' && posJogadorY > 1 && mapa[novaPosJogadorX][novaPosJogadorY - 1] != '*') {
                    novaPosJogadorY--;
                } else if (movimento == 'w' && posJogadorX > 1 && mapa[novaPosJogadorX - 1][novaPosJogadorY] != '*') {
                    novaPosJogadorX--;
                } else if (movimento == 's' && posJogadorX < TAMANHO_MAPA2 - 2 && mapa[novaPosJogadorX + 1][novaPosJogadorY] != '*') {
                    novaPosJogadorX++;
                } else if (movimento == 'r') {
                    // Reiniciar a fase
                    // Recriar o mapa
                    for (int i = 0; i < TAMANHO_MAPA2; i++) {
                        for (int j = 0; j < TAMANHO_MAPA2; j++) {
                            if (i == 0 || i == TAMANHO_MAPA2 - 1 || j == 0 || j == TAMANHO_MAPA2 - 1) {
                                mapa[i][j] = '*';
                            } else {
                                mapa[i][j] = ' ';
                            }
                        }
                    }
                    // Adicionar as paredes
                    mapa[2][2] = '*';
                    mapa[5][5] = '*';
                    mapa[7][14] = '*';
                    mapa[8][18] = '*';
                    mapa[4][6] = '@';
                    mapa[17][3] = 'D';
                    mapa[1][18] = 'X';

                    // Adicionar os espinhos
                    for (int i = 0; i < NUM_OBSTACULOS; i++) {
                        int x = rand() % (TAMANHO_MAPA2 - 2) + 1;
                        int y = rand() % (TAMANHO_MAPA2 - 2) + 1;
                        posEspinhoX[i] = x;
                        posEspinhoY[i] = y;
                        mapa[x][y] = '#';
                    }
                    posJogadorX = 1; // Definir a posição inicial do jogador
                    posJogadorY = 1;
                    contadorEspinho = 0; // Zerar o contador de toques no espinho
                    posX = 1; // Definir a posição inicial do 'X'
                    posY = 18; // Definir a posição inicial do 'X'
                    continue; // Reiniciar o loop para exibir o mapa atualizado
                }

                // Verificar se a nova posição coincide com o obstáculo "O"
                if (novaPosJogadorX == 18 && novaPosJogadorY == 1) {
                    int opcao;
                    printf("Quer tocar no butao? (1 para sim, 2 para nao): ");
                    scanf("%d", &opcao);
                    if (opcao == 1) {
                    	system("cls") ;
                        printf("Se f#deu KKKKKKKKKKKKKKKKKKKKK \n");
                        system("pause") ;
                        system("cls") ;
                        return 0; // Encerrar o programa
                        system("cls") ;
                    } else if (opcao == 2) {
                        // Continuar o jogo normalmente
                    } else {
                        printf("Continuando o game");
                    }
                }

                // Verificar se a nova posição colide com o espinho
                if (ehObstaculo(novaPosJogadorX, novaPosJogadorY, posEspinhoX, posEspinhoY, NUM_OBSTACULOS)) {
                    posJogadorX = 1; // Reiniciar a posição do jogador
                    posJogadorY = 1;
                    contadorEspinho++; // Incrementar o contador de toques no espinho
                    if (contadorEspinho == 3) {
                        system("cls");
                        printf("Tu eh tao pereba que conseguiu morrer 3 vezes, volta pro menu e reinicia colega");
                        system("pause");
                        system("cls");
                        break; // Sair do loop e voltar para o menu
                    }
                } else {
                    // Atualizar a posição do jogador
                    posJogadorX = novaPosJogadorX;
                    posJogadorY = novaPosJogadorY;
                }

                // Verificar se o jogador está na mesma posição que o caractere "@"
                if (mapa[posJogadorX][posJogadorY] == '@') {
                    mapa[posJogadorX][posJogadorY] = ' '; // Substituir "@" por espaço em branco
                    passouPorAt = 1; // Atualizar o status indicando que o jogador passou pelo caractere "@"
                }

                // Verificar se o jogador está na mesma posição que o caractere "="
                if (mapa[posJogadorX][posJogadorY] == '=') {
                    printf("Fala dele (a), nunca critiquei \n");
                    system("pause");
                    fase3(); // Sair do loop e voltar para o menu
                }
                
                // Verificar se o jogador e o 'X' estão na mesma posição
                if (posJogadorX == posX && posJogadorY == posY) {
                    printf("Burrao, game over\n");
			        // Redefinir as posições iniciais do jogador e do 'X'
			        posJogadorX = 1;
			        posJogadorY = 1;
			        mapa[posX][posY] = ' ' ;
			        posX = 1;
			        posY = 18;
			        mapa [1] [18] = 'X' ;
			        // Outras redefinições necessárias...
			    }

                // Verificar se o jogador e o '&' estão na mesma posição
                if (posJogadorX == 18 && posJogadorY == 1) {
                    printf("Voce foi pego pelo &! Reiniciando a fase...\n");
			        // Redefinir as posições iniciais do jogador e do 'X'
			        posJogadorX = 1;
			        posJogadorY = 1;
			        posX = 1;
			        posY = 18;
			        // Outras redefinições necessárias...
			    }
            }
        } 



void fase3() {
    char mapa[TAMANHO_MAPA3][TAMANHO_MAPA3];

    // Inicializar o mapa com espaços em branco
    for (int i = 0; i < TAMANHO_MAPA3; i++) {
        for (int j = 0; j < TAMANHO_MAPA3; j++) {
            mapa[i][j] = ' ';
        }
    }

    // Adicionar as bordas do mapa
    for (int i = 0; i < TAMANHO_MAPA3; i++) {
        for (int j = 0; j < TAMANHO_MAPA3; j++) {
            if (i == 0 || i == TAMANHO_MAPA3 - 1 || j == 0 || j == TAMANHO_MAPA3 - 1) {
                mapa[i][j] = '*';
            }
        }
    }

    // Adicionar obstáculos, paredes, portas, etc.
    // Exemplo:
    mapa[5][5] = '*';  // Paredes
    mapa[10][20] = '*'; // Paredes
    mapa[15][30] = 'D'; // Porta
    mapa[25][10] = '#'; // Obstáculo
    mapa[1][20] = 'V';

    // Definir a posição inicial do jogador
    int posJogadorX = 1; // Escolha a posição inicial em X
    int posJogadorY = 1; // Escolha a posição inicial em Y

    // Definir a posição inicial do caractere "&"
    int posAndX = 1; // Escolha a posição inicial em X
    int posAndY = 1; // Escolha a posição inicial em Y

    // Definir a posição inicial do personagem 'V'
    int posVX = 1; // Defina a posição inicial do personagem 'V' aqui
    int posVY = 20; // Defina a posição inicial do personagem 'V' aqui

    // Loop principal para movimentação do jogador e interações com o mapa
    system("cls"); // Limpar a tela antes de imprimir o mapa
    printf("Fase 3:\n");

    while (1) {
        // Limpar a tela e exibir o mapa atualizado
        system("cls");
        printf("Fase 3:\n");
        for (int i = 0; i < TAMANHO_MAPA3; i++) {
            for (int j = 0; j < TAMANHO_MAPA3; j++) {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        // Capturar o movimento do jogador
        char movimento;
        scanf(" %c", &movimento);

        // Movimento do caractere "&" baseado na entrada do jogador
        moverAnd(&posAndX, &posAndY, mapa, movimento);

        // Lógica de movimento do jogador e outras interações...

        // Exemplo: verificar se o jogador e o '&' estão na mesma posição
        if (posJogadorX == posAndX && posJogadorY == posAndY) {
            printf("Voce foi pego pelo &! Reiniciando a fase...\n");
            // Redefinir as posições iniciais do jogador e do '&'
            posJogadorX = 1;
            posJogadorY = 1;
            posAndX = 1;
            posAndY = 1;
            // Outras redefinições necessárias...
        }

        // Movimento do personagem 'V'
        moverV(&posVX, &posVY, posAndX, posAndY, mapa);

        // Verificar se o personagem 'V' e o '&' estão na mesma posição
        if (posVX == posAndX && posVY == posAndY) {
        	printf("Egua te arriaram, bora de novo\n");
            system("pause") ;
        	system("cls") ;
            // Redefinir as posições iniciais do jogador e do 'V'
            posJogadorX = 1;
            posJogadorY = 1;
            posAndX = 1;
            posAndY = 1;
            mapa[posVX] [posVY] = ' ' ;
            posVX = 1; // Defina a posição inicial do personagem 'V' aqui
            posVY = 20;
			mapa [1] [20] = 'V' ;// Defina a posição inicial do personagem 'V' aqui
			continue ;
            // Outras redefinições necessárias...
        }

        // Lógica de movimento do jogador e outras interações...
    }
}




>>>>>>> 45851e366bceb3de44eaa881ecdcfadafd668a5f
int main() {
    srand(time(NULL));

    int escolha;

<<<<<<< HEAD
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
=======
    do {
        printf("Menu:\n");
        printf("1. Hablar no Mapa 1\n");
        printf("2. Hablar no Mapa 2\n");
    	printf("3. Teste monstro nivel 2\n") ;
        printf("4. Tutorial\n");
        printf("5. Jogo ir de naninha\n");
		printf("Escolha: ");
        scanf("%d", &escolha);

        // Limpar o buffer de entrada
        while (getchar() != '\n');

        if (escolha == 1) {
            fase1();
        } else if (escolha == 2) {
        	fase2();
        } else if (escolha == 3) {
        	fase3();
		  }else if (escolha == 4) {
            // Tutorial
            printf("=== Tutorial ===\n");
            printf("Use as teclas 'w', 'a', 's', 'd' para mover o boneco.\n");
            printf("Use a tecla 'r' para reiniciar a fase 2 caso venha errada\n") ;
            printf("Pressione 'i' para abrir a porta apos passar pelo @.\n");
            printf("Te arranca do monstro e passe pela porta para vencer o jogo!\n");
            printf("Fica de olho no espinho irmao, se tu tocar 3 vezes nele, sal em ti brother\n") ;
            printf("Pressione qualquer tecla para voltar ao menu.\n");
            getchar(); // Limpar o buffer de entrada
            getchar(); // Aguardar pressionar qualquer tecla para continuar
            system("cls");
		
        
		} else if (escolha == 5) {
            printf("zzzzzzzzzzzz....\n");
            break; // Finalizar o loop
       	}else {
            printf("Escolha invalida! Por favor, escolha 1, 2, 3 ou 4.\n");
            system("pause");
            system("cls");
>>>>>>> 45851e366bceb3de44eaa881ecdcfadafd668a5f
        }
    }

    return 0;
}

