#include <stdio.h>

#define NUM_CARTAS 2

typedef struct {
    char estado;               // Letra de 'A' a 'H'
    char codigo[4];            // Ex: A01, B03
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // Número de habitantes
    float area;               // Área em km²
    float pib;                // PIB da cidade
    int pontosTuristicos;     // Número de pontos turísticos
} Carta;

void imprimirCarta(Carta c) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %c\n", c.estado);
    printf("Código da Carta: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

int main() {
    Carta cartas[NUM_CARTAS];

    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);

        printf("Informe o estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Informe o código da carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Informe o nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade); // Lê string com espaços

        printf("Informe a população: ");
        scanf("%d", &cartas[i].populacao);

        printf("Informe a área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("Informe o PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Informe o número de pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    for (int i = 0; i < NUM_CARTAS; i++) {
        imprimirCarta(cartas[i]);
    }

    return 0;
}
