
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"
  
    #include "quadruplets.h"
    #include "tableDesSymboles.h"
    #include "generationCodeObjet.h"
 
  
    // reecupère les variables déclarées dans l'analyseur lexical
    extern int nb_lines ;
    extern int nb_chars ;
    extern char* currentText;
    extern int lexical_error;

    // type d'un ensemble à sa declaration
    char typeEns[20];
    // type d'un ensemble à sa declaration
    char idfName[20];
    // verifie si il recoit 1 cte ou plus
    int unique = 1;
    //guess if it s an arithm or logical exp
    int express = 1;
    char type[20];
    
    int yylex(); // lance l'analyseur lexical
    void yyerror(char *s);// fonction d'affichage d'erreurs




/* Line 189 of yacc.c  */
#line 102 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     idf = 258,
     mc_float = 259,
     mc_int = 260,
     mc_char = 261,
     mc_bool = 262,
     mc_if = 263,
     mc_ifelse = 264,
     mc_else = 265,
     mc_for = 266,
     mc_in = 267,
     mc_while = 268,
     int_pos = 269,
     int_neg = 270,
     float_value = 271,
     char_value = 272,
     bool_value = 273,
     mc_and = 274,
     mc_or = 275,
     sup_equal = 276,
     inf_equal = 277,
     equal = 278,
     diff = 279,
     affect = 280,
     saut_ligne = 281
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 35 "syntax.y"


    char* value;

    listes bool;

    int number;

    br next;
 



/* Line 214 of yacc.c  */
#line 178 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 190 "syntax.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    31,     2,     2,
      35,    36,    29,    27,    34,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      37,     2,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    12,    15,    18,    21,
      24,    27,    30,    33,    36,    39,    41,    42,    47,    48,
      53,    54,    59,    60,    65,    66,    72,    77,    82,    87,
      88,    91,    95,    97,    99,   103,   104,   108,   112,   116,
     120,   124,   128,   130,   132,   134,   136,   141,   143,   145,
     150,   152,   154,   156,   158,   160,   162,   165,   170,   175,
     177,   178,   181,   187,   190,   192,   194,   196,   198,   200,
     205,   213,   218,   226,   229,   231,   232,   235,   236,   240,
     243,   249,   253,   259,   262,   263,   268,   272,   279,   283,
     286,   289,   292,   295,   298,   308,   312,   316,   319,   323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    46,    44,    -1,    44,    -1,    45,    44,
      -1,    -1,    47,    46,    -1,    65,    46,    -1,    69,    46,
      -1,    70,    46,    -1,    74,    46,    -1,    79,    46,    -1,
      84,    46,    -1,    87,    46,    -1,    26,    46,    -1,    26,
      -1,    -1,     5,     3,    48,    53,    -1,    -1,     4,     3,
      49,    53,    -1,    -1,     6,     3,    50,    53,    -1,    -1,
       7,     3,    51,    53,    -1,    -1,     5,     3,    25,    52,
      55,    -1,     6,     3,    25,    17,    -1,     7,     3,    25,
      18,    -1,     4,     3,    25,    16,    -1,    -1,    54,    56,
      -1,    32,    14,    33,    -1,    15,    -1,    14,    -1,    34,
       3,    56,    -1,    -1,    57,    27,    57,    -1,    57,    28,
      57,    -1,    57,    29,    57,    -1,    57,    30,    57,    -1,
      57,    31,    57,    -1,    35,    57,    36,    -1,    58,    -1,
      16,    -1,    55,    -1,     3,    -1,     3,    32,    59,    33,
      -1,    55,    -1,     3,    -1,    35,    57,    61,    62,    -1,
      37,    -1,    38,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    57,    36,    -1,    63,    19,    64,    63,    -1,
      63,    20,    64,    63,    -1,    60,    -1,    -1,    66,    67,
      -1,     3,    32,    59,    33,    25,    -1,     3,    25,    -1,
      63,    -1,    57,    -1,    68,    -1,    17,    -1,    18,    -1,
       3,    27,    25,    14,    -1,     3,    32,    59,    33,    27,
      25,    14,    -1,     3,    28,    25,    14,    -1,     3,    32,
      59,    33,    28,    25,    14,    -1,    72,    73,    -1,    46,
      -1,    -1,    45,    73,    -1,    -1,    75,    26,    78,    -1,
      76,    77,    -1,     8,    35,    63,    36,    46,    -1,    39,
      71,    40,    -1,    10,    46,    39,    71,    40,    -1,    10,
      74,    -1,    -1,    80,    81,    82,    83,    -1,     3,    25,
       9,    -1,     3,    32,    59,    33,    25,     9,    -1,    35,
      63,    34,    -1,    57,    34,    -1,    63,    34,    -1,    57,
      36,    -1,    63,    36,    -1,    85,    86,    -1,    11,    35,
       3,    12,    14,    41,    14,    36,    46,    -1,    39,    71,
      40,    -1,    88,    89,    90,    -1,    13,    35,    -1,    63,
      36,    46,    -1,    39,    71,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    70,    71,    76,    77,    78,    79,
      80,    81,    82,    83,    89,    90,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   101,   102,   106,
     106,   108,   113,   114,   117,   118,   123,   130,   137,   145,
     154,   162,   164,   167,   168,   169,   170,   177,   178,   182,
     192,   193,   194,   195,   196,   197,   200,   204,   208,   211,
     215,   220,   224,   230,   234,   247,   248,   254,   255,   263,
     270,   280,   286,   299,   301,   302,   305,   306,   312,   320,
     328,   335,   339,   340,   341,   347,   354,   356,   363,   366,
     371,   389,   392,   409,   420,   434,   439,   445,   449,   455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "idf", "mc_float", "mc_int", "mc_char",
  "mc_bool", "mc_if", "mc_ifelse", "mc_else", "mc_for", "mc_in",
  "mc_while", "int_pos", "int_neg", "float_value", "char_value",
  "bool_value", "mc_and", "mc_or", "sup_equal", "inf_equal", "equal",
  "diff", "affect", "saut_ligne", "'+'", "'-'", "'*'", "'/'", "'%'", "'['",
  "']'", "','", "'('", "')'", "'<'", "'>'", "'{'", "'}'", "':'", "$accept",
  "AXIOME", "PRG", "INST", "MULTI_SAUT_LIGNE", "DEC", "$@1", "$@2", "$@3",
  "$@4", "$@5", "DEC_D", "$@6", "INT_VALUE", "ENS", "EXP_ARITHME", "INFO",
  "INDICE", "EXP_COMP", "MGEXP_COMP", "MDEXP_COMP", "EXP_LOG", "M", "AFF",
  "MGAFF", "MDAFF", "VALUE", "INCR", "DECR", "BLOC_INSTS", "MGBLOC_INSTS",
  "MDBLOC_INSTS", "COND", "IF_COND", "MGIF_COND", "MDIF_COND", "ELSE_COND",
  "AFFEC_COND", "MGAFFEC_COND", "AFFEC_COND1", "AFFEC_COND2",
  "AFFEC_COND3", "FOR_LOOP", "MGFOR_LOOP", "MDFOR_LOOP", "WHILE_LOOP",
  "MGWHILE_LOOP", "MMWHILE_LOOP", "MDWHILE_LOOP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    43,    45,    42,
      47,    37,    91,    93,    44,    40,    41,    60,    62,   123,
     125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    48,    47,    49,    47,
      50,    47,    51,    47,    52,    47,    47,    47,    47,    54,
      53,    53,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    61,    61,    61,    61,    62,    63,    63,    63,
      64,    65,    66,    66,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    74,    75,
      76,    77,    78,    78,    78,    79,    80,    80,    81,    82,
      82,    83,    83,    84,    85,    86,    87,    88,    89,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     5,     4,     4,     4,     0,
       2,     3,     1,     1,     3,     0,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     4,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     1,
       0,     2,     5,     2,     1,     1,     1,     1,     1,     4,
       7,     4,     7,     2,     1,     0,     2,     0,     3,     2,
       5,     3,     5,     2,     0,     4,     3,     6,     3,     2,
       2,     2,     2,     2,     9,     3,     3,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     3,     5,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,    18,    16,    20,    22,     0,     0,    97,    14,
       1,     4,     2,     6,     7,    45,    33,    32,    43,    67,
      68,     0,    44,    65,    42,    59,    64,    61,    66,     8,
       9,    10,    84,    75,    79,    11,     0,     0,    12,    75,
      93,    13,     0,     0,     0,    86,     0,     0,    48,    47,
       0,     0,    29,    24,    29,     0,    29,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      60,     0,    78,    74,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    75,    96,    69,    71,     0,    28,     0,
      19,    35,     0,    17,    26,    21,    27,    23,     0,     0,
       0,     0,    52,    53,    54,    55,    41,    50,    51,     0,
      36,    37,    38,    39,    40,     0,     0,     0,    83,    81,
      77,    73,    88,    89,    90,     0,     0,    85,    95,    98,
       0,    62,     0,     0,     0,     0,    30,    25,    80,     0,
      46,     0,    49,    57,    58,    75,    76,    91,    92,    99,
      87,     0,     0,    31,    35,     0,    56,     0,    70,    72,
      34,     0,    82,     0,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,   103,    14,    84,    82,    86,    88,
     122,   120,   121,    52,   166,    53,    54,    80,    55,   139,
     172,    56,   145,    15,    16,    57,    58,    17,    18,   104,
     105,   151,    19,    20,    21,    64,   102,    22,    23,    67,
     109,   157,    24,    25,    70,    26,    27,    74,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
      73,    68,     3,     5,    13,    28,   -22,     2,     7,    38,
      67,   -99,   148,   148,    38,    38,    18,    38,    38,    38,
      48,    74,    38,    50,    38,    87,    38,    79,    78,   102,
     113,    24,   132,   133,   152,   153,    79,   126,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   105,   -99,   -99,   -99,   -99,
     -99,    40,   -99,   117,   -99,   -99,    41,   -99,   -99,   -99,
     -99,   -99,   150,    38,   -99,   -99,    79,    54,   -99,    38,
     -99,   -99,    40,    -8,   131,   -99,   165,   166,   -99,   -99,
     154,   175,   162,   -99,   162,   178,   162,   179,   162,    46,
     184,    24,    40,    94,    40,    40,    40,    40,    40,   -99,
     -99,    -3,   -99,   -99,   158,   148,    10,   155,    39,    54,
     159,   112,    38,    38,   -99,   -99,   -99,    82,   -99,   186,
     -99,   167,    76,   -99,   -99,   -99,   -99,   -99,    38,   188,
     170,    75,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    40,
     138,   138,   -99,   -99,   -99,    79,    79,   168,   -99,   -99,
     148,   -99,   -99,   -99,   -99,   135,    52,   -99,   -99,   -99,
     164,   196,   181,   183,   176,   207,   -99,   -99,   -99,   171,
     -99,   145,   -99,   -99,   -99,    38,   -99,   -99,   -99,   -99,
     -99,   197,   199,   -99,   167,   200,   -99,   177,   -99,   -99,
     -99,   180,   -99,    38,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,    85,   -98,     0,   -99,   -99,   -99,   -99,   -99,
     -99,   104,   -99,   -28,    31,   -47,   -99,   127,   -99,   -99,
     -99,   -26,   119,   -99,   -99,   -99,   -99,   -99,   -99,   -67,
     -99,    70,   120,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      13,    73,   110,    79,    93,     6,    32,   150,    33,    39,
      89,    99,   100,    36,    43,    44,    34,    59,    60,    61,
     107,    45,    65,     9,    68,   111,    71,    78,   112,    99,
     100,    35,    46,    47,    48,    49,    50,    37,    46,    47,
     106,   108,    38,    45,   152,   131,   160,   140,   141,   142,
     143,   144,   150,    51,    46,    47,    48,    45,    99,   100,
      99,   100,   155,    79,     9,    99,   100,    40,    46,    47,
      48,    99,   100,   154,    62,    92,     1,     2,     3,     4,
       5,     6,   128,   156,     7,    66,     8,    75,   178,    51,
      46,    47,   171,    28,   167,    29,    30,    41,    42,     9,
      31,   147,    94,    95,    96,    97,    98,   161,   187,   162,
     163,   136,   159,    63,    72,   132,   133,   134,   135,   173,
     174,    94,    95,    96,    97,    98,    69,    76,   168,    90,
     136,   137,   138,   132,   133,   134,   135,    91,    77,    94,
      95,    96,    97,    98,    94,    95,    96,    97,    98,   137,
     138,     1,     2,     3,     4,     5,     6,    81,    83,     7,
     101,     8,    94,    95,    96,    97,    98,    96,    97,    98,
     113,   177,    94,    95,    96,    97,    98,    85,    87,   115,
     116,   186,    94,    95,    96,    97,    98,   117,   123,   153,
     125,   118,   127,   194,   119,   124,   129,   126,   149,   158,
     164,   165,   169,   170,   179,   180,   181,   175,   182,   183,
     184,   188,   185,   189,   191,   190,   193,   192,   130,   146,
     176,   148
};

static const yytype_uint8 yycheck[] =
{
       0,    27,    69,    31,    51,     8,     3,   105,     3,     9,
      36,    19,    20,    35,    14,    15,     3,    17,    18,    19,
      67,     3,    22,    26,    24,    72,    26,     3,    36,    19,
      20,     3,    14,    15,    16,    17,    18,    35,    14,    15,
      66,    67,    35,     3,    34,    92,   113,    94,    95,    96,
      97,    98,   150,    35,    14,    15,    16,     3,    19,    20,
      19,    20,   109,    91,    26,    19,    20,     0,    14,    15,
      16,    19,    20,    34,    26,    35,     3,     4,     5,     6,
       7,     8,    36,   109,    11,    35,    13,     9,    36,    35,
      14,    15,   139,    25,   122,    27,    28,    12,    13,    26,
      32,   101,    27,    28,    29,    30,    31,    25,   175,    27,
      28,    36,   112,    39,    35,    21,    22,    23,    24,   145,
     146,    27,    28,    29,    30,    31,    39,    25,   128,     3,
      36,    37,    38,    21,    22,    23,    24,    32,    25,    27,
      28,    29,    30,    31,    27,    28,    29,    30,    31,    37,
      38,     3,     4,     5,     6,     7,     8,    25,    25,    11,
      10,    13,    27,    28,    29,    30,    31,    29,    30,    31,
      39,    36,    27,    28,    29,    30,    31,    25,    25,    14,
      14,    36,    27,    28,    29,    30,    31,    33,    84,    34,
      86,    16,    88,   193,    32,    17,    12,    18,    40,    40,
      14,    34,    14,    33,    40,     9,    25,    39,    25,    33,
       3,    14,    41,    14,    14,   184,    36,    40,    91,   100,
     150,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    11,    13,    26,
      43,    44,    45,    46,    47,    65,    66,    69,    70,    74,
      75,    76,    79,    80,    84,    85,    87,    88,    25,    27,
      28,    32,     3,     3,     3,     3,    35,    35,    35,    46,
       0,    44,    44,    46,    46,     3,    14,    15,    16,    17,
      18,    35,    55,    57,    58,    60,    63,    67,    68,    46,
      46,    46,    26,    39,    77,    46,    35,    81,    46,    39,
      86,    46,    35,    63,    89,     9,    25,    25,     3,    55,
      59,    25,    49,    25,    48,    25,    50,    25,    51,    63,
       3,    32,    35,    57,    27,    28,    29,    30,    31,    19,
      20,    10,    78,    46,    71,    72,    63,    57,    63,    82,
      71,    57,    36,    39,    90,    14,    14,    33,    16,    32,
      53,    54,    52,    53,    17,    53,    18,    53,    36,    12,
      59,    57,    21,    22,    23,    24,    36,    37,    38,    61,
      57,    57,    57,    57,    57,    64,    64,    46,    74,    40,
      45,    73,    34,    34,    34,    57,    63,    83,    40,    46,
      71,    25,    27,    28,    14,    34,    56,    55,    46,    14,
      33,    57,    62,    63,    63,    39,    73,    36,    36,    40,
       9,    25,    25,    33,     3,    41,    36,    71,    14,    14,
      56,    14,    40,    36,    46
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
        case 5:

/* Line 1455 of yacc.c  */
#line 71 "syntax.y"
    {YYACCEPT;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 76 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 77 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 78 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 79 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 80 "syntax.y"
    {(yyvsp[(1) - (2)].next).next = removePosQuad((yyvsp[(1) - (2)].next).next,currentQuad);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 81 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 82 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 83 "syntax.y"
    {(yyval.next).next = NULL;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 95 "syntax.y"
    {strcpy(typeEns,(yyvsp[(1) - (2)].value));strcpy(idfName,(yyvsp[(2) - (2)].value));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 96 "syntax.y"
    {strcpy(typeEns,(yyvsp[(1) - (2)].value));strcpy(idfName,(yyvsp[(2) - (2)].value));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 97 "syntax.y"
    {strcpy(typeEns,(yyvsp[(1) - (2)].value));strcpy(idfName,(yyvsp[(2) - (2)].value));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 98 "syntax.y"
    {strcpy(typeEns,(yyvsp[(1) - (2)].value));strcpy(idfName,(yyvsp[(2) - (2)].value));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 99 "syntax.y"
    {inserer((yyvsp[(2) - (3)].value),"VARIABLE",(yyvsp[(1) - (3)].value),1,"YES",nb_lines,nb_chars);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 100 "syntax.y"
    {inserer((yyvsp[(2) - (4)].value),"VARIABLE",(yyvsp[(1) - (4)].value),1,"YES",nb_lines,nb_chars);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 101 "syntax.y"
    {inserer((yyvsp[(2) - (4)].value),"VARIABLE",(yyvsp[(1) - (4)].value),1,"YES",nb_lines,nb_chars);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 102 "syntax.y"
    {inserer((yyvsp[(2) - (4)].value),"VARIABLE",(yyvsp[(1) - (4)].value),1,"YES",nb_lines,nb_chars);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 106 "syntax.y"
    { inserer(idfName,"VARIABLE",typeEns,1,"YES",nb_lines,nb_chars); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 108 "syntax.y"
    {inserer(idfName,"TABLEAU",typeEns,atoi((yyvsp[(2) - (3)].value)),"YES",nb_lines,nb_chars);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 113 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 114 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 117 "syntax.y"
    {inserer((yyvsp[(2) - (3)].value),"VARIABLE",typeEns,1,"YES",nb_lines,nb_chars);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 123 "syntax.y"
    { 
                    strcpy(type,checkCompatible((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),nb_lines,nb_chars));
                    (yyval.value)= getTemp(); 
                    inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                    genererQuad("+",(yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),(yyval.value));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 130 "syntax.y"
    { 
                unique = 0; 
                strcpy(type,checkCompatible((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),nb_lines,nb_chars)); 
                (yyval.value)= getTemp(); inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                genererQuad("-",(yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),(yyval.value));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 137 "syntax.y"
    { 
                unique = 0; 
                strcpy(type,checkCompatible((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),nb_lines,nb_chars)); 
                (yyval.value)= getTemp(); 
                inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                genererQuad("*",(yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),(yyval.value));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 145 "syntax.y"
    { 
                 unique = 0; 
                 divisionParZero((yyvsp[(3) - (3)].value),nb_lines,nb_chars);
                 strcpy(type,checkCompatible((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),nb_lines,nb_chars)); 
                 (yyval.value)= getTemp(); 
                 inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                 genererQuad("/",(yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),(yyval.value));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 154 "syntax.y"
    { 
                 unique = 0; 
                 strcpy(type,checkCompatible((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),nb_lines,nb_chars)); 
                 (yyval.value)= getTemp(); 
                 inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                 genererQuad("%",(yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),(yyval.value));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 162 "syntax.y"
    {(yyval.value) = (yyvsp[(2) - (3)].value);unique = 0;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 164 "syntax.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 167 "syntax.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); if(express && unique){inserer(idfName,"VARIABLE","NUMERIC",1,"NO",nb_lines,nb_chars); } express=1;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 168 "syntax.y"
    {  (yyval.value) = (yyvsp[(1) - (1)].value); if(express && unique){inserer(idfName,"VARIABLE","INTEGER",1,"NO",nb_lines,nb_chars); } express=1;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 169 "syntax.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 170 "syntax.y"
    { char tmp [50];
                            snprintf(tmp, sizeof(tmp),"%s[%s]",(yyvsp[(1) - (4)].value),(yyvsp[(3) - (4)].value));
                            strcpy((yyval.value),tmp);
                            checkTableau((yyvsp[(1) - (4)].value),(yyvsp[(3) - (4)].value),nb_lines,nb_chars);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 177 "syntax.y"
    {  (yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 178 "syntax.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 182 "syntax.y"
    {  checkCompatible((yyvsp[(2) - (4)].value),(yyvsp[(4) - (4)].value),nb_lines,nb_chars);
                                                    (yyval.bool).true=NULL;
                                                    (yyval.bool).true = addPosQuad((yyval.bool).true);
                                                    genererQuad((yyvsp[(3) - (4)].value),(yyvsp[(2) - (4)].value),(yyvsp[(4) - (4)].value)," ");
                                                    (yyval.bool).false=NULL;
                                                    (yyval.bool).false = addPosQuad((yyval.bool).false);
                                                    genererQuad("BR","",""," ");
                                                 ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 192 "syntax.y"
    {(yyval.value) = "<";;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 193 "syntax.y"
    {(yyval.value) = ">";;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 194 "syntax.y"
    {(yyval.value) =  (yyvsp[(1) - (1)].value);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 195 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 196 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 197 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 200 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (2)].value);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 204 "syntax.y"
    {(yyvsp[(1) - (4)].bool).true = removePosQuad((yyvsp[(1) - (4)].bool).true,(yyvsp[(3) - (4)].number));
                                    (yyval.bool).true = (yyvsp[(4) - (4)].bool).true;
                                    (yyval.bool).false = fusion((yyvsp[(1) - (4)].bool).false,(yyvsp[(4) - (4)].bool).false); 
                                    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 208 "syntax.y"
    {(yyvsp[(1) - (4)].bool).false = removePosQuad((yyvsp[(1) - (4)].bool).false,(yyvsp[(3) - (4)].number));
                                     (yyval.bool).false = (yyvsp[(4) - (4)].bool).false;
                                     (yyval.bool).true = fusion((yyvsp[(1) - (4)].bool).true,(yyvsp[(4) - (4)].bool).true);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 211 "syntax.y"
    {(yyval.bool) = (yyvsp[(1) - (1)].bool);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 215 "syntax.y"
    {(yyval.number) = currentQuad;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 224 "syntax.y"
    { 
                                        char tmp [50];
                                        snprintf(tmp, sizeof(tmp),"%s[%s]",(yyvsp[(1) - (5)].value),(yyvsp[(3) - (5)].value));
                                        strcpy(idfName,tmp);
                                        checkTableau((yyvsp[(1) - (5)].value),(yyvsp[(3) - (5)].value),nb_lines,nb_chars);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 230 "syntax.y"
    {strcpy(idfName,(yyvsp[(1) - (2)].value));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 234 "syntax.y"
    {   
                    (yyvsp[(1) - (1)].bool).true = removePosQuad((yyvsp[(1) - (1)].bool).true,currentQuad); 
                    genererQuad("<-","TRUE"," ",idfName); 
                    (yyvsp[(1) - (1)].bool).true= addPosQuad((yyvsp[(1) - (1)].bool).true);
                    genererQuad("BR",""," ",""); 

                    (yyvsp[(1) - (1)].bool).false = removePosQuad((yyvsp[(1) - (1)].bool).false,currentQuad);
                    genererQuad("<-","FALSE"," ",idfName);
                    (yyvsp[(1) - (1)].bool).true = removePosQuad((yyvsp[(1) - (1)].bool).true,currentQuad);   

                    express = 0;
                    inserer(idfName,"VARIABLE","LOGICAL",1,"NO",nb_lines,nb_chars);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 247 "syntax.y"
    {genererQuad("<-",(yyvsp[(1) - (1)].value)," ",idfName); unique = 1;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 248 "syntax.y"
    {genererQuad("<-",(yyvsp[(1) - (1)].value)," ",idfName); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 254 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);inserer(idfName,"VARIABLE","CHARACTER",1,"NO",nb_lines,nb_chars);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 255 "syntax.y"
    {(yyval.value) = (yyvsp[(1) - (1)].value);inserer(idfName,"VARIABLE","LOGICAL",1,"NO",nb_lines,nb_chars);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 263 "syntax.y"
    { strcpy(type,checkCompatible((yyvsp[(1) - (4)].value),(yyvsp[(4) - (4)].value),nb_lines,nb_chars)); 
                                (yyval.value)= getTemp(); 
                                inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                genererQuad("+",(yyvsp[(1) - (4)].value),(yyvsp[(4) - (4)].value),(yyval.value));
                                genererQuad((yyvsp[(3) - (4)].value),(yyval.value),"",(yyvsp[(1) - (4)].value));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 270 "syntax.y"
    { 
                                checkTableau((yyvsp[(1) - (7)].value),(yyvsp[(3) - (7)].value),nb_lines,nb_chars);
                                strcpy(type,checkCompatible((yyvsp[(1) - (7)].value),(yyvsp[(7) - (7)].value),nb_lines,nb_chars)); 
                                (yyval.value)= getTemp(); 
                                inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                char tmp [50];
                                snprintf(tmp, sizeof(tmp),"%s[%s]",(yyvsp[(1) - (7)].value),(yyvsp[(3) - (7)].value));
                                genererQuad("+",tmp,(yyvsp[(7) - (7)].value),(yyval.value));
                                genererQuad((yyvsp[(6) - (7)].value),(yyval.value),"",tmp);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 280 "syntax.y"
    { strcpy(type,checkCompatible((yyvsp[(1) - (4)].value),(yyvsp[(4) - (4)].value),nb_lines,nb_chars)); 
                                (yyval.value) = getTemp(); 
                                inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                genererQuad("-",(yyvsp[(1) - (4)].value),(yyvsp[(4) - (4)].value),(yyval.value));
                                genererQuad((yyvsp[(3) - (4)].value),(yyval.value),"",(yyvsp[(1) - (4)].value));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 286 "syntax.y"
    { 
                                checkTableau((yyvsp[(1) - (7)].value),(yyvsp[(3) - (7)].value),nb_lines,nb_chars);
                                strcpy(type,checkCompatible((yyvsp[(1) - (7)].value),(yyvsp[(7) - (7)].value),nb_lines,nb_chars)); 
                                (yyval.value)= getTemp(); 
                                inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                char tmp [50];
                                snprintf(tmp, sizeof(tmp),"%s[%s]",(yyvsp[(1) - (7)].value),(yyvsp[(3) - (7)].value));
                                genererQuad("-",tmp,(yyvsp[(7) - (7)].value),(yyval.value));
                                genererQuad((yyvsp[(6) - (7)].value),(yyval.value),"",tmp);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 299 "syntax.y"
    { (yyval.next) = (yyvsp[(2) - (2)].next);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 305 "syntax.y"
    {(yyval.next)=(yyvsp[(1) - (2)].next);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 306 "syntax.y"
    {(yyval.next).next = NULL;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 312 "syntax.y"
    { 

                                        (yyval.next).next = fusion((yyvsp[(1) - (3)].next).next,(yyvsp[(3) - (3)].next).next);
                                      ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 320 "syntax.y"
    { 
                                  (yyval.next).next = addPosQuad((yyval.next).next); 
                                  genererQuad("BR"," "," "," "); 
                                  (yyvsp[(1) - (2)].bool).false = removePosQuad((yyvsp[(1) - (2)].bool).false,currentQuad);

                                  (yyval.next).next = fusion((yyval.next).next,(yyvsp[(2) - (2)].next).next);
                            ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 328 "syntax.y"
    {
                                                        (yyvsp[(3) - (5)].bool).true = removePosQuad((yyvsp[(3) - (5)].bool).true,currentQuad); 
                                                        (yyval.bool) = (yyvsp[(3) - (5)].bool);
                                                    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 335 "syntax.y"
    {(yyval.next) =(yyvsp[(2) - (3)].next);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 339 "syntax.y"
    { (yyval.next) = (yyvsp[(4) - (5)].next);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 340 "syntax.y"
    { (yyval.next) = (yyvsp[(2) - (2)].next);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 341 "syntax.y"
    { (yyval.next).next = NULL;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 347 "syntax.y"
    {
                                                (yyvsp[(2) - (4)].bool).false = removePosQuad((yyvsp[(2) - (4)].bool).false,(yyvsp[(3) - (4)].next).quad);
                                                (yyvsp[(3) - (4)].next).next = removePosQuad((yyvsp[(3) - (4)].next).next,currentQuad);
                                                ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 354 "syntax.y"
    { strcpy(idfName,(yyvsp[(1) - (3)].value));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 356 "syntax.y"
    {char tmp [50];
                                                        snprintf(tmp, sizeof(tmp),"%s[%s]",(yyvsp[(1) - (6)].value),(yyvsp[(3) - (6)].value)); 
                                                        strcpy(idfName,tmp);
                                                        checkTableau((yyvsp[(1) - (6)].value),(yyvsp[(3) - (6)].value),nb_lines,nb_chars);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 363 "syntax.y"
    { (yyvsp[(2) - (3)].bool).true =  removePosQuad((yyvsp[(2) - (3)].bool).true,currentQuad);
                                 (yyval.bool) = (yyvsp[(2) - (3)].bool);       ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 366 "syntax.y"
    { genererQuad("<-",(yyvsp[(1) - (2)].value),"",idfName);
                                (yyval.next).next = NULL;
                                (yyval.next).next = addPosQuad((yyval.next).next);
                                genererQuad("BR","","","");
                                (yyval.next).quad = currentQuad;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 371 "syntax.y"
    {   
                                (yyval.next).next = NULL;
                                (yyvsp[(1) - (2)].bool).true = removePosQuad((yyvsp[(1) - (2)].bool).true,currentQuad);
                                genererQuad("<-","TRUE","",idfName);
                                (yyval.next).next = addPosQuad((yyval.next).next);
                                genererQuad("BR","","","");

                                (yyvsp[(1) - (2)].bool).false = removePosQuad((yyvsp[(1) - (2)].bool).false,currentQuad);
                                genererQuad("<-","FALSE","",idfName);
                                (yyval.next).next = addPosQuad((yyval.next).next);
                                genererQuad("BR","","","");


                                (yyval.next).quad = currentQuad;

                                ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 389 "syntax.y"
    {            
                                    genererQuad("<-",(yyvsp[(1) - (2)].value),"",idfName); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 392 "syntax.y"
    {  (yyval.next).next = NULL;
                                (yyvsp[(1) - (2)].bool).true = removePosQuad((yyvsp[(1) - (2)].bool).true,currentQuad);
                                genererQuad("<-","TRUE","",idfName);
                                (yyval.next).next = addPosQuad((yyval.next).next);
                                genererQuad("BR","","","");

                                (yyvsp[(1) - (2)].bool).false = removePosQuad((yyvsp[(1) - (2)].bool).false,currentQuad);
                                genererQuad("<-","FALSE","",idfName);
                                (yyval.next).next = addPosQuad((yyval.next).next);
                                genererQuad("BR","","","");

                                (yyval.next).next = removePosQuad((yyval.next).next,currentQuad);
                                ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 409 "syntax.y"
    {
                                       strcpy(type,checkCompatible((yyvsp[(1) - (2)].next).idf,"1",nb_lines,nb_chars)); 
                                       (yyval.value)= getTemp(); 
                                       inserer((yyval.value),"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                       genererQuad("+",(yyvsp[(1) - (2)].next).idf,"1",(yyval.value));
                                       genererQuad("<-",(yyval.value),"",(yyvsp[(1) - (2)].next).idf);
                                       genererQuad("BR","","",intToChar((yyvsp[(1) - (2)].next).quad+1));
                                       (yyvsp[(1) - (2)].next).next = removePosQuad((yyvsp[(1) - (2)].next).next,currentQuad);
                                    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 420 "syntax.y"
    {
                                                            
                                                            genererQuad("<-",(yyvsp[(5) - (9)].value)," ",(yyvsp[(3) - (9)].value));
                                                            (yyval.next).quad = currentQuad;
                                                            genererQuad("<=",(yyvsp[(3) - (9)].value),(yyvsp[(7) - (9)].value),intToChar((yyval.next).quad+3));
                                                            (yyval.next).next = NULL;
                                                            (yyval.next).next = addPosQuad((yyval.next).next);
                                                            genererQuad("BR"," "," "," ");
                                                            (yyval.next).idf = (yyvsp[(3) - (9)].value);

                                                        ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 439 "syntax.y"
    {
                                                        genererQuad("BR"," "," ",intToChar((yyvsp[(1) - (3)].number)+1));
                                                        (yyvsp[(2) - (3)].bool).false = removePosQuad((yyvsp[(2) - (3)].bool).false,currentQuad);
                                                    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 445 "syntax.y"
    {  (yyval.number) = currentQuad;;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 449 "syntax.y"
    { (yyvsp[(1) - (3)].bool).true = removePosQuad((yyvsp[(1) - (3)].bool).true,currentQuad);
                                               
                                                (yyval.bool) = (yyvsp[(1) - (3)].bool);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 455 "syntax.y"
    { (yyval.next)=(yyvsp[(2) - (3)].next);;}
    break;



/* Line 1455 of yacc.c  */
#line 2289 "syntax.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 457 "syntax.y"


int main () 
{
    yyparse();

    if(error && lexical_error){
        
        afficherTS();

        afficherQuads();

        generateCode();
    }

}


void yyerror(char *s){

    printf("Erreur syntaxique a la ligne %d, colonne %d, sur l'entite : %s \n",nb_lines,nb_chars,currentText);
    error = 0;
}

int yywrap()
{}


