#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// =====================================
//Estrutura que representa um item na mochila
//======================================

typedef struct {
    char nome[30];         // Nome do item
    char tipo[20];     //Tipo do item ex
    int quantidade;    // Quantidade de itens
    int prioridade;

} Item;

// Funções do sistema
void inserirItem(Item mochila[], int *contador);
void listarItens(Item mochila[], int contador);
void removerItem(Item mochila[], int *contador);
void buscarItem(Item mochila[], int contador);
void pausar();

// Vetor global que armazena os itens
int main() {
Item mochila[MAX_ITENS];
int qtdItens = 0; // Quantidade atual de itens na mochila
int opção;

do {
        printf("\n=== MENU INVENTÁRIO ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o '\n' deixado pelo scanf

         switch(opcao) {
            case 1:
                inserirItem(mochila, &qtde);
                listarItens(mochila, qtde);
                break;
            case 2:
                removerItem(mochila, &qtde);
                listarItens(mochila, qtde);
                break;
            case 3:
                listarItens(mochila, qtde);
                break;
            case 4:
                buscarItem(mochila, qtde);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}

void inserirItem(Item mochila[], int *qtde) {
    if (*qtde >= MAX_ITENS) {
        printf("A mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("Digite o nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // Remove o \n do fgets

    printf("Digite o tipo do item (arma, municao, cura...): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar();

    mochila[*qtde] = novo;
    (*qtde)++;

    printf("Item adicionado com sucesso!\n");
}
// Remover |Item
void removerItem(Item mochila[], int *qtde) {
    if (*qtde == 0) {
        printf("A mochila esta vazia! Nenhum item para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int encontrado = -1;
    for (int i = 0; i < *qtde; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item nao encontrado!\n");
        return;
    }

    // Desloca os itens seguintes para preencher a lacuna
    for (int i = encontrado; i < *qtde - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*qtde)--;
    printf("Item removido com sucesso!\n");
}
// listar Item
void listarItens(Item mochila[], int qtde) {
    if (qtde == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < qtde; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("-------------------------\n");
}

// Busca por nome do item
void buscarItem(Item mochila[], int qtde) {
    if (qtde == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    char nomeBuscar[30];
    printf("Digite o nome do item que deseja buscar: ");
    fgets(nomeBuscar, sizeof(nomeBuscar), stdin);
    nomeBuscar[strcspn(nomeBuscar, "\n")] = '\0';

    for (int i = 0; i < qtde; i++) {
        if (strcmp(mochila[i].nome, nomeBuscar) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado na mochila.\n");
}