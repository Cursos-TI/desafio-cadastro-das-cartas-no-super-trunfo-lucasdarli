#include <stdio.h>

#define NUM_CARTAS 2

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
    c->superPoder = (float)c->populacao +
                    c->area +
                    (c->pib * 1000000000) +
                    c->pontosTuristicos +
                    c->pibPerCapita +
                    (1.0f / c->densidadePopulacional);
}

int compararMaior(float a, float b) {
    return a > b ? 1 : 0;
}

int compararMenor(float a, float b) {
    return a < b ? 1 : 0;
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
        scanf("%lu", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de reais): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        calcularIndicadores(&cartas[i]);
    }

    printf("\n--- Comparação de Cartas ---\n");

    printf("População: Carta 1 venceu (%d)\n", compararMaior((float)cartas[0].populacao, (float)cartas[1].populacao));
    printf("Área: Carta 1 venceu (%d)\n", compararMaior(cartas[0].area, cartas[1].area));
    printf("PIB: Carta 1 venceu (%d)\n", compararMaior(cartas[0].pib, cartas[1].pib));
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", compararMaior((float)cartas[0].pontosTuristicos, (float)cartas[1].pontosTuristicos));
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", compararMenor(cartas[0].densidadePopulacional, cartas[1].densidadePopulacional));
    printf("PIB per Capita: Carta 1 venceu (%d)\n", compararMaior(cartas[0].pibPerCapita, cartas[1].pibPerCapita));
    printf("Super Poder: Carta 1 venceu (%d)\n", compararMaior(cartas[0].superPoder, cartas[1].superPoder));

    return 0;
}
