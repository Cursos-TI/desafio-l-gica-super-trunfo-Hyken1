#include <stdio.h> 


// Definição da estrutura para armazenar os dados de uma carta (cidade)
typedef struct {
    char estado[3];                 // Sigla do estado (ex: "SP") - 2 caracteres + '\0'
    char codigo[5];                 // Código da cidade (ex: "001A") - 4 caracteres + '\0'
    char nome[50];                  // Nome da cidade
    unsigned long int populacao;    // População da cidade
    float area;                     // Área em km²
    float PIB;                      // Produto Interno Bruto em milhões de reais
    int pontosTuristicos;           // Número de pontos turísticos
    float densidadePopulacional;    // Calculado: habitantes por km²
    float PIBperCapita;             // Calculado: PIB em reais por habitante
} Carta;

int main() {
    // Inicialização da primeira carta com dados fixos 
    Carta carta1 = {"SC", "001A", "Florianópolis", 12396372, 1521.11, 710500.50, 165, 0.0, 0.0};
    // Inicialização da segunda carta com dados fixos 
    Carta carta2 = {"RS", "002B", "Rio Grande do Sul", 6747815, 1200.26, 485200.75, 110, 0.0, 0.0};

    // --- CÁLCULOS PARA A CARTA 1 ---
    // Calcula a densidade populacional da carta 1
    if (carta1.area > 0) { 
        carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidadePopulacional = 0;
    }
    // Calcula o PIB per capita da carta 1
    if (carta1.populacao > 0) { 
        // Converte PIB de milhões para unidades antes de dividir
        carta1.PIBperCapita = (carta1.PIB * 1000000) / carta1.populacao;
    } else {
        carta1.PIBperCapita = 0; 
    }

    // --- CÁLCULOS PARA A CARTA 2 ---
    // Calcula a densidade populacional da carta 2
    if (carta2.area > 0) {
        carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidadePopulacional = 0;
    }
    // Calcula o PIB per capita da carta 2
    if (carta2.populacao > 0) {
        carta2.PIBperCapita = (carta2.PIB * 1000000) / carta2.populacao;
    } else {
        carta2.PIBperCapita = 0;
    }

    // --- EXIBIÇÃO DOS DADOS DAS CARTAS ---
    printf("--- CARTA 1 --- \n");
    printf("Cidade: %s-%s (%s)\n", carta1.nome, carta1.estado, carta1.codigo);
    printf("População: %lu\n", carta1.populacao);
    printf("Área da cidade: %.2f km²\n", carta1.area);
    printf("PIB: %.2f milhões de reais\n", carta1.PIB);
    printf("Pontos turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per capita: %.2f reais\n", carta1.PIBperCapita);

    printf("\n--- CARTA 2 --- \n");
    printf("Cidade: %s-%s (%s)\n", carta2.nome, carta2.estado, carta2.codigo);
    printf("População: %lu\n", carta2.populacao);
    printf("Área da cidade: %.2f km²\n", carta2.area);
    printf("PIB: %.2f milhões de reais\n", carta2.PIB);
    printf("Pontos turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per capita: %.2f reais\n", carta2.PIBperCapita);

    // --- MENU DE ESCOLHA E COMPARAÇÃO ---
    int escolha; // Variável para armazenar a escolha do usuário no menu
    printf("\n\n* Escolha o atributo para comparar as cidades: *\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha); // Lê a opção do usuário
    while (getchar() != '\n'); // Limpa o buffer de entrada para evitar problemas com leituras futuras

    printf("\n--- Resultado da Comparação ---\n");
    // Informa quais cidades estão sendo comparadas
    printf("Comparando %s vs %s\n", carta1.nome, carta2.nome);

    // Estrutura switch para tratar a escolha do usuário
    switch (escolha) {
        case 1: // Comparação por População
            printf("Atributo selecionado: População\n");
            printf("%s: %lu habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %lu habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("\n%s vence com maior população!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("\n%s vence com maior população!\n", carta2.nome);
            } else {
                printf("\nEmpate na população!\n");
            }
            break;

        case 2: // Comparação por Área
            printf("Atributo selecionado: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("\n%s vence com maior área!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("\n%s vence com maior área!\n", carta2.nome);
            } else {
                printf("\nEmpate na área!\n");
            }
            break;

        case 3: // Comparação por PIB
            printf("Atributo selecionado: PIB\n");
            printf("%s: %.2f milhões de reais\n", carta1.nome, carta1.PIB);
            printf("%s: %.2f milhões de reais\n", carta2.nome, carta2.PIB);
            if (carta1.PIB > carta2.PIB) {
                printf("\n%s vence com maior PIB!\n", carta1.nome);
            } else if (carta2.PIB > carta1.PIB) {
                printf("\n%s vence com maior PIB!\n", carta2.nome);
            } else {
                printf("\nEmpate no PIB!\n");
            }
            break;

        case 4: // Comparação por Pontos Turísticos
            printf("Atributo selecionado: Pontos Turísticos\n");
            printf("%s: %d pontos turísticos\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d pontos turísticos\n", carta2.nome, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("\n%s vence com mais pontos turísticos!\n", carta1.nome);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("\n%s vence com mais pontos turísticos!\n", carta2.nome);
            } else {
                printf("\nEmpate no número de pontos turísticos!\n");
            }
            break;

        case 5: // Comparação por Densidade Demográfica (menor vence)
            printf("Atributo selecionado: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidadePopulacional);
            // Regra especial: menor densidade vence
            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("\n%s vence com menor densidade demográfica!\n", carta1.nome);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("\n%s vence com menor densidade demográfica!\n", carta2.nome);
            } else {
                printf("\nEmpate na densidade demográfica!\n");
            }
            break;

        default: // Caso o usuário digite uma opção inválida
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    printf("\n--- Fim da Comparação ---\n");

    return 0; 
}