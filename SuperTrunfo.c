#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 4
#define NUM_ATRIBUTOS 3

typedef struct {
    char nome[20];
    int atributos[NUM_ATRIBUTOS]; // Ex: Força, Velocidade, Inteligência
} Carta;

void mostrarCarta(Carta c) {
    printf("Carta: %s\n", c.nome);
    printf("1. Força: %d\n", c.atributos[0]);
    printf("2. Velocidade: %d\n", c.atributos[1]);
    printf("3. Inteligência: %d\n", c.atributos[2]);
}

int main() {
    srand(time(NULL));

    Carta baralho[NUM_CARTAS] = {
        {"Dragão", {90, 60, 70}},
        {"Fênix", {70, 80, 90}},
        {"Grifo", {85, 75, 65}},
        {"Unicórnio", {60, 70, 95}}
    };

    int cartaJogador = rand() % NUM_CARTAS;
    int cartaComputador;
    do {
        cartaComputador = rand() % NUM_CARTAS;
    } while (cartaComputador == cartaJogador);

    printf("Sua carta:\n");
    mostrarCarta(baralho[cartaJogador]);

    int escolha;
    printf("Escolha um atributo (1-Força, 2-Velocidade, 3-Inteligência): ");
    scanf("%d", &escolha);
    escolha--; // Ajustar para índice do array

    printf("\nCarta do computador:\n");
    mostrarCarta(baralho[cartaComputador]);

    int valorJogador = baralho[cartaJogador].atributos[escolha];
    int valorComputador = baralho[cartaComputador].atributos[escolha];

    if (valorJogador > valorComputador) {
        printf("\nVocê venceu!\n");
    } else if (valorJogador < valorComputador) {
        printf("\nVocê perdeu!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
