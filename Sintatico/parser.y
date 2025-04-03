/* Analisador Sintatico*/

%{
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        #include "hashtable.h"
        #include "arvore.h"
        #include "parser.tab.h"
        
        extern FILE *yyin;              
        extern FILE *yyout;             
        extern Hash** tabela_reservada;
        extern Hash** tabela_simbolos;
        
        extern int line;              // Contar a quantidade de linhas no arquivo
        int erro = 0 ;                // Vai contar a quantidade de erros que tem no arquivo
        extern char* yytext;          // Mostra o texto do token
        void yyerror(char *mensagem); 
        char arquivoArvore[80];       
        struct Node* head;
%}

%union{
    struct nome_var{
        char strNome[100]; 
        struct Node* no;
    }no_obj;
             
};
 
/* Definicao dos tokens */
 
%token INCREMENTO DECREMENTO IGUAL DIFERENTE ATRIBUICAO
%token PONTO_VIRGULA VIRGULA 
%token A_PARENT F_PARENT A_CHAVE F_CHAVE A_COLCHET F_COLCHET
%token COMPARACAO
%token ADICAO SUBTRACAO MULTIPLICACAO DIVISAO
%token AND OR NOT 

%token <no_obj> INT FLOAT CHAR DOUBLE VOID STRING
%token <no_obj> IF ELSE FOR WHILE
%token <no_obj> RETURN PRINTF SCANF 
%token <no_obj> ID STR CARACTER BIBLIOTECA COMENTARIO 
%token <no_obj> INTEGER REAL
%token <no_obj> ESCRITA LEITURA


%right ATRIBUICAO
%left  COMPARACAO
%left  AND OR
%left  ADICAO SUBTRACAO 
%left  MULTIPLICACAO DIVISAO
%right NOT

%type <no_obj> programa includes main tipo var_id main_conteudo func retorno declarar atribuir if_decl else_decl while_decl for_decl for_opt print_decl scanf_decl corpo exp valor imp_str
%start programa

%%
/* Regras Sintaticas */
programa:   includes main     { $$.no = inserirArvore($1.no, $2.no, "programa"); 
                                head = $$.no;};

includes:   includes includes {$$.no = inserirArvore($1.no, $2.no, "includes: <includes> <includes>");}|
            BIBLIOTECA        {$$.no = inserirArvore(NULL, NULL, yytext);}|
            COMENTARIO        {$$.no = inserirArvore(NULL, NULL, yytext);}|
            /*vazio*/         {$$.no = inserirArvore(NULL, NULL, " ");};

main: tipo var_id A_PARENT F_PARENT A_CHAVE main_conteudo retorno F_CHAVE {$$.no = inserirArvore($6.no, $7.no, $2.strNome);}

tipo:   INT    {$$.no = inserirArvore(NULL, NULL, yytext);}|
        CHAR   {$$.no = inserirArvore(NULL, NULL, yytext);}| 
        FLOAT  {$$.no = inserirArvore(NULL, NULL, yytext);}|
        DOUBLE {$$.no = inserirArvore(NULL, NULL, yytext);}|
        STRING {$$.no = inserirArvore(NULL, NULL, yytext);}|
        VOID   {$$.no = inserirArvore(NULL, NULL, yytext);};
       

var_id: ID {$$.no = inserirArvore(NULL, NULL, yytext);};


retorno: RETURN exp PONTO_VIRGULA {$$.no = inserirArvore(NULL, $2.no, "retorno: return <exp> ;");}

main_conteudo:  main_conteudo main_conteudo {$$.no = inserirArvore($1.no, $2.no, "main_conteudo: <main_conteudo> <main conteudo>");}|
                func                        {$$.no = inserirArvore($1.no, NULL,  "main_conteudo: <func>");}|
                /*vazio*/                   {$$.no = inserirArvore(NULL, NULL,   "main_conteudo:  ");}

func:   declarar PONTO_VIRGULA      {$$.no = inserirArvore($1.no, NULL,  "func: <declarar> ;");}|
        atribuir PONTO_VIRGULA      {$$.no = inserirArvore($1.no, NULL,  "func: <atribuir> ;");}|
        if_decl else_decl           {$$.no = inserirArvore($1.no, $2.no, "func: <if_decl> <else_decl>");}|
        while_decl                  {$$.no = inserirArvore($1.no, NULL,  "func: <while_decl>");}|
        for_decl                    {$$.no = inserirArvore($1.no, NULL,  "func: <for_decl>");}|
        print_decl PONTO_VIRGULA    {$$.no = inserirArvore($1.no, NULL,  "func: <print_decl>");}|
        scanf_decl PONTO_VIRGULA    {$$.no = inserirArvore($1.no, NULL,  "func: <scanf_decl>");}|
        COMENTARIO                  {$$.no = inserirArvore(NULL, NULL, yytext);};

declarar: tipo var_id                           {$$.no = inserirArvore($1.no, $2.no, "declarar: <tipo> <var_id>");}|
          tipo var_id A_COLCHET valor F_COLCHET {$$.no = inserirArvore($2.no, $4.no, "declarar: <tipo> <var_id> [ <valor> ]");}|
          declarar VIRGULA var_id               {$$.no = inserirArvore($1.no, $3.no, "declarar: <declarar> , <var_id> ");}|
          declarar ATRIBUICAO valor             {$$.no = inserirArvore($1.no, $3.no, "declarar: <declarar> = <valor>");}|
          tipo atribuir                         {$$.no = inserirArvore($1.no, $2.no, "declarar: <tipo> <atribuir>");}|
          tipo ATRIBUICAO imp_str               {$$.no = inserirArvore($1.no, $3.no, "declarar: <tipo> = <string>");}|
          error                                 {$$.no = inserirError(NULL, NULL);};

atribuir:  var_id ATRIBUICAO exp                {$$.no = inserirArvore($1.no, $3.no, "atribuir: <var_id> = <exp>");}|
           var_id A_COLCHET valor F_COLCHET     {$$.no = inserirArvore($1.no, $3.no, "atribuir: <var_id> [ <valor> ]");}|
           atribuir ATRIBUICAO exp              {$$.no = inserirArvore($1.no, $3.no, "atribuir: <atribuir> = <exp>");}|
           exp                                  {$$.no = inserirArvore($1.no, NULL,  "atribuir: <exp>");}|
           error                                {$$.no = inserirError(NULL, NULL);};

imp_str : STR {$$.no = inserirArvore(NULL, NULL, yytext);}

if_decl: IF A_PARENT exp F_PARENT corpo {$$.no = inserirArvore($3.no, $5.no, "if_decl: if( <exp> ) <corpo>");}

else_decl:  ELSE corpo  {$$.no = inserirArvore(NULL, $2.no, "else_decl: else <corpo>");}|
             /*vazio*/  {$$.no = inserirArvore(NULL, NULL,  "else_decl: ");};

while_decl: WHILE A_PARENT exp F_PARENT corpo {$$.no = inserirArvore($3.no, $5.no, "while_decl: while( <exp> ) <corpo>");}

for_decl: FOR A_PARENT for_opt exp PONTO_VIRGULA exp F_PARENT corpo {
    struct Node* condicao = inserirArvore($4.no, $6.no, "condicao");
    struct Node* inicio = inserirArvore($3.no, NULL, "inicializacao");
    struct Node* noFor = inserirArvore(inicio, condicao, "forhead");    
    $$.no = inserirArvore(noFor, $8.no, "for");   
    };

for_opt: declarar PONTO_VIRGULA {$$.no = inserirArvore($1.no, NULL, "for_opt: <declarar> ;");}|
         atribuir PONTO_VIRGULA {$$.no = inserirArvore($1.no, NULL, "for_opt: <atribuir> ;");};

print_decl: PRINTF A_PARENT ESCRITA F_PARENT  {$$.no = inserirArvore(NULL, NULL, $3.strNome);}

scanf_decl: SCANF A_PARENT LEITURA VIRGULA var_id F_PARENT {$$.no = inserirArvore(NULL, $5.no, $3.strNome);}

corpo:  A_CHAVE main_conteudo F_CHAVE   {$$.no = inserirArvore(NULL, $2.no, "corpo: { <main_conteudo> }");};

exp:
    exp ADICAO exp         {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> + <exp>");}|
    exp SUBTRACAO exp      {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> - <exp>");}|
    exp MULTIPLICACAO exp  {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> * <exp>");}|
    exp DIVISAO exp        {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> / <exp>");}|
    exp INCREMENTO         {$$.no = inserirArvore($1.no,  NULL, "exp: <exp> ++");}|
    INCREMENTO exp         {$$.no = inserirArvore(NULL,  $2.no, "exp: ++ <exp>");}|
    exp DECREMENTO         {$$.no = inserirArvore($1.no,  NULL, "exp: <exp> --");}|
    DECREMENTO exp         {$$.no = inserirArvore(NULL,  $2.no, "exp: -- <exp>");}|
    exp OR exp             {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> || <exp>");}|
    exp AND exp            {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> && <exp>");}|
    NOT exp                {$$.no = inserirArvore(NULL,  $2.no, "exp: ! <exp>");}|
    exp IGUAL exp          {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> == <exp>");}|
    exp COMPARACAO exp     {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> comp <exp>");}|
    exp DIFERENTE exp      {$$.no = inserirArvore($1.no, $3.no, "exp: <exp> != <exp>");}|
    A_PARENT exp F_PARENT  {$$.no = inserirArvore(NULL,  $2.no, "exp: ( <exp> )");}| 
    var_id                 {$$.no = inserirArvore($1.no,  NULL, "exp: <var_id>");}|
    valor                  {$$.no = inserirArvore($1.no,  NULL, "exp: <valor>"); }|
    error                  {$$.no = inserirError(NULL, NULL);};

valor:  INTEGER            {$$.no = inserirArvore(NULL,  NULL, yytext);}|
        REAL               {$$.no = inserirArvore(NULL,  NULL, yytext);}|
        CARACTER           {$$.no = inserirArvore(NULL,  NULL, yytext);}|
        STR                {$$.no = inserirArvore(NULL,  NULL, yytext);}|
        var_id             {$$.no = inserirArvore($1.no, NULL, yytext);};
     
;

%%

// Funcao que e ativada quando um erro sintatico e encontrado
void yyerror(char *mensagem) {
    erro++; 
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", line, mensagem);
}


int main(int argc, char *argv[]) {
    tabela_reservada = criarTabelaHash();     // tabela que sera guardada os tokens que sao reservada na linguagem
    tabela_simbolos = criarTabelaHash();      // tabela que sera guardada os simbolos presentes no arquivo de entrada

    yyin = fopen (argv[1] , "r");

    if(yyin != NULL){
        yyparse();
        fclose(yyin);

        sprintf(arquivoArvore, "arvore_%s", argv[1]);
        yyout = fopen(arquivoArvore, "w");

        if (erro == 0) // imprime a arvore completa se nao tiver erros
            imprimirArvore(yyout, head);
     
        else // Nao imprime nada no arquivo da arvore
            printf("\nA Arvore nao pode ser gerada, pois o codigo apresenta erro!\n");


        printf("\n------Tabela de Palavras Reservada------\n");
        mostrar (tabela_reservada);

        printf("\n========================================\n");
    
        printf("\n-----------Tabela de Simbolos-----------\n");
        mostrar (tabela_simbolos);
        
        fclose(yyout);
    } else{
        printf("\nArquivo nao encontrado\n");
      }

    return 0;  
}
