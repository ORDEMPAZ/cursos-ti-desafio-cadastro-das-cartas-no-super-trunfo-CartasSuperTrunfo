
#include <stdio.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1[3];
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePop1;
    float pibPerCapita1;

    // Declaração das variáveis para a segunda carta
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePop2;
    float pibPerCapita2;

    int escolha1, escolha2;

    // Entrada de dados para a primeira carta
    printf("\n=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: SP, RJ): ");
    scanf("%2s", estado1);
    getchar();
    
    printf("Código da Carta: ");
    scanf("%3s", codigo1);
    getchar();
    
    printf("Nome da Cidade: ");
    fgets(nomeCidade1, 50, stdin);
    if (nomeCidade1[strlen(nomeCidade1) - 1] == '\n')
        nomeCidade1[strlen(nomeCidade1) - 1] = '\0';
    
    printf("População: ");
    scanf("%lu", &populacao1);
    
    printf("Área (em km²): ");
    scanf("%f", &area1);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    getchar();

    densidadePop1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1e9) / populacao1;

    // Entrada de dados para a segunda carta
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: SP, RJ): ");
    scanf("%2s", estado2);
    getchar();
    
    printf("Código da Carta: ");
    scanf("%3s", codigo2);
    getchar();
    
    printf("Nome da Cidade: ");
    fgets(nomeCidade2, 50, stdin);
    if (nomeCidade2[strlen(nomeCidade2) - 1] == '\n')
        nomeCidade2[strlen(nomeCidade2) - 1] = '\0';
    
    printf("População: ");
    scanf("%lu", &populacao2);
    
    printf("Área (em km²): ");
    scanf("%f", &area2);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidadePop2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Menu de seleção de atributos
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n6 - PIB per Capita\n");
    scanf("%d", &escolha1);

    do {
        printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional\n6 - PIB per Capita\n");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1);

    double atributos1[] = {(double)populacao1, area1, pib1, pontosTuristicos1, densidadePop1, pibPerCapita1};
    double atributos2[] = {(double)populacao2, area2, pib2, pontosTuristicos2, densidadePop2, pibPerCapita2};
    
    double valor1_carta1 = atributos1[escolha1 - 1];
    double valor1_carta2 = atributos2[escolha1 - 1];
    double valor2_carta1 = atributos1[escolha2 - 1];
    double valor2_carta2 = atributos2[escolha2 - 1];

    int pontos1 = 0, pontos2 = 0;

    // Lógica de pontuação
    if (escolha1 == 5) { // Densidade populacional (menor é melhor)
        pontos1 += (valor1_carta1 < valor1_carta2) ? 1 : 0;
        pontos2 += (valor1_carta2 < valor1_carta1) ? 1 : 0;
    } else {
        pontos1 += (valor1_carta1 > valor1_carta2) ? 1 : 0;
        pontos2 += (valor1_carta2 > valor1_carta1) ? 1 : 0;
    }

    if (escolha2 == 5) { // Densidade populacional (menor é melhor)
        pontos1 += (valor2_carta1 < valor2_carta2) ? 1 : 0;
        pontos2 += (valor2_carta2 < valor2_carta1) ? 1 : 0;
    } else {
        pontos1 += (valor2_carta1 > valor2_carta2) ? 1 : 0;
        pontos2 += (valor2_carta2 > valor2_carta1) ? 1 : 0;
    }

    // Apresentação dos resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("Carta 1: %s (%s) - Valores: %.2f e %.2f\n", nomeCidade1, estado1, valor1_carta1, valor2_carta1);
    printf("Carta 2: %s (%s) - Valores: %.2f e %.2f\n", nomeCidade2, estado2, valor1_carta2, valor2_carta2);

    if (pontos1 > pontos2) {
        printf("\nCarta 1 venceu!\n");
    } else if (pontos2 > pontos1) {
        printf("\nCarta 2 venceu!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
