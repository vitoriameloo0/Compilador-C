#include "hashtable.h"

// Função de hash simples para mapear uma chave a um índice na tabela
unsigned int hash(const char* chave) {
    unsigned int hash = 0;
    while (*chave) {
        hash = (hash * 31) + (*chave++);
    }
    return hash % TAM_TABELA;
}

// Função para inicializar uma tabela hash vazia
Hash** criarTabelaHash() {
    Hash** tabela = (Hash**)malloc(sizeof(Hash*) * TAM_TABELA);
    int i;
    for ( i = 0; i < TAM_TABELA; i++) {
        tabela[i] = NULL;
    }
    return tabela;
}

// Função para inserir um par chave-valor na tabela hash

void inserir(Hash** tabela, const char* chave, char* token) {
    unsigned int indice = hash(chave);
    
    Hash* novoNo = (Hash*)malloc(sizeof(Hash));
    novoNo->chave = strdup(chave);
    novoNo->token = token;
    novoNo->prox = tabela[indice];
    
    tabela[indice] = novoNo;
}

// Função para buscar um token na tabela hash com base na chave
int buscar(Hash** tabela, const char* chave) {
    unsigned int indice = hash(chave);
    
    Hash* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1; //Caso a chave ja esteja na tabela
        }
        atual = atual->prox;
    }

    return 0; // Caso não tenha encontrado a chave
}

// Função para imprimir todos os elementos da tabela

void mostrar(Hash** tabela){
    int i;
    Hash* aux;
    printf("--Lexema----------Token--\n");
    for (i = 0; i < TAM_TABELA; i++){
        if(tabela[i] != NULL){
            aux = tabela[i];
            while(aux != NULL){
                printf("%5s%18s\n", aux->chave, aux->token);
                aux = aux->prox;
            }   
        }
    }
}
