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

    // Entrada de dados para a primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Estado (sigla de 2 letras): ");
    scanf("%2s", estado1);
    printf("Código da Carta: ");
    scanf("%3s", codigo1);
    getchar(); // Limpa buffer do teclado
    printf("Nome da Cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo da densidade populacional e PIB per capita
    densidadePop1 = (area1 > 0) ? populacao1 / area1 : 0;
    pibPerCapita1 = (populacao1 > 0) ? (pib1 * 1000000000) / populacao1 : 0;

    // Entrada de dados para a segunda carta
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (sigla de 2 letras): ");
    scanf("%2s", estado2);
    printf("Código da Carta: ");
    scanf("%3s", codigo2);
    getchar();
    printf("Nome da Cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional e PIB per capita
    densidadePop2 = (area2 > 0) ? populacao2 / area2 : 0;
    pibPerCapita2 = (populacao2 > 0) ? (pib2 * 1000000000) / populacao2 : 0;

    // Menu interativo para escolha do atributo
    int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparação de Cartas:\n");
    switch(opcao) {
        case 1:
            printf("População: %s (%lu) vs %s (%lu)\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
            printf("Vencedor: %s\n", (populacao1 > populacao2) ? nomeCidade1 : (populacao1 < populacao2) ? nomeCidade2 : "Empate!");
            break;
        case 2:
            printf("Área: %s (%.2f km²) vs %s (%.2f km²)\n", nomeCidade1, area1, nomeCidade2, area2);
            printf("Vencedor: %s\n", (area1 > area2) ? nomeCidade1 : (area1 < area2) ? nomeCidade2 : "Empate!");
            break;
        case 3:
            printf("PIB: %s (%.2f bilhões) vs %s (%.2f bilhões)\n", nomeCidade1, pib1, nomeCidade2, pib2);
            printf("Vencedor: %s\n", (pib1 > pib2) ? nomeCidade1 : (pib1 < pib2) ? nomeCidade2 : "Empate!");
            break;
        case 4:
            printf("Pontos Turísticos: %s (%d) vs %s (%d)\n", nomeCidade1, pontosTuristicos1, nomeCidade2, pontosTuristicos2);
            printf("Vencedor: %s\n", (pontosTuristicos1 > pontosTuristicos2) ? nomeCidade1 : (pontosTuristicos1 < pontosTuristicos2) ? nomeCidade2 : "Empate!");
            break;
        case 5:
            printf("Densidade Populacional: %s (%.2f hab/km²) vs %s (%.2f hab/km²)\n", nomeCidade1, densidadePop1, nomeCidade2, densidadePop2);
            printf("Vencedor: %s\n", (densidadePop1 < densidadePop2) ? nomeCidade1 : (densidadePop1 > densidadePop2) ? nomeCidade2 : "Empate!");
            break;
        case 6:
            printf("PIB per Capita: %s (%.2f) vs %s (%.2f)\n", nomeCidade1, pibPerCapita1, nomeCidade2, pibPerCapita2);
            printf("Vencedor: %s\n", (pibPerCapita1 > pibPerCapita2) ? nomeCidade1 : (pibPerCapita1 < pibPerCapita2) ? nomeCidade2 : "Empate!");
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
