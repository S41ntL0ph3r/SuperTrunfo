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

// Auxiliar para obter o nome do estado automaticamente a partir da letra
const char* obterNomeEstado(char letra) {
    switch (letra) {
        case 'A': return "SP";
        case 'B': return "RJ";
        case 'C': return "AM";
        case 'D': return "BA";
        case 'E': return "CE";
        case 'F': return "DF";
        case 'G': return "ES";
        case 'H': return "GO";
        default: return "Estado Invalido";
    }
}


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

    // ===== Cálculo dos Indicadores ====
    float densidade1 = (float)carta1.populacao / carta1.area;
    float densidade2 = (float)carta2.populacao / carta2.area;

    float pibPerCapita1 = carta1.pib * 1e9 / carta1.populacao; // PIB em reais
    float pibPerCapita2 = carta2.pib * 1e9 / carta2.populacao; // PIB em reais

     // ===== Exibição dos dados com indicadores calculados =====
    printf("\n=====================\n");
    printf("Dados da Carta 1:\n");
    printf("Estado: %s\n", obterNomeEstado(carta1.estado));
    printf("Codigo: %s\n", carta1.codigo);
    printf("Cidade: %s", carta1.nome);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %d km2\n", carta1.area);
    printf("PIB: %.2f bilhoes\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosturisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per capita: %.2f R$\n", pibPerCapita1);

    printf("\nDados da Carta 2:\n");
    printf("Estado: %s\n", obterNomeEstado(carta2.estado));
    printf("Codigo: %s\n", carta2.codigo);
    printf("Cidade: %s", carta2.nome);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %d km2\n", carta2.area);
    printf("PIB: %.2f bilhoes\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosturisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per capita: %.2f R$\n", pibPerCapita2);
    printf("=====================\n");

    // ===== Comparação - Atributo: Densidade Populacional (O menor vence) =====
    printf("\nComparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n");
    printf("Carta 1 - %sDensidade: %.2f hab/km2\n", carta1.nome, densidade1);
    printf("Carta 2 - %sDensidade: %.2f hab/km2\n", carta2.nome, densidade2);


    if (densidade1 < densidade2) {
        printf("Resultado: Carta 1 (%s) vence!\n", carta1.nome);
    } else if (densidade1 > densidade2) {
        printf("Resultado: Carta 2 (%s) vence!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
    return 0;
}