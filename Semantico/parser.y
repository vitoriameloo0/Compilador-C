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
        extern int yylex();
        void yyerror(char *mensagem); 
        char arquivoArvore[80];       
        struct Node* head;
%}
 
%union{
    struct nome_var{
        char strNome[100]; 
        int type; 
        int vInt;
        float vReal;

        struct Node* no; // no para a arvore sintatica
        //struct Hash* listaSimb; // no para a lista Hash
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

%type <no_obj> programa includes main declaracaoV tipo var_id main_conteudo func retorno declarar atribuir if_decl else_decl while_decl for_decl for_opt print_decl scanf_decl corpo exp valor imp_str
%start programa

%%
/* Regras Sintaticas */
programa:   includes main     { $$.no = inserirArvore($1.no, $2.no, "programa"); 
                                head = $$.no;};

includes:   includes includes {$$.no = inserirArvore($1.no, $2.no, "includes: <includes> <includes>");}|
            BIBLIOTECA        {$$.no = inserirArvore(NULL, NULL, yytext);}|
            COMENTARIO        {$$.no = inserirArvore(NULL, NULL, yytext);}|
            /*vazio*/         {$$.no = inserirArvore(NULL, NULL, " ");};

main: tipo var_id A_PARENT declaracaoV F_PARENT A_CHAVE main_conteudo retorno F_CHAVE { if(buscar(tabela_simbolos, $2.strNome)->type != 4){
                                                                                            int x = verificaExistencia(tabela_simbolos, $2.strNome);
                                                                                            printf("Erro Semantico: Variavel com mesmo nome da funcao definido na linha %d\n", x);    
                                                                                        }
                                                                                        definirCategoria(tabela_simbolos, $2.strNome, 22);
                                                                                        definirTipo($2.strNome, 22, tabela_simbolos);
                                                                                        $$.no = inserirArvore($4.no, NULL, "main: <declaracaoV>");
                                                                                        $$.no = inserirArvore($7.no, $8.no, $2.strNome);}

declaracaoV: declaracaoV VIRGULA declaracaoV    {$$.no = inserirArvore($1.no, $3.no, "declaracaoV: <declaracaoV> , <declaracaoV>");}|
             tipo var_id                        {  if(buscar(tabela_simbolos, $2.strNome)->type != 4){
                                                        printf("Erro Semantico: Tipo de variavel foi redefinido na linha %d\n", line);    
                                                    }
                                                    definirCategoria(tabela_simbolos, $2.strNome, 21);
                                                    definirTipo($2.strNome, $1.type, tabela_simbolos);
                                                    $$.no = inserirArvore($1.no, $2.no, "declaracaoV: <tipo> <var_id>");
                                                }|
             /*vazio*/                          {$$.no = inserirArvore(NULL, NULL, " ");}; 

tipo:   INT    {$$.type = 1;    $$.no = inserirArvore(NULL, NULL, yytext);}|
        CHAR   {$$.type = 6;    $$.no = inserirArvore(NULL, NULL, yytext);}| 
        FLOAT  {$$.type = 2;    $$.no = inserirArvore(NULL, NULL, yytext);}|
        DOUBLE {$$.type = 2;    $$.no = inserirArvore(NULL, NULL, yytext);}|
        STRING {$$.type = 3;    $$.no = inserirArvore(NULL, NULL, yytext);}|
        VOID   {$$.type = 7;    $$.no = inserirArvore(NULL, NULL, yytext);}; 
       

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

declarar: tipo var_id                           {   if(buscar(tabela_simbolos, $2.strNome)->type != 4){
                                                        printf("Erro Semantico: Tipo da variavel '%s' redefinido na linha %d\n", $2.strNome , line);    
                                                    }
                                                    if(buscar(tabela_simbolos, $2.strNome)->categoria != 4) {
                                                        printf("Erro Semantico: Categoria da variavel '%s' redefinida na linha %d\n", $2.strNome , line);    
                                                    }
                                                    definirCategoria(tabela_simbolos, $2.strNome, 21);
                                                    definirTipo($2.strNome, $1.type, tabela_simbolos);
                                                    $$.type = $1.type;
                                                    strcpy($$.strNome, $2.strNome);
                                                    $$.no = inserirArvore($1.no, $2.no, "declarar: <tipo> <var_id>");
                                                }|

          tipo var_id A_COLCHET valor F_COLCHET {   if(buscar(tabela_simbolos, $2.strNome)->type != 4){
                                                        printf("Erro Semantico: Tipo da variavel '%s' redefinido na linha %d\n", $2.strNome, line);    
                                                    }
                                                    if(buscar(tabela_simbolos, $2.strNome)->categoria != 4) {
                                                        printf("Erro Semantico: Categoria da variavel '%s' redefinida na linha %d\n", $2.strNome , line);    
                                                    }
                                                    definirCategoria(tabela_simbolos, $2.strNome, 21);
                                                    definirTipo($2.strNome, $1.type, tabela_simbolos);
                                                    $$.type = $1.type;
                                                    strcpy($$.strNome, $2.strNome);
                                                    $$.no = inserirArvore($2.no, $4.no, "declarar: <tipo> <var_id> [ <valor> ]");
                                                }|

          declarar VIRGULA var_id               {   if(buscar(tabela_simbolos, $3.strNome)->type != 4){
                                                        printf("Erro Semantico: Tipo da variavel '%s' redefinido na linha %d\n", $3.strNome , line);  
                                                    }
                                                    if(buscar(tabela_simbolos, $3.strNome)->categoria != 4) {
                                                        printf("Erro Semantico: Categoria da variavel '%s' redefinida na linha %d\n", $3.strNome , line);    
                                                    }
                                                    definirCategoria(tabela_simbolos, $3.strNome, 21);
                                                    definirTipo($3.strNome, $1.type, tabela_simbolos);
                                                    $$.type = $1.type;
                                                    strcpy($$.strNome, $3.strNome);
                                                    $$.no = inserirArvore($1.no, $3.no, "declarar: <declarar> , <var_id> "); 
                                                }|

          /*declarar ATRIBUICAO valor             {   Hash* temp = buscar(tabela_simbolos, $1.strNome);
                                                    if(temp->type == $3.type){
                                                        $$.type = $3.type;
                                                        definirTipo(temp->chave, $3.type, tabela_simbolos);
                                                        receberValor(tabela_simbolos, $1.strNome, $3.strNome);
                                                        $$.no = inserirArvore($1.no, $3.no, "declarar: <declarar> = <valor>");
                                                    }
                                                    else if($1.type == 0){
                                                        printf("Erro Semantico: '%s' nao declarado na linha %d\n", $1.strNome, line);
                                                        $$.no = inserirError(NULL, NULL);
                                                    }
                                                    else{
                                                        printf("Erro Semantico: Atribuicao de tipos incompativeis na linha %d\n", line);
                                                        $$.no = inserirError(NULL, NULL);
                                                    }                 
                                                }|*/


          declarar ATRIBUICAO imp_str           {   if(buscar(tabela_simbolos, $3.strNome) != 4){
                                                        printf("Erro Semantico: Tipo da variavel '%s' redefinido na linha %d\n", $3.strNome , line); 
                                                    }
                                                    definirTipo($3.strNome, $1.type, tabela_simbolos);
                                                    $$.type = $1.type;
                                                    strcpy($$.strNome, $3.strNome);
                                                    $$.no = inserirArvore($1.no, $3.no, "declarar: <tipo> = <string>");
                                                }|

          error                                 {$$.no = inserirError(NULL, NULL);};

atribuir:   tipo var_id ATRIBUICAO exp          {   if(buscar(tabela_simbolos, $2.strNome)->type != 4){
                                                        printf("Erro Semantico: Tipo da variavel '%s' redefinido na linha %d\n", $2.strNome, line);    
                                                    }
                                                    if(buscar(tabela_simbolos, $2.strNome)->categoria != 4) {
                                                        printf("Erro Semantico: Categoria da variavel '%s' redefinida na linha %d\n", $2.strNome , line);    
                                                    }
                                                    definirCategoria(tabela_simbolos, $2.strNome, 21);
                                                    definirTipo($2.strNome, $1.type, tabela_simbolos);
                                                    if($1.type == $4.type){
                                                        $$.type = $4.type;
                                                        receberValor(tabela_simbolos, $2.strNome, $4.strNome);
                                                        $$.no = inserirArvore(NULL, $4.no, "atribuir: <tipo> <var_id> = <exp>");
                                                        $$.no = inserirArvore($1.no, $2.no, "<tipo> <var_id>");
                                                    }
                                                    else {
                                                        printf("Erro Semantico: Atribuicao de tipos incompativeis na linha %d\n", line);
                                                        $$.no = inserirError(NULL, NULL);
                                                    }
                                                }|
            var_id ATRIBUICAO exp                {   Hash* temp = buscar(tabela_simbolos, $1.strNome);
                                                    if(temp->type == $3.type){
                                                        $$.type = $3.type;
                                                        definirTipo(temp->chave, $3.type, tabela_simbolos);
                                                        receberValor(tabela_simbolos, $1.strNome, $3.strNome);
                                                        $$.no = inserirArvore($1.no, $3.no, "atribuir: <var_id> = <exp>");
                                                    }
                                                    else if(temp->type == 4){
                                                        printf("Erro semantico: '%s' nao foi declarado na linha %d\n", $1.strNome, line);
                                                        $$.no = inserirError(NULL, NULL);
                                                    }
                                                    else{
                                                        printf("Erro Semantico: Atribuicao de tipos incompativeis na linha %d\n", line);
                                                        $$.no = inserirError(NULL, NULL);
                                                    }                                                   
                                                }|

           var_id A_COLCHET valor F_COLCHET ATRIBUICAO exp  {   Hash* temp = buscar(tabela_simbolos, $1.strNome); 
                                                                if(temp->type == $6.type){
                                                                    $$.type = $6.type;
                                                                    definirTipo(temp->chave, $6.type, tabela_simbolos);
                                                                    receberValor(tabela_simbolos, $1.strNome, $6.strNome);

                                                                    if($3.type == 1){
                                                                        $$.no = inserirArvore(NULL, $6.no, "atribuir: <var_id> [ <valor> ] = <exp>");
                                                                        $$.no = inserirArvore($1.no, $3.no, "atribuir: <var_id> [ <valor> ]");
                                                                        $$.type = $3.type;
                                                                    }
                                                                    else {
                                                                        printf("Erro Semantico: Valor entre colchetes incompativel na linha %d\n", line);
                                                                    }
                                                                }
                                                                else if($1.type == 4){
                                                                        printf("Erro semantico: '%s' nao declarado na linha %d\n", $1.strNome, line);
                                                                        $$.no = inserirError(NULL, NULL);
                                                                    }
                                                                else{
                                                                    printf("Erro Semantico: Atribuicao de tipos incompativeis na linha %d\n", line);
                                                                    $$.no = inserirError(NULL, NULL);
                                                                }     
                                                            }|

         tipo var_id A_COLCHET valor F_COLCHET ATRIBUICAO exp   {   if(buscar(tabela_simbolos, $2.strNome)->type != 4){
                                                                        printf("Erro Semantico: Tipo de variavel redefinido na linha %d\n", line);    
                                                                    }
                                                                    if(buscar(tabela_simbolos, $2.strNome)->categoria != 4) {
                                                                        printf("Erro Semantico: Categoria da variavel '%s' redefinida na linha %d\n", $2.strNome , line);    
                                                                    }
                                                                    definirCategoria(tabela_simbolos, $2.strNome, 21);
                                                                    definirTipo($2.strNome, $1.type, tabela_simbolos);
                                                                    if($1.type == $7.type){
                                                                        $$.type = $7.type;
                                                                        receberValor(tabela_simbolos, $2.strNome, $7.strNome);
                                                                        if($4.type == 1){
                                                                            $$.no = inserirArvore(NULL, $7.no, "atribuir: <tipo> <var_id> [ <valor> ] = <exp>");
                                                                            $$.no = inserirArvore(NULL, $4.no, "atribuir: <tipo> <var_id> [ <valor> ]");
                                                                            $$.no = inserirArvore($1.no, $2.no,"atribuir: <tipo> <var_id>");
                                                                        }
                                                                        else {
                                                                            printf("Erro Semantico: Valor entre colchetes incompativel na linha %d\n", line);
                                                                        }
                                                                    }
                                                                    else {
                                                                         printf("Erro Semantico: Atribuicao de tipos incompativeis na linha %d\n", line);
                                                                         $$.no = inserirError(NULL, NULL);
                                                                    }
                                                                }|

          /* atribuir ATRIBUICAO exp              {   if($1.type == $3.type){
                                                        $$.type = $1.type;

                                                        $$.no = inserirArvore($1.no, $3.no, "atribuir: <atribuir> = <exp>");
                                                    }
                                                
                                                    
                                                }|*/

           exp                                  {$$.no = inserirArvore($1.no, NULL,  "atribuir: <exp>");}|

           error                                {$$.no = inserirError(NULL, NULL);};

imp_str : STR {$$.type = 3; $$.no = inserirArvore(NULL, NULL, yytext);}

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
    exp ADICAO exp         {   
                                 if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> + <exp>");
                                    $$.type = $1.type;
                                    if($$.type == 1){ // Caso o tipo seja inteiro 
                                        $$.vInt = calcularInt(tabela_simbolos, $1.strNome, $3.strNome, "+");
                                        itoa($$.vInt, $$.strNome, 10);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_INT", 1, 20, line); 
                                    }
                                    else if($$.type == 2){ // Caso o tipo seja real
                                        $$.vReal = calcularReal(tabela_simbolos, $1.strNome, $3.strNome, "+");
                                        sprintf($$.strNome, "%.2f", $$.vReal);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_REAL", 2, 20, line);    
                                    }  
                                }
                                else{
                                    //printf("tipo exp1: %s\ntipo exp2: %s\n", $1.type, $3.type);
                                    printf("Erro Semantico: Tipo incompativel aqui tbm na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }      
                            }|

    exp SUBTRACAO exp      {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> - <exp>");
                                    $$.type = $1.type;
                                    if($$.type == 1){ // Caso o tipo seja inteiro 
                                        $$.vInt = calcularInt(tabela_simbolos, $1.strNome, $3.strNome, "-");
                                        itoa($$.vInt, $$.strNome, 10);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_INT", 1, 20, line); 
                                    }
                                    else if($$.type == 2){ // Caso o tipo seja real
                                        $$.vReal = calcularReal(tabela_simbolos, $1.strNome, $3.strNome, "-");
                                        sprintf($$.strNome, "%.2f", $$.vReal);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_REAL", 2, 20, line);    
                                    }
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }   
                            }|

    exp MULTIPLICACAO exp  {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> * <exp>");
                                    $$.type = $1.type;

                                    if($$.type == 1){ // Caso o tipo seja inteiro 
                                        $$.vInt = calcularInt(tabela_simbolos, $1.strNome, $3.strNome, "*");
                                        itoa($$.vInt, $$.strNome, 10);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_INT", 1, 20, line); 
                                    }
                                    else if($$.type == 2){ // Caso o tipo seja real
                                        $$.vReal = calcularReal(tabela_simbolos, $1.strNome, $3.strNome, "*");
                                        sprintf($$.strNome, "%.2f", $$.vReal);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_REAL", 2, 20, line);    
                                    }
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }                          
                            }|
 
    exp DIVISAO exp        {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> / <exp>");
                                    $$.type = $1.type;
                                    if($$.type == 1){ // Caso o tipo seja inteiro 
                                        $$.vInt = calcularInt(tabela_simbolos, $1.strNome, $3.strNome, "/");
                                        itoa($$.vInt, $$.strNome, 10);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_INT", 1, 20, line); 
                                    }
                                    else if($$.type == 2){ // Caso o tipo seja real
                                        $$.vReal = calcularReal(tabela_simbolos, $1.strNome, $3.strNome, "/");
                                        sprintf($$.strNome, "%.2f", $$.vReal);
                                        inserir(tabela_simbolos, $$.strNome, "DIG_REAL", 2, 20, line);    
                                    }
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }
                            }|

    exp INCREMENTO         {    $$.no = inserirArvore($1.no,  NULL, "exp: <exp> ++");
                                $$.type = $1.type;

                                if($$.type == 1){
                                    $$.vInt = calcularInt(tabela_simbolos, $1.strNome, $1.strNome, "++");
                                    itoa($$.vInt, $$.strNome, 10);
                                }
                                else if ($$.type == 2){
                                    $$.vReal = calcularReal(tabela_simbolos, $1.strNome, $1.strNome, "++");
                                    sprintf($$.strNome, "%.2f", $$.vReal);
                                }
    
                            }|

    INCREMENTO exp         {    $$.no = inserirArvore(NULL,  $2.no, "exp: ++ <exp>");
                                $$.type = $2.type;

                                if($$.type == 1){
                                    $$.vInt = calcularInt(tabela_simbolos, $2.strNome, $2.strNome, "++");
                                    itoa($$.vInt, $$.strNome, 10);
                                }
                                else if ($$.type == 2){
                                    $$.vReal = calcularReal(tabela_simbolos, $2.strNome, $2.strNome, "++");
                                    sprintf($$.strNome, "%.2f", $$.vReal);
                                }
                            
                            }|

    exp DECREMENTO         {    $$.no = inserirArvore($1.no,  NULL, "exp: <exp> --");
                                 $$.type = $1.type;

                                if($$.type == 1){
                                    $$.vInt = calcularInt(tabela_simbolos, $1.strNome, $1.strNome, "--");
                                    itoa($$.vInt, $$.strNome, 10);
                                }
                                else if ($$.type == 2){
                                    $$.vReal = calcularReal(tabela_simbolos, $1.strNome, $1.strNome, "--");
                                    sprintf($$.strNome, "%.2f", $$.vReal);
                                }
                            }|

    DECREMENTO exp         {$$.no = inserirArvore(NULL,  $2.no, "exp: -- <exp>");}|

    exp OR exp             {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> || <exp>");
                                    $$.type = $1.type;
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }
                            }|

    exp AND exp            {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> && <exp>");
                                    $$.type = $1.type;
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }
                             }|

    NOT exp                {$$.no = inserirArvore(NULL,  $2.no, "exp: ! <exp>");}|

    exp IGUAL exp          {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> == <exp>");
                                    $$.type = $1.type;
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }
                            }|

    exp COMPARACAO exp     {    
                                if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> comp <exp>");
                                    $$.type = $1.type;
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha aqui ohhh %d\n", line);
                                    printf("tipo1: %d\ntipo2: %d\n", $1.type, $3.type);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }
    }|

    exp DIFERENTE exp      {    if($1.type == $3.type){
                                    $$.no = inserirArvore($1.no, $3.no, "exp: <exp> != <exp>");
                                    $$.type = $1.type;
                                }
                                else{
                                    printf("Erro Semantico: Tipo incompativel na linha %d\n", line);
                                    $$.no = inserirError($1.no, $3.no);
                                    $$.type = 4;
                                }
                            }|

    A_PARENT exp F_PARENT  {$$.no = inserirArvore(NULL,  $2.no, "exp: ( <exp> )");}| 

    var_id                 {$$.no = inserirArvore($1.no,  NULL, "exp: <var_id>");
                            $$.type = $1.type;
                            }|

    valor                  {$$.no = inserirArvore($1.no,  NULL, "exp: <valor>"); 
                            $$.type = $1.type;
                            }|

    error                  {$$.no = inserirError(NULL, NULL);};

valor:  INTEGER            { struct Node* temp = inserirArvore(NULL, NULL, yytext);
                             $$.no = inserirArvore(temp,  NULL, "constInt");
                             $$.type = 1;
                            }|

        REAL               { struct Node* temp = inserirArvore(NULL, NULL, yytext);
                             $$.no = inserirArvore(temp,  NULL, "constReal");
                             $$.type = 2;
                            }|

        CARACTER           { struct Node* temp = inserirArvore(NULL, NULL, yytext);
                             $$.no = inserirArvore(temp,  NULL, "constChar");
                             $$.type = 6;
                            }|

        STR                { struct Node* temp = inserirArvore(NULL, NULL, yytext);
                             $$.no = inserirArvore(NULL,  NULL, "constStr");
                             $$.type = 3;
                            };

%%

// Funcao que e ativada quando um erro sintatico e encontrado
void yyerror(char *mensagem) {
    erro++; 
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", line, mensagem);
}

void welcome (){
    printf("\nANALISADOR SEMANTICO\n");
    printf("LINGUAGEM C--\n");
    printf("\nDesenvolvido por: \n");
    printf("        Vitoria Conceicao Melo\n");
    printf("        Matheus Prokopowiski dos Santos\n\n\n");
   
}

int main(int argc, char *argv[]) {
    tabela_reservada = criarTabelaHash();     // tabela que sera guardada os tokens que sao reservada na linguagem
    tabela_simbolos = criarTabelaHash();      // tabela que sera guardada os simbolos presentes no arquivo de entrada
    welcome();

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


        printf("\n---------------Tabela de Palavras Reservada---------------\n");
        mostrarReservada (tabela_reservada);

        printf("\n=========================================================================\n");
    
        printf("\n----------------------------Tabela de Simbolos---------------------------\n");
        mostrar (tabela_simbolos);
        
        fclose(yyout);
    } else{
        printf("\nArquivo nao encontrado\n");
      }

    return 0;  
}
