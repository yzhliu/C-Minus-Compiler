
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
#line 1 "c-grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include "hash.h"
#include "var.h"
#include "command.h"

Node *tmp;

/* 属性操作类型 */
Node *opr(int name, int num, ...);
Node *set_index(int value);
Node *set_content(int value);
void freeNode(Node * p);
int exeNode(Node * p, int signal);

int yylexeNode(void);
void yyerror(char *s);

/*int var[26]; [> 变量数组 <]*/

/* Line 189 of yacc.c  */
#line 99 "y.tab.c"

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
	CONSTANT = 258,
	INT = 259,
	VOID = 260,
	IDENTIFIER = 261,
	STRING_LITERAL = 262,
	SIZEOF = 263,
	PTR_OP = 264,
	INC_OP = 265,
	DEC_OP = 266,
	LEFT_OP = 267,
	RIGHT_OP = 268,
	LE_OP = 269,
	GE_OP = 270,
	EQ_OP = 271,
	NE_OP = 272,
	AND_OP = 273,
	OR_OP = 274,
	MUL_ASSIGN = 275,
	DIV_ASSIGN = 276,
	MOD_ASSIGN = 277,
	ADD_ASSIGN = 278,
	SUB_ASSIGN = 279,
	LEFT_ASSIGN = 280,
	RIGHT_ASSIGN = 281,
	AND_ASSIGN = 282,
	XOR_ASSIGN = 283,
	OR_ASSIGN = 284,
	TYPE_NAME = 285,
	TYPEDEF = 286,
	EXTERN = 287,
	STATIC = 288,
	AUTO = 289,
	REGISTER = 290,
	INLINE = 291,
	RESTRICT = 292,
	CHAR = 293,
	SHORT = 294,
	LONG = 295,
	SIGNED = 296,
	UNSIGNED = 297,
	FLOAT = 298,
	DOUBLE = 299,
	CONST = 300,
	VOLATILE = 301,
	BOOL = 302,
	COMPLEX = 303,
	IMAGINARY = 304,
	STRUCT = 305,
	UNION = 306,
	ENUM = 307,
	ELLIPSIS = 308,
	CASE = 309,
	DEFAULT = 310,
	IF = 311,
	ELSE = 312,
	SWITCH = 313,
	WHILE = 314,
	DO = 315,
	FOR = 316,
	GOTO = 317,
	CONTINUE = 318,
	BREAK = 319,
	RETURN = 320,
	PARAM = 321,
	FUNC = 322,
	VAR = 323,
	CALL = 324,
	GLOBAL_VAR = 325,
	LOWER_THAN_ELSE = 326
};
#endif
/* Tokens.  */
#define CONSTANT 258
#define INT 259
#define VOID 260
#define IDENTIFIER 261
#define STRING_LITERAL 262
#define SIZEOF 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define AND_OP 273
#define OR_OP 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define LEFT_ASSIGN 280
#define RIGHT_ASSIGN 281
#define AND_ASSIGN 282
#define XOR_ASSIGN 283
#define OR_ASSIGN 284
#define TYPE_NAME 285
#define TYPEDEF 286
#define EXTERN 287
#define STATIC 288
#define AUTO 289
#define REGISTER 290
#define INLINE 291
#define RESTRICT 292
#define CHAR 293
#define SHORT 294
#define LONG 295
#define SIGNED 296
#define UNSIGNED 297
#define FLOAT 298
#define DOUBLE 299
#define CONST 300
#define VOLATILE 301
#define BOOL 302
#define COMPLEX 303
#define IMAGINARY 304
#define STRUCT 305
#define UNION 306
#define ENUM 307
#define ELLIPSIS 308
#define CASE 309
#define DEFAULT 310
#define IF 311
#define ELSE 312
#define SWITCH 313
#define WHILE 314
#define DO 315
#define FOR 316
#define GOTO 317
#define CONTINUE 318
#define BREAK 319
#define RETURN 320
#define PARAM 321
#define FUNC 322
#define VAR 323
#define CALL 324
#define GLOBAL_VAR 325
#define LOWER_THAN_ELSE 326

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE {

/* Line 214 of yacc.c  */
#line 26 "c-grammar.y"

	int iValue;
	int sIndex;
	Node *nPtr;

/* Line 214 of yacc.c  */
#line 285 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE	/* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 297 "y.tab.c"

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
#  include <stddef.h>		/* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h>		/* INFRINGES ON USER NAME SPACE */
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
# define YYUSE(e)		/* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int YYID(int yyi)
#else
static int YYID(yyi)
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
#    include <alloca.h>		/* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h>		/* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h>	/* INFRINGES ON USER NAME SPACE */
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
#   define YYSTACK_ALLOC_MAXIMUM 4032	/* reasonable circa 2006 */
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
#   include <stdlib.h>		/* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc(YYSIZE_T);		/* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free(void *);		/* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc {
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   98

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] = {
	0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	75, 76, 85, 83, 77, 84, 2, 86, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 72,
	81, 80, 82, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 73, 2, 74, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 78, 2, 79, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
	35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
	45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
	55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
	65, 66, 67, 68, 69, 70, 71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] = {
	0, 0, 3, 5, 8, 10, 12, 14, 18, 25,
	27, 29, 35, 37, 39, 41, 45, 47, 50, 55,
	60, 63, 64, 67, 68, 70, 72, 74, 76, 78,
	81, 83, 89, 97, 103, 106, 110, 114, 116, 118,
	123, 127, 129, 131, 133, 135, 137, 139, 141, 145,
	147, 149, 151, 155, 157, 159, 161, 165, 167, 169,
	171, 176, 178, 179, 183
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] = {
	88, 0, -1, 89, -1, 89, 90, -1, 90, -1,
	91, -1, 93, -1, 92, 6, 72, -1, 92, 6,
	73, 3, 74, 72, -1, 4, -1, 5, -1, 92,
	6, 75, 94, 76, -1, 97, -1, 95, -1, 5,
	-1, 95, 77, 96, -1, 96, -1, 92, 6, -1,
	92, 6, 73, 74, -1, 78, 98, 99, 79, -1,
	98, 91, -1, -1, 99, 100, -1, -1, 101, -1,
	97, -1, 102, -1, 103, -1, 104, -1, 105, 72,
	-1, 72, -1, 56, 75, 105, 76, 100, -1, 56,
	75, 105, 76, 100, 57, 100, -1, 59, 75, 105,
	76, 100, -1, 65, 72, -1, 65, 105, 72, -1,
	106, 80, 105, -1, 107, -1, 6, -1, 6, 73,
	105, 74, -1, 109, 108, 109, -1, 109, -1, 14,
	-1, 81, -1, 82, -1, 15, -1, 16, -1, 17,
	-1, 109, 110, 111, -1, 111, -1, 83, -1, 84,
	-1, 111, 112, 113, -1, 113, -1, 85, -1, 86,
	-1, 75, 105, 76, -1, 106, -1, 114, -1, 3,
	-1, 6, 75, 115, 76, -1, 116, -1, -1, 116,
	77, 105, -1, 105, -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] = {
	0, 65, 65, 69, 70, 74, 78, 82, 89, 99,
	100, 104, 111, 116, 117, 121, 122, 126, 133, 143,
	148, 149, 153, 154, 158, 159, 160, 161, 162, 166,
	167, 171, 172, 177, 181, 182, 186, 190, 194, 195,
	204, 208, 212, 213, 214, 215, 216, 217, 221, 225,
	232, 233, 237, 241, 245, 246, 250, 251, 252, 253,
	257, 266, 267, 271, 272
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {
	"$end", "error", "$undefined", "CONSTANT", "INT", "VOID", "IDENTIFIER",
	"STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
	"RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
	"MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
	"LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
	"TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
	    "INLINE",
	"RESTRICT", "CHAR", "SHORT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
	"DOUBLE", "CONST", "VOLATILE", "BOOL", "COMPLEX", "IMAGINARY", "STRUCT",
	"UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH",
	"WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "PARAM",
	"FUNC", "VAR", "CALL", "GLOBAL_VAR", "LOWER_THAN_ELSE", "';'", "'['",
	"']'", "'('", "')'", "','", "'{'", "'}'", "'='", "'<'", "'>'", "'+'",
	"'-'", "'*'", "'/'", "$accept", "program", "declaration_list",
	"declaration", "var_declaration", "type_specifier", "fun_declaration",
	"params", "params_list", "param", "compound_stmt", "local_declarations",
	"statement_list", "statement", "expression_stmt", "selection_stmt",
	"iteration_stmt", "return_stmt", "expression", "var",
	"simple_expression", "relop", "additive_expression", "addop", "term",
	"mulop", "factor", "call", "args", "arg_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] = {
	0, 256, 257, 258, 259, 260, 261, 262, 263, 264,
	265, 266, 267, 268, 269, 270, 271, 272, 273, 274,
	275, 276, 277, 278, 279, 280, 281, 282, 283, 284,
	285, 286, 287, 288, 289, 290, 291, 292, 293, 294,
	295, 296, 297, 298, 299, 300, 301, 302, 303, 304,
	305, 306, 307, 308, 309, 310, 311, 312, 313, 314,
	315, 316, 317, 318, 319, 320, 321, 322, 323, 324,
	325, 326, 59, 91, 93, 40, 41, 44, 123, 125,
	61, 60, 62, 43, 45, 42, 47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] = {
	0, 87, 88, 89, 89, 90, 90, 91, 91, 92,
	92, 93, 93, 94, 94, 95, 95, 96, 96, 97,
	98, 98, 99, 99, 100, 100, 100, 100, 100, 101,
	101, 102, 102, 103, 104, 104, 105, 105, 106, 106,
	107, 107, 108, 108, 108, 108, 108, 108, 109, 109,
	110, 110, 111, 111, 112, 112, 113, 113, 113, 113,
	114, 115, 115, 116, 116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] = {
	0, 2, 1, 2, 1, 1, 1, 3, 6, 1,
	1, 5, 1, 1, 1, 3, 1, 2, 4, 4,
	2, 0, 2, 0, 1, 1, 1, 1, 1, 2,
	1, 5, 7, 5, 2, 3, 3, 1, 1, 4,
	3, 1, 1, 1, 1, 1, 1, 1, 3, 1,
	1, 1, 3, 1, 1, 1, 3, 1, 1, 1,
	4, 1, 0, 3, 1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] = {
	0, 9, 10, 21, 0, 2, 4, 5, 0, 6,
	12, 23, 1, 3, 0, 20, 0, 0, 7, 0,
	0, 0, 59, 38, 0, 0, 0, 30, 0, 19,
	25, 22, 24, 26, 27, 28, 0, 57, 37, 41,
	49, 53, 58, 0, 10, 0, 0, 13, 16, 0,
	62, 0, 0, 34, 0, 0, 29, 0, 42, 45,
	46, 47, 43, 44, 50, 51, 0, 0, 54, 55,
	0, 0, 17, 11, 0, 0, 64, 0, 61, 0,
	0, 35, 56, 36, 57, 40, 48, 52, 8, 0,
	15, 39, 60, 0, 0, 0, 18, 63, 31, 33,
	0, 32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] = {
	-1, 4, 5, 6, 7, 8, 9, 46, 47, 48,
	30, 11, 17, 31, 32, 33, 34, 35, 36, 37,
	38, 66, 39, 67, 40, 70, 41, 42, 77, 78
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int8 yypact[] = {
	2, -76, -76, -76, 14, 2, -76, -76, 16, -76,
	-76, 25, -76, -76, -34, -76, 18, -3, -76, 30,
	39, -27, -76, -65, -35, -26, -2, -76, 6, -76,
	-76, -76, -76, -76, -76, -76, -20, -23, -76, 1,
	-38, -76, -76, -14, -22, 53, -13, -16, -76, 6,
	6, 6, 6, -76, -7, -10, -76, 6, -76, -76,
	-76, -76, -76, -76, -76, -76, 6, 6, -76, -76,
	6, -5, 15, -76, 25, -6, -76, 3, 10, 13,
	17, -76, -76, -76, -76, -33, -38, -76, -76, 20,
	-76, -76, -76, 6, -1, -1, -76, -76, 33, -76,
	-1, -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] = {
	-76, -76, -76, 86, 81, 12, -76, -76, -76, 22,
	21, -76, -76, -75, -76, -76, -76, -76, -15, -39,
	-76, -76, 29, -76, 31, -76, 27, -76, -76, -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] = {
	22, 22, 22, 23, 23, 23, 1, 2, 49, 22,
	50, 54, 23, 55, 12, 58, 59, 60, 61, 98,
	99, 10, 14, 16, 21, 101, 10, 84, 84, 1,
	2, 84, 45, 43, 75, 76, 79, 80, 18, 19,
	51, 20, 83, 1, 44, 18, 19, 68, 69, 52,
	64, 65, 56, 24, -14, 24, 25, 57, 25, 72,
	71, 74, 26, 73, 26, 81, 82, 88, 91, 27,
	53, 27, 28, 28, 28, 3, 29, 3, 97, 92,
	3, 28, 62, 63, 64, 65, 45, 93, 89, 94,
	100, 13, 15, 95, 96, 85, 90, 87, 86
};

static const yytype_uint8 yycheck[] = {
	3, 3, 3, 6, 6, 6, 4, 5, 73, 3,
	75, 26, 6, 28, 0, 14, 15, 16, 17, 94,
	95, 0, 6, 11, 6, 100, 5, 66, 67, 4,
	5, 70, 20, 3, 49, 50, 51, 52, 72, 73,
	75, 75, 57, 4, 5, 72, 73, 85, 86, 75,
	83, 84, 72, 56, 76, 56, 59, 80, 59, 6,
	74, 77, 65, 76, 65, 72, 76, 72, 74, 72,
	72, 72, 75, 75, 75, 78, 79, 78, 93, 76,
	78, 75, 81, 82, 83, 84, 74, 77, 73, 76,
	57, 5, 11, 76, 74, 66, 74, 70, 67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] = {
	0, 4, 5, 78, 88, 89, 90, 91, 92, 93,
	97, 98, 0, 90, 6, 91, 92, 99, 72, 73,
	75, 6, 3, 6, 56, 59, 65, 72, 75, 79,
	97, 100, 101, 102, 103, 104, 105, 106, 107, 109,
	111, 113, 114, 3, 5, 92, 94, 95, 96, 73,
	75, 75, 75, 72, 105, 105, 72, 80, 14, 15,
	16, 17, 81, 82, 83, 84, 108, 110, 85, 86,
	112, 74, 6, 76, 77, 105, 105, 115, 116, 105,
	105, 72, 76, 105, 106, 109, 111, 113, 72, 73,
	96, 74, 76, 77, 76, 76, 74, 105, 100, 100,
	57, 100
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
#  include <stdio.h>		/* INFRINGES ON USER NAME SPACE */
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
yy_symbol_value_print(FILE * yyoutput, int yytype,
		      YYSTYPE const *const yyvaluep)
#else
static void yy_symbol_value_print(yyoutput, yytype, yyvaluep)
FILE *yyoutput;
int yytype;
YYSTYPE const *const yyvaluep;
#endif
{
	if (!yyvaluep)
		return;
# ifdef YYPRINT
	if (yytype < YYNTOKENS)
		YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
# else
	YYUSE(yyoutput);
# endif
	switch (yytype) {
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
yy_symbol_print(FILE * yyoutput, int yytype, YYSTYPE const *const yyvaluep)
#else
static void yy_symbol_print(yyoutput, yytype, yyvaluep)
FILE *yyoutput;
int yytype;
YYSTYPE const *const yyvaluep;
#endif
{
	if (yytype < YYNTOKENS)
		YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
	else
		YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

	yy_symbol_value_print(yyoutput, yytype, yyvaluep);
	YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void yy_stack_print(yytype_int16 * yybottom, yytype_int16 * yytop)
#else
static void yy_stack_print(yybottom, yytop)
yytype_int16 *yybottom;
yytype_int16 *yytop;
#endif
{
	YYFPRINTF(stderr, "Stack now");
	for (; yybottom <= yytop; yybottom++) {
		int yybot = *yybottom;
		YYFPRINTF(stderr, " %d", yybot);
	}
	YYFPRINTF(stderr, "\n");
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
static void yy_reduce_print(YYSTYPE * yyvsp, int yyrule)
#else
static void yy_reduce_print(yyvsp, yyrule)
YYSTYPE *yyvsp;
int yyrule;
#endif
{
	int yynrhs = yyr2[yyrule];
	int yyi;
	unsigned long int yylno = yyrline[yyrule];
	YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
		  yyrule - 1, yylno);
	/* The symbols being reduced.  */
	for (yyi = 0; yyi < yynrhs; yyi++) {
		YYFPRINTF(stderr, "   $%d = ", yyi + 1);
		yy_symbol_print(stderr, yyrhs[yyprhs[yyrule] + yyi],
				&(yyvsp[(yyi + 1) - (yynrhs)])
		    );
		YYFPRINTF(stderr, "\n");
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
static YYSIZE_T yystrlen(const char *yystr)
#else
static YYSIZE_T yystrlen(yystr)
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
static char *yystpcpy(char *yydest, const char *yysrc)
#else
static char *yystpcpy(yydest, yysrc)
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
static YYSIZE_T yytnamerr(char *yyres, const char *yystr)
{
	if (*yystr == '"') {
		YYSIZE_T yyn = 0;
		char const *yyp = yystr;

		for (;;)
			switch (*++yyp) {
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
	      do_not_strip_quotes:;
	}

	if (!yyres)
		return yystrlen(yystr);

	return yystpcpy(yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T yysyntax_error(char *yyresult, int yystate, int yychar)
{
	int yyn = yypact[yystate];

	if (!(YYPACT_NINF < yyn && yyn <= YYLAST))
		return 0;
	else {
		int yytype = YYTRANSLATE(yychar);
		YYSIZE_T yysize0 = yytnamerr(0, yytname[yytype]);
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
		static char const yyunexpected[] =
		    "syntax error, unexpected %s";
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
		yyfmt = yystpcpy(yyformat, yyunexpected);

		for (yyx = yyxbegin; yyx < yyxend; ++yyx)
			if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR) {
				if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM) {
					yycount = 1;
					yysize = yysize0;
					yyformat[sizeof yyunexpected - 1] =
					    '\0';
					break;
				}
				yyarg[yycount++] = yytname[yyx];
				yysize1 = yysize + yytnamerr(0, yytname[yyx]);
				yysize_overflow |= (yysize1 < yysize);
				yysize = yysize1;
				yyfmt = yystpcpy(yyfmt, yyprefix);
				yyprefix = yyor;
			}

		yyf = YY_(yyformat);
		yysize1 = yysize + yystrlen(yyf);
		yysize_overflow |= (yysize1 < yysize);
		yysize = yysize1;

		if (yysize_overflow)
			return YYSIZE_MAXIMUM;

		if (yyresult) {
			/* Avoid sprintf, as that infringes on the user's name space.
			   Don't have undefined behavior even if the translation
			   produced a string with the wrong number of "%s"s.  */
			char *yyp = yyresult;
			int yyi = 0;
			while ((*yyp = *yyf) != '\0') {
				if (*yyp == '%' && yyf[1] == 's'
				    && yyi < yycount) {
					yyp += yytnamerr(yyp, yyarg[yyi++]);
					yyf += 2;
				} else {
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
static void yydestruct(const char *yymsg, int yytype, YYSTYPE * yyvaluep)
#else
static void yydestruct(yymsg, yytype, yyvaluep)
const char *yymsg;
int yytype;
YYSTYPE *yyvaluep;
#endif
{
	YYUSE(yyvaluep);

	if (!yymsg)
		yymsg = "Deleting";
	YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

	switch (yytype) {

	default:
		break;
	}
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse(void *YYPARSE_PARAM);
#else
int yyparse();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse(void);
#else
int yyparse();
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
int yyparse(void *YYPARSE_PARAM)
#else
int yyparse(YYPARSE_PARAM)
void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int yyparse(void)
#else
int yyparse()
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

	YYDPRINTF((stderr, "Starting parse\n"));

	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY;	/* Cause a token to be read.  */

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

	if (yyss + yystacksize - 1 <= yyssp) {
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
			yyoverflow(YY_("memory exhausted"),
				   &yyss1, yysize * sizeof(*yyssp),
				   &yyvs1, yysize * sizeof(*yyvsp),
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
			    (union yyalloc *)
			    YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
			if (!yyptr)
				goto yyexhaustedlab;
			YYSTACK_RELOCATE(yyss_alloc, yyss);
			YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
			if (yyss1 != yyssa)
				YYSTACK_FREE(yyss1);
		}
# endif
#endif /* no yyoverflow */

		yyssp = yyss + yysize - 1;
		yyvsp = yyvs + yysize - 1;

		YYDPRINTF((stderr, "Stack size increased to %lu\n",
			   (unsigned long int)yystacksize));

		if (yyss + yystacksize - 1 <= yyssp)
			YYABORT;
	}

	YYDPRINTF((stderr, "Entering state %d\n", yystate));

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
	if (yychar == YYEMPTY) {
		YYDPRINTF((stderr, "Reading a token: "));
		yychar = YYLEX;
	}

	if (yychar <= YYEOF) {
		yychar = yytoken = YYEOF;
		YYDPRINTF((stderr, "Now at end of input.\n"));
	} else {
		yytoken = YYTRANSLATE(yychar);
		YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
	}

	/* If the proper action on seeing token YYTOKEN is to reduce or to
	   detect an error, take that action.  */
	yyn += yytoken;
	if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
		goto yydefault;
	yyn = yytable[yyn];
	if (yyn <= 0) {
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
	YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

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
	yyval = yyvsp[1 - yylen];

	YY_REDUCE_PRINT(yyn);
	switch (yyn) {
	case 2:

/* Line 1455 of yacc.c  */
#line 65 "c-grammar.y"
		{
			exeNode((yyvsp[(1) - (1)].nPtr), 0);
			freeNode((yyvsp[(1) - (1)].nPtr));
		}
		break;

	case 3:

/* Line 1455 of yacc.c  */
#line 69 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(';', 2, (yyvsp[(1) - (2)].nPtr),
				(yyvsp[(2) - (2)].nPtr));
		}
		break;

	case 4:

/* Line 1455 of yacc.c  */
#line 70 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 5:

/* Line 1455 of yacc.c  */
#line 75 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(GLOBAL_VAR, 1, (yyvsp[(1) - (1)].nPtr));
		}
		break;

	case 6:

/* Line 1455 of yacc.c  */
#line 78 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 7:

/* Line 1455 of yacc.c  */
#line 83 "c-grammar.y"
		{
			Node *tmp1;
			/* here to insert new var declaration */
			tmp1 = set_index((yyvsp[(2) - (3)].sIndex));
			(yyval.nPtr) =
			    opr(VAR, 2, (yyvsp[(1) - (3)].nPtr), tmp1);
		}
		break;

	case 8:

/* Line 1455 of yacc.c  */
#line 90 "c-grammar.y"
		{
			Node *tmp1, *tmp2;
			tmp1 = set_index((yyvsp[(2) - (6)].sIndex));
			tmp2 = set_content((yyvsp[(4) - (6)].iValue));
			(yyval.nPtr) =
			    opr(VAR, 3, (yyvsp[(1) - (6)].nPtr), tmp1, tmp2);
		}
		break;

	case 9:

/* Line 1455 of yacc.c  */
#line 99 "c-grammar.y"
		{
			(yyval.nPtr) = set_content(INT);
		}
		break;

	case 10:

/* Line 1455 of yacc.c  */
#line 100 "c-grammar.y"
		{
			(yyval.nPtr) = set_content(VOID);
		}
		break;

	case 11:

/* Line 1455 of yacc.c  */
#line 105 "c-grammar.y"
		{
			Node *tmp1;
			tmp1 = set_index((yyvsp[(2) - (5)].sIndex));
			(yyval.nPtr) =
			    opr(FUNC, 3, (yyvsp[(1) - (5)].nPtr), tmp1,
				(yyvsp[(4) - (5)].nPtr));
		}
		break;

	case 12:

/* Line 1455 of yacc.c  */
#line 112 "c-grammar.y"
		{
			(yyval.nPtr) = opr(FUNC, 1, (yyvsp[(1) - (1)].nPtr));
		}
		break;

	case 13:

/* Line 1455 of yacc.c  */
#line 116 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 14:

/* Line 1455 of yacc.c  */
#line 117 "c-grammar.y"
		{
			(yyval.nPtr) = NULL;
		}
		break;

	case 15:

/* Line 1455 of yacc.c  */
#line 121 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(',', 2, (yyvsp[(1) - (3)].nPtr),
				(yyvsp[(3) - (3)].nPtr));
		}
		break;

	case 16:

/* Line 1455 of yacc.c  */
#line 122 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 17:

/* Line 1455 of yacc.c  */
#line 127 "c-grammar.y"
		{
			Node *tmp1;
			/* here to insert new var declaration */
			tmp1 = set_index((yyvsp[(2) - (2)].sIndex));
			(yyval.nPtr) =
			    opr(PARAM, 2, (yyvsp[(1) - (2)].nPtr), tmp1);
		}
		break;

	case 18:

/* Line 1455 of yacc.c  */
#line 134 "c-grammar.y"
		{
			Node *tmp1;
			/* here to insert new var declaration */
			tmp1 = set_index((yyvsp[(2) - (4)].sIndex));
			(yyval.nPtr) =
			    opr(PARAM, 3, (yyvsp[(1) - (4)].nPtr), tmp1, NULL);
		}
		break;

	case 19:

/* Line 1455 of yacc.c  */
#line 144 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr('{', 2, (yyvsp[(2) - (4)].nPtr),
				(yyvsp[(3) - (4)].nPtr));
		}
		break;

	case 20:

/* Line 1455 of yacc.c  */
#line 148 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(';', 2, (yyvsp[(1) - (2)].nPtr),
				(yyvsp[(2) - (2)].nPtr));
		}
		break;

	case 21:

/* Line 1455 of yacc.c  */
#line 149 "c-grammar.y"
		{
			(yyval.nPtr) = NULL;
		}
		break;

	case 22:

/* Line 1455 of yacc.c  */
#line 153 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(';', 2, (yyvsp[(1) - (2)].nPtr),
				(yyvsp[(2) - (2)].nPtr));
		}
		break;

	case 23:

/* Line 1455 of yacc.c  */
#line 154 "c-grammar.y"
		{
			(yyval.nPtr) = NULL;
		}
		break;

	case 24:

/* Line 1455 of yacc.c  */
#line 158 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 25:

/* Line 1455 of yacc.c  */
#line 159 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 26:

/* Line 1455 of yacc.c  */
#line 160 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 27:

/* Line 1455 of yacc.c  */
#line 161 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 28:

/* Line 1455 of yacc.c  */
#line 162 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 29:

/* Line 1455 of yacc.c  */
#line 166 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);
		}
		break;

	case 30:

/* Line 1455 of yacc.c  */
#line 167 "c-grammar.y"
		{
			(yyval.nPtr) = NULL;
		}
		break;

	case 31:

/* Line 1455 of yacc.c  */
#line 171 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(IF, 2, (yyvsp[(3) - (5)].nPtr),
				(yyvsp[(5) - (5)].nPtr));
		}
		break;

	case 32:

/* Line 1455 of yacc.c  */
#line 173 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(IF, 3, (yyvsp[(3) - (7)].nPtr),
				(yyvsp[(5) - (7)].nPtr),
				(yyvsp[(7) - (7)].nPtr));
		}
		break;

	case 33:

/* Line 1455 of yacc.c  */
#line 177 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr),
				(yyvsp[(5) - (5)].nPtr));
		}
		break;

	case 34:

/* Line 1455 of yacc.c  */
#line 181 "c-grammar.y"
		{
			(yyval.nPtr) = opr(RETURN, 0);
		}
		break;

	case 35:

/* Line 1455 of yacc.c  */
#line 182 "c-grammar.y"
		{
			(yyval.nPtr) = opr(RETURN, 1, (yyvsp[(2) - (3)].nPtr));
		}
		break;

	case 36:

/* Line 1455 of yacc.c  */
#line 187 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr('=', 2, (yyvsp[(1) - (3)].nPtr),
				(yyvsp[(3) - (3)].nPtr));
		}
		break;

	case 37:

/* Line 1455 of yacc.c  */
#line 190 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 38:

/* Line 1455 of yacc.c  */
#line 194 "c-grammar.y"
		{
			(yyval.nPtr) = set_index((yyvsp[(1) - (1)].sIndex));
		}
		break;

	case 39:

/* Line 1455 of yacc.c  */
#line 196 "c-grammar.y"
		{
			Node *tmp1;
			tmp1 = set_index((yyvsp[(1) - (4)].sIndex));
			(yyval.nPtr) =
			    opr('[', 2, tmp1, (yyvsp[(3) - (4)].nPtr));
		}
		break;

	case 40:

/* Line 1455 of yacc.c  */
#line 205 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr((yyvsp[(2) - (3)].iValue), 2,
				(yyvsp[(1) - (3)].nPtr),
				(yyvsp[(3) - (3)].nPtr));
		}
		break;

	case 41:

/* Line 1455 of yacc.c  */
#line 208 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 42:

/* Line 1455 of yacc.c  */
#line 212 "c-grammar.y"
		{
			(yyval.iValue) = LE_OP;
		}
		break;

	case 43:

/* Line 1455 of yacc.c  */
#line 213 "c-grammar.y"
		{
			(yyval.iValue) = '<';
		}
		break;

	case 44:

/* Line 1455 of yacc.c  */
#line 214 "c-grammar.y"
		{
			(yyval.iValue) = '>';
		}
		break;

	case 45:

/* Line 1455 of yacc.c  */
#line 215 "c-grammar.y"
		{
			(yyval.iValue) = GE_OP;
		}
		break;

	case 46:

/* Line 1455 of yacc.c  */
#line 216 "c-grammar.y"
		{
			(yyval.iValue) = EQ_OP;
		}
		break;

	case 47:

/* Line 1455 of yacc.c  */
#line 217 "c-grammar.y"
		{
			(yyval.iValue) = NE_OP;
		}
		break;

	case 48:

/* Line 1455 of yacc.c  */
#line 222 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr((yyvsp[(2) - (3)].iValue), 2,
				(yyvsp[(1) - (3)].nPtr),
				(yyvsp[(3) - (3)].nPtr));
		}
		break;

	case 49:

/* Line 1455 of yacc.c  */
#line 226 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 50:

/* Line 1455 of yacc.c  */
#line 232 "c-grammar.y"
		{
			(yyval.iValue) = '+';
		}
		break;

	case 51:

/* Line 1455 of yacc.c  */
#line 233 "c-grammar.y"
		{
			(yyval.iValue) = '-';
		}
		break;

	case 52:

/* Line 1455 of yacc.c  */
#line 238 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr((yyvsp[(2) - (3)].iValue), 2,
				(yyvsp[(1) - (3)].nPtr),
				(yyvsp[(3) - (3)].nPtr));
		}
		break;

	case 53:

/* Line 1455 of yacc.c  */
#line 241 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 54:

/* Line 1455 of yacc.c  */
#line 245 "c-grammar.y"
		{
			(yyval.iValue) = '*';
		}
		break;

	case 55:

/* Line 1455 of yacc.c  */
#line 246 "c-grammar.y"
		{
			(yyval.iValue) = '/';
		}
		break;

	case 56:

/* Line 1455 of yacc.c  */
#line 250 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);
		}
		break;

	case 57:

/* Line 1455 of yacc.c  */
#line 251 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 58:

/* Line 1455 of yacc.c  */
#line 252 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 59:

/* Line 1455 of yacc.c  */
#line 253 "c-grammar.y"
		{
			(yyval.nPtr) = set_content((yyvsp[(1) - (1)].iValue));
		}
		break;

	case 60:

/* Line 1455 of yacc.c  */
#line 258 "c-grammar.y"
		{
			Node *tmp1;
			tmp1 = set_index((yyvsp[(1) - (4)].sIndex));
			(yyval.nPtr) =
			    opr(CALL, 2, tmp1, (yyvsp[(3) - (4)].nPtr));
		}
		break;

	case 61:

/* Line 1455 of yacc.c  */
#line 266 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

	case 62:

/* Line 1455 of yacc.c  */
#line 267 "c-grammar.y"
		{
			(yyval.nPtr) = NULL;
		}
		break;

	case 63:

/* Line 1455 of yacc.c  */
#line 271 "c-grammar.y"
		{
			(yyval.nPtr) =
			    opr(',', 2, (yyvsp[(1) - (3)].nPtr),
				(yyvsp[(3) - (3)].nPtr));
		}
		break;

	case 64:

/* Line 1455 of yacc.c  */
#line 272 "c-grammar.y"
		{
			(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
		}
		break;

/* Line 1455 of yacc.c  */
#line 2085 "y.tab.c"
	default:
		break;
	}
	YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);

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
	if (!yyerrstatus) {
		++yynerrs;
#if ! YYERROR_VERBOSE
		yyerror(YY_("syntax error"));
#else
		{
			YYSIZE_T yysize = yysyntax_error(0, yystate, yychar);
			if (yymsg_alloc < yysize
			    && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM) {
				YYSIZE_T yyalloc = 2 * yysize;
				if (!
				    (yysize <= yyalloc
				     && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
					yyalloc = YYSTACK_ALLOC_MAXIMUM;
				if (yymsg != yymsgbuf)
					YYSTACK_FREE(yymsg);
				yymsg = (char *)YYSTACK_ALLOC(yyalloc);
				if (yymsg)
					yymsg_alloc = yyalloc;
				else {
					yymsg = yymsgbuf;
					yymsg_alloc = sizeof yymsgbuf;
				}
			}

			if (0 < yysize && yysize <= yymsg_alloc) {
				(void)yysyntax_error(yymsg, yystate, yychar);
				yyerror(yymsg);
			} else {
				yyerror(YY_("syntax error"));
				if (yysize != 0)
					goto yyexhaustedlab;
			}
		}
#endif
	}

	if (yyerrstatus == 3) {
		/* If just tried and failed to reuse lookahead token after an
		   error, discard it.  */

		if (yychar <= YYEOF) {
			/* Return failure if at end of input.  */
			if (yychar == YYEOF)
				YYABORT;
		} else {
			yydestruct("Error: discarding", yytoken, &yylval);
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
	if ( /*CONSTCOND*/ 0)
		goto yyerrorlab;

	/* Do not reclaim the symbols of the rule which action triggered
	   this YYERROR.  */
	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);
	yystate = *yyssp;
	goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
      yyerrlab1:
	yyerrstatus = 3;	/* Each real token shifted decrements this.  */

	for (;;) {
		yyn = yypact[yystate];
		if (yyn != YYPACT_NINF) {
			yyn += YYTERROR;
			if (0 <= yyn && yyn <= YYLAST
			    && yycheck[yyn] == YYTERROR) {
				yyn = yytable[yyn];
				if (0 < yyn)
					break;
			}
		}

		/* Pop the current state because it cannot handle the error token.  */
		if (yyssp == yyss)
			YYABORT;

		yydestruct("Error: popping", yystos[yystate], yyvsp);
		YYPOPSTACK(1);
		yystate = *yyssp;
		YY_STACK_PRINT(yyss, yyssp);
	}

	*++yyvsp = yylval;

	/* Shift the error token.  */
	YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

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
	yyerror(YY_("memory exhausted"));
	yyresult = 2;
	/* Fall through.  */
#endif

      yyreturn:
	if (yychar != YYEMPTY)
		yydestruct("Cleanup: discarding lookahead", yytoken, &yylval);
	/* Do not reclaim the symbols of the rule which action triggered
	   this YYABORT or YYACCEPT.  */
	YYPOPSTACK(yylen);
	YY_STACK_PRINT(yyss, yyssp);
	while (yyssp != yyss) {
		yydestruct("Cleanup: popping", yystos[*yyssp], yyvsp);
		YYPOPSTACK(1);
	}
#ifndef yyoverflow
	if (yyss != yyssa)
		YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
	if (yymsg != yymsgbuf)
		YYSTACK_FREE(yymsg);
#endif
	/* Make sure YYID is used.  */
	return YYID(yyresult);
}

/* Line 1675 of yacc.c  */
#line 275 "c-grammar.y"

#define SIZE_OF_NODE ((char *)&p->content - (char *)p)

Node *set_content(int value)
{
	Node *p;
	size_t sizeNode;
	/* 分配结点空间 */
	sizeNode = SIZE_OF_NODE + sizeof(int);

	if ((p = malloc(sizeNode)) == NULL)
		yyerror("out of memory");

	/* 复制内容 */
	p->type = TYPE_CONTENT;
	p->content = value;

	return p;
}

Node *set_index(int value)
{
	Node *p;
	size_t sizeNode;
	/* 分配结点空间 */
	sizeNode = SIZE_OF_NODE + sizeof(int);
	if ((p = malloc(sizeNode)) == NULL)
		yyerror("out of memory");

	/* 复制内容 */
	p->type = TYPE_INDEX;
	p->index = value;
	return p;
}

Node *opr(int name, int num, ...)
{
	va_list valist;
	Node *p;
	size_t sizeNode;
	int i;
	/* 分配结点空间 */
	sizeNode = SIZE_OF_NODE + sizeof(OpNode) + (num - 1) * sizeof(Node *);

	if ((p = malloc(sizeNode)) == NULL)
		yyerror("out of memory");

	/* 复制内容 */
	p->type = TYPE_OP;
	p->op.name = name;
	p->op.num = num;
	va_start(valist, num);

	for (i = 0; i < num; i++)
		p->op.node[i] = va_arg(valist, Node *);

	va_end(valist);
	return p;
}

void freeNode(Node * p)
{
	int i;
	if (!p)
		return;
	if (p->type == TYPE_OP) {
		for (i = 0; i < p->op.num; i++)
			freeNode(p->op.node[i]);
	}
	free(p);
}

void yyerror(char *s)
{
	printf("%s\n", s);
}

int main()
{

	hash_init(var_local, HASHSIZE);
	hash_init(var_local_SorA, HASHSIZE);
	hash_init(var_local_GorP, HASHSIZE);

	yyparse();

	return 0;
}
