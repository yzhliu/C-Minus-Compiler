
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 26 "c-grammar.y"

	int iValue;
	int sIndex;
	Node *nPtr;

/* Line 1676 of yacc.c  */
#line 202 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE	/* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;
