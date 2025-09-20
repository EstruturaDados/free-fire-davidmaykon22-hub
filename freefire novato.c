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