#include <stdio.h>
#include <string.h>

#define MAX_ITENS 100
#define TAM_NOME 50
#define TAM_TIPO 30

// Estrutura do item
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

// Função para buscar item por nome
void buscarItemPorNome(Item itens[], int total) {
    char nomeBusca[TAM_NOME];
    int encontrado = 0;

    printf("\n🔎 Digite o nome do item a ser buscado: ");
    scanf(" %[^\n]", nomeBusca);  // Lê linha com espaços

    for (int i = 0; i < total; i++) {
        if (strcmp(itens[i].nome, nomeBusca) == 0) {
            printf("\n✅ Item encontrado:\n");
            printf("📌 Nome: %s\n", itens[i].nome);
            printf("📂 Tipo: %s\n", itens[i].tipo);
            printf("📦 Quantidade: %d\n", itens[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Item '%s' não encontrado.\n", nomeBusca);
    }
}

// Função principal com exemplo de uso
int main() {
    Item inventario[MAX_ITENS] = {
        {"Martelo", "Ferramenta", 5},
        {"Parafuso", "Peça", 100},
        {"Chave de fenda", "Ferramenta", 8}
    };
    int totalItens = 3;

    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                buscarItemPorNome(inventario, totalItens);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

