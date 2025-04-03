#include "hashtable.h"
 
// Função para inicializar uma tabela hash vazia
Hash** criarTabelaHash() {
    Hash** tabela = (Hash**)malloc(sizeof(Hash*) * TAM_TABELA);
    int i;
    for ( i = 0; i < TAM_TABELA; i++) {
        tabela[i] = NULL;
    }
    return tabela;
} 

// Função de hash simples para mapear uma chave a um índice na tabela
unsigned int hash(const char* chave) {
    unsigned int hash = 0;
    while (*chave) {
        hash = (hash * 31) + (*chave++);
    }
    return hash % TAM_TABELA;
}

// Função para inserir uma chave, valor, tipo, categoria e a linha que ele aparece na tabela hash passada
void inserir(Hash** tabela, const char* chave, char* token, int type, int categoria, int linha) {
    Hash* verifica = buscar(tabela, chave);
    

    if(verifica == NULL){ //insere na tabela caso ainda não esteja inserida
        unsigned int indice = hash(chave);
        Hash* novoNo = (Hash*)malloc(sizeof(Hash));
        novoNo->chave = strdup(chave);
        novoNo->token = token;
        novoNo->type = type;
        novoNo->categoria = categoria;
        
        if(type == 1 && strcmp(token, "DIG_INT") == 0) novoNo->valor_int = atoi(chave);
        else if(type == 2 && strcmp(token, "DIG_REAL") == 0) novoNo->valor_real = atof(chave);
        else if(type == 3 && strcmp(token, "STRING") == 0) strcpy(novoNo->valor_str, chave);
        else if(type == 6 && strcmp(token, "CARACTER") == 0) strcpy(novoNo->valor_char, chave);

        novoNo->lines = (ListaId*) malloc (sizeof(ListaId));
        novoNo->lines->line = linha;
        novoNo->lines->next = NULL;

        novoNo->prox = tabela[indice];
        tabela[indice] = novoNo;  
    }
    else { // insere a linha em que o tokem apareceu novamente no arquivo       
        ListaId *lista = verifica->lines;
        while (lista->next != NULL) lista = lista->next;

        lista->next = (ListaId*) malloc (sizeof(ListaId));
        lista->next->line = linha;
        lista->next->next = NULL;
    }
}

// Função para buscar um token na tabela hash com base na chave
Hash* buscar(Hash** tabela, const char* chave) {
    unsigned int indice = hash(chave);
    
    Hash* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual; //Caso a chave ja esteja na tabela, retorna no atual
        }
        atual = atual->prox;
    }
    return NULL; // Caso não tenha encontrado a chave
}

// Funcao pra verificar se um ID com o mesmo nome da funcao ja foi inserido na tabela
int verificaExistencia(Hash** tabela, char* nome){
    Hash* verifica = buscar(tabela, nome);
    ListaId *lista = verifica->lines;
    
    while(lista->next != NULL) lista = lista->next;
    
    return lista->line; // Devolve a linha da primeira vez que ele foi inserido
}

// Função para definir a categoria de um lexema
void definirCategoria(Hash** tabela, char* nome , int categoria){
    Hash* l = buscar(tabela, nome);
    l->categoria = categoria;
}

// Funcao para definir o tipo de uma variavel
void definirTipo(char* nome, int tipo, Hash** tabela){
    Hash* l = buscar(tabela, nome);
    l->type = tipo;
}

// Funcao para atribuir um valor a uma variavel
void receberValor(Hash** tabela, char *var_id, char* exp){
    Hash* l_id = buscar(tabela, var_id);
    Hash* l_exp = buscar(tabela, exp);

    if(l_exp->type == 1){ // caso o tipo seja inteiro
        l_id->valor_int = atoi(l_exp->chave);
    }
    else if(l_exp->type == 2){ // caso o tipo seja real
            l_id->valor_real = atof(l_exp->chave);
    }
    else if(l_exp->type == 3){ // caso o tipo seja string
            strcpy(l_id->valor_str, l_exp->chave);
    }
    else if(l_exp->type == 6){ // caso o tipo seja char
            strcpy(l_id->valor_char, l_exp->chave);
    }
}

// Função que faz o calculo de variaveis inteira
int calcularInt(Hash** tabela, char* expressao1, char* expressao2, char* simbolo){
    Hash* expr1 = buscar(tabela, expressao1);
    Hash* expr2 = buscar(tabela, expressao2);
    int x;

    if (strcmp(simbolo, "+") == 0){
        x = expr1->valor_int + expr2->valor_int;
        return x;
    }
    else if(strcmp(simbolo, "-") == 0){
        x = expr1->valor_int - expr2->valor_int;
        return x;
    }
    else if(strcmp(simbolo, "*") == 0){
        x = expr1->valor_int * expr2->valor_int;
        return x;
    }
    else if(strcmp(simbolo, "/") == 0){
        x = expr1->valor_int / expr2->valor_int;
        return x;
    } 
    else if(strcmp(simbolo, "++") == 0){
        x = expr1->valor_int + 1;
        expr1->valor_int = x;
        return expr1->valor_int;
    }
    else if(strcmp(simbolo, "--") == 0){
        x = expr1->valor_int - 1;
        expr1->valor_int = x;
        return expr1->valor_int;
    }
    return 0;
}

// Função que faz o calculo de variaveis float
float calcularReal (Hash** tabela, char* expressao1, char* expressao2, char* simbolo){
    Hash* expr1 = buscar(tabela, expressao1);
    Hash* expr2 = buscar(tabela, expressao2);
    float y;

    if(strcmp(simbolo, "+") == 0){
        y = expr1->valor_real + expr2->valor_real;
        return y;
    }
    else if(strcmp(simbolo, "-") == 0){
        y = expr1->valor_real - expr2->valor_real;
        return y;
    }
    else if(strcmp(simbolo, "*") == 0){
        y = expr1->valor_real * expr2->valor_real;
        return y;
    }
    else if(strcmp(simbolo, "/") == 0){
        y = expr1->valor_real / expr2->valor_real;
        return y;
    }
    else if(strcmp(simbolo, "++") == 0){
        y = expr1->valor_real + 1.0;
        printf("%f aqui\n", y);
        expr1->valor_real = y;
        return expr1->valor_real;
    }
    else if(strcmp(simbolo, "--") == 0){
        y = expr1->valor_real - 1.0;
        expr1->valor_real = y;
        return expr1->valor_real;
    }
    return 0.0;
}

// Função para imprimir todos os elementos da tabela de simbolos
void mostrar(Hash** tabela){
    int i;
    Hash* aux;
    printf("------------------------- -------------------- --------------- --------------------- ----------\n");
    printf("Lexema                    Token                Tipo            Categoria             Valor      \n");
    printf("------------------------- -------------------- --------------- --------------------- ----------\n");
    for (i = 0; i < TAM_TABELA; i++){
        if(tabela[i] != NULL){
            aux = tabela[i];
            while(aux != NULL){
                printf("%-26s%-21s", aux->chave, aux->token);
                if(aux->type == TIPO_INT)           printf("%-16s", "int");
                else if(aux->type == TIPO_REAL)     printf("%-16s", "real");
                else if(aux->type == TIPO_STR)      printf("%-16s", "string");
                else if(aux->type == TIPO_CHAR)     printf("%-16s", "char");
                else if(aux->type == TIPO_VOID)     printf("%-16s", "void");
                else if(aux->type == TIPO_KEIWORD)  printf("%-16s", "Keyword");
                else if(aux->type == FUNCAO)        printf("%-16s", "Funcao");
                else                                printf("%-16s", "Indefinido"); 
                
                if(aux->categoria == NUMERO)            printf("%-22s", "Numero");
                else if(aux->categoria == VARIAVEL)     printf("%-22s", "Variavel");
                else if(aux->categoria == FUNCAO)       printf("%-22s", "Funcao"); 
                else if(aux->categoria == CARACTERES)   printf("%-22s", "Caracteres");
                else                                    printf("%-22s", "Indefinido");
                
                if(aux->type == TIPO_INT)       printf("%-16d", aux->valor_int);
                else if(aux->type == TIPO_REAL) printf("%-16.2f", aux->valor_real);
                else if(aux->type == TIPO_STR)  printf("%-16s", aux->valor_str);
                else if(aux->type == TIPO_CHAR) printf("%-16s", aux->valor_char);
                else                            printf("%-16s", "---");
                
                printf("\n");
                aux = aux->prox;
            }   
        }
    }
}

// Função para imprimir todos os elementos da tabela de reservada
void mostrarReservada(Hash** tabela){
    int i;
    Hash* aux;
    printf("------------------------- -------------------- --------------- -------------------- \n");
    printf("Lexema                    Token                Tipo            Categoria \n");
    printf("------------------------- -------------------- --------------- -------------------- \n");
    for (i = 0; i < TAM_TABELA; i++){
        if(tabela[i] != NULL){
            aux = tabela[i];
            while(aux != NULL){
                printf("%-26s%-21s", aux->chave, aux->token);
                if(aux->type == TIPO_KEIWORD)           printf("%-16s", "Keyword");
                else if(aux->type == OP_ARITMETICO)     printf("%-16s", "Aritmetico");
                else if(aux->type == OP_RELACIONAL)     printf("%-16s", "Relacional");
                else if(aux->type == OP_INC_DEC)        printf("%-16s", "Inc_Dec");
                else if(aux->type == OP_ATRI)           printf("%-16s", "Atribuicao");
                else if(aux->type == OP_LOGIC)          printf("%-16s", "Logico"); 
                else                                    printf("%-16s", "Underfined");
                
                if(aux->categoria == TIPO_DADO)         printf("%-21s","Tipo de Dado");
                else if(aux->categoria == BIBLIOTECAS)  printf("%-21s", "Bibliotecas");
                else if(aux->categoria == SIMBOLOS)     printf("%-21s", "Simbolos");
                else if(aux->categoria == TIPO_KEIWORD) printf("%-21s", "Palavra Reservada");
                else                                    printf("%-21s", "Indefinido");
        
                printf("\n");
                aux = aux->prox;
            }   
        }
    }
}
