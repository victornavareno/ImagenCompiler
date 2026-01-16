/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_IMAGEN_TAB_H_INCLUDED
# define YY_YY_IMAGEN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 35 "imagen.y"

    typedef struct {
        float valor;   // El número (sea entero o real, lo guardamos como float para operar)
        int tipo;      // T_ENTERO o T_REAL (La bandera semántica)
    } info_expr;

#line 56 "imagen.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    NUMREAL = 259,                 /* NUMREAL  */
    IDENTIFICADOR = 260,           /* IDENTIFICADOR  */
    CADENA = 261,                  /* CADENA  */
    VARIABLES = 262,               /* VARIABLES  */
    ENTERO = 263,                  /* ENTERO  */
    REAL = 264,                    /* REAL  */
    BOOL = 265,                    /* BOOL  */
    FIGURAS = 266,                 /* FIGURAS  */
    IMAGEN = 267,                  /* IMAGEN  */
    FINIMAGEN = 268,               /* FINIMAGEN  */
    PONER = 269,                   /* PONER  */
    BORRAR = 270,                  /* BORRAR  */
    HORIZONTAL = 271,              /* HORIZONTAL  */
    VERTICAL = 272,                /* VERTICAL  */
    PAUSA = 273,                   /* PAUSA  */
    CIRCULO = 274,                 /* CIRCULO  */
    RECTANGULO = 275,              /* RECTANGULO  */
    CUADRADO = 276,                /* CUADRADO  */
    T_ROJO = 277,                  /* T_ROJO  */
    T_VERDE = 278,                 /* T_VERDE  */
    T_AZUL = 279,                  /* T_AZUL  */
    T_NARANJA = 280,               /* T_NARANJA  */
    T_MARRON = 281,                /* T_MARRON  */
    T_AMARILLO = 282,              /* T_AMARILLO  */
    T_NEGRO = 283,                 /* T_NEGRO  */
    T_GRIS = 284,                  /* T_GRIS  */
    SI = 285,                      /* SI  */
    SI_NO = 286,                   /* SI_NO  */
    REPE = 287,                    /* REPE  */
    LLLAVE = 288,                  /* LLLAVE  */
    RLLAVE = 289,                  /* RLLAVE  */
    TRUE = 290,                    /* TRUE  */
    FALSE = 291,                   /* FALSE  */
    IGUAL = 292,                   /* IGUAL  */
    AND = 293,                     /* AND  */
    MENOR = 294,                   /* MENOR  */
    MAYOR = 295,                   /* MAYOR  */
    COMA = 296,                    /* COMA  */
    PAR_IZQ = 297,                 /* PAR_IZQ  */
    PAR_DER = 298,                 /* PAR_DER  */
    ASIGNACION = 299,              /* ASIGNACION  */
    UMINUS = 300                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "imagen.y"

    char str[100];     // Para nombres (arrays fijos)
    int entero;        // Para números literales enteros
    float real;        // Para números literales reales
    info_expr expr;    // LA MOCHILA PARA EXPRESIONES (Valor + Bandera)

#line 125 "imagen.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_IMAGEN_TAB_H_INCLUDED  */
