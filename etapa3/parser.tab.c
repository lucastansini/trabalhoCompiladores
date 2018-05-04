/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 3 "parser.y" /* yacc.c:355  */

    #inclde<ast.h>
    struct hash_node *symbol;
    struct ast_node *ast;
    

#line 141 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 76 "parser.y" /* yacc.c:358  */

extern int getLineNumber();
#include<stdio.h>
#include <stdlib.h>
#include "AST.h"

    

#line 166 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    88,    89,    92,    93,    94,    95,    96,
      97,    98,    99,   107,   111,   112,   114,   116,   121,   122,
     123,   124,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   147,   148,   149,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     179,   180,   181,   182,   183,   184,   187,   188,   191,   194,
     197,   199,   200,   202,   203,   207,   211,   212,   213,   214,
     219,   220,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "program", "ldec", "dec", "reset", "block", "lcmd", "cmd", "type", "exp",
  "func_args", "l_func_args", "func_dec", "func_header", "func_par",
  "l_func_par", "reset_func_par", "print", "pe", "lpe", "read", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    33,    60,    62,
      44,    61,    43,    45,    42,    47,    40,    41,    59,    91,
      93,    58,    35,   123,   125,    38
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -26,   -13,   -12,  -126,  -126,  -126,    34,  -126,    74,
     -16,  -126,    22,    -5,    -5,    46,  -126,  -126,    18,    50,
      79,  -126,    43,  -126,  -126,  -126,    -5,    -5,   372,   395,
      47,   120,   131,    55,    56,    -5,   -10,    89,    66,    72,
    -126,  -126,    60,    67,  -126,  -126,   -15,    -5,   225,   418,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    87,   128,    -5,    69,    70,    73,    91,   131,
      83,    96,  -126,   486,  -126,  -126,    98,   105,   -10,  -126,
     357,   -15,    -5,   -11,    24,  -126,   204,  -126,  -126,  -126,
    -126,   112,   114,   -15,   106,    41,  -126,   225,   225,   225,
     225,    97,    97,   225,   225,   -31,   -31,   121,  -126,   128,
    -126,   465,  -126,  -126,  -126,  -126,  -126,   131,   110,   122,
    -126,  -126,  -126,    -5,    -5,   486,   106,   165,    -5,    -5,
      -5,    -5,  -126,   166,  -126,  -126,  -126,   -15,   124,  -126,
     151,    -5,    83,  -126,  -126,   313,   338,   125,   132,   486,
     203,   486,   235,  -126,   106,  -126,   128,   441,  -126,    -5,
      -5,  -126,    -5,   133,   134,  -126,  -126,   128,   261,   287,
     486,    -5,    -5,  -126,  -126,  -126,   486,   486
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,    37,    38,    39,     0,     2,     4,
       0,     9,    17,     0,     0,     0,     1,     3,     0,     0,
      17,    68,    40,    44,    43,    42,     0,     0,     0,     0,
       0,     0,    72,     0,     0,     0,    81,     0,     0,     0,
      21,    22,     0,     0,    34,    35,    67,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,    72,
      74,     0,    82,    36,    77,    76,     0,     0,    81,    75,
       0,    67,     0,     0,     0,    16,    17,    63,    62,    60,
      61,     0,     0,    67,    15,     0,    59,    52,    53,    54,
      55,    56,    57,    49,    50,    45,    46,    47,    48,    19,
       7,     0,    12,    10,    11,    70,    71,     0,     0,     0,
      79,    78,    80,     0,     0,    23,    15,     0,     0,     0,
       0,     0,    18,    19,    64,    65,    66,     0,     0,    41,
       5,     0,    74,    69,    13,    26,    27,     0,     0,    24,
       0,    25,     0,    20,    15,    58,    19,     0,    73,     0,
       0,    33,     0,     0,     0,    14,     6,    19,     0,     0,
      28,     0,     0,     8,    31,    32,    29,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   158,    53,  -125,   156,   -61,    88,   -18,   -14,
      32,   -29,  -126,  -126,    75,   117,    49,  -126,  -126,   118,
    -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    40,   138,    41,    42,    43,    10,    28,
      93,    94,    11,    12,    69,    70,   118,    44,    78,    79,
      45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   147,   110,    60,    61,    18,    87,    88,    89,    90,
      13,    74,    48,    49,    68,    75,    22,    23,    24,    25,
     128,    73,    26,    14,    15,   132,    19,    91,   129,   165,
      92,    27,    76,    95,    16,    77,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   140,    31,
     111,    68,   126,     9,    32,   130,    50,    51,    52,    53,
      54,    55,     9,   131,   136,    20,   125,    30,   127,    56,
      57,    33,   153,    58,    59,    60,    61,    72,    64,    46,
       1,   139,    47,     2,     3,     1,    71,    83,     2,     3,
      34,    35,    36,    84,   109,   166,     4,     5,     6,    68,
      37,     4,     5,     6,    85,    86,   173,   112,   113,   145,
     146,   114,   115,   117,   149,   150,   151,   152,   119,   120,
      80,    38,    20,   -19,    39,    81,   121,   157,    82,    58,
      59,    60,    61,   134,     1,   135,   137,     2,     3,    34,
      35,    36,    65,    66,    67,   168,   169,   143,   170,    37,
       4,     5,     6,     4,     5,     6,    61,   176,   177,   156,
     144,   155,   161,   162,   171,   172,   -17,    17,    21,   154,
      38,    20,     1,    39,   133,     2,     3,    34,    35,    36,
      50,    51,    52,    53,    54,    55,   116,    37,     4,     5,
       6,   158,   142,    56,    57,     0,   122,    58,    59,    60,
      61,     0,     0,     0,    86,   148,     0,     0,    38,    20,
       1,    39,     0,     2,     3,    34,    35,    36,    50,    51,
      52,    53,    54,    55,     0,    37,     4,     5,     6,     0,
       0,    56,    57,     0,     0,    58,    59,    60,    61,     0,
       0,     0,     0,   163,    54,    55,    38,    20,     0,    39,
      50,    51,    52,    53,    54,    55,     0,    58,    59,    60,
      61,     0,     0,    56,    57,     0,     0,    58,    59,    60,
      61,     0,     0,     0,     0,   164,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    56,
      57,     0,     0,    58,    59,    60,    61,     0,     0,     0,
       0,   174,    50,    51,    52,    53,    54,    55,     0,     0,
       0,     0,     0,     0,     0,    56,    57,     0,     0,    58,
      59,    60,    61,     0,     0,     0,     0,   175,    50,    51,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,    56,    57,     0,     0,    58,    59,    60,    61,     0,
       0,     0,   159,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     0,
      58,    59,    60,    61,     0,     0,     0,   160,    22,    23,
      24,    25,     0,     0,    26,     0,     0,    50,    51,    52,
      53,    54,    55,    27,     0,     0,     0,     0,     0,   123,
      56,    57,   124,     0,    58,    59,    60,    61,     0,    62,
      50,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,    56,    57,     0,     0,    58,    59,    60,
      61,     0,    63,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     0,
      58,    59,    60,    61,     0,    96,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    56,
      57,     0,     0,    58,    59,    60,    61,     0,   167,   141,
      50,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,    56,    57,     0,     0,    58,    59,    60,
      61,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     0,    58,    59,
      60,    61
};

static const yytype_int16 yycheck[] =
{
      14,   126,    63,    34,    35,    21,    21,    22,    23,    24,
      36,    21,    26,    27,    32,    25,    21,    22,    23,    24,
      31,    35,    27,    36,    36,    86,    42,    42,    39,   154,
      45,    36,    42,    47,     0,    45,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   109,    31,
      64,    69,    81,     0,    36,    31,    15,    16,    17,    18,
      19,    20,     9,    39,    93,    43,    80,    21,    82,    28,
      29,    21,   133,    32,    33,    34,    35,    21,    31,    36,
       6,    40,    39,     9,    10,     6,    31,    21,     9,    10,
      11,    12,    13,    21,     7,   156,    22,    23,    24,   117,
      21,    22,    23,    24,    44,    38,   167,    38,    38,   123,
     124,    38,    21,    30,   128,   129,   130,   131,    22,    21,
      31,    42,    43,    44,    45,    36,    21,   141,    39,    32,
      33,    34,    35,    21,     6,    21,    30,     9,    10,    11,
      12,    13,    22,    23,    24,   159,   160,    37,   162,    21,
      22,    23,    24,    22,    23,    24,    35,   171,   172,     8,
      38,    37,    37,    31,    31,    31,    38,     9,    12,   137,
      42,    43,     6,    45,    86,     9,    10,    11,    12,    13,
      15,    16,    17,    18,    19,    20,    69,    21,    22,    23,
      24,   142,   117,    28,    29,    -1,    78,    32,    33,    34,
      35,    -1,    -1,    -1,    38,    40,    -1,    -1,    42,    43,
       6,    45,    -1,     9,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    20,    -1,    21,    22,    23,    24,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    19,    20,    42,    43,    -1,    45,
      15,    16,    17,    18,    19,    20,    -1,    32,    33,    34,
      35,    -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    15,    16,    17,
      18,    19,    20,    36,    -1,    -1,    -1,    -1,    -1,    42,
      28,    29,    45,    -1,    32,    33,    34,    35,    -1,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,
      35,    -1,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    37,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    35,    -1,    37,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,
      35,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    10,    22,    23,    24,    47,    48,    49,
      54,    58,    59,    36,    36,    36,     0,    48,    21,    42,
      43,    51,    21,    22,    23,    24,    27,    36,    55,    55,
      21,    31,    36,    21,    11,    12,    13,    21,    42,    45,
      49,    51,    52,    53,    63,    66,    36,    39,    55,    55,
      15,    16,    17,    18,    19,    20,    28,    29,    32,    33,
      34,    35,    37,    37,    31,    22,    23,    24,    54,    60,
      61,    31,    21,    55,    21,    25,    42,    45,    64,    65,
      31,    36,    39,    21,    21,    44,    38,    21,    22,    23,
      24,    42,    45,    56,    57,    55,    37,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,     7,
      52,    55,    38,    38,    38,    21,    61,    30,    62,    22,
      21,    21,    65,    42,    45,    55,    57,    55,    31,    39,
      31,    39,    52,    53,    21,    21,    57,    30,    50,    40,
      52,    14,    60,    37,    38,    55,    55,    50,    40,    55,
      55,    55,    55,    52,    56,    37,     8,    55,    62,    39,
      39,    37,    31,    40,    40,    50,    52,    37,    55,    55,
      55,    31,    31,    52,    40,    40,    55,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    59,
      60,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      65,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     8,     5,     9,     1,
       5,     5,     5,     6,     3,     0,     3,     0,     3,     0,
       4,     1,     1,     3,     4,     4,     4,     4,     6,     7,
       7,     7,     7,     5,     1,     1,     2,     1,     1,     1,
       1,     4,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     5,     3,
       1,     1,     1,     1,     2,     2,     2,     0,     2,     6,
       2,     2,     0,     3,     0,     2,     1,     1,     2,     2,
       2,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast); astPrint((yyvsp[0].ast));}
#line 1429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_DEC,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0);}
#line 1435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_IF_THEN, 0, (yyvsp[-3].ast), (yyvsp[0].ast), 0, 0); }
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_IF_THEN_ELSE, 0, (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1453 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_IF_THEN, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_FOR_TO, (yyvsp[-6].symbol), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE,0,(yyvsp[-4].ast),0,(yyvsp[-1].symbol),0);}
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE,0,(yyvsp[-4].ast),0,(yyvsp[-1].symbol),0);}
#line 1483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VARIABLE,0,(yyvsp[-4].ast),0,(yyvsp[-1].symbol),0);}
#line 1489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "parser.y" /* yacc.c:1646  */
    {(AST_FUNC_RESET, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(ASTREE_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(ASTREE_LCMD, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(ASTREE_LCMD, 0, (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast), 0);}
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_ATRIBUTION,0, (yyvsp[-2].symbol),(yyvsp[0].ast),0,0);}
#line 1543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_TO_PTR_ATRIBUTION,0, (yyvsp[-2].symbol),(yyvsp[0].ast),0,0);}
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_TO_END_ATRIBUTION,0, (yyvsp[-2].symbol),(yyvsp[0].ast),0,0);}
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_PTR_ATRIBUTION,0, (yyvsp[-3].symbol),(yyvsp[0].ast),0,0);}
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_END_ATRIBUTION,0, (yyvsp[-3].symbol),(yyvsp[0].ast),0,0);}
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_VEC_ATRIBUTION,0, (yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0);}
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_TO_PTR_VEC_ATRIBUTION,0, (yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0);}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 138 "parser.y" /* yacc.c:1646  */
    {astreeCreate(AST_TO_END VEC_ATRIBUTION,0, (yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0);}
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 139 "parser.y" /* yacc.c:1646  */
    {astreeCreate(AST_PTR_VEC_ATRIBUTION,0, (yyvsp[-6].symbol),(yyvsp[-3].ast),(yyvsp[-1].ast),0);}
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 140 "parser.y" /* yacc.c:1646  */
    {astreeCreate(AST_END_VEC_ATRIBUTION,0, (yyvsp[-6].symbol),(yyvsp[-3].ast),(yyvsp[-1].ast),0);}
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 141 "parser.y" /* yacc.c:1646  */
    {astreeCreate(AST_FUNC_CALL,0,(yyvsp[-4].symbol),(yyvsp[-2].ast),(yyvsp[-1].ast),0);}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 144 "parser.y" /* yacc.c:1646  */
    {astreeCreate(AST_RETURN,0,(yyvsp[0].ast),0,0,0);}
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 147 "parser.y" /* yacc.c:1646  */
    {(AST_INT, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "parser.y" /* yacc.c:1646  */
    {(AST_FLOAT, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 149 "parser.y" /* yacc.c:1646  */
    {(AST_CHAR, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(READ_VEC, 0, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0); }
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_MULT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_LT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_GT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_NOT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(ASTAND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(FUNC_CALL, 0, (yyvsp[-4].symbol), (yyvsp[-2].ast), (yyvsp[-1].ast), 0); }
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_PARENTHESES, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].symbol);}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].symbol);}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].symbol);}
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].symbol);}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_PTR, 0, (yyvsp[0].symbol), 0, 0, 0);}
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_END, 0, (yyvsp[0].symbol), 0, 0, 0);}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_FUNC_ARGL_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_FUNC_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_FUNC_HEADER, 0, (yyvsp[-2].ast), (yyvsp[-1].ast), 0, 0); }
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_FUNC_PAR_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_FUNC_PAR, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_PRINT_LIST, 0, 0, (yyvsp[0].ast), 0, 0); }
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1855 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(END_SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(PTR_SYMBOL, 0, (yyvsp[0].symbol), 0, 0, 0); }
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astreeCreate(AST_PRINT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astreeCreate(AST_READ, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1891 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1895 "parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 224 "parser.y" /* yacc.c:1906  */

int yyerror(int code){
    printf("O analisador encontrou um erro na linha %d\n",getLineNumber());
    exit(3);

}
#include "main.c"
