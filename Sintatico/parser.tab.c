/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 3 "parser.y"

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

/* Line 371 of yacc.c  */
#line 89 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 24 "parser.y"

    struct nome_var{
        char strNome[100]; 
        struct Node* no;
    }no_obj;
             


/* Line 387 of yacc.c  */
#line 186 "parser.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 214 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    14,    23,    25,
      27,    29,    31,    33,    35,    37,    41,    44,    46,    47,
      50,    53,    56,    58,    60,    63,    66,    68,    71,    77,
      81,    85,    88,    92,    94,    98,   103,   107,   109,   111,
     113,   119,   122,   123,   129,   138,   141,   144,   149,   156,
     160,   164,   168,   172,   176,   179,   182,   185,   188,   192,
     196,   199,   203,   207,   211,   215,   217,   219,   221,   223,
     225,   227,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    49,    -1,    48,    48,    -1,    40,
      -1,    41,    -1,    -1,    50,    51,    10,    11,    12,    53,
      52,    13,    -1,    24,    -1,    26,    -1,    25,    -1,    27,
      -1,    29,    -1,    28,    -1,    37,    -1,    34,    66,     8,
      -1,    53,    53,    -1,    54,    -1,    -1,    55,     8,    -1,
      56,     8,    -1,    58,    59,    -1,    60,    -1,    61,    -1,
      63,     8,    -1,    64,     8,    -1,    41,    -1,    50,    51,
      -1,    50,    51,    14,    67,    15,    -1,    55,     9,    51,
      -1,    55,     7,    67,    -1,    50,    56,    -1,    50,     7,
      57,    -1,     1,    -1,    51,     7,    66,    -1,    51,    14,
      67,    15,    -1,    56,     7,    66,    -1,    66,    -1,     1,
      -1,    38,    -1,    30,    10,    66,    11,    65,    -1,    31,
      65,    -1,    -1,    33,    10,    66,    11,    65,    -1,    32,
      10,    62,    66,     8,    66,    11,    65,    -1,    55,     8,
      -1,    56,     8,    -1,    35,    10,    44,    11,    -1,    36,
      10,    45,     9,    51,    11,    -1,    12,    53,    13,    -1,
      66,    17,    66,    -1,    66,    18,    66,    -1,    66,    19,
      66,    -1,    66,    20,    66,    -1,    66,     3,    -1,     3,
      66,    -1,    66,     4,    -1,     4,    66,    -1,    66,    22,
      66,    -1,    66,    21,    66,    -1,    23,    66,    -1,    66,
       5,    66,    -1,    66,    16,    66,    -1,    66,     6,    66,
      -1,    10,    66,    11,    -1,    51,    -1,    67,    -1,     1,
      -1,    42,    -1,    43,    -1,    39,    -1,    38,    -1,    51,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    65,    66,    67,    69,    71,    72,
      73,    74,    75,    76,    79,    82,    84,    85,    86,    88,
      89,    90,    91,    92,    93,    94,    95,    97,    98,    99,
     100,   101,   102,   103,   105,   106,   107,   108,   109,   111,
     113,   115,   116,   118,   120,   127,   128,   130,   132,   134,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   156,   157,
     158,   159,   160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCREMENTO", "DECREMENTO", "IGUAL",
  "DIFERENTE", "ATRIBUICAO", "PONTO_VIRGULA", "VIRGULA", "A_PARENT",
  "F_PARENT", "A_CHAVE", "F_CHAVE", "A_COLCHET", "F_COLCHET", "COMPARACAO",
  "ADICAO", "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "AND", "OR", "NOT",
  "INT", "FLOAT", "CHAR", "DOUBLE", "VOID", "STRING", "IF", "ELSE", "FOR",
  "WHILE", "RETURN", "PRINTF", "SCANF", "ID", "STR", "CARACTER",
  "BIBLIOTECA", "COMENTARIO", "INTEGER", "REAL", "ESCRITA", "LEITURA",
  "$accept", "programa", "includes", "main", "tipo", "var_id", "retorno",
  "main_conteudo", "func", "declarar", "atribuir", "imp_str", "if_decl",
  "else_decl", "while_decl", "for_decl", "for_opt", "print_decl",
  "scanf_decl", "corpo", "exp", "valor", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    50,    50,
      50,    50,    50,    50,    51,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    57,
      58,    59,    59,    60,    61,    62,    62,    63,    64,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     0,     8,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     0,     2,
       2,     2,     1,     1,     2,     2,     1,     2,     5,     3,
       3,     2,     3,     1,     3,     4,     3,     1,     1,     1,
       5,     2,     0,     5,     8,     2,     2,     4,     6,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     4,     5,     0,     0,     1,     8,    10,     9,    11,
      13,    12,     3,     2,     0,    14,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    70,    26,    68,    69,     0,    65,     0,    17,     0,
       0,    42,    22,    23,     0,     0,    37,    66,    67,    65,
      55,    57,     0,    60,     0,     0,     0,     0,     0,    67,
       0,    65,    31,     0,     0,     0,     0,     0,     0,    19,
       0,     0,    20,     0,    21,    24,    25,    54,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,    39,    32,     0,    34,
      72,     0,     0,     7,    30,    29,    36,     0,    41,    61,
      63,    62,    50,    51,    52,    53,    59,    58,     0,    45,
      46,     0,     0,    47,     0,     0,    35,    15,     0,    40,
       0,    43,     0,    28,    49,     0,    48,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    12,    13,    35,    49,    66,    67,    38,    39,
      40,    97,    41,    74,    42,    43,    92,    44,    45,   108,
      46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
      24,   -99,   -99,     4,   425,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,    24,   -99,   -23,   -99,    15,    29,    34,   137,
      83,   317,   317,   317,   317,    42,    45,    47,    49,    57,
     -99,   -99,   -99,   -99,   -99,   274,    31,   180,   -99,   104,
      28,    52,   -99,   -99,    65,    80,   422,   -99,   -99,   -99,
     422,   422,   325,    66,   317,     5,   317,    50,    51,   141,
      61,    54,    96,   317,    63,   317,    95,    94,    63,   -99,
     -23,   317,   -99,    97,   -99,   -99,   -99,   -99,   -99,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   -99,   346,
     144,    78,   317,   366,   105,   106,   -99,   -99,    63,   422,
     -99,   119,   386,   -99,   -99,   -99,   422,   223,   -99,   422,
     422,   442,     7,     7,    66,    66,   139,   139,    97,   -99,
     -99,   393,    97,   -99,   -23,   124,   -99,   -99,   266,   -99,
     317,   -99,   135,   -99,   -99,   413,   -99,    97,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   154,   -99,   151,   -14,   -99,   -18,   -99,   113,
     -33,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -98,
      -5,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -39
static const yytype_int16 yytable[] =
{
      16,    37,    62,   101,     5,    36,    20,   104,    21,    22,
      77,    78,    79,    80,    15,    23,    50,    51,    52,    53,
     129,    61,    91,    36,   131,    17,    84,    85,    24,     6,
       7,     8,     9,    10,    11,    71,    72,   125,    63,   138,
      18,    36,    15,    30,    31,    64,    19,    33,    34,    89,
     100,    93,    54,    36,   100,    55,   105,    56,    99,    57,
     102,    63,   -27,   -27,     1,     2,   106,    58,    98,    77,
      78,    79,    80,    75,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    73,   100,    71,   120,   121,    76,   128,
     -33,   -33,   -33,    36,    94,    20,    95,    21,    22,    96,
      15,    30,    31,    71,    23,    33,    34,   -16,   103,   107,
     132,    68,    69,    70,    36,   124,   123,    24,     6,     7,
       8,     9,    10,    11,    25,   135,    26,    27,   -16,    28,
      29,    15,    30,    31,   126,    32,    33,    34,    20,   133,
      21,    22,    77,    78,    79,    80,   136,    23,   -38,   -38,
     -38,    68,   119,    70,     4,    14,    82,    83,    84,    85,
      24,     6,     7,     8,     9,    10,    11,    25,    90,    26,
      27,   -18,    28,    29,    15,    30,    31,     0,    32,    33,
      34,    20,     0,    21,    22,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     6,     7,     8,     9,    10,    11,
      25,     0,    26,    27,    65,    28,    29,    15,    30,    31,
       0,    32,    33,    34,    20,     0,    21,    22,     0,     0,
       0,     0,     0,    23,     0,     0,   -18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     6,     7,     8,
       9,    10,    11,    25,     0,    26,    27,     0,    28,    29,
      15,    30,    31,     0,    32,    33,    34,    20,     0,    21,
      22,     0,     0,     0,     0,    59,    23,    21,    22,   134,
       0,    60,     0,     0,    23,     0,     0,     0,     0,    24,
       6,     7,     8,     9,    10,    11,    25,    24,    26,    27,
       0,    28,    29,    15,    30,    31,     0,    32,    33,    34,
       0,    15,    30,    31,     0,     0,    33,    34,    48,     0,
      21,    22,     0,     0,     0,     0,     0,    23,    77,    78,
      79,    80,     0,     0,     0,     0,    88,     0,     0,     0,
      24,    81,    82,    83,    84,    85,    86,    87,     0,    77,
      78,    79,    80,     0,    15,    30,    31,   118,     0,    33,
      34,     0,    81,    82,    83,    84,    85,    86,    87,    77,
      78,    79,    80,     0,     0,     0,     0,   122,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    77,
      78,    79,    80,     0,   127,     0,    77,    78,    79,    80,
       0,   130,    81,    82,    83,    84,    85,    86,    87,    81,
      82,    83,    84,    85,    86,    87,    77,    78,    79,    80,
       0,     0,     0,     0,   137,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    77,    78,    79,    80,     6,
       7,     8,     9,    10,    11,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,     1,     2
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      14,    19,    35,    64,     0,    19,     1,    68,     3,     4,
       3,     4,     5,     6,    37,    10,    21,    22,    23,    24,
     118,    35,    55,    37,   122,    10,    19,    20,    23,    24,
      25,    26,    27,    28,    29,     7,     8,    98,     7,   137,
      11,    55,    37,    38,    39,    14,    12,    42,    43,    54,
      64,    56,    10,    67,    68,    10,    70,    10,    63,    10,
      65,     7,     8,     9,    40,    41,    71,    10,    14,     3,
       4,     5,     6,     8,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    31,    98,     7,     8,    92,     8,   107,
       7,     8,     9,   107,    44,     1,    45,     3,     4,    38,
      37,    38,    39,     7,    10,    42,    43,    13,    13,    12,
     124,     7,     8,     9,   128,     9,    11,    23,    24,    25,
      26,    27,    28,    29,    30,   130,    32,    33,    34,    35,
      36,    37,    38,    39,    15,    41,    42,    43,     1,    15,
       3,     4,     3,     4,     5,     6,    11,    10,     7,     8,
       9,     7,     8,     9,     0,     4,    17,    18,    19,    20,
      23,    24,    25,    26,    27,    28,    29,    30,    55,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,     1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,     1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     1,    10,     3,     4,    13,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    23,    32,    33,
      -1,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      -1,    37,    38,    39,    -1,    -1,    42,    43,     1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    10,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      23,    16,    17,    18,    19,    20,    21,    22,    -1,     3,
       4,     5,     6,    -1,    37,    38,    39,    11,    -1,    42,
      43,    -1,    16,    17,    18,    19,    20,    21,    22,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,     3,
       4,     5,     6,    -1,     8,    -1,     3,     4,     5,     6,
      -1,     8,    16,    17,    18,    19,    20,    21,    22,    16,
      17,    18,    19,    20,    21,    22,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    11,     3,     4,     5,     6,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,     3,     4,     5,     6,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,    47,    48,     0,    24,    25,    26,    27,
      28,    29,    48,    49,    50,    37,    51,    10,    11,    12,
       1,     3,     4,    10,    23,    30,    32,    33,    35,    36,
      38,    39,    41,    42,    43,    50,    51,    53,    54,    55,
      56,    58,    60,    61,    63,    64,    66,    67,     1,    51,
      66,    66,    66,    66,    10,    10,    10,    10,    10,     1,
       7,    51,    56,     7,    14,    34,    52,    53,     7,     8,
       9,     7,     8,    31,    59,     8,     8,     3,     4,     5,
       6,    16,    17,    18,    19,    20,    21,    22,    11,    66,
      55,    56,    62,    66,    44,    45,    38,    57,    14,    66,
      51,    67,    66,    13,    67,    51,    66,    12,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    11,     8,
       8,    66,    11,    11,     9,    67,    15,     8,    53,    65,
       8,    65,    51,    15,    13,    66,    11,    11,    65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    { (yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, (yyvsp[(2) - (2)].no_obj).no, "programa"); 
                                head = (yyval.no_obj).no;}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, (yyvsp[(2) - (2)].no_obj).no, "includes: <includes> <includes>");}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 65 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 66 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, " ");}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 69 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(6) - (8)].no_obj).no, (yyvsp[(7) - (8)].no_obj).no, (yyvsp[(2) - (8)].no_obj).strNome);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 71 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 73 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 76 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, (yyvsp[(2) - (3)].no_obj).no, "retorno: return <exp> ;");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 84 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, (yyvsp[(2) - (2)].no_obj).no, "main_conteudo: <main_conteudo> <main conteudo>");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 85 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no, NULL,  "main_conteudo: <func>");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL,   "main_conteudo:  ");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, NULL,  "func: <declarar> ;");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, NULL,  "func: <atribuir> ;");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, (yyvsp[(2) - (2)].no_obj).no, "func: <if_decl> <else_decl>");}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no, NULL,  "func: <while_decl>");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no, NULL,  "func: <for_decl>");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, NULL,  "func: <print_decl>");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, NULL,  "func: <scanf_decl>");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, (yyvsp[(2) - (2)].no_obj).no, "declarar: <tipo> <var_id>");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 98 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(2) - (5)].no_obj).no, (yyvsp[(4) - (5)].no_obj).no, "declarar: <tipo> <var_id> [ <valor> ]");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "declarar: <declarar> , <var_id> ");}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "declarar: <declarar> = <valor>");}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, (yyvsp[(2) - (2)].no_obj).no, "declarar: <tipo> <atribuir>");}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "declarar: <tipo> = <string>");}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    {(yyval.no_obj).no = inserirError(NULL, NULL);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "atribuir: <var_id> = <exp>");}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (4)].no_obj).no, (yyvsp[(3) - (4)].no_obj).no, "atribuir: <var_id> [ <valor> ]");}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 107 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "atribuir: <atribuir> = <exp>");}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no, NULL,  "atribuir: <exp>");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    {(yyval.no_obj).no = inserirError(NULL, NULL);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, yytext);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(3) - (5)].no_obj).no, (yyvsp[(5) - (5)].no_obj).no, "if_decl: if( <exp> ) <corpo>");}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 115 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, (yyvsp[(2) - (2)].no_obj).no, "else_decl: else <corpo>");}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL,  "else_decl: ");}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(3) - (5)].no_obj).no, (yyvsp[(5) - (5)].no_obj).no, "while_decl: while( <exp> ) <corpo>");}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    {
    struct Node* condicao = inserirArvore((yyvsp[(4) - (8)].no_obj).no, (yyvsp[(6) - (8)].no_obj).no, "condicao");
    struct Node* inicio = inserirArvore((yyvsp[(3) - (8)].no_obj).no, NULL, "inicializacao");
    struct Node* noFor = inserirArvore(inicio, condicao, "forhead");    
    (yyval.no_obj).no = inserirArvore(noFor, (yyvsp[(8) - (8)].no_obj).no, "for");   
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, NULL, "for_opt: <declarar> ;");}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no, NULL, "for_opt: <atribuir> ;");}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, NULL, (yyvsp[(3) - (4)].no_obj).strNome);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, (yyvsp[(5) - (6)].no_obj).no, (yyvsp[(3) - (6)].no_obj).strNome);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL, (yyvsp[(2) - (3)].no_obj).no, "corpo: { <main_conteudo> }");}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> + <exp>");}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 138 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> - <exp>");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> * <exp>");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> / <exp>");}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no,  NULL, "exp: <exp> ++");}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  (yyvsp[(2) - (2)].no_obj).no, "exp: ++ <exp>");}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 143 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (2)].no_obj).no,  NULL, "exp: <exp> --");}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  (yyvsp[(2) - (2)].no_obj).no, "exp: -- <exp>");}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> || <exp>");}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> && <exp>");}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  (yyvsp[(2) - (2)].no_obj).no, "exp: ! <exp>");}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 148 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> == <exp>");}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> comp <exp>");}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (3)].no_obj).no, (yyvsp[(3) - (3)].no_obj).no, "exp: <exp> != <exp>");}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  (yyvsp[(2) - (3)].no_obj).no, "exp: ( <exp> )");}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no,  NULL, "exp: <var_id>");}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no,  NULL, "exp: <valor>"); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    {(yyval.no_obj).no = inserirError(NULL, NULL);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  NULL, yytext);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  NULL, yytext);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 158 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  NULL, yytext);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 159 "parser.y"
    {(yyval.no_obj).no = inserirArvore(NULL,  NULL, yytext);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 160 "parser.y"
    {(yyval.no_obj).no = inserirArvore((yyvsp[(1) - (1)].no_obj).no, NULL, yytext);}
    break;


/* Line 1792 of yacc.c  */
#line 2025 "parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 164 "parser.y"


// Funcao que e ativada quando um erro sintatico e encontrado
void yyerror(char *mensagem) {
    erro++; 
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", line, mensagem);
}

void welcome (){
    printf("\nANALISADOR LEXICO E SINTATICO\n");
    printf("LINGUAGEM C--\n");
    printf("\nDesenvolvido por: \n");
    printf("        Vitoria Conceicao Melo\n");
    printf("        Matheus Prokopowiski dos Santos\n");
   
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