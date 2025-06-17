#include <stdio.h>

// A Estrutura abaixo será utilizada para armazenar os dados de cada carta
typedef struct {
    char estado;      // Letras do estado ( de A até H )
    char codigo[4];   // Código da carta ( por exemplo: "A01" )
    char nome[50];    // Nome da cidade
    int populacao;    // População da cidade
    int area;         // Área da cidade em km²
    float pib;       // O Produto Interno Bruto da cidade em bilhões
    int pontosturisticos; // Pontos turísticos da cidade
} CartaSuperTrunfo;

int main() {}