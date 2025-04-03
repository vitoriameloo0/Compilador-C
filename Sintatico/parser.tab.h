/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INCREMENTO = 258,
     DECREMENTO = 259,
     IGUAL = 260,
     DIFERENTE = 261,
     ATRIBUICAO = 262,
     PONTO_VIRGULA = 263,
     VIRGULA = 264,
     A_PARENT = 265,
     F_PARENT = 266,
     A_CHAVE = 267,
     F_CHAVE = 268,
     A_COLCHET = 269,
     F_COLCHET = 270,
     COMPARACAO = 271,
     ADICAO = 272,
     SUBTRACAO = 273,
     MULTIPLICACAO = 274,
     DIVISAO = 275,
     AND = 276,
     OR = 277,
     NOT = 278,
     INT = 279,
     FLOAT = 280,
     CHAR = 281,
     DOUBLE = 282,
     VOID = 283,
     STRING = 284,
     IF = 285,
     ELSE = 286,
     FOR = 287,
     WHILE = 288,
     RETURN = 289,
     PRINTF = 290,
     SCANF = 291,
     ID = 292,
     STR = 293,
     CARACTER = 294,
     BIBLIOTECA = 295,
     COMENTARIO = 296,
     INTEGER = 297,
     REAL = 298,
     ESCRITA = 299,
     LEITURA = 300
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 24 "parser.y"

    struct nome_var{
        char strNome[100]; 
        struct Node* no;
    }no_obj;
             


/* Line 2058 of yacc.c  */
#line 111 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
