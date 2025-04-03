%{
	#include <stdio.h>
	#include "hashtable.h"

    Hash** tabela_reservada;
    Hash** tabela_simbolos;
    FILE *yyin;
    FILE *yyout;
%}

%option yylineno

	//Especificacao das regras

INT             "int"
FLOAT           "float"
CHAR            "char"
VOID            "void"
IF  	        "if"
ELSE	        "else"
FOR	            "for"
WHILE	        "while"
SWITCH	        "switch"
DEFAULT	        "default"
CASE	        "case"
BREAK	        "break"
RETURN	        "return"
ERROSIMB        ("@"|"#"|"&"|"?"|"+"|"$")+("=")+
INCREMENTO	    "++"
DECREMENTO	    "--"
IGUAL		    "=="
MENOR_IGUAL	    "<="	
MAIOR_IGUAL	    ">="	
DIFERENTE	    "!="
ATRIBUICAO	    "="
EXCLAMACAO	    "!"
PONTO_VIRGULA	";"
DOIS_PONTO	    ":"
VIRGULA		    ","
MAIOR		    ">"
MENOR		    "<"
CT_BARRA	    "\"
A_PARENT	    "("
F_PARENT	    ")"
A_CHAVE		    "{"
F_CHAVE		    "}"
A_COLCHET	    "["
F_COLCHET	    "]"
ADICAO		    "+"
SUBTRACAO	    "-" 
MULTIPLICACAO	"*"
DIVISAO		    "/"
LETRA           [a-zA-Z]
ID		        [a-zA-Z]+[a-zA-Z0-9]*
CARACTER	    ['][a-zA-Z]+[']
DIG_INT		    [0-9]+
DIG_FLOAT	    [0-9]+[.][0-9]+
ESPACO		    [" "\n\t]+ 
ERROID          [0-9]+[A-Za-z0-9]+
SIMBOLOS        ("@"|"#"|"&"|"?"|"+"|"$")+
ERROID2         (LETRA)*(SIMBOLOS)(LETRA)+


%%
	//Regras
{INT}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_INT");
                }
            }

{FLOAT}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_FLOAT");
                }
            }

{CHAR}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_CHAR");
                }
            }

{VOID}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_VOID");
                }
            }

{IF}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_IF");
                }
            }

{ELSE}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_ELSE");
                }
            }

{FOR}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_FOR");
                }
            }

{WHILE}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_WHILE");
                }
            }

{SWITCH}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_SWITCH");
                }
            }

{DEFAULT}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_DEFAULT");
                }
            }

{CASE}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_CASE");
                }
            }

{BREAK}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_BREAK");
                }
            }

{RETURN}    {   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "TIPO_RETURN");
                }
            }

{INCREMENTO}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "INCREMENTO");
                    }
                }

{DECREMENTO}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "DESCREMENTO");
                    }
                }

{IGUAL}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "IGUAL");
                }
            }

{MENOR_IGUAL}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "MENOR_IGUAL");
                    }
                }

{MAIOR_IGUAL}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "MAIOR_IGUAL");
                    }
                }

{DIFERENTE}	    {   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "DIFERENTE");
                    }
                }

{ATRIBUICAO}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "ATRIBUICAO");
                    }
                }

{EXCLAMACAO}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "EXCLAMACAO");
                    }
                }

{PONTO_VIRGULA}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "PONTO_VIRGULA");
                    }
                }

{DOIS_PONTO}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "DOIS_PONTO");
                    }
                }

{VIRGULA}		{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "VIRGULA");
                    }
                }

{MAIOR}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "MAIOR");
                }
            }

{MENOR}		{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "MENOR");
                }
            }

{A_PARENT}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "A_PARENT");
                }
            }

{F_PARENT}	{   int token = buscar(tabela_reservada, yytext); 
                if(token == 0){
                    inserir(tabela_reservada, yytext, "F_PARENT"); 
                }
            }

{A_CHAVE}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "A_CHAVE");
                }
            }

{F_CHAVE}	{   int token = buscar(tabela_reservada, yytext); 
                if(token == 0){
                    inserir(tabela_reservada, yytext, "F_CHAVE"); 
                }
            }

{A_COLCHET}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "A_COLCHET");
                }
            }

{F_COLCHET}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "F_COLCHET");
                }
            }

{ADICAO}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "ADICAO");
                }
            }

{SUBTRACAO}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "SUBTRACAO");
                }
            }

{MULTIPLICACAO}	{   int token = buscar(tabela_reservada, yytext);
                    if(token == 0){
                        inserir(tabela_reservada, yytext, "MULTIPLICACAO");
                    }
                }

{DIVISAO}	{   int token = buscar(tabela_reservada, yytext);
                if(token == 0){
                    inserir(tabela_reservada, yytext, "DIVISAO");
                }
            }

{ID}		{   int token = buscar(tabela_simbolos, yytext);
                if(token == 0){
                    inserir(tabela_simbolos, yytext, "ID");
                }
            }

{CARACTER}	{   int token = buscar(tabela_simbolos, yytext);
                if(token == 0){
                    inserir(tabela_simbolos, yytext, "CARACTER");
                }
            }

{DIG_INT}	{   int token = buscar(tabela_simbolos, yytext);
                if(token == 0){
                    inserir(tabela_simbolos, yytext, "DIG_INT");
                }
            }

{DIG_FLOAT}	{   int token = buscar(tabela_simbolos, yytext);
                if(token == 0){
                    inserir(tabela_simbolos, yytext, "DIG_FLOAT");
                }
            }

{ERROID}    {
                printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
            }

{ERROID2}   {
                printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
            }

{ERROSIMB}  {
                printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
            }

{ESPACO}	{;}

.           {
                printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);    
            }
%%



int yywrap(){
    return 1;
}

int main(int argc, char *argv[]) {
    tabela_reservada = criarTabelaHash();     // tabela que sera guardada os tokens que sao reservada na linguagem
    tabela_simbolos = criarTabelaHash();      // tabela que sera guardada os simbolos presentes no arquivo de entrada

    char str[100];                            //string para ler o nome do arquivo
    printf("\nEntre com o arquivo.txt\n");
    scanf("%s", str);
    yyin = fopen (str , "r");

    if(yyin != NULL){
        yylex();
        fclose(yyin);
    }
    else{
        printf("\nArquivo nao encontrado\n");
    }

    printf("\nTabela de Palavras Reservada\n");
    mostrar (tabela_reservada);

    printf("\n===================================\n");
    
    printf("\nTabela de Simbolos\n");
    mostrar (tabela_simbolos);      
}
