#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_MAPA 10
#define TAMANHO_MAPA2 20
#define TAMANHO_MAPA3 40
#define NUM_OBSTACULOS 50

int ehObstaculo(int x, int y, int obstaculosX[], int obstaculosY[], int numObstaculos);

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
            printf("Voce encontrou um obstaculo! Tente outra direcao.\n");
            novaPosX = posX;
            novaPosY = posY;
        }

        mapa[posX][posY] = ' ';
        posX = novaPosX;
        posY = novaPosY;

        if (!passouPorAt && mapa[posX][posY] == '@') {
            printf("Voce passou pelo caractere @! Pressione 'i' para alterar o caractere D para =.\n");
            passouPorAt = 1;
        }

        if (mapa[posX][posY] == '=' && passouPorAt) {
            printf("Voce venceu!\n");
            venceu = 1;
            system("pause") ;
        	fase2() ;
        }

       if (posX == posAnteriorX && posY == posAnteriorY) {
		    printf("Voce encontrou o caractere X! Fim do jogo.\n");
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
                printf("Voce so pode transformar o D em = quando estiver ao lado dele!\n");
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
			        printf("Voce foi pego pelo X! Reiniciando a fase...\n");
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
                        printf("Voce so pode transformar o D em = quando estiver ao lado dele!\n");
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
                    printf("Voce deseja tocar no botao? (1 para sim, 2 para nao): ");
                    scanf("%d", &opcao);
                    if (opcao == 1) {
                    	system("cls") ;
                        printf("Morreu, otario KKKKKKKKKKKKKKKKKKKKK \n");
                        system("pause") ;
                        system("cls") ;
                        return 0; // Encerrar o programa
                        system("cls") ;
                    } else if (opcao == 2) {
                        // Continuar o jogo normalmente
                    } else {
                        printf("Opçao invalida! Continuando o jogo...\n");
                    }
                }

                // Verificar se a nova posição colide com o espinho
                if (ehObstaculo(novaPosJogadorX, novaPosJogadorY, posEspinhoX, posEspinhoY, NUM_OBSTACULOS)) {
                    posJogadorX = 1; // Reiniciar a posição do jogador
                    posJogadorY = 1;
                    contadorEspinho++; // Incrementar o contador de toques no espinho
                    if (contadorEspinho == 3) {
                        system("cls");
                        printf("Voce tocou em um espinho 3 vezes! Voltando para o menu...\n");
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
                    printf("Parabens! Voce completou o desafio!\n");
                    system("pause");
                    break; // Sair do loop e voltar para o menu
                }
                
                // Verificar se o jogador e o 'X' estão na mesma posição
                if (posJogadorX == posX && posJogadorY == posY) {
                    printf("Voce foi pego pelo X! Reiniciando a fase...\n");
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




int main() {
    srand(time(NULL));

    int escolha;

    do {
        printf("Menu:\n");
        printf("1. Iniciar jogo no Mapa 1\n");
        printf("2. Iniciar jogo no Mapa 2\n");
        printf("3. Tutorial\n");
        printf("4. Encerrar programa\n");
		printf("Escolha: ");
        scanf("%d", &escolha);

        // Limpar o buffer de entrada
        while (getchar() != '\n');

        if (escolha == 1) {
            fase1();
        } else if (escolha == 2) {
        	fase2();
        } else if (escolha == 3) {
            // Tutorial
            printf("=== Tutorial ===\n");
            printf("Use as teclas 'w', 'a', 's', 'd' para mover o personagem '&'.\n");
            printf("Use a tecla 'r' para reiniciar a fase 2 caso venha errada\n") ;
            printf("Pressione 'i' para abrir a porta após passar pelo @.\n");
            printf("Evite o monstro e passe pela porta para vencer o jogo!\n");
            printf("Cuidado com espinho, se tocar 3 vezes nele, sal em ti brother\n") ;
            printf("Pressione qualquer tecla para voltar ao menu.\n");
            getchar(); // Limpar o buffer de entrada
            getchar(); // Aguardar pressionar qualquer tecla para continuar
            system("cls");

        } else if (escolha == 4) {
            printf("Encerrando o programa...\n");
            break; // Finalizar o loop
        } else {
            printf("Escolha invalida! Por favor, escolha 1, 2, 3 ou 4.\n");
            system("pause");
            system("cls");
        }
    } while (1);

    return 0;
}
