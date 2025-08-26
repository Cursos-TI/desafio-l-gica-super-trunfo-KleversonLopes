#include <stdio.h>
#include <stdlib.h>

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

    if (ValorAtributo1 == ValorAtributo2) {
        printf(" Empate entre as cartas\n");
        return;
    }

    char* resultado = "";
    
    if (NomeAtributo == "Densidade Populacional") {
        /*
        * se o atributo for Densidade Populacional - vence a carta que tem o menor valor
        */
        resultado = (ValorAtributo1 < ValorAtributo2) ? 
            printf("Resultado: Carta 1 (%s) venceu!\n", NomeCidade1) : 
            printf("Resultado: Carta 2 (%s) venceu!\n", NomeCidade2);
    } else {
        /**
         * se o atributo não for "Densidade Populacional" vence o maior valor
         */
        resultado = (ValorAtributo1 > ValorAtributo2) ? 
            printf("Resultado: Carta 1 (%s) venceu!\n", NomeCidade1) : 
            printf("Resultado: Carta 2 (%s) venceu!\n", NomeCidade2);
    }

    return 0;
}

void LimpaTela() {
    // Limpar a tela
    #ifdef __linux__ // se o SO for linux
        system("clear");
    #elif _WIN32 // se o SO for Windows
        system("cls");
    #endif
}

void Espera() {
    printf("\n*** Pressione ENTER para continuar...");
    int c;
    // Limpa qualquer entrada residual
    while ((c = getchar()) != '\n' && c != EOF);
    // Espera o ENTER
    getchar();
}

/**
 * processo da partida
 */
int SuperTrunfo(){
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

    /* Limpar a tela */
    LimpaTela();

    printf("\n*** NOVA PARTIDA ***\n");

    // Entrada de dados da carta 1
    printf("\n*** Digite os dados da carta1 ***\n\n");
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
    printf("\n\n*** Digite os dados da carta2 ***\n\n");
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

    Espera();

    short Atributo1, Atributo2 = 0;
    
    do {
        LimpaTela();

        // Mostrar resultado da comparação
        printf("\n*** Comparação de Cartas ***\n");

        printf("1. Nome da Cidade\n");
        printf("2. População\n");
        printf("3. Área\n");
        printf("4. PIB\n");
        printf("5. Número de pontos turísticos\n");
        printf("6. Densidade demográfica\n");
        printf("7. Reiniciar Atributos\n");
        printf("0. Sair\n\n");
    
        printf("Selecione o PRIMEIRO atributo a ser comparado: ");
        scanf(" %d", &Atributo1);

        /**
         * inicia variáveis de soma
         */
        double SomaAtributosCidade1, SomaAtributosCidade2 = 0;

        /**
         * compara primeiro atributo
         */
        switch (Atributo1)
        {
            case 0:
                printf("\nSaindo da partida...\n");
                continue;
                break;
            case 1:
                printf("\n*** [ Nome das Cidades ] ***\n");
                printf("Carta 1 - %s (%s)\n", Carta1_Nome_da_cidade, Carta1_Codigo_da_carta);
                printf("Carta 2 - %s (%s)\n", Carta2_Nome_da_cidade, Carta2_Codigo_da_carta);
                break;
            case 2:
                // População
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "População",
                            (float) Carta1_Populacao, (float) Carta2_Populacao);

                SomaAtributosCidade1 += (float) Carta1_Populacao;
                SomaAtributosCidade2 += (float) Carta2_Populacao;
                break;
            case 3:
                // Área
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "Área",
                            Carta1_Area, Carta2_Area);

                SomaAtributosCidade1 += Carta1_Area;
                SomaAtributosCidade2 += Carta2_Area;
                break;
            case 4:
                // PIB
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "PIB",
                            Carta1_PIB, Carta2_PIB);
                            
                SomaAtributosCidade1 += Carta1_PIB;
                SomaAtributosCidade2 += Carta2_PIB;
                break;
            case 5:
                // Número de Pontos Turísticos
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "Número de Pontos Turísticos",
                            (float) Carta1_Numero_de_pontos_turisticos, (float) Carta2_Numero_de_pontos_turisticos);

                SomaAtributosCidade1 += (float) Carta1_Numero_de_pontos_turisticos;
                SomaAtributosCidade2 += (float) Carta2_Numero_de_pontos_turisticos;
                break;
            case 6:
                // Densidade Populacional
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "Densidade Populacional",
                            Carta1_densidade_populacional, Carta2_densidade_populacional);

                SomaAtributosCidade1 += Carta1_densidade_populacional;
                SomaAtributosCidade2 += Carta2_densidade_populacional;
                break;
            case 7:
                continue;
                break;
            default:
                printf("\n*** Atributo inválido! ***\n");
                Espera();
                continue; // Volta ao início do loop
                break;
        }

        printf("\n\n");
        if (Atributo1 != 1) { printf("1. Nome da Cidade\n"); }
        if (Atributo1 != 2) { printf("2. População\n"); }
        if (Atributo1 != 3) { printf("3. Área\n"); }
        if (Atributo1 != 4) { printf("4. PIB\n"); }
        if (Atributo1 != 5) { printf("5. Número de pontos turísticos\n"); }
        if (Atributo1 != 6) { printf("6. Densidade demográfica\n"); }
        if (Atributo1 != 7) { printf("7. Reiniciar Atributos\n");}
        printf("0. Sair\n\n");

        printf("Selecione o SEGUNDO atributo a ser comparado: ");
        scanf(" %d", &Atributo2);
    
        if (Atributo2 == Atributo1) {
            printf("\n*** Atributo inválido! ***\n");
            Espera();
            continue; // Volta ao início do loop
        }
        /**
         * compara segundo atributo
         */
        switch (Atributo2)
        {
            case 0:
                printf("\nSaindo da partida...\n");
                continue;
                break;
            case 1:
                printf("\n*** [ Nome das Cidades ] ***\n");
                printf("Carta 1 - %s (%s)\n", Carta1_Nome_da_cidade, Carta1_Codigo_da_carta);
                printf("Carta 2 - %s (%s)\n", Carta2_Nome_da_cidade, Carta2_Codigo_da_carta);
                break;
            case 2:
                // População
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "População",
                            (float) Carta1_Populacao, (float) Carta2_Populacao);

                SomaAtributosCidade1 += (float) Carta1_Populacao;
                SomaAtributosCidade2 += (float) Carta2_Populacao;
                break;
            case 3:
                // Área
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "Área",
                            Carta1_Area, Carta2_Area);

                SomaAtributosCidade1 += Carta1_Area;
                SomaAtributosCidade2 += Carta2_Area;
                break;
            case 4:
                // PIB
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "PIB",
                            Carta1_PIB, Carta2_PIB);
                            
                SomaAtributosCidade1 += Carta1_PIB;
                SomaAtributosCidade2 += Carta2_PIB;
                break;
            case 5:
                // Número de Pontos Turísticos
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "Número de Pontos Turísticos",
                            (float) Carta1_Numero_de_pontos_turisticos, (float) Carta2_Numero_de_pontos_turisticos);

                SomaAtributosCidade1 += (float) Carta1_Numero_de_pontos_turisticos;
                SomaAtributosCidade2 += (float) Carta2_Numero_de_pontos_turisticos;
                break;
            case 6:
                // Densidade Populacional
                compara_cartas(Carta1_Nome_da_cidade, Carta1_Codigo_da_carta,
                            Carta2_Nome_da_cidade, Carta2_Codigo_da_carta,
                            "Densidade Populacional",
                            Carta1_densidade_populacional, Carta2_densidade_populacional);

                SomaAtributosCidade1 += Carta1_densidade_populacional;
                SomaAtributosCidade2 += Carta2_densidade_populacional;
                break;
            case 7:
                continue;
                break;
            default:
                printf("\n*** Atributo inválido! ***\n");
                Espera();
                continue; // Volta ao início do loop
                break;
        }

        /**
         * mostra soma dos atributos
         */
        printf("\n\n*** Soma dos atributos ***\n");
        printf("Cidade 1 (%s): %.2f\n", Carta1_Nome_da_cidade, SomaAtributosCidade1);
        printf("Cidade 2 (%s): %.2f\n", Carta2_Nome_da_cidade, SomaAtributosCidade2);
        if (SomaAtributosCidade1 == SomaAtributosCidade2) {
            printf("\n*** Empate na soma dos atributos! ***\n");
        } else {
            char* vencedor = (SomaAtributosCidade1 > SomaAtributosCidade2) ? Carta1_Nome_da_cidade : Carta2_Nome_da_cidade;
            printf("\n*** A cidade vencedora na soma dos atributos é: %s ***\n", vencedor);
        }

       Espera();

    } while (Atributo1 != 0);
    
    return 0;
};


/**
 * rotina principal da aplicação
 */
void main() {
    /**
     *  Lógica do processo principal
     */
    short Opcao;

    do {
        LimpaTela();

        printf("\n\n### JOGO SUPER TRUNFO ###\n\n");
        printf("(1) - Iniciar Nova Partida\n");
        printf("(0) - Sair do Jogo\n\n");
        printf("Escolha uma opção: ");
        scanf(" %d", &Opcao);

        switch (Opcao)
        {
            case 1:
                SuperTrunfo();
                break;

            case 0:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                Espera();
                break;
        }
    } while (Opcao != 0);
}
