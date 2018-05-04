/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CHAR = 258,
     KW_INT = 259,
     KW_FLOAT = 260,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_WHILE = 264,
     KW_FOR = 265,
     KW_READ = 266,
     KW_RETURN = 267,
     KW_PRINT = 268,
     KW_TO = 269,
     OPERATOR_LE = 270,
     OPERATOR_GE = 271,
     OPERATOR_EQ = 272,
     OPERATOR_NE = 273,
     OPERATOR_AND = 274,
     OPERATOR_OR = 275,
     TK_IDENTIFIER = 276,
     LIT_INTEGER = 277,
     LIT_REAL = 278,
     LIT_CHAR = 279,
     LIT_STRING = 280,
     TOKEN_ERROR = 281
   };
#endif
/* Tokens.  */
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_FOR 265
#define KW_READ 266
#define KW_RETURN 267
#define KW_PRINT 268
#define KW_TO 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_REAL 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

#include "ast.c"
extern int getLineNumber();
#include<stdio.h>
#include <stdlib.h>
AST *ast_Geral;
    

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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 12 "parser.y"
{

    struct hash_node *symbol;
    struct ast_node *ast;

}
/* Line 193 of yacc.c.  */
#line 163 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 176 "parser.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
<<<<<<< Updated upstream
/* YYNSTATES -- Number of states.  */
=======
/* YYNRULES -- Number of states.  */
>>>>>>> Stashed changes
#define YYNSTATES  229

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
       2,     2,     2,    27,     2,    42,     2,     2,    45,     2,
      36,    37,    34,    32,    30,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    38,
      28,    31,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
       0,     0,     3,     5,     8,     9,    16,    25,    31,    41,
      43,    49,    55,    61,    70,    77,    86,    93,   102,   109,
     116,   123,   130,   134,   135,   139,   140,   144,   145,   150,
     152,   154,   158,   163,   168,   173,   178,   185,   193,   201,
     209,   217,   223,   225,   227,   230,   232,   234,   236,   239,
     241,   243,   248,   250,   252,   254,   258,   262,   266,   270,
     274,   278,   281,   285,   289,   293,   297,   301,   305,   311,
     315,   317,   319,   321,   323,   326,   329,   332,   333,   336,
     343,   350,   357,   360,   363,   366,   369,   370,   374,   375,
     378,   380,   382,   385,   388,   391,   392
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    48,    -1,    -1,     6,
      36,    56,    37,     7,    52,    -1,     6,    36,    56,    37,
       7,    52,     8,    52,    -1,     9,    36,    56,    37,    52,
      -1,    10,    36,    21,    31,    56,    14,    56,    37,    52,
      -1,    59,    -1,     5,    21,    31,    56,    38,    -1,     3,
      21,    31,    56,    38,    -1,     4,    21,    31,    56,    38,
      -1,     4,    21,    39,    56,    40,    41,    55,    38,    -1,
       4,    21,    39,    56,    40,    38,    -1,     5,    21,    39,
      56,    40,    41,    55,    38,    -1,     5,    21,    39,    56,
      40,    38,    -1,     3,    21,    39,    56,    40,    41,    55,
      38,    -1,     3,    21,    39,    56,    40,    38,    -1,     5,
      42,    21,    31,    56,    38,    -1,     3,    42,    21,    31,
      56,    38,    -1,     4,    42,    21,    31,    56,    38,    -1,
      30,    57,    50,    -1,    -1,    43,    52,    44,    -1,    -1,
      53,    38,    52,    -1,    -1,    53,    38,    53,    52,    -1,
      49,    -1,    51,    -1,    21,    31,    56,    -1,    42,    21,
      31,    56,    -1,    45,    21,    31,    56,    -1,    21,    31,
      42,    56,    -1,    21,    31,    45,    56,    -1,    21,    39,
      56,    40,    31,    56,    -1,    42,    21,    39,    56,    40,
      31,    56,    -1,    45,    21,    39,    56,    40,    31,    56,
      -1,    21,    31,    42,    56,    39,    56,    40,    -1,    21,
      31,    45,    56,    39,    56,    40,    -1,    21,    36,    58,
      50,    37,    -1,    64,    -1,    67,    -1,    12,    56,    -1,
      22,    -1,    23,    -1,    24,    -1,    54,    55,    -1,    54,
      -1,    21,    -1,    21,    39,    56,    40,    -1,    24,    -1,
      23,    -1,    22,    -1,    56,    32,    56,    -1,    56,    33,
      56,    -1,    56,    34,    56,    -1,    56,    35,    56,    -1,
      56,    28,    56,    -1,    56,    29,    56,    -1,    27,    56,
      -1,    56,    15,    56,    -1,    56,    16,    56,    -1,    56,
      17,    56,    -1,    56,    18,    56,    -1,    56,    19,    56,
      -1,    56,    20,    56,    -1,    21,    36,    58,    50,    37,
      -1,    36,    56,    37,    -1,    23,    -1,    24,    -1,    22,
      -1,    21,    -1,    42,    21,    -1,    45,    21,    -1,    57,
      58,    -1,    -1,    60,    51,    -1,     4,    21,    36,    62,
      63,    37,    -1,     5,    21,    36,    62,    63,    37,    -1,
       3,    21,    36,    62,    63,    37,    -1,     4,    21,    -1,
       5,    21,    -1,     3,    21,    -1,    61,    62,    -1,    -1,
      30,    61,    63,    -1,    -1,    13,    66,    -1,    25,    -1,
      21,    -1,    45,    21,    -1,    42,    21,    -1,    65,    66,
      -1,    -1,    11,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    90,    90,    93,    94,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   112,
     113,   114,   117,   118,   120,   122,   127,   128,   129,   130,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   153,   154,   155,   158,   159,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     186,   187,   188,   189,   190,   191,   194,   195,   198,   201,
     202,   203,   206,   207,   208,   210,   211,   213,   214,   218,
     222,   223,   224,   225,   230,   231,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_READ", "KW_RETURN",
  "KW_PRINT", "KW_TO", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_REAL", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR",
  "'!'", "'<'", "'>'", "','", "'='", "'+'", "'-'", "'*'", "'/'", "'('",
  "')'", "';'", "'['", "']'", "':'", "'#'", "'{'", "'}'", "'&'", "$accept",
  "program", "ldec", "dec", "reset", "block", "lcmd", "cmd", "lit",
  "vet_dec", "exp", "func_args", "l_func_args", "func_dec", "func_header",
  "func_par", "l_func_par", "reset_func_par", "print", "pe", "lpe", "read", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    33,    60,    62,
      44,    61,    43,    45,    42,    47,    40,    41,    59,    91,
      93,    58,    35,   123,   125,    38
};
# endif

<<<<<<< Updated upstream
#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  0
=======
/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    65,    65,    66,    66,    67
};
>>>>>>> Stashed changes

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
<<<<<<< Updated upstream
     127,    -2,     9,    10,   -21,     1,     6,    32,  -163,   127,
    -163,    -9,    66,    23,    70,    36,   112,    58,   159,   159,
      68,  -163,  -163,    82,  -163,   159,   118,   159,    22,   159,
     118,   159,    69,   159,   118,   159,    73,    44,  -163,  -163,
    -163,   159,   159,   610,   633,    76,    87,   159,    -4,   225,
      93,   117,  -163,  -163,   102,   115,  -163,  -163,   466,   137,
     138,   145,   118,   141,   182,   159,   490,   141,   208,   159,
     514,   141,   234,   159,     3,   159,   199,   656,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     171,   107,   159,  -163,   724,  -163,  -163,   158,   163,    -4,
    -163,    54,     3,   159,     4,    16,  -163,   164,  -163,  -163,
    -163,  -163,  -163,   118,   154,   106,   538,  -163,   155,   167,
     562,  -163,   175,   197,   586,  -163,  -163,  -163,  -163,   192,
     200,     3,   190,   260,  -163,   199,   199,   199,   199,   212,
     212,   199,   199,    37,    37,   194,  -163,   107,  -163,   703,
    -163,  -163,  -163,   159,   159,   724,   190,   286,   159,   159,
     159,   159,  -163,   151,   141,  -163,  -163,   235,  -163,  -163,
    -163,   235,  -163,  -163,  -163,   235,  -163,  -163,  -163,  -163,
       3,   193,  -163,   231,   159,   416,   441,   218,   229,   724,
     312,   724,   338,  -163,  -163,  -163,  -163,  -163,   235,   227,
     232,   233,   190,  -163,   107,   679,   159,   159,  -163,   159,
     241,   242,  -163,  -163,  -163,  -163,  -163,  -163,   107,   364,
     390,   724,   159,   159,  -163,  -163,  -163,   724,   724
=======
       0,     2,     1,     2,     0,     6,     8,     5,     9,     1,
       5,     5,     5,     8,     6,     8,     6,     8,     6,     6,
       6,     6,     3,     0,     3,     0,     3,     0,     4,     1,
       1,     3,     4,     4,     4,     4,     6,     7,     7,     7,
       7,     5,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     4,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     5,     3,
       1,     1,     1,     1,     2,     2,     2,     0,     2,     6,
       6,     6,     2,     2,     2,     2,     0,     3,     0,     2,
       1,     1,     2,     2,     2,     0,     2
>>>>>>> Stashed changes
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       9,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     3,    25,    78,     0,    86,     0,     0,     0,
      86,     0,     0,     0,    86,     0,     0,    50,    54,    53,
      52,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,    29,    30,     0,     0,    42,    43,     0,     0,
       0,     0,    86,    88,     0,     0,     0,    88,     0,     0,
       0,    88,     0,     0,    77,     0,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,    96,    44,    91,    90,     0,     0,    95,
      89,     0,    77,     0,     0,     0,    24,    25,    11,    84,
      82,    83,    85,     0,     0,     0,     0,    12,     0,     0,
       0,    10,     0,     0,     0,    73,    72,    70,    71,     0,
       0,    77,    23,     0,    69,    62,    63,    64,    65,    66,
      67,    59,    60,    55,    56,    57,    58,    27,     7,     0,
      93,    92,    94,     0,     0,    31,    23,     0,     0,     0,
       0,     0,    26,    27,    88,    81,    18,     0,    20,    79,
      14,     0,    21,    80,    16,     0,    19,    74,    75,    76,
       0,     0,    51,     5,     0,    34,    35,     0,     0,    32,
       0,    33,     0,    28,    87,    45,    46,    47,    49,     0,
       0,     0,    23,    68,    27,     0,     0,     0,    41,     0,
       0,     0,    48,    17,    13,    15,    22,     6,    27,     0,
       0,    36,     0,     0,     8,    39,    40,    37,    38
};

<<<<<<< Updated upstream
  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   272,    20,  -153,   271,   -89,   176,  -163,  -162,
     -19,   104,   -98,  -163,  -163,   172,   -23,   -66,  -163,  -163,
     187,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
=======
/* YYDEFGOTO[NTERM-NUM].  */
>>>>>>> Stashed changes
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    52,   181,    53,    54,    55,   198,   199,
      43,   131,   132,    10,    11,    62,    63,   114,    56,    99,
     100,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
static const yytype_int16 yypact[] =
{
     127,    -2,     9,    10,   -21,     1,     6,    32,  -163,   127,
    -163,    -9,    66,    23,    70,    36,   112,    58,   159,   159,
      68,  -163,  -163,    82,  -163,   159,   118,   159,    22,   159,
     118,   159,    69,   159,   118,   159,    73,    44,  -163,  -163,
    -163,   159,   159,   610,   633,    76,    87,   159,    -4,   225,
      93,   117,  -163,  -163,   102,   115,  -163,  -163,   466,   137,
     138,   145,   118,   141,   182,   159,   490,   141,   208,   159,
     514,   141,   234,   159,     3,   159,   199,   656,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     171,   107,   159,  -163,   724,  -163,  -163,   158,   163,    -4,
    -163,    54,     3,   159,     4,    16,  -163,   164,  -163,  -163,
    -163,  -163,  -163,   118,   154,   106,   538,  -163,   155,   167,
     562,  -163,   175,   197,   586,  -163,  -163,  -163,  -163,   192,
     200,     3,   190,   260,  -163,   199,   199,   199,   199,   212,
     212,   199,   199,    37,    37,   194,  -163,   107,  -163,   703,
    -163,  -163,  -163,   159,   159,   724,   190,   286,   159,   159,
     159,   159,  -163,   151,   141,  -163,  -163,   235,  -163,  -163,
    -163,   235,  -163,  -163,  -163,   235,  -163,  -163,  -163,  -163,
       3,   193,  -163,   231,   159,   416,   441,   218,   229,   724,
     312,   724,   338,  -163,  -163,  -163,  -163,  -163,   235,   227,
     232,   233,   190,  -163,   107,   679,   159,   159,  -163,   159,
     241,   242,  -163,  -163,  -163,  -163,  -163,  -163,   107,   364,
     390,   724,   159,   159,  -163,  -163,  -163,   724,   724
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   272,    20,  -153,   271,   -89,   176,  -163,  -162,
     -19,   104,   -98,  -163,  -163,   172,   -23,   -66,  -163,  -163,
     187,  -163
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      44,   118,   148,   187,   156,   122,    58,    67,    64,   200,
      66,    71,    68,   201,    70,    18,    72,    95,   162,    12,
       9,    96,    76,    77,   125,   126,   127,   128,    94,     9,
      14,    16,    21,   179,    23,   158,   212,    19,    97,   112,
      13,    98,    20,   159,    28,   129,   116,   160,   130,   216,
     120,    15,    17,    65,   124,   161,   133,    32,   183,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    88,    89,   149,   193,    37,    38,    39,    40,    36,
      74,    41,   155,    75,   157,     1,     2,     3,     4,    45,
      42,     5,     6,    46,    47,    48,   153,    25,   194,   154,
      69,    29,    26,    49,    73,    27,    30,    92,    93,    31,
       1,     2,     3,     4,   104,   217,     5,     6,    46,    47,
      48,    59,    60,    61,    50,    23,   -27,    51,    49,   224,
       1,     2,     3,     4,   185,   186,     5,     6,   105,   189,
     190,   191,   192,    33,   166,   -25,   106,   167,    34,    50,
      23,    35,    51,   107,     1,     2,     3,     4,   109,   110,
       5,     6,    46,    47,    48,   205,   111,     1,     2,     3,
       4,   113,    49,     5,     6,    46,    47,    48,   147,   150,
      37,    38,    39,    40,   151,    49,    41,   219,   220,   107,
     221,   165,   169,    50,    23,    42,    51,    78,    79,    80,
      81,    82,    83,   227,   228,   170,    50,    23,   171,    51,
      84,    85,   173,   177,    86,    87,    88,    89,    82,    83,
     180,   178,   115,    78,    79,    80,    81,    82,    83,    89,
     203,    86,    87,    88,    89,   174,    84,    85,   175,   204,
      86,    87,    88,    89,    86,    87,    88,    89,   119,    78,
      79,    80,    81,    82,    83,   208,   101,   195,   196,   197,
     209,   102,    84,    85,   103,   213,    86,    87,    88,    89,
     214,   215,   222,   223,   123,    78,    79,    80,    81,    82,
      83,    22,    24,   163,   202,   164,   152,     0,    84,    85,
       0,     0,    86,    87,    88,    89,     0,     0,     0,     0,
     182,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,     0,     0,     0,     0,   188,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,    86,    87,    88,    89,     0,     0,
       0,     0,   210,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
      86,    87,    88,    89,     0,     0,     0,     0,   211,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,    86,    87,    88,    89,
       0,     0,     0,     0,   225,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,    86,    87,    88,    89,     0,     0,     0,     0,
     226,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,     0,     0,     0,   206,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,    86,    87,    88,    89,     0,     0,     0,
     207,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,     0,     0,   108,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,    86,    87,    88,    89,     0,     0,   117,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,    86,    87,    88,    89,
       0,     0,   121,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
      86,    87,    88,    89,     0,     0,   168,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,    86,    87,    88,    89,     0,     0,
     172,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,     0,     0,   176,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,    86,    87,    88,    89,     0,    90,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,    86,    87,    88,    89,     0,
      91,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,     0,   134,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,    86,    87,    88,    89,     0,   218,   184,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,    86,    87,    88,    89,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
      19,    67,    91,   156,   102,    71,    25,    30,    27,   171,
      29,    34,    31,   175,    33,    36,    35,    21,   107,    21,
       0,    25,    41,    42,    21,    22,    23,    24,    47,     9,
      21,    21,     0,   131,    43,    31,   198,    36,    42,    62,
      42,    45,    36,    39,    21,    42,    65,    31,    45,   202,
      69,    42,    42,    31,    73,    39,    75,    21,   147,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    34,    35,    92,   163,    21,    22,    23,    24,    21,
      36,    27,   101,    39,   103,     3,     4,     5,     6,    21,
      36,     9,    10,    11,    12,    13,    42,    31,   164,    45,
      31,    31,    36,    21,    31,    39,    36,    31,    21,    39,
       3,     4,     5,     6,    21,   204,     9,    10,    11,    12,
      13,     3,     4,     5,    42,    43,    44,    45,    21,   218,
       3,     4,     5,     6,   153,   154,     9,    10,    21,   158,
     159,   160,   161,    31,    38,    38,    44,    41,    36,    42,
      43,    39,    45,    38,     3,     4,     5,     6,    21,    21,
       9,    10,    11,    12,    13,   184,    21,     3,     4,     5,
       6,    30,    21,     9,    10,    11,    12,    13,     7,    21,
      21,    22,    23,    24,    21,    21,    27,   206,   207,    38,
     209,    37,    37,    42,    43,    36,    45,    15,    16,    17,
      18,    19,    20,   222,   223,    38,    42,    43,    41,    45,
      28,    29,    37,    21,    32,    33,    34,    35,    19,    20,
      30,    21,    40,    15,    16,    17,    18,    19,    20,    35,
      37,    32,    33,    34,    35,    38,    28,    29,    41,     8,
      32,    33,    34,    35,    32,    33,    34,    35,    40,    15,
      16,    17,    18,    19,    20,    37,    31,    22,    23,    24,
      31,    36,    28,    29,    39,    38,    32,    33,    34,    35,
      38,    38,    31,    31,    40,    15,    16,    17,    18,    19,
      20,     9,    11,   107,   180,   113,    99,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    38,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,    35,
      -1,    -1,    38,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    38,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      38,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    37,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    35,    -1,
      37,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    37,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    34,    35,    -1,    37,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    35,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    47,    48,    49,
      59,    60,    21,    42,    21,    42,    21,    42,    36,    36,
      36,     0,    48,    43,    51,    31,    36,    39,    21,    31,
      36,    39,    21,    31,    36,    39,    21,    21,    22,    23,
      24,    27,    36,    56,    56,    21,    11,    12,    13,    21,
      42,    45,    49,    51,    52,    53,    64,    67,    56,     3,
       4,     5,    61,    62,    56,    31,    56,    62,    56,    31,
      56,    62,    56,    31,    36,    39,    56,    56,    15,    16,
      17,    18,    19,    20,    28,    29,    32,    33,    34,    35,
      37,    37,    31,    21,    56,    21,    25,    42,    45,    65,
      66,    31,    36,    39,    21,    21,    44,    38,    38,    21,
      21,    21,    62,    30,    63,    40,    56,    38,    63,    40,
      56,    38,    63,    40,    56,    21,    22,    23,    24,    42,
      45,    57,    58,    56,    37,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,     7,    52,    56,
      21,    21,    66,    42,    45,    56,    58,    56,    31,    39,
      31,    39,    52,    53,    61,    37,    38,    41,    38,    37,
      38,    41,    38,    37,    38,    41,    38,    21,    21,    58,
      30,    50,    40,    52,    14,    56,    56,    50,    40,    56,
      56,    56,    56,    52,    63,    22,    23,    24,    54,    55,
      55,    55,    57,    37,     8,    56,    39,    39,    37,    31,
      40,    40,    55,    38,    38,    38,    50,    52,    37,    56,
      56,    56,    31,    31,    52,    40,    40,    56,    56
<<<<<<< Updated upstream
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    65,    65,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     8,     5,     9,     1,
       5,     5,     5,     8,     6,     8,     6,     8,     6,     6,
       6,     6,     3,     0,     3,     0,     3,     0,     4,     1,
       1,     3,     4,     4,     4,     4,     6,     7,     7,     7,
       7,     5,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     4,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     5,     3,
       1,     1,     1,     1,     2,     2,     2,     0,     2,     6,
       6,     6,     2,     2,     2,     2,     0,     3,     0,     2,
       1,     1,     2,     2,     2,     0,     2
};
=======
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0
>>>>>>> Stashed changes

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
<<<<<<< Updated upstream
#line 90 "parser.y" /* yacc.c:1646  */
    {ast_Geral = (yyvsp[0].ast);}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_DEC,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0);}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_IF_THEN, 0, (yyvsp[-3].ast), (yyvsp[0].ast), 0, 0); }
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_IF_THEN_ELSE, 0, (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_IF_THEN, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_FOR_TO, (yyvsp[-6].symbol), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0);}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0);}
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0);}
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_1_INT,(yyvsp[-6].symbol),(yyvsp[-4].ast),0,0,0);}
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_2_INT,(yyvsp[-4].symbol),(yyvsp[-2].ast),0,0,0);}
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_1_FLOAT,(yyvsp[-6].symbol),(yyvsp[-4].ast),0,0,0);}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_2_FLOAT,(yyvsp[-4].symbol),(yyvsp[-2].ast),0,0,0);}
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_1_CHAR,(yyvsp[-6].symbol),(yyvsp[-4].ast),0,0,0);}
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_2_CHAR,(yyvsp[-4].symbol),(yyvsp[-2].ast),0,0,0);}
#line 1589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_PTR_FLOAT,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0);}
#line 1595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_PTR_CHAR,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0);}
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE_PTR_INT,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0);}
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 117 "parser.y" /* yacc.c:1646  */
    {(AST_FUNC_RESET, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LCMD, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LCMD, 0, (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast), 0);}
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_ATRIBUTION,(yyvsp[-2].symbol),(yyvsp[0].ast), 0,0,0);}
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_TO_PTR_ATRIBUTION,(yyvsp[-2].symbol), (yyvsp[0].ast),0,0,0);}
#line 1667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_TO_END_ATRIBUTION,(yyvsp[-2].symbol), (yyvsp[0].ast),0,0,0);}
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_PTR_ATRIBUTION,(yyvsp[-3].symbol),(yyvsp[0].ast),0 ,0,0);}
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_END_ATRIBUTION,(yyvsp[-3].symbol),(yyvsp[0].ast), 0,0,0);}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VEC_ATRIBUTION,(yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0 ,0);}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_TO_PTR_VEC_ATRIBUTION,(yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0 ,0);}
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 144 "parser.y" /* yacc.c:1646  */
    {astCreate(AST_TO_END_VEC_ATRIBUTION,(yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0, 0);}
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 145 "parser.y" /* yacc.c:1646  */
    {astCreate(AST_PTR_VEC_ATRIBUTION,(yyvsp[-6].symbol),(yyvsp[-3].ast),(yyvsp[-1].ast),0, 0);}
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 146 "parser.y" /* yacc.c:1646  */
    {astCreate(AST_END_VEC_ATRIBUTION, (yyvsp[-6].symbol),(yyvsp[-3].ast),(yyvsp[-1].ast),0,0);}
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 147 "parser.y" /* yacc.c:1646  */
    {astCreate(AST_FUNCTIONCALL,(yyvsp[-4].symbol),(yyvsp[-2].ast),(yyvsp[-1].ast),0,0);}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 150 "parser.y" /* yacc.c:1646  */
    {astCreate(AST_RETURN,0,(yyvsp[0].ast),0,0,0);}
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 153 "parser.y" /* yacc.c:1646  */
    {(AST_INT, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 154 "parser.y" /* yacc.c:1646  */
    {(AST_FLOAT, (yyvsp[0].symbol),0, 0, 0, 0); }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 155 "parser.y" /* yacc.c:1646  */
    {(AST_CHAR, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[0].symbol), 0,  0, 0, 0); }
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(READ_VEC, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0); }
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL,(yyvsp[0].symbol), 0,  0, 0, 0); }
#line 1781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[0].symbol), 0,  0, 0, 0); }
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_MULT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_GT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_NOT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_NE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_FUNCTIONCALL, (yyvsp[-4].symbol), (yyvsp[-2].ast), (yyvsp[-1].ast),0,  0); }
#line 1871 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PARENTHESES, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1901 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PTR, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_END, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_ARGL_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1925 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1931 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_INT, 0, (yyvsp[-2].ast), (yyvsp[-1].ast), 0, 0); }
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_FLOAT, 0, (yyvsp[-2].ast), (yyvsp[-1].ast), 0, 0); }
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_CHAR, 0, (yyvsp[-2].ast), (yyvsp[-1].ast), 0, 0); }
#line 1949 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_PAR_INT, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_PAR_FLOAT, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_PAR_CHAR,(yyvsp[0].symbol), 0,  0, 0, 0); }
#line 1967 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_PAR_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNC_PAR, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_PRINT_LIST, 0, 0, (yyvsp[0].ast), 0, 0); }
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_VAR_PRINT, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 2003 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_VAR_PRINT,(yyvsp[0].symbol), 0,  0, 0, 0); }
#line 2009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_VAR_END, (yyvsp[0].symbol),0,  0, 0, 0); }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_VAR_PTR, (yyvsp[0].symbol), 0,  0, 0, 0); }
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_PRINT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 2027 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_READ, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 2039 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2043 "parser.tab.c" /* yacc.c:1646  */
=======
#line 90 "parser.y"
    {ast = (yyvsp[(1) - (1)].ast);;}
    break;

  case 3:
#line 93 "parser.y"
    {(yyval.ast) = astCreate(AST_DEC,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);;}
    break;

  case 4:
#line 94 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 5:
#line 97 "parser.y"
    { (yyval.ast) = astCreate(AST_IF_THEN, 0, (yyvsp[(3) - (6)].ast), (yyvsp[(6) - (6)].ast), 0, 0); ;}
    break;

  case 6:
#line 98 "parser.y"
    { (yyval.ast) = astCreate(AST_IF_THEN_ELSE, 0, (yyvsp[(3) - (8)].ast), (yyvsp[(6) - (8)].ast), (yyvsp[(8) - (8)].ast), 0); ;}
    break;

  case 7:
#line 99 "parser.y"
    { (yyval.ast) = astCreate(AST_IF_THEN, 0, (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast), 0, 0); ;}
    break;

  case 8:
#line 100 "parser.y"
    { (yyval.ast) = astCreate(AST_FOR_TO, (yyvsp[(3) - (9)].symbol), (yyvsp[(5) - (9)].ast), (yyvsp[(7) - (9)].ast), (yyvsp[(9) - (9)].ast), 0); ;}
    break;

  case 9:
#line 101 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 10:
#line 102 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[(2) - (5)].symbol),(yyvsp[(4) - (5)].ast),0,0,0);;}
    break;

  case 11:
#line 103 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[(2) - (5)].symbol),(yyvsp[(4) - (5)].ast),0,0,0);;}
    break;

  case 12:
#line 104 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[(2) - (5)].symbol),(yyvsp[(4) - (5)].ast),0,0,0);;}
    break;

  case 13:
#line 105 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_1_INT,(yyvsp[(2) - (8)].symbol),(yyvsp[(4) - (8)].ast),0,0,0);;}
    break;

  case 14:
#line 106 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_2_INT,(yyvsp[(2) - (6)].symbol),(yyvsp[(4) - (6)].ast),0,0,0);;}
    break;

  case 15:
#line 107 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_1_FLOAT,(yyvsp[(2) - (8)].symbol),(yyvsp[(4) - (8)].ast),0,0,0);;}
    break;

  case 16:
#line 108 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_2_FLOAT,(yyvsp[(2) - (6)].symbol),(yyvsp[(4) - (6)].ast),0,0,0);;}
    break;

  case 17:
#line 109 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_1_CHAR,(yyvsp[(2) - (8)].symbol),(yyvsp[(4) - (8)].ast),0,0,0);;}
    break;

  case 18:
#line 110 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_VEC_2_CHAR,(yyvsp[(2) - (6)].symbol),(yyvsp[(4) - (6)].ast),0,0,0);;}
    break;

  case 19:
#line 112 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_PTR_FLOAT,(yyvsp[(3) - (6)].symbol),(yyvsp[(5) - (6)].ast),0,0,0);;}
    break;

  case 20:
#line 113 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_PTR_CHAR,(yyvsp[(3) - (6)].symbol),(yyvsp[(5) - (6)].ast),0,0,0);;}
    break;

  case 21:
#line 114 "parser.y"
    {(yyval.ast) = astCreate(AST_VARIABLE_PTR_INT,(yyvsp[(3) - (6)].symbol),(yyvsp[(5) - (6)].ast),0,0,0);;}
    break;

  case 22:
#line 117 "parser.y"
    {(AST_FUNC_RESET, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 23:
#line 118 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 24:
#line 120 "parser.y"
    { (yyval.ast) = astCreate(AST_BLOCK, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0); ;}
    break;

  case 25:
#line 122 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 26:
#line 127 "parser.y"
    { (yyval.ast) = astCreate(AST_LCMD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0);;}
    break;

  case 27:
#line 128 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 28:
#line 129 "parser.y"
    { (yyval.ast) = astCreate(AST_LCMD, 0, (yyvsp[(1) - (4)].ast), (yyvsp[(3) - (4)].ast), (yyvsp[(4) - (4)].ast), 0);;}
    break;

  case 29:
#line 130 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 31:
#line 137 "parser.y"
    {(yyval.ast) = astCreate(AST_ATRIBUTION,(yyvsp[(1) - (3)].symbol),(yyvsp[(3) - (3)].ast), 0,0,0);;}
    break;

  case 32:
#line 138 "parser.y"
    {(yyval.ast) = astCreate(AST_TO_PTR_ATRIBUTION,(yyvsp[(2) - (4)].symbol), (yyvsp[(4) - (4)].ast),0,0,0);;}
    break;

  case 33:
#line 139 "parser.y"
    {(yyval.ast) = astCreate(AST_TO_END_ATRIBUTION,(yyvsp[(2) - (4)].symbol), (yyvsp[(4) - (4)].ast),0,0,0);;}
    break;

  case 34:
#line 140 "parser.y"
    {(yyval.ast) = astCreate(AST_PTR_ATRIBUTION,(yyvsp[(1) - (4)].symbol),(yyvsp[(4) - (4)].ast),0 ,0,0);;}
    break;

  case 35:
#line 141 "parser.y"
    {(yyval.ast) = astCreate(AST_END_ATRIBUTION,(yyvsp[(1) - (4)].symbol),(yyvsp[(4) - (4)].ast), 0,0,0);;}
    break;

  case 36:
#line 142 "parser.y"
    {(yyval.ast) = astCreate(AST_VEC_ATRIBUTION,(yyvsp[(1) - (6)].symbol),(yyvsp[(3) - (6)].ast),(yyvsp[(6) - (6)].ast),0 ,0);;}
    break;

  case 37:
#line 143 "parser.y"
    {(yyval.ast) = astCreate(AST_TO_PTR_VEC_ATRIBUTION,(yyvsp[(2) - (7)].symbol),(yyvsp[(4) - (7)].ast),(yyvsp[(7) - (7)].ast),0 ,0);;}
    break;

  case 38:
#line 144 "parser.y"
    {astCreate(AST_TO_END_VEC_ATRIBUTION,(yyvsp[(2) - (7)].symbol),(yyvsp[(4) - (7)].ast),(yyvsp[(7) - (7)].ast),0, 0);;}
    break;

  case 39:
#line 145 "parser.y"
    {astCreate(AST_PTR_VEC_ATRIBUTION,(yyvsp[(1) - (7)].symbol),(yyvsp[(4) - (7)].ast),(yyvsp[(6) - (7)].ast),0, 0);;}
    break;

  case 40:
#line 146 "parser.y"
    {astCreate(AST_END_VEC_ATRIBUTION, (yyvsp[(1) - (7)].symbol),(yyvsp[(4) - (7)].ast),(yyvsp[(6) - (7)].ast),0,0);;}
    break;

  case 41:
#line 147 "parser.y"
    {astCreate(AST_FUNCTIONCALL,(yyvsp[(1) - (5)].symbol),(yyvsp[(3) - (5)].ast),(yyvsp[(4) - (5)].ast),0,0);;}
    break;

  case 42:
#line 148 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 43:
#line 149 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 44:
#line 150 "parser.y"
    {astCreate(AST_RETURN,0,(yyvsp[(2) - (2)].ast),0,0,0);;}
    break;

  case 45:
#line 153 "parser.y"
    {(AST_INT, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 46:
#line 154 "parser.y"
    {(AST_FLOAT, (yyvsp[(1) - (1)].symbol),0, 0, 0, 0); ;}
    break;

  case 47:
#line 155 "parser.y"
    {(AST_CHAR, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 50:
#line 164 "parser.y"
    { (yyval.ast) = astCreate(AST_VARIABLE,(yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); ;}
    break;

  case 51:
#line 165 "parser.y"
    { (yyval.ast) = astCreate(READ_VEC, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].ast), 0, 0, 0); ;}
    break;

  case 52:
#line 166 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 53:
#line 167 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL,(yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); ;}
    break;

  case 54:
#line 168 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); ;}
    break;

  case 55:
#line 169 "parser.y"
    { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 56:
#line 170 "parser.y"
    { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 57:
#line 171 "parser.y"
    { (yyval.ast) = astCreate(AST_MULT, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 58:
#line 172 "parser.y"
    { (yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 59:
#line 173 "parser.y"
    { (yyval.ast) = astCreate(AST_LT, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 60:
#line 174 "parser.y"
    { (yyval.ast) = astCreate(AST_GT, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 61:
#line 175 "parser.y"
    { (yyval.ast) = astCreate(AST_NOT, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0); ;}
    break;

  case 62:
#line 176 "parser.y"
    { (yyval.ast) = astCreate(AST_LE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 63:
#line 177 "parser.y"
    { (yyval.ast) = astCreate(AST_GE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 64:
#line 178 "parser.y"
    { (yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 65:
#line 179 "parser.y"
    { (yyval.ast) = astCreate(AST_NE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 66:
#line 180 "parser.y"
    { (yyval.ast) = astCreate(AST_AND, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 67:
#line 181 "parser.y"
    { (yyval.ast) = astCreate(AST_OR, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 68:
#line 182 "parser.y"
    { (yyval.ast) = astCreate(AST_FUNCTIONCALL, (yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].ast), (yyvsp[(4) - (5)].ast),0,  0); ;}
    break;

  case 69:
#line 183 "parser.y"
    { (yyval.ast) = astCreate(AST_PARENTHESES, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0); ;}
    break;

  case 70:
#line 186 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 71:
#line 187 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 72:
#line 188 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 73:
#line 189 "parser.y"
    { (yyval.ast) = astCreate(SYMBOL, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 74:
#line 190 "parser.y"
    { (yyval.ast) = astCreate(AST_PTR, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0);;}
    break;

  case 75:
#line 191 "parser.y"
    { (yyval.ast) = astCreate(AST_END, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0);;}
    break;

  case 76:
#line 194 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_ARGL_LIST, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); ;}
    break;

  case 77:
#line 195 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 78:
#line 198 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_BLOCK, 0, (yyvsp[(1) - (2)].ast), 0, 0, 0); ;}
    break;

  case 79:
#line 201 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_INT, 0, (yyvsp[(4) - (6)].ast), (yyvsp[(5) - (6)].ast), 0, 0); ;}
    break;

  case 80:
#line 202 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_FLOAT, 0, (yyvsp[(4) - (6)].ast), (yyvsp[(5) - (6)].ast), 0, 0); ;}
    break;

  case 81:
#line 203 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_CHAR, 0, (yyvsp[(4) - (6)].ast), (yyvsp[(5) - (6)].ast), 0, 0); ;}
    break;

  case 82:
#line 206 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_PAR_INT, (yyvsp[(2) - (2)].symbol),0,  0, 0, 0); ;}
    break;

  case 83:
#line 207 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_PAR_FLOAT, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); ;}
    break;

  case 84:
#line 208 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_HEADER_CHAR,(yyvsp[(2) - (2)].symbol), 0,  0, 0, 0); ;}
    break;

  case 85:
#line 210 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_PAR_LIST, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); ;}
    break;

  case 86:
#line 211 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 87:
#line 213 "parser.y"
    {(yyval.ast) = astCreate(AST_FUNC_PAR, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); ;}
    break;

  case 88:
#line 214 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 89:
#line 218 "parser.y"
    {(yyval.ast) = astCreate(AST_PRINT_LIST, 0, 0, (yyvsp[(2) - (2)].ast), 0, 0); ;}
    break;

  case 90:
#line 222 "parser.y"
    { (yyval.ast) = astCreate(AST_VAR_PRINT, (yyvsp[(1) - (1)].symbol),0,  0, 0, 0); ;}
    break;

  case 91:
#line 223 "parser.y"
    { (yyval.ast) = astCreate(AST_VAR_PRINT,(yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); ;}
    break;

  case 92:
#line 224 "parser.y"
    { (yyval.ast) = astCreate(AST_VAR_END, (yyvsp[(2) - (2)].symbol),0,  0, 0, 0); ;}
    break;

  case 93:
#line 225 "parser.y"
    { (yyval.ast) = astCreate(AST_VAR_PTR, (yyvsp[(2) - (2)].symbol), 0,  0, 0, 0); ;}
    break;

  case 94:
#line 230 "parser.y"
    {(yyval.ast) = astCreate(AST_PRINT, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); ;}
    break;

  case 95:
#line 231 "parser.y"
    {(yyval.ast) = 0;;}
    break;

  case 96:
#line 233 "parser.y"
    { (yyval.ast) = astCreate(AST_READ, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2125 "parser.tab.c"
>>>>>>> Stashed changes
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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
<<<<<<< Updated upstream
#line 235 "parser.y" /* yacc.c:1906  */
=======


#line 235 "parser.y"
>>>>>>> Stashed changes

int yyerror(int code){
    printf("O analisador encontrou um erro na linha %d\n",getLineNumber());
    exit(3);

}
#include "main.c"

