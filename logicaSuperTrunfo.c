#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

float calcula_densidade_populacional(float populacao, float area){
    float densidade = 0;
    densidade = populacao / area;
    return densidade;
};

double calcula_pib_percapita(float pib, int populacao){
    double pib_percapita = 0;
    pib_percapita = (double) (pib / populacao) * 1000000000;
    return pib_percapita;
};

double calcular_super_poder(unsigned long int populacao, float area, float pib, int pontos_turisticos, double pib_percapita){
    double super_poder = 0;
    super_poder = populacao + area + pib + pontos_turisticos + pib_percapita;
    return super_poder;
}

int compara_cartas(char NomeCidade1[51], char CodigoCarta1[3], 
                   char NomeCidade2[51], char CodigoCarta2[3], 
                   char NomeAtributo[51], 
                   float ValorAtributo1, float ValorAtributo2) {
                    
    printf("\n*** [ %s ] ***\n", NomeAtributo);

    printf("Carta 1 - %s (%s): ", NomeCidade1, CodigoCarta1);

    if (NomeAtributo == "População" || NomeAtributo == "Pontos Turísticos") {
        printf("%lu\n", (unsigned long int) ValorAtributo1);
    } else {
        printf("%.2f\n", ValorAtributo1);
    }

    printf("Carta 2 - %s (%s): ", NomeCidade2, CodigoCarta2);

    if (NomeAtributo == "População" || NomeAtributo == "Pontos Turísticos") {
        printf("%lu\n", (unsigned long int) ValorAtributo2);
    } else {
        printf("%.2f\n", ValorAtributo2);
    }

    /*
    * se o atributo for Densidade Populacional - vence a carta que tem o valor menor
    */
    if (NomeAtributo == "Densidade Populacional") {
        if (ValorAtributo1 < ValorAtributo2) {
           printf("Resultado: Carta 1 (%s) venceu!\n", NomeCidade1);
        } else if (ValorAtributo1 > ValorAtributo2) {
           printf("Resultado: Carta 2 (%s) venceu!\n", NomeCidade2);
        } else {
           printf(" Empate entre as cartas\n");
        }
    /**
     * se o atributo não for "Densidade Populacional" vence o maior valor
     */
    } else {
        if (ValorAtributo1 > ValorAtributo2) {
           printf("Resultado: Carta 1 (%s) venceu!\n", NomeCidade1);
        } else if (ValorAtributo1 < ValorAtributo2) {
           printf("Resultado: Carta 2 (%s) venceu!\n", NomeCidade2);
        } else {
           printf(" Empate entre as cartas\n");
        }
    }

    return 0;
}

int main() {
    // Declaração das variáveis para a carta 1
    char Carta1_Estado = "A";
    char Carta1_Codigo_da_carta[4];
    char Carta1_Nome_da_cidade[51];
    unsigned long int Carta1_Populacao;
    float Carta1_Area;
    float Carta1_PIB;
    int Carta1_Numero_de_pontos_turisticos;
    float Carta1_densidade_populacional = 0;
    double Carta1_pib_percapita = 0;
    double Carta1_super_poder = 0;

    // Declaração das variáveis para a carta 2
    char Carta2_Estado;
    char Carta2_Codigo_da_carta[4];
    char Carta2_Nome_da_cidade[51];
    unsigned long int Carta2_Populacao;
    float Carta2_Area;
    float Carta2_PIB;
    int Carta2_Numero_de_pontos_turisticos;
    float Carta2_densidade_populacional = 0;
    double Carta2_pib_percapita = 0;
    double Carta2_super_poder = 0;

    // Entrada de dados da carta 1
    printf("Digite os dados da carta1\n");
    printf("Estado - Uma letra de 'A' a 'H' : ");
    scanf(" %c", &Carta1_Estado);
    printf("Código - A letra do estado seguida de um número de 01 a 04 (ex: A01, B03) : ");
    scanf(" %3s", &Carta1_Codigo_da_carta);
    printf("Nome da cidade - Até 50 letras : ");
    scanf(" %50s", &Carta1_Nome_da_cidade);
    printf("População - O número de habitantes da cidade : ");
    scanf(" %d", &Carta1_Populacao);
    printf("Área da cidade (em km²) : ");
    scanf(" %f", &Carta1_Area);
    printf("PIB em bilhões de reais - O Produto Interno Bruto da cidade : ");
    scanf(" %f", &Carta1_PIB);
    printf("Número de Pontos Turísticos da cidade : ");
    scanf(" %d", &Carta1_Numero_de_pontos_turisticos);

    // Entrada de dados da carta 2
    printf("\n\nDigite os dados da carta2\n");
    printf("Estado - Uma letra de 'A' a 'H' : ");
    scanf(" %c", &Carta2_Estado);
    printf("Código - A letra do estado seguida de um número de 01 a 04 (ex: A01, B03) : ");
    scanf(" %3s", &Carta2_Codigo_da_carta);
    printf("Nome da cidade - Até 50 letras : ");
    scanf(" %50s", &Carta2_Nome_da_cidade);
    printf("População - O número de habitantes da cidade : ");
    scanf(" %d", &Carta2_Populacao);
    printf("Área da cidade (em km²) : ");
    scanf(" %f", &Carta2_Area);
    printf("PIB em bilhões de reais - O Produto Interno Bruto da cidade : ");
    scanf(" %f", &Carta2_PIB);
    printf("Número de Pontos Turísticos da cidade : ");
    scanf(" %d", &Carta2_Numero_de_pontos_turisticos);

    // Saída de dados da carta 1
    printf("\n\nCarta 1:\n");
    printf("Estado: %c\n", Carta1_Estado);
    printf("Código: %s\n", Carta1_Codigo_da_carta);
    printf("Nome da Cidade: %s\n", Carta1_Nome_da_cidade);
    printf("População: %d\n", Carta1_Populacao);
    printf("Área: %.2f km²\n", Carta1_Area);
    printf("PIB: %.2f bilhões de reais\n", Carta1_PIB);
    printf("Número de Pontos Turísticos: %d\n", Carta1_Numero_de_pontos_turisticos);
    Carta1_densidade_populacional = calcula_densidade_populacional(Carta1_Populacao, Carta1_Area);
    printf("Densidade Populacional: %.2f hab/km²\n", Carta1_densidade_populacional);
    Carta1_pib_percapita = calcula_pib_percapita(Carta1_PIB, Carta1_Populacao);
    printf("PIB per capita: %.2f reais\n", Carta1_pib_percapita);
    Carta1_super_poder = calcular_super_poder(Carta1_Populacao, Carta1_Area, Carta1_PIB, Carta1_Numero_de_pontos_turisticos, Carta1_pib_percapita);

    // Saída de dados da carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", Carta2_Estado);
    printf("Código: %s\n", Carta2_Codigo_da_carta);
    printf("Nome da Cidade: %s\n", Carta2_Nome_da_cidade);
    printf("População: %d\n", Carta2_Populacao);
    printf("Área: %.2f km²\n", Carta2_Area);
    printf("PIB: %.2f bilhões de reais\n", Carta2_PIB);
    printf("Número de Pontos Turísticos: %d\n", Carta2_Numero_de_pontos_turisticos);
    Carta2_densidade_populacional = calcula_densidade_populacional(Carta2_Populacao, Carta2_Area);
    printf("Densidade Populacional: %.2f hab/km²\n", Carta2_densidade_populacional);
    Carta2_pib_percapita = calcula_pib_percapita(Carta2_PIB, Carta2_Populacao);
    printf("PIB per capita: %.2f reais\n", Carta2_pib_percapita);
    Carta2_super_poder = calcular_super_poder(Carta2_Populacao, Carta2_Area, Carta2_PIB, Carta2_Numero_de_pontos_turisticos, Carta2_pib_percapita);
    
    // Mostrar resultado da comparação
    printf("\n*** Comparação de Cartas ***\n");
    
    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "População",
                   (float) Carta1_Populacao, (float) Carta2_Populacao);

    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "Área",
                   Carta1_Area, Carta2_Area);

    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "PIB",
                   Carta1_PIB, Carta2_PIB);

    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "Pontos Turísticos",
                   (float) Carta1_Numero_de_pontos_turisticos, (float) Carta2_Numero_de_pontos_turisticos);

    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "Densidade Populacional",
                   Carta1_densidade_populacional, Carta2_densidade_populacional);

    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "PIB per Capita",
                   Carta1_pib_percapita, Carta2_pib_percapita);

    compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                   Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                   "Super Poder",
                   Carta1_super_poder, Carta2_super_poder);

    return 0;
}
