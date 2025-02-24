#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1[3], codigo1[4], nomeCidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidadePop1 = 0, pibPerCapita1 = 0;
    int pontosTuristicos1;

    // Declaração das variáveis para a segunda carta
    char estado2[3], codigo2[4], nomeCidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidadePop2 = 0, pibPerCapita2 = 0;
    int pontosTuristicos2;

    // Entrada de dados para a primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Estado (sigla ex: SP): ");
    scanf("%2s", estado1);
    printf("Código da Carta: ");
    scanf("%3s", codigo1);
    getchar();
    printf("Nome da Cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0;
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    if (area1 > 0) densidadePop1 = populacao1 / area1;
    if (populacao1 > 0) pibPerCapita1 = (pib1 * 1e9) / populacao1;

    // Entrada de dados para a segunda carta
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (sigla ex: RJ): ");
    scanf("%2s", estado2);
    printf("Código da Carta: ");
    scanf("%3s", codigo2);
    getchar();
    printf("Nome da Cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    if (area2 > 0) densidadePop2 = populacao2 / area2;
    if (populacao2 > 0) pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Escolha do atributo para comparação (População neste caso)
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %lu\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n", nomeCidade2, estado2, populacao2);

    // Determinação da carta vencedora
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
