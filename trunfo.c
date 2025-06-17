#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada carta
typedef struct {
    char estado;           // Letra do estado (A-H)
    char codigo[4];        // Código da carta (ex: "A01")
    char nome[50];         // Nome da cidade/país
    int populacao;         // População
    int area;              // Área em km²
    float pib;             // PIB em bilhões
    int pontosturisticos;  // Número de pontos turísticos
} CartaSuperTrunfo;

// Função para obter nome do estado por letra
const char* obterNomeEstado(char letra) {
    switch (letra) {
        case 'A': return "Estado A";
        case 'B': return "Estado B";
        case 'C': return "Estado C";
        case 'D': return "Estado D";
        case 'E': return "Estado E";
        case 'F': return "Estado F";
        case 'G': return "Estado G";
        case 'H': return "Estado H";
        default: return "Estado Desconhecido";
    }
}

// Função para obter nome do atributo por número
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Atributo Desconhecido";
    }
}

// Pega o valor do atributo da carta (float para unificar tipos)
float getValorAtributo(CartaSuperTrunfo carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return (float)carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosturisticos;
        case 5: return (float)carta.populacao / carta.area; // Densidade
        default: return 0.0f;
    }
}

// Compara dois valores de atributo, considerando regra especial da densidade (menor vence)
// Retorna 1 se carta1 vence, 2 se carta2 vence, 0 empate
int compararAtributo(float val1, float val2, int atributo) {
    if (atributo == 5) { // Densidade: menor vence
        if (val1 < val2) return 1;
        else if (val1 > val2) return 2;
        else return 0;
    } else { // Outros: maior vence
        if (val1 > val2) return 1;
        else if (val1 < val2) return 2;
        else return 0;
    }
}

// Função para ler as cartas do usuário (preenchimento manual)
void preencherCarta(CartaSuperTrunfo *carta) {
    printf("Preencha os dados da carta:\n");

    printf("Letra do Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Codigo (3 caracteres): ");
    scanf("%3s", carta->codigo);

    getchar();  // Limpa o '\n' que ficou no buffer do scanf antes do fgets

    printf("Nome da cidade/pais: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0';  // Remove o '\n' final

    printf("Populacao: ");
    scanf("%d", &carta->populacao);

    printf("Area (km2): ");
    scanf("%d", &carta->area);

    printf("PIB (bilhoes): ");
    scanf("%f", &carta->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->pontosturisticos);

    printf("\n");
}


// Escolha do primeiro atributo com validação
int escolherPrimeiroAtributo() {
    int opcao;
    do {
        printf("Escolha o PRIMEIRO atributo para comparar:\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Demografica\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 5)
            printf("Opcao invalida! Tente novamente.\n");
    } while (opcao < 1 || opcao > 5);
    return opcao;
}

// Escolha do segundo atributo excluindo o primeiro escolhido
int escolherSegundoAtributo(int primeiro) {
    int opcao;
    do {
        printf("Escolha o SEGUNDO atributo para comparar (diferente do %d):\n", primeiro);
        if (primeiro != 1) printf("1 - Populacao\n");
        if (primeiro != 2) printf("2 - Area\n");
        if (primeiro != 3) printf("3 - PIB\n");
        if (primeiro != 4) printf("4 - Pontos Turisticos\n");
        if (primeiro != 5) printf("5 - Densidade Demografica\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 5 || opcao == primeiro)
            printf("Opcao invalida! Tente novamente.\n");
    } while (opcao < 1 || opcao > 5 || opcao == primeiro);
    return opcao;
}

int main() {
    CartaSuperTrunfo carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    preencherCarta(&carta1);

    printf("Cadastro da Carta 2:\n");
    preencherCarta(&carta2);

    // Escolha dos atributos
    int atributo1 = escolherPrimeiroAtributo();
    int atributo2 = escolherSegundoAtributo(atributo1);

    // Obter os valores dos atributos para as duas cartas
    float val1_carta1 = getValorAtributo(carta1, atributo1);
    float val1_carta2 = getValorAtributo(carta2, atributo1);
    float val2_carta1 = getValorAtributo(carta1, atributo2);
    float val2_carta2 = getValorAtributo(carta2, atributo2);

    // Comparar cada atributo
    int vencedor_atributo1 = compararAtributo(val1_carta1, val1_carta2, atributo1);
    int vencedor_atributo2 = compararAtributo(val2_carta1, val2_carta2, atributo2);

    // Somar os valores para cada carta
    float soma_carta1 = val1_carta1 + val2_carta1;
    float soma_carta2 = val1_carta2 + val2_carta2;

    // Definir vencedor final baseado na soma
    int vencedor_final;
    if (soma_carta1 > soma_carta2)
        vencedor_final = 1;
    else if (soma_carta2 > soma_carta1)
        vencedor_final = 2;
    else
        vencedor_final = 0; // empate

    // Exibir resultado
    printf("\n========== RESULTADO DA COMPARACAO ==========\n\n");
    printf("Cartas comparadas:\n");
    printf("Carta 1: %s (%s)\n", carta1.nome, obterNomeEstado(carta1.estado));
    printf("Carta 2: %s (%s)\n\n", carta2.nome, obterNomeEstado(carta2.estado));

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("  Carta 1: %.2f\n", val1_carta1);
    printf("  Carta 2: %.2f\n", val1_carta2);
    printf("  Vencedor: %s\n\n",
           vencedor_atributo1 == 0 ? "Empate" : (vencedor_atributo1 == 1 ? "Carta 1" : "Carta 2"));

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("  Carta 1: %.2f\n", val2_carta1);
    printf("  Carta 2: %.2f\n", val2_carta2);
    printf("  Vencedor: %s\n\n",
           vencedor_atributo2 == 0 ? "Empate" : (vencedor_atributo2 == 1 ? "Carta 1" : "Carta 2"));

    printf("Soma dos atributos:\n");
    printf("  Carta 1: %.2f\n", soma_carta1);
    printf("  Carta 2: %.2f\n", soma_carta2);

    if (vencedor_final == 0)
        printf("\nResultado final: EMPATE!\n");
    else
        printf("\nResultado final: %s vence a rodada!\n", vencedor_final == 1 ? "Carta 1" : "Carta 2");

    printf("============================================\n");

    return 0;
} 
// Compilação: gcc trunfo.c -o trunfo -std=c17
// Execução: ./trunfo