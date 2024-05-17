#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define LARGURA 40
#define ALTURA 40

char mapa[ALTURA][LARGURA];
int jogadorX, jogadorY;
int chaveX, chaveY;
int portaX, portaY;
int monstro1X, monstro1Y;
int monstro2X, monstro2Y;
int teletransporte1X, teletransporte1Y;
int teletransporte2X, teletransporte2Y;
int portaAberta = 0;

void inicializaMapa() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            mapa[i][j] = ' ';
        }
    }
    for (int i = 0; i < ALTURA; i++) {
        mapa[i][0] = '#';
        mapa[i][LARGURA - 1] = '#';
    }
    for (int j = 0; j < LARGURA; j++) {
        mapa[0][j] = '#';
        mapa[ALTURA - 1][j] = '#';
    }
    
    // Posições iniciais
    jogadorX = 1; jogadorY = 1;
    chaveX = LARGURA - 2; chaveY = ALTURA - 2;
    portaX = LARGURA / 2; portaY = ALTURA / 2;
    monstro1X = 3; monstro1Y = 3;
    monstro2X = 6; monstro2Y = 6;
    teletransporte1X = 10; teletransporte1Y = 10;
    teletransporte2X = 30; teletransporte2Y = 30;
    
    // Posiciona elementos no mapa
    mapa[jogadorY][jogadorX] = '&';
    mapa[chaveY][chaveX] = '@';
    mapa[portaY][portaX] = 'D';
    mapa[monstro1Y][monstro1X] = 'X';
    mapa[monstro2Y][monstro2X] = 'V';
    mapa[teletransporte1Y][teletransporte1X] = '>';
    mapa[teletransporte2Y][teletransporte2X] = '>';
}

void imprimeMapa() {
    system("cls"); // Para Windows, use "clear" para sistemas Unix-like
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
    if (portaAberta) {
        printf("A porta está aberta! Vá até a porta para terminar a fase.\n");
    }
}

void moverJogador(char comando) {
    int novoX = jogadorX, novoY = jogadorY;

    if (comando == 'W') novoY--;
    else if (comando == 'A') novoX--;
    else if (comando == 'S') novoY++;
    else if (comando == 'D') novoX++;
    else if (comando == 'I' && jogadorX == chaveX && jogadorY == chaveY) {
        portaAberta = 1;
        mapa[portaY][portaX] = '=';
    }

    if (mapa[novoY][novoX] == ' ' || mapa[novoY][novoX] == '@' || mapa[novoY][novoX] == '=' || mapa[novoY][novoX] == '>') {
        if (mapa[novoY][novoX] == '>') {
            if (novoX == teletransporte1X && novoY == teletransporte1Y) {
                novoX = teletransporte2X;
                novoY = teletransporte2Y;
            } else {
                novoX = teletransporte1X;
                novoY = teletransporte1Y;
            }
        }
        mapa[jogadorY][jogadorX] = ' ';
        jogadorX = novoX;
        jogadorY = novoY;
        mapa[jogadorY][jogadorX] = '&';
    }
}

void moverMonstro1() {
    int direcao = rand() % 4;
    int novoX = monstro1X, novoY = monstro1Y;
    
    if (direcao == 0) novoY--;
    else if (direcao == 1) novoX--;
    else if (direcao == 2) novoY++;
    else if (direcao == 3) novoX++;

    if (mapa[novoY][novoX] == ' ') {
        mapa[monstro1Y][monstro1X] = ' ';
        monstro1X = novoX;
        monstro1Y = novoY;
        mapa[monstro1Y][monstro1X] = 'X';
    }
}

void moverMonstro2() {
    int dx = jogadorX - monstro2X;
    int dy = jogadorY - monstro2Y;
    int novoX = monstro2X, novoY = monstro2Y;

    if (abs(dx) > abs(dy)) {
        novoX += (dx > 0) ? 1 : -1;
    } else {
        novoY += (dy > 0) ? 1 : -1;
    }

    if (mapa[novoY][novoX] == ' ') {
        mapa[monstro2Y][monstro2X] = ' ';
        monstro2X = novoX;
        monstro2Y = novoY;
        mapa[monstro2Y][monstro2X] = 'V';
    }
}

void verificaColisao() {
    if (jogadorX == monstro1X && jogadorY == monstro1Y) {
        printf("Você foi pego pelo monstro! Reiniciando fase...\n");
        inicializaMapa();
    } else if (jogadorX == monstro2X && jogadorY 

