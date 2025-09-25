#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// =====================================
//Estrutura que representa um item na mochila
//======================================

typedef struct {
    char nome[30];       //Nome do item
    char tipo[20];       //Tipo do item ex
    int  quantidade;      //Quantidade de itens
    int prioridade;

} Item;