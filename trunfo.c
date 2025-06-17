#include <stdio.h>

// Estrutura para armazenar os dados de cada carta
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    int area;
    float pib;
    int pontosturisticos;
} CartaSuperTrunfo;

int main() {
    CartaSuperTrunfo carta1;
    CartaSuperTrunfo carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta1:\n");

    printf("Informe a letra do estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Informe o codigo da carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    getchar(); // consome quebra de linha anterior
    printf("Informe o nome da cidade: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);

    printf("Informe a populacao da cidade: ");
    scanf("%d", &carta1.populacao);

    printf("Informe a area da cidade (em km2): ");
    scanf("%d", &carta1.area);

    printf("Informe o PIB da cidade (em bilhoes): ");
    scanf("%f", &carta1.pib);

    printf("Informe o numero de pontos turisticos da cidade: ");
    scanf("%d", &carta1.pontosturisticos);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta2:\n");

    printf("Informe a letra do estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Informe o codigo da carta (ex: A01): ");
    scanf("%s", carta2.codigo);

    getchar(); // consome quebra de linha anterior
    printf("Informe o nome da cidade: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);

    printf("Informe a populacao da cidade: ");
    scanf("%d", &carta2.populacao);

    printf("Informe a area da cidade (em km2): ");
    scanf("%d", &carta2.area);

    printf("Informe o PIB da cidade (em bilhoes): ");
    scanf("%f", &carta2.pib);

    printf("Informe o numero de pontos turisticos da cidade: ");
    scanf("%d", &carta2.pontosturisticos);

    // Exibicao dos dados
    printf("\n=====================\n");
    printf("Dados da Carta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Cidade: %s", carta1.nome);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %d km2\n", carta1.area);
    printf("PIB: %.2f bilhoes\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosturisticos);

    printf("\nDados da Carta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Cidade: %s", carta2.nome);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %d km2\n", carta2.area);
    printf("PIB: %.2f bilhoes\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosturisticos);
    printf("=====================\n");

    return 0;
}