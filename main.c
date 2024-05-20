#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_MAPA 10
#define TAMANHO_MAPA2 20
#define TAMANHO_MAPA3 40
#define NUM_OBSTACULOS 50
#define NUM_OBSTACULOS_FASE3 250
#define POSICAO_INICIAL_V_X 13
#define POSICAO_INICIAL_V_Y 20

int posEspinhoX3[NUM_OBSTACULOS_FASE3];
int posEspinhoY3[NUM_OBSTACULOS_FASE3];


int ehObstaculo(int x, int y, int obstaculosX[], int obstaculosY[], int numObstaculos);

int ehPosicaoProibida(int x, int y) {
    // Adicione todas as posições proibidas aqui
    if ((x == 4 && y == 6) || (x == 17 && y == 3) || (x == 1 && y == 18)) {
        return 1;
    }
    return 0;
}

int dentroLimites(int x, int y, int tamanhoMapa) {
    return x >= 0 && x < tamanhoMapa && y >= 0 && y < tamanhoMapa;
}

int ehObstaculo(int x, int y, int obstaculosX[], int obstaculosY[], int numObstaculos) {
    for (int i = 0; i < numObstaculos; i++) {
        if (x == obstaculosX[i] && y == obstaculosY[i]) {
            return 1;
        }
    }
    return 0;
}

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

void moverX2(int *posX, int *posY, char mapa[][TAMANHO_MAPA2]) { 
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
    
void moverX3(int *posX, int *posY, char mapa[][TAMANHO_MAPA3]) { // Alteração aqui
    int deltaX, deltaY;
    do {
        deltaX = rand() % 3 - 1;
        deltaY = rand() % 3 - 1;
    } while (!dentroLimites(*posX + deltaX, *posY + deltaY, TAMANHO_MAPA3) || mapa[*posX + deltaX][*posY + deltaY] == '*' || mapa[*posX + deltaX][*posY + deltaY] == '#' ||  mapa[*posX + deltaX][*posY + deltaY] == 'V' ||  mapa[*posX + deltaX][*posY + deltaY] == '>'   || mapa[*posX + deltaX][*posY + deltaY] == 'D' || mapa[*posX + deltaX][*posY + deltaY] == '@'|| mapa[*posX + deltaX][*posY + deltaY] == '=' || mapa[*posX + deltaX][*posY + deltaY] == '<');

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
    if (dentroLimites(*posX + deltaX, *posY + deltaY, TAMANHO_MAPA3) && mapa[*posX + deltaX][*posY + deltaY] != '*' && mapa[*posX + deltaX][*posY + deltaY] != 'D') {
        mapa[*posX][*posY] = ' '; // Limpar a posição atual
        *posX += deltaX; // Atualizar a posição em X
        *posY += deltaY; // Atualizar a posição em Y
        mapa[*posX][*posY] = '&'; // Atualizar a posição no mapa
    } else if (mapa[*posX + deltaX][*posY + deltaY] == '#') {
        // Se a próxima posição for um espinho, apenas retorne à posição inicial
        *posX = POSICAO_INICIAL_V_X;
        *posY = POSICAO_INICIAL_V_Y;
        
        
    }
}

void moverV(int* posVX, int* posVY, int posAndX, int posAndY, char mapa[TAMANHO_MAPA3][TAMANHO_MAPA3], int espinhosX[], int espinhosY[], int numEspinhos) {
    int novaPosVX = *posVX;
    int novaPosVY = *posVY;
    int movimentoX = (posAndX > *posVX) ? 1 : (posAndX < *posVX) ? -1 : 0;
    int movimentoY = (posAndY > *posVY) ? 1 : (posAndY < *posVY) ? -1 : 0;

    // Primeiro tenta mover na direção X
    if (movimentoX != 0 && dentroLimites(*posVX + movimentoX, *posVY, TAMANHO_MAPA3) && mapa[*posVX + movimentoX][*posVY] != '*' && mapa[*posVX + movimentoX][*posVY] != 'X' && mapa[*posVX + movimentoX][*posVY] != '<' && mapa[*posVX + movimentoX][*posVY] != 'O' && mapa[*posVX + movimentoX][*posVY] != 'D' && mapa[*posVX + movimentoX][*posVY] != '@' && mapa[*posVX + movimentoX][*posVY] != '=') {
        novaPosVX += movimentoX;
    } else if (movimentoY != 0 && dentroLimites(*posVX, *posVY + movimentoY, TAMANHO_MAPA3) && mapa[*posVX][*posVY + movimentoY] != '*' && mapa[*posVX][*posVY + movimentoY] != 'X' && mapa[*posVX + movimentoX][*posVY] != '<' && mapa[*posVX + movimentoX][*posVY] != 'O' && mapa[*posVX + movimentoX][*posVY] != 'D' && mapa[*posVX + movimentoX][*posVY] != '@' && mapa[*posVX + movimentoX][*posVY] != '=') {
        novaPosVY += movimentoY;
    } else {
        // Se não puder mover na direção principal, tenta mover em direções alternativas
        if (movimentoX != 0 && dentroLimites(*posVX, *posVY + movimentoY, TAMANHO_MAPA3) && mapa[*posVX][*posVY + movimentoY] != '*' && mapa[*posVX][*posVY + movimentoY] != 'X' && mapa[*posVX + movimentoX][*posVY] != '<' && mapa[*posVX + movimentoX][*posVY] != 'O' && mapa[*posVX + movimentoX][*posVY] != 'D' && mapa[*posVX + movimentoX][*posVY] != '@' && mapa[*posVX + movimentoX][*posVY] != '=' ) {
            novaPosVY += movimentoY;
        } else if (movimentoY != 0 && dentroLimites(*posVX + movimentoX, *posVY, TAMANHO_MAPA3) && mapa[*posVX + movimentoX][*posVY] != '*' && mapa[*posVX + movimentoX][*posVY] != 'X' && mapa[*posVX + movimentoX][*posVY] != '<' && mapa[*posVX + movimentoX][*posVY] != 'O' && mapa[*posVX + movimentoX][*posVY] != 'D' && mapa[*posVX + movimentoX][*posVY] != '@' && mapa[*posVX + movimentoX][*posVY] != '=') {
            novaPosVX += movimentoX;
        }
        if (mapa[*posVX + movimentoX][*posVY + movimentoY] == '<' || mapa[*posVX + movimentoX][*posVY + movimentoY] == 'D' || mapa[*posVX + movimentoX][*posVY + movimentoY] == '@' || mapa[*posVX + movimentoX][*posVY + movimentoY] == 'O' || mapa[*posVX + movimentoX][*posVY + movimentoY] == '=') {
        // Se o próximo movimento colidir com o portal, não realiza o movimento
        return;
    }
    }

    // Verifica colisão com espinhos
    if (ehObstaculo(novaPosVX, novaPosVY, espinhosX, espinhosY, numEspinhos)) {
        // Se houver colisão, tenta mover em outra direção

        // Primeiro tenta mover na direção Y
        if (movimentoY != 0 && dentroLimites(*posVX, *posVY + movimentoY, TAMANHO_MAPA3) && mapa[*posVX][*posVY + movimentoY] != '*' && mapa[*posVX][*posVY + movimentoY] != 'X' && mapa[*posVX + movimentoX][*posVY] != '<' && mapa[*posVX + movimentoX][*posVY] != 'O' && mapa[*posVX + movimentoX][*posVY] != 'D' && mapa[*posVX + movimentoX][*posVY] != '@' && mapa[*posVX + movimentoX][*posVY] != '=') {
            novaPosVY += movimentoY;
        } else if (movimentoX != 0 && dentroLimites(*posVX + movimentoX, *posVY, TAMANHO_MAPA3) && mapa[*posVX + movimentoX][*posVY] != '*' && mapa[*posVX + movimentoX][*posVY] != 'X' && mapa[*posVX + movimentoX][*posVY] != '<' && mapa[*posVX + movimentoX][*posVY] != 'O' && mapa[*posVX + movimentoX][*posVY] != 'D' && mapa[*posVX + movimentoX][*posVY] != '@' && mapa[*posVX + movimentoX][*posVY] != '=') {
            novaPosVX += movimentoX;
        }

        // Se ainda houver colisão, informa e não realiza o movimento
        if (ehObstaculo(novaPosVX, novaPosVY, espinhosX, espinhosY, numEspinhos)) {
            return;
        }
    }

    mapa[*posVX][*posVY] = ' ';  // Limpa a posição antiga
    *posVX = novaPosVX;
    *posVY = novaPosVY;
    mapa[*posVX][*posVY] = 'V';  // Define a nova posição
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
                if (movimento == 'd' && posJogadorY < TAMANHO_MAPA2 - 2 && mapa[novaPosJogadorX][novaPosJogadorY + 1] != '*' && mapa[novaPosJogadorX][novaPosJogadorY + 1] != 'D') {
            		novaPosJogadorY++;
		        } else if (movimento == 'a' && posJogadorY > 1 && mapa[novaPosJogadorX][novaPosJogadorY - 1] != '*' && mapa[novaPosJogadorX][novaPosJogadorY - 1] != 'D') {
		            novaPosJogadorY--;
		        } else if (movimento == 'w' && posJogadorX > 1 && mapa[novaPosJogadorX - 1][novaPosJogadorY] != '*' && mapa[novaPosJogadorX - 1][novaPosJogadorY] != 'D') {
		            novaPosJogadorX--;
		        } else if (movimento == 's' && posJogadorX < TAMANHO_MAPA2 - 2 && mapa[novaPosJogadorX + 1][novaPosJogadorY] != '*' && mapa[novaPosJogadorX + 1][novaPosJogadorY] != 'D') {
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
                    // Adicionar os caracteres
                    mapa[2][2] = '*';
                    mapa[5][5] = '*';
                    mapa[7][14] = '*';
                    mapa[8][18] = '*';
                    mapa[4][6] = '@';
                    mapa[17][3] = 'D';
                    mapa[1][18] = 'X';

                    // Adicionar os espinhos
                    for (int i = 0; i < NUM_OBSTACULOS; i++) {
                    	int x, y ;
						do {
                    		x = rand() % (TAMANHO_MAPA2 - 2) + 1;
	                        y = rand() % (TAMANHO_MAPA2 - 2) + 1;
	                        
	                    }while(ehPosicaoProibida(x, y) || mapa[x][y] != ' '); // Verificar se a posição é proibida ou já está ocupada)
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
                        exit(0); // Encerrar o programa
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
                        printf("Tu eh tao pereba que conseguiu morrer 3 vezes, volta pro menu e reinicia colega\n");
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
    for (int i = 0; i < TAMANHO_MAPA3; i++) {
        for (int j = 0; j < TAMANHO_MAPA3; j++) {
            mapa[i][j] = ' ';
        }
    }

    for (int i = 0; i < TAMANHO_MAPA3; i++) {
        for (int j = 0; j < TAMANHO_MAPA3; j++) {
            if (i == 0 || i == TAMANHO_MAPA3 - 1 || j == 0 || j == TAMANHO_MAPA3 - 1) {
                mapa[i][j] = '*';
            }
        }
    }

    #define NUM_POSICOES_PROIBIDAS 80
    int posicoesProibidasX[NUM_POSICOES_PROIBIDAS] = {1, 8, 21, 9, 20, 24, 19, 27, 2, 3, 21, 2}; // posições proibidas X
    int posicoesProibidasY[NUM_POSICOES_PROIBIDAS] = {1, 8, 22, 9, 20, 18, 8, 24, 3, 1, 19, 2}; // posições proibidas Y

    int posEspinhoX[NUM_OBSTACULOS_FASE3];
    int posEspinhoY[NUM_OBSTACULOS_FASE3];

    for (int i = 0; i < NUM_OBSTACULOS_FASE3; i++) {
        int x, y;
        int posicaoValida;

        do {
            posicaoValida = 1;
            x = rand() % (TAMANHO_MAPA3 - 2) + 1;
            y = rand() % (TAMANHO_MAPA3 - 2) + 1;

            // Verificar se a posição gerada está nas posições proibidas
            for (int j = 0; j < NUM_POSICOES_PROIBIDAS; j++) {
                if (x == posicoesProibidasX[j] && y == posicoesProibidasY[j]) {
                    posicaoValida = 0;
                    break;
                }
            }
        } while (!posicaoValida);

        posEspinhoX[i] = x;
        posEspinhoY[i] = y;
        mapa[x][y] = '#';
    }

    int posJogadorX = 1;
    int posJogadorY = 1;
    int posX = 8;
    int posY = 8;
    int posVx = POSICAO_INICIAL_V_X;
    int posVy = POSICAO_INICIAL_V_Y;
    int portal1X = 9;
    int portal1Y = 9;
    int portal2X = 20;
    int portal2Y = 20;
    mapa[8][8] = 'X';
    mapa[21][22] = 'O';
    mapa[2][2] = 'D';
    mapa[27][24] = '@';
    mapa[POSICAO_INICIAL_V_X][POSICAO_INICIAL_V_Y] = 'V';
    mapa[9][9] = '<';
    mapa[20][20] = '<';

    char movimento;
    int contadorEspinho = 0;
    int passouPorAt = 0;

    while (1) {
        if (posJogadorX == posX && posJogadorY == posY) {
            system("cls");
            printf("De novo KKKKKKKKKKKKKKKK ruinzao\n");
            system("pause");
            system("cls");
            mapa[posX][posY] = ' ';
            mapa[posVx][posVy] = ' ';
            posJogadorX = 1;
            posJogadorY = 1;
            posX = 8;
            posY = 8;
            posVx = POSICAO_INICIAL_V_X;
            posVy = POSICAO_INICIAL_V_Y;
            mapa[8][8] = 'X';
            mapa[POSICAO_INICIAL_V_X][POSICAO_INICIAL_V_Y] = 'V';
            continue;
        }

        system("cls");
        printf("Fase 3:\n");
        for (int i = 0; i < TAMANHO_MAPA3; i++) {
            for (int j = 0; j < TAMANHO_MAPA3; j++) {
                if (i == posJogadorX && j == posJogadorY) {
                    printf("& ");
                } else if (i == posX && j == posY) {
                    printf("X ");
                } else if (i == posVx && j == posVy) {
                    printf("V ");
                } else {
                    printf("%c ", mapa[i][j]);
                }
            }
            printf("\n");
        }

        scanf(" %c", &movimento);

        int novaPosJogadorX = posJogadorX;
        int novaPosJogadorY = posJogadorY;

        moverAnd(&novaPosJogadorX, &novaPosJogadorY, mapa, movimento);

        if (ehObstaculo(novaPosJogadorX, novaPosJogadorY, posEspinhoX, posEspinhoY, NUM_OBSTACULOS_FASE3)) {
            printf("Afobou maninho (a), acontece\n");
            system("pause");
            system("cls");
            // Remover os personagens das posições anteriores
            mapa[posJogadorX][posJogadorY] = ' ';
            mapa[posX][posY] = ' ';
            mapa[posVx][posVy] = ' ';

            // Redefinir as posições iniciais
            posJogadorX = 1;
            posJogadorY = 1;
            posX = 8;
            posY = 8;
            posVx = POSICAO_INICIAL_V_X;
            posVy = POSICAO_INICIAL_V_Y;

            // Adicionar os personagens nas novas posições iniciais
            mapa[posX][posY] = 'X';
            mapa[posVx][posVy] = 'V';
            mapa[9][9] = '<';
            mapa[20][20] = '<';
            mapa[27][24] = '@';

            for (int i = 0; i < NUM_OBSTACULOS_FASE3; i++) {
                mapa[posEspinhoX[i]][posEspinhoY[i]] = '#';
            }
            if (mapa[posJogadorX][posJogadorY] == '#') {
                mapa[posJogadorX][posJogadorY] = '&';
            }
            contadorEspinho++; // Incrementar o contador de toques no espinho
            if (contadorEspinho == 3) {
                system("cls");
                printf("Tu eh tao pereba que conseguiu morrer 3 vezes, volta pro menu e reinicia colega\n");
                system("pause");
                system("cls");
                break; // Sair do loop e voltar para o menu
            }
            continue;

        }
        posJogadorX = novaPosJogadorX;
        posJogadorY = novaPosJogadorY;
        moverX3(&posX, &posY, mapa);
        moverV(&posVx, &posVy, posJogadorX, posJogadorY, mapa, posEspinhoX, posEspinhoY, NUM_OBSTACULOS_FASE3);

        if (posJogadorX == portal1X && posJogadorY == portal1Y) {
            mapa[9][9] = '<';
            posJogadorX = 20;
            posJogadorY = 19;
        } else if (posJogadorX == portal2X && posJogadorY == portal2Y) {
            mapa[20][20] = '<';
            posJogadorX = 9;
            posJogadorY = 8;
        }
        if (posJogadorX == 27 && posJogadorY == 24){
		    printf("Pegaste a chave brother, so nao ser ruim");
		    mapa[posJogadorX][posJogadorY] = ' '; // Substituir "@" por espaço em branco
		    system("pause");
		    system("cls");
		    passouPorAt = 1; // Atualizar o status indicando que o jogador passou pelo caractere "@"
		}
		// Verificar se o jogador está na mesma posição que o caractere "="
		if (posJogadorX == 2 && posJogadorY == 2) {
			system("cls") ;
		    printf("Parabens! vc zerou o game!\n\n\n");
	printf(" ____           _   _\n");                   
	printf("|  _ \    ___  (_) | |_    ___    _   _\n");   
    printf("| | | |  / _ \ | | | __|  / _ \  | | | |\n");  
    printf("| |_| | |  __/ | | | |_  | (_) | | |_| |\n"); 
    printf("|____/   \___| |_|  \__|  \___/   \__,_|_\n");
    printf("(_)  _ __   _ __ ___     __ _    ___   | |\n");
    printf("| | | '__| | '_ ` _ \   / _` |  / _ \  | |\n");
	printf("| | | |    | | | | | | | (_| | | (_) | |_|\n");
	printf("|_| |_|    |_| |_| |_|  \__,_|  \___/  (_)\n");
		    system("pause");
		    system("cls") ;
		    return; // Retorna ao menu
		}


        // Verificar se o jogador pressionou "i" e se ele passou pelo caractere "@"
        if (movimento == 'i' && passouPorAt == 1) {
            // Verificar se o jogador está adjacente ao caractere "D" (nas posições 17,2 17,4 16,3 18,3)
            if ((posJogadorX == 2 || (posJogadorY == 1 || posJogadorY == 2)) || ((posJogadorX == 3 || posJogadorX == 1) || posJogadorY == 3)) {
                mapa[2][2] = '='; // Trocar o caractere "D" por "="
            } else {
                printf("Egua bicho terceiro mapa e tu ainda n sabe que precisa estar do lado pra apertar, pqp\n");
                system("pause");
            }
        }
		if (novaPosJogadorX == 21 && novaPosJogadorY == 22) {
                    int opcao;
                    printf("Quer tocar no butao? (1 para sim, 2 para nao): ");
                    scanf("%d", &opcao);
                    if (opcao == 1) {
                    	system("cls") ;
                        printf("Quero ver passar agora\n");
                        system("pause") ;
            			mapa[9][9] = ' ';
            			mapa[20][20] = ' ';
                    } else if (opcao == 2) {
                        
                    } else {
                        printf("Continuando o game");
                    }
        }
        if (posJogadorX == posVx && posJogadorY == posVy) {
            system("cls");
            printf("V te arriou, bora de novo\n");
            system("pause");
            system("cls");
			
            // Remover os caracteres das suas posições atuais
            mapa[posJogadorX][posJogadorY] = ' ';
            mapa[posX][posY] = ' ';
            mapa[posVx][posVy] = ' ';

            // Redefinir as posições iniciais
            posJogadorX = 1;
            posJogadorY = 1;
            posX = 8;
            posY = 8;
            posVx = POSICAO_INICIAL_V_X;
            posVy = POSICAO_INICIAL_V_Y;

            // Adicionar os personagens nas novas posições iniciais
            mapa[posJogadorX][posJogadorY] = '&';
            mapa[posX][posY] = 'X';
            mapa[posVx][posVy] = 'V';
            mapa[9][9] = '<';
            mapa[20][20] = '<';
            mapa[27][24] = '@';
            mapa[21][22] = 'O';
            

            for (int i = 0; i < NUM_OBSTACULOS_FASE3; i++) {
                mapa[posEspinhoX[i]][posEspinhoY[i]] = '#';
            }
            if (mapa[posJogadorX][posJogadorY] == '#') {
                mapa[posJogadorX][posJogadorY] = '&';
        }

            continue;

        }
    }
}



int main() {
    srand(time(NULL));

    int escolha;

    do {
        printf("Menu:\n");
        printf("1. Comessar o show\n");
        printf("2. Tutorial\n");
        printf("3. Jogo ir de naninha\n");
		printf("Escolha: ");
		scanf("%d", &escolha);
        

        // Limpar o buffer de entrada
        while (getchar() != '\n');

        if (escolha == 1) {
            fase1();
        } else if (escolha == 22) {
        	fase2();
        } else if (escolha == 33) {
        	fase3();
		} else if (escolha == 2) {
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
		
        
		} else if (escolha == 3) {
            printf("zzzzzzzzzzzz....\n");
            break; // Finalizar o loop
       	}else {
            printf("Escolha invalida! Por favor, escolha 1, 2, 3 ou 4.\n");
            system("pause");
            system("cls");
        }
    } while (1);

    return 0;
}
