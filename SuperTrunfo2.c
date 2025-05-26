#include <stdio.h>

#define NUM_CARTAS 2

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao; // PIB em reais
}

void imprimirCarta(Carta c, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
}

int main() {
    Carta cartas[NUM_CARTAS];

    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);

        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Código da Carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de reais): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        calcularIndicadores(&cartas[i]);
    }

    for (int i = 0; i < NUM_CARTAS; i++) {
        imprimirCarta(cartas[i], i + 1);
    }

    return 0;
}
