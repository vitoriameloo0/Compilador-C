%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "hashtable.h"
    #include "parser.tab.h"

    Hash** tabela_reservada;
    Hash** tabela_simbolos;
    int line = 1;
%}

%option yylineno

DIG             [0-9]
INTEGER		    ([-]?{DIG}+)
REAL	        ({DIG}+)\.({DIG}+)
CARACTER	    (\'.*\')
ID		        [a-zA-Z_]+[a-zA-Z0-9_]*
STR             (\".*\")
ESCRITA          (\^.*\^)
LEITURA           (\*.*\*)
ERROSIMB        ("@"|"#"|"&"|"?"|"$")+("=")+
INCREMENTO	    "++"
DECREMENTO	    "--"
ADICAO		    "+"
SUBTRACAO	    "-" 
MULTIPLICACAO	"*"
DIVISAO		    "/"
IGUAL		    "=="
ATRIBUICAO	    "="
COMPARACAO      (<|>|<\=|>\=)
DIFERENTE	    "!="
AND             "&&"
OR              "||"
NOT             "!"
PONTO_VIRGULA	";"
VIRGULA		    ","
A_PARENT	    "("
F_PARENT	    ")"
A_CHAVE		    "{"
F_CHAVE		    "}"
A_COLCHET	    "["
F_COLCHET	    "]"
COMENTARIO     ("//"[^\n]*)
ERROID          [0-9]+[A-Za-z0-9]+
ERROID2         (LETRA)*("@"|"#"|"&"|"?"|"$")+(LETRA)+
BIBLIOTECA      ("#include"[ ]*<.+\.h>)

%%


"int"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_INT");    
                return INT;
            }

"float"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_FLOAT");             
                return FLOAT;
            }

"char"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_CHAR");
                return CHAR;
            }

"double"	{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_DOUBLE");
                return DOUBLE;
            }

"void"      {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_VOID");
                return VOID;
            }

"string"    {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_STRING");
                return STRING;
            }

"if"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "IF");                
                return IF;
            }

"else"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "ELSE");              
                return ELSE;
            }

"for"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "FOR");                                 
                return FOR;
            }

"while"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "WHILE");                                  
                return WHILE;
            }

"return"    {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "RETURN");                   
                return RETURN;
            }

"printf"    {    strcpy(yylval.no_obj.strNome, (yytext));
                 inserir(tabela_reservada, yytext, "PRINTF");                                
                return PRINTF;
            }

"scanf"    {   strcpy(yylval.no_obj.strNome, (yytext));
               inserir(tabela_reservada, yytext, "SCANF");                               
               return SCANF;
            }         

{ID}		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "ID");                                
                return ID;
            }

{STR}       {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "STRING");                                
                return STR;
            }

{ESCRITA}   {    strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "ESCRITA");                                
                return ESCRITA;           
            }

{LEITURA}   {    strcpy(yylval.no_obj.strNome, (yytext));
               inserir(tabela_simbolos, yytext, "LEITURA");                                 
               return LEITURA;           
            }

{INTEGER}	{  strcpy(yylval.no_obj.strNome, (yytext));
               inserir(tabela_simbolos, yytext, "DIG_INT");                                 
                return  INTEGER;
            }

{REAL}      {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "DIG_REAL");                  
                return REAL;
            }           

{CARACTER}	{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "CARACTER");                                
                return CARACTER;
            }

{BIBLIOTECA} {  strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "NOME_BIBLIOTECA");                                 
                return BIBLIOTECA;
            } 

{INCREMENTO} {  inserir(tabela_reservada, yytext, "INCREMENTO");                       
                return INCREMENTO;
             }

{DECREMENTO} {  inserir(tabela_reservada, yytext, "DECREMENTO");                        
                return DECREMENTO;
             }

{ADICAO}	{  inserir(tabela_reservada, yytext, "ADICAO");                   
               return ADICAO;
            }

{SUBTRACAO}	{   inserir(tabela_reservada, yytext, "SUBTRACAO");                    
                return SUBTRACAO;
            }

{MULTIPLICACAO} {   inserir(tabela_reservada, yytext, "MULTIPLICACAO");                       
                    return MULTIPLICACAO;
                }

{DIVISAO}	{   inserir(tabela_reservada, yytext, "DIVISAO");                   
                return DIVISAO;
            }

{IGUAL}		{   inserir(tabela_reservada, yytext, "IGUAL");                    
                return IGUAL;
            }

{ATRIBUICAO}	{   inserir(tabela_reservada, yytext, "ATRIBUICAO");                        
                    return ATRIBUICAO;
                }            

{COMPARACAO}	{   inserir(tabela_reservada, yytext, "COMPARACAO");                       
                    return COMPARACAO;
                }

{DIFERENTE}	    {   inserir(tabela_reservada, yytext, "DIFERENTE");
                    return DIFERENTE;
                }

{AND}           {   inserir(tabela_reservada, yytext, "AND");
                    return AND;
                }

{OR}            {   inserir(tabela_reservada, yytext, "OR");
                    return OR;
                }

{NOT}           {   inserir(tabela_reservada, yytext, "NOT");
                    return NOT;
                }
            
{PONTO_VIRGULA}	{   inserir(tabela_reservada, yytext, "PONTO_VIRGULA");
                    return PONTO_VIRGULA;
                }

{VIRGULA}		{   inserir(tabela_reservada, yytext, "VIRGULA");
                    return VIRGULA;
                }
                
{A_PARENT}	    {   inserir(tabela_reservada, yytext, "A_PARENT");
                    return  A_PARENT;
                }

{F_PARENT}	    {   inserir(tabela_reservada, yytext, "F_PARENT");
                    return F_PARENT;
                }           

{A_CHAVE}	    {   inserir(tabela_reservada, yytext, "A_CHAVE");
                    return A_CHAVE;
                }

{F_CHAVE}	    {   inserir(tabela_reservada, yytext, "F_CHAVE"); 
                    return F_CHAVE;
                }

{A_COLCHET}	    {   inserir(tabela_reservada, yytext, "A_COLCHET");
                    return A_COLCHET;
                }

{F_COLCHET}	    {   inserir(tabela_reservada, yytext, "F_COLCHET");
                    return F_COLCHET;
                }       

{COMENTARIO}    {   inserir(tabela_simbolos, yytext, "COMENTARIO");
                   strcpy(yylval.no_obj.strNome, (yytext));
                    return COMENTARIO;
                }

"\n"            {line++;}            

[ \t\r]*        {;}

{ERROID}        {
                    printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
                    
                }

{ERROID2}       {
                    printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
                    
                }

{ERROSIMB}      {
                  printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
                  
                }

.               {
                    printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext); 
                
                }
%%

int yywrap(){
    return 1;
}
