#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

typedef struct Nodo {
    Produto produto;
    struct Nodo* proximo;
} Nodo;

Nodo* inicializarLista() {
    return NULL;
}

Nodo* adicionarProduto(Nodo* lista) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    
    printf("Informe o codigo do produto: ");
    scanf("%d", &novoNodo->produto.codigo);
    printf("Informe a descricao do produto: ");
    scanf("%[^\n]s", novoNodo->produto.descricao);
    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoNodo->produto.quantidade);
    printf("Informe o valor do produto: ");
    scanf("%f", &novoNodo->produto.valor);
    
    novoNodo->proximo = lista;
    return novoNodo;
}

void imprimirRelatorio(Nodo* lista) {
    Nodo* atual = lista;

    printf("\n----------- Relatorio de Produtos -----------\n");
    
    while (atual != NULL) {
        printf("Codigo: %d\n", atual->produto.codigo);
        printf("Descricao: %s\n", atual->produto.descricao);
        printf("Quantidade: %d\n", atual->produto.quantidade);
        printf("Valor: %.2f\n\n", atual->produto.valor);

        atual = atual->proximo;
    }
}

void pesquisarProduto(Nodo* lista) {
    int codigoPesquisa;
    printf("Informe o codigo do produto a ser pesquisado: ");
    scanf("%d", &codigoPesquisa);

    Nodo* atual = lista;

    while (atual != NULL) {
        if (atual->produto.codigo == codigoPesquisa) {
            printf("\n----------- Produto Encontrado -----------\n");
            printf("Codigo: %d\n", atual->produto.codigo);
            printf("Descricao: %s\n", atual->produto.descricao);
            printf("Quantidade: %d\n", atual->produto.quantidade);
            printf("Valor: %.2f\n\n", atual->produto.valor);
            return;
        }

        atual = atual->proximo;
    }

    printf("Produto nao encontrado.\n\n");
}

Nodo* removerProduto(Nodo* lista) {
    int codigoRemover;
    printf("Informe o codigo do produto a ser removido: ");
    scanf("%d", &codigoRemover);

    Nodo* anterior = NULL;
    Nodo* atual = lista;

    while (atual != NULL) {
        if (atual->produto.codigo == codigoRemover) {
            if (anterior == NULL) {
                Nodo* proximo = atual->proximo;
                free(atual);
                return proximo;
            } else {
                anterior->proximo = atual->proximo;
                free(atual);
                return lista;
            }
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Produto nao encontrado. Nada foi removido.\n\n");
    return lista;
}


int main() {
    Nodo* lista = inicializarLista();
    int escolha;

    do {
        printf("\n----------- Menu -----------\n");
        printf("1 - Adicionar Produto\n");
        printf("2 - Imprimir Relatorio\n");
        printf("3 - Pesquisar Produto\n");
        printf("4 - Remover Produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                lista = adicionarProduto(lista);
                break;
            case 2:
                imprimirRelatorio(lista);
                break;
            case 3:
                pesquisarProduto(lista);
                break;
            case 4:
                lista = removerProduto(lista);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 0);

    Nodo* atual = lista;
    Nodo* proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}