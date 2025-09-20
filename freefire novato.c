#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// =====================================
//Estrutura que representa um item na mochila
//======================================

typedef struct {
    char [30];         // Nome do item
    char tipo[20];     //Tipo do item ex
    int quantidade;    // Quantidade de itens

} Item;

// Vetor global que armazena os itens
Item mochila[MAX_ITENS];
int qtdItens = 0; // Quantidade atual de itens cadastrados