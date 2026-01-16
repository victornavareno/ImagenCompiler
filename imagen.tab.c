/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "imagen.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

/* Incluimos la librería gráfica para pintar YA */
#include "imagen.h" 
#include "tabla_simbolos.h"

extern int yylineno;
int yylex(void);
void yyerror(const char *s);

/* La Tabla de Símbolos: Nuestra Memoria RAM */
extern tipo_tabla TS;

/* Función auxiliar para mapear el texto "rojo" al código de color de Allegro */
/* Asumimos que imagen.h define constantes o usamos las de Allegro */
int obtener_color(char* nombre_color) {
    // Nota: Estas constantes deben coincidir con las que use imagen.h/allegro
    // Si imagen.h usa ROJO, VERDE, etc, perfecto.
    if (strcmp(nombre_color, "ROJO") == 0) return ROJO;
    if (strcmp(nombre_color, "VERDE") == 0) return VERDE;
    if (strcmp(nombre_color, "AZUL") == 0) return AZUL;
    if (strcmp(nombre_color, "NARANJA") == 0) return NARANJA;
    if (strcmp(nombre_color, "MARRON") == 0) return MARRON;
    if (strcmp(nombre_color, "AMARILLO") == 0) return AMARILLO;
    if (strcmp(nombre_color, "GRIS") == 0) return GRIS;
    return NEGRO; // Por defecto
}

#line 104 "imagen.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "imagen.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_NUMREAL = 4,                    /* NUMREAL  */
  YYSYMBOL_IDENTIFICADOR = 5,              /* IDENTIFICADOR  */
  YYSYMBOL_CADENA = 6,                     /* CADENA  */
  YYSYMBOL_VARIABLES = 7,                  /* VARIABLES  */
  YYSYMBOL_ENTERO = 8,                     /* ENTERO  */
  YYSYMBOL_REAL = 9,                       /* REAL  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_FIGURAS = 11,                   /* FIGURAS  */
  YYSYMBOL_IMAGEN = 12,                    /* IMAGEN  */
  YYSYMBOL_FINIMAGEN = 13,                 /* FINIMAGEN  */
  YYSYMBOL_PONER = 14,                     /* PONER  */
  YYSYMBOL_BORRAR = 15,                    /* BORRAR  */
  YYSYMBOL_HORIZONTAL = 16,                /* HORIZONTAL  */
  YYSYMBOL_VERTICAL = 17,                  /* VERTICAL  */
  YYSYMBOL_PAUSA = 18,                     /* PAUSA  */
  YYSYMBOL_CIRCULO = 19,                   /* CIRCULO  */
  YYSYMBOL_RECTANGULO = 20,                /* RECTANGULO  */
  YYSYMBOL_CUADRADO = 21,                  /* CUADRADO  */
  YYSYMBOL_T_ROJO = 22,                    /* T_ROJO  */
  YYSYMBOL_T_VERDE = 23,                   /* T_VERDE  */
  YYSYMBOL_T_AZUL = 24,                    /* T_AZUL  */
  YYSYMBOL_T_NARANJA = 25,                 /* T_NARANJA  */
  YYSYMBOL_T_MARRON = 26,                  /* T_MARRON  */
  YYSYMBOL_T_AMARILLO = 27,                /* T_AMARILLO  */
  YYSYMBOL_T_NEGRO = 28,                   /* T_NEGRO  */
  YYSYMBOL_T_GRIS = 29,                    /* T_GRIS  */
  YYSYMBOL_SI = 30,                        /* SI  */
  YYSYMBOL_SI_NO = 31,                     /* SI_NO  */
  YYSYMBOL_REPE = 32,                      /* REPE  */
  YYSYMBOL_LLLAVE = 33,                    /* LLLAVE  */
  YYSYMBOL_RLLAVE = 34,                    /* RLLAVE  */
  YYSYMBOL_TRUE = 35,                      /* TRUE  */
  YYSYMBOL_FALSE = 36,                     /* FALSE  */
  YYSYMBOL_IGUAL = 37,                     /* IGUAL  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_MENOR = 39,                     /* MENOR  */
  YYSYMBOL_MAYOR = 40,                     /* MAYOR  */
  YYSYMBOL_COMA = 41,                      /* COMA  */
  YYSYMBOL_PAR_IZQ = 42,                   /* PAR_IZQ  */
  YYSYMBOL_PAR_DER = 43,                   /* PAR_DER  */
  YYSYMBOL_ASIGNACION = 44,                /* ASIGNACION  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_50_n_ = 50,                     /* '\n'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_programa = 52,                  /* programa  */
  YYSYMBOL_saltos = 53,                    /* saltos  */
  YYSYMBOL_opt_saltos = 54,                /* opt_saltos  */
  YYSYMBOL_opt_variables = 55,             /* opt_variables  */
  YYSYMBOL_lista_declaraciones = 56,       /* lista_declaraciones  */
  YYSYMBOL_declaracion = 57,               /* declaracion  */
  YYSYMBOL_tipo = 58,                      /* tipo  */
  YYSYMBOL_lista_identificadores = 59,     /* lista_identificadores  */
  YYSYMBOL_seccion_figuras = 60,           /* seccion_figuras  */
  YYSYMBOL_lista_figuras = 61,             /* lista_figuras  */
  YYSYMBOL_figura = 62,                    /* figura  */
  YYSYMBOL_tipo_figura3 = 63,              /* tipo_figura3  */
  YYSYMBOL_tipo_figura4 = 64,              /* tipo_figura4  */
  YYSYMBOL_color = 65,                     /* color  */
  YYSYMBOL_lista_imagenes = 66,            /* lista_imagenes  */
  YYSYMBOL_imagen = 67,                    /* imagen  */
  YYSYMBOL_68_1 = 68,                      /* $@1  */
  YYSYMBOL_lista_acciones = 69,            /* lista_acciones  */
  YYSYMBOL_cabecera_si = 70,               /* cabecera_si  */
  YYSYMBOL_instruccion = 71,               /* instruccion  */
  YYSYMBOL_expresion = 72,                 /* expresion  */
  YYSYMBOL_expresion_booleana = 73         /* expresion_booleana  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    47,    45,     2,    46,     2,    48,     2,     2,
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
      49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    85,    85,    86,    86,    91,    91,    92,
      92,    95,    96,   110,   121,   121,   121,   124,   130,   140,
     141,   141,   144,   157,   172,   172,   173,   176,   176,   177,
     177,   178,   178,   179,   179,   185,   185,   189,   188,   201,
     201,   204,   207,   226,   244,   254,   263,   264,   274,   275,
     276,   281,   286,   291,   307,   314,   320,   326,   331,   332,
     336,   337,   338,   339
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "NUMREAL",
  "IDENTIFICADOR", "CADENA", "VARIABLES", "ENTERO", "REAL", "BOOL",
  "FIGURAS", "IMAGEN", "FINIMAGEN", "PONER", "BORRAR", "HORIZONTAL",
  "VERTICAL", "PAUSA", "CIRCULO", "RECTANGULO", "CUADRADO", "T_ROJO",
  "T_VERDE", "T_AZUL", "T_NARANJA", "T_MARRON", "T_AMARILLO", "T_NEGRO",
  "T_GRIS", "SI", "SI_NO", "REPE", "LLLAVE", "RLLAVE", "TRUE", "FALSE",
  "IGUAL", "AND", "MENOR", "MAYOR", "COMA", "PAR_IZQ", "PAR_DER",
  "ASIGNACION", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'\\n'", "$accept",
  "programa", "saltos", "opt_saltos", "opt_variables",
  "lista_declaraciones", "declaracion", "tipo", "lista_identificadores",
  "seccion_figuras", "lista_figuras", "figura", "tipo_figura3",
  "tipo_figura4", "color", "lista_imagenes", "imagen", "$@1",
  "lista_acciones", "cabecera_si", "instruccion", "expresion",
  "expresion_booleana", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -93,     7,     2,   -93,   -35,   -93,     5,   -93,     3,   -35,
      24,   -17,   -93,   -93,   -93,   -93,   124,   -93,    37,     1,
      34,    24,   -93,    15,   -93,    -1,   -36,    33,    59,   -93,
      15,   -93,    28,   -93,   -93,   -93,    15,    15,    69,    15,
      85,    42,    55,   -93,   141,    28,    38,   -93,    15,    15,
      15,    15,    42,    69,   -93,    51,    15,   -93,   -44,   -44,
     -93,   -93,    42,   -93,   -93,   -93,    54,    57,   149,    15,
      15,   107,   157,   165,    78,    15,    15,   -93,   173,   181,
     -93,    15,    15,    88,   189,   197,    79,   120,   132,   139,
     151,    15,   112,    15,   153,   127,   -93,   150,    15,    15,
     -93,   -93,    15,    15,   105,    20,    -7,   -93,   -93,   -93,
      28,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   122,
     205,   105,   105,   105,   -93,   -93,   -15,    22,   -93,    28,
      88,   -35,   150,    15,    20,   -93,    88,    94,    42,   140,
     105,   -93,   125,   133,   -35,   -93,   148,    42,   -93,    88,
     131,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     7,     1,     0,     6,     0,     3,     0,     0,
       0,     0,    14,    15,    16,     4,     8,     9,     0,     0,
       0,     2,     5,     0,    10,    17,     0,     0,    19,    20,
       0,     5,    35,    51,    52,    53,     0,     0,     0,     0,
       0,    11,     0,    21,     0,    36,     0,    59,     0,     0,
       0,     0,    13,     0,    18,     0,     0,    58,    54,    55,
      56,    57,    12,    25,    26,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
      42,    43,     0,     0,    46,     0,     0,    38,     5,     5,
      39,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    47,    44,    45,    60,    61,     0,     0,     5,    40,
       0,     0,     0,     0,     0,    41,     0,     0,    22,     0,
      62,    63,     0,    48,     0,    50,     0,    23,     5,     0,
       0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,    -9,   -21,   -93,   -93,   168,   -93,   -93,   -93,
     -93,   163,   -93,   -93,    60,   -93,   172,   -93,   -67,   -93,
     -92,    -2,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     8,     2,     6,    16,    17,    18,    26,    10,
      28,    29,    66,    67,   119,    21,    22,    80,    94,    95,
      96,   126,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    32,   108,    50,    51,    40,    27,     3,    11,     4,
      45,    12,    13,    14,     7,     7,     9,    41,    33,    34,
      35,    38,   133,    33,    34,    35,   128,    23,    44,    52,
      48,    49,    50,    51,    46,    47,    20,    53,    48,    49,
      50,    51,    25,    39,    62,   108,    58,    59,    60,    61,
     108,    15,     5,    15,    68,   124,   125,    36,   108,    83,
     134,    37,    36,   137,    27,   135,    37,    72,    73,   142,
      63,    64,    65,    78,    79,   110,    30,    42,     5,    84,
      85,    57,   150,    48,    49,    50,    51,   129,   130,   104,
      54,   106,    15,    86,    55,    69,   120,   121,    70,    86,
     122,   123,    87,    88,    89,    90,    91,   136,    87,    88,
      89,    90,    91,    74,    48,    49,    50,    51,    92,     7,
      93,    77,   138,    99,    92,   100,    93,   149,   143,    11,
      86,   140,    12,    13,    14,   147,    86,   101,     5,    87,
      88,    89,    90,    91,   102,    87,    88,    89,    90,    91,
      48,    49,    50,    51,   105,    92,   103,    93,    86,   145,
     109,    92,   131,    93,   146,   151,   107,    87,    88,    89,
      90,    91,   111,   112,   113,   114,   115,   116,   117,   118,
     144,   148,    56,    92,    24,    93,    48,    49,    50,    51,
      71,    43,   139,    31,    48,    49,    50,    51,    75,   141,
       0,     0,    48,    49,    50,    51,    76,     0,     0,     0,
      48,    49,    50,    51,    81,     0,     0,     0,    48,    49,
      50,    51,    82,     0,     0,     0,    48,    49,    50,    51,
      97,     0,     0,     0,    48,    49,    50,    51,    98,     0,
       0,     0,    48,    49,    50,    51,   132,     0,     0,     0,
      48,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
       9,    22,    94,    47,    48,    41,     5,     0,     5,     7,
      31,     8,     9,    10,    50,    50,    11,    26,     3,     4,
       5,    23,    37,     3,     4,     5,    33,    44,    30,    38,
      45,    46,    47,    48,    36,    37,    12,    39,    45,    46,
      47,    48,     5,    44,    53,   137,    48,    49,    50,    51,
     142,    50,    50,    50,    56,    35,    36,    42,   150,    80,
      38,    46,    42,   130,     5,    43,    46,    69,    70,   136,
      19,    20,    21,    75,    76,    96,    42,    44,    50,    81,
      82,    43,   149,    45,    46,    47,    48,   108,   109,    91,
       5,    93,    50,     5,    39,    41,    98,    99,    41,     5,
     102,   103,    14,    15,    16,    17,    18,   128,    14,    15,
      16,    17,    18,     6,    45,    46,    47,    48,    30,    50,
      32,    43,   131,    44,    30,     5,    32,   148,    34,     5,
       5,   133,     8,     9,    10,   144,     5,     5,    50,    14,
      15,    16,    17,    18,     5,    14,    15,    16,    17,    18,
      45,    46,    47,    48,    42,    30,     5,    32,     5,    34,
      33,    30,    40,    32,    31,    34,    13,    14,    15,    16,
      17,    18,    22,    23,    24,    25,    26,    27,    28,    29,
      40,    33,    41,    30,    16,    32,    45,    46,    47,    48,
      41,    28,   132,    21,    45,    46,    47,    48,    41,   134,
      -1,    -1,    45,    46,    47,    48,    41,    -1,    -1,    -1,
      45,    46,    47,    48,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    41,    -1,    -1,    -1,
      45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    54,     0,     7,    50,    55,    50,    53,    11,
      60,     5,     8,     9,    10,    50,    56,    57,    58,    53,
      12,    66,    67,    44,    57,     5,    59,     5,    61,    62,
      42,    67,    54,     3,     4,     5,    42,    46,    72,    44,
      41,    53,    44,    62,    72,    54,    72,    72,    45,    46,
      47,    48,    53,    72,     5,    39,    41,    43,    72,    72,
      72,    72,    53,    19,    20,    21,    63,    64,    72,    41,
      41,    41,    72,    72,     6,    41,    41,    43,    72,    72,
      68,    41,    41,    54,    72,    72,     5,    14,    15,    16,
      17,    18,    30,    32,    69,    70,    71,    41,    41,    44,
       5,     5,     5,     5,    72,    42,    72,    13,    71,    33,
      54,    22,    23,    24,    25,    26,    27,    28,    29,    65,
      72,    72,    72,    72,    35,    36,    72,    73,    33,    54,
      54,    40,    41,    37,    38,    43,    54,    69,    53,    65,
      72,    73,    69,    34,    40,    34,    31,    53,    33,    54,
      69,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    68,    67,    69,
      69,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     0,     2,     0,     3,     1,
       2,     3,     5,     4,     1,     1,     1,     1,     3,     3,
       1,     2,    14,    16,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     0,    12,     2,
       3,     4,     2,     2,     3,     3,     2,     3,     5,    10,
       6,     1,     1,     1,     3,     3,     3,     3,     3,     2,
       1,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 12: /* declaracion: tipo IDENTIFICADOR ASIGNACION expresion saltos  */
#line 97 "imagen.y"
    {
        tipo_datoTS d; 
        strcpy(d.identificador, (yyvsp[-3].str));
        
        // Asignamos el tipo según lo que ha dicho la expresión (Bandera)
        d.tipo = (yyvsp[-1].expr).tipo; 
        
        // Guardamos el valor en el hueco correcto del union
        if (d.tipo == T_ENTERO) d.valor.valor_entero = (int)(yyvsp[-1].expr).valor;
        else d.valor.valor_real = (yyvsp[-1].expr).valor;
        
        insertar(&TS, d);
    }
#line 1296 "imagen.tab.c"
    break;

  case 13: /* declaracion: IDENTIFICADOR ASIGNACION expresion saltos  */
#line 111 "imagen.y"
    {
        // Asignación posterior (x := x + 1)
        tipo_valor val;
        if ((yyvsp[-1].expr).tipo == T_ENTERO) val.valor_entero = (int)(yyvsp[-1].expr).valor;
        else val.valor_real = (yyvsp[-1].expr).valor;
        
        actualizar(&TS, (yyvsp[-3].str), val, (yyvsp[-1].expr).tipo);
    }
#line 1309 "imagen.tab.c"
    break;

  case 17: /* lista_identificadores: IDENTIFICADOR  */
#line 125 "imagen.y"
    {
        // Declarar sin inicializar (basura o 0)
        tipo_datoTS d; strcpy(d.identificador, (yyvsp[0].str)); d.tipo = T_ENTERO; d.valor.valor_entero = 0;
        insertar(&TS, d);
    }
#line 1319 "imagen.tab.c"
    break;

  case 18: /* lista_identificadores: lista_identificadores COMA IDENTIFICADOR  */
#line 131 "imagen.y"
    {
        tipo_datoTS d; strcpy(d.identificador, (yyvsp[0].str)); d.tipo = T_ENTERO; d.valor.valor_entero = 0;
        insertar(&TS, d);
    }
#line 1328 "imagen.tab.c"
    break;

  case 22: /* figura: IDENTIFICADOR ASIGNACION MENOR tipo_figura3 COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos  */
#line 145 "imagen.y"
    {
        tipo_datoTS d; strcpy(d.identificador, (yyvsp[-13].str)); d.tipo = T_FIGURA;
        d.valor.valor_figura.subtipo = (yyvsp[-10].entero);
        
        // Evaluamos y guardamos los valores numéricos
        d.valor.valor_figura.p1 = (yyvsp[-8].expr).valor;  // posF
        d.valor.valor_figura.p2 = (yyvsp[-6].expr).valor;  // posC
        d.valor.valor_figura.p3 = (yyvsp[-4].expr).valor; // lado/radio
        strcpy(d.valor.valor_figura.color, (yyvsp[-2].str));
        
        insertar(&TS, d);
    }
#line 1345 "imagen.tab.c"
    break;

  case 23: /* figura: IDENTIFICADOR ASIGNACION MENOR tipo_figura4 COMA expresion COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos  */
#line 158 "imagen.y"
    {
        tipo_datoTS d; strcpy(d.identificador, (yyvsp[-15].str)); d.tipo = T_FIGURA;
        d.valor.valor_figura.subtipo = (yyvsp[-12].entero); // Rectangulo
        
        d.valor.valor_figura.p1 = (yyvsp[-10].expr).valor;
        d.valor.valor_figura.p2 = (yyvsp[-8].expr).valor;
        d.valor.valor_figura.p3 = (yyvsp[-6].expr).valor; // Alto
        d.valor.valor_figura.p4 = (yyvsp[-4].expr).valor; // Ancho
        strcpy(d.valor.valor_figura.color, (yyvsp[-2].str));
        
        insertar(&TS, d);
    }
#line 1362 "imagen.tab.c"
    break;

  case 24: /* tipo_figura3: CUADRADO  */
#line 172 "imagen.y"
                       { (yyval.entero) = F_CUADRADO; }
#line 1368 "imagen.tab.c"
    break;

  case 25: /* tipo_figura3: CIRCULO  */
#line 172 "imagen.y"
                                                      { (yyval.entero) = F_CIRCULO; }
#line 1374 "imagen.tab.c"
    break;

  case 26: /* tipo_figura4: RECTANGULO  */
#line 173 "imagen.y"
                         { (yyval.entero) = F_RECTANGULO; }
#line 1380 "imagen.tab.c"
    break;

  case 27: /* color: T_ROJO  */
#line 176 "imagen.y"
           { strcpy((yyval.str), "ROJO"); }
#line 1386 "imagen.tab.c"
    break;

  case 28: /* color: T_VERDE  */
#line 176 "imagen.y"
                                             { strcpy((yyval.str), "VERDE"); }
#line 1392 "imagen.tab.c"
    break;

  case 29: /* color: T_AZUL  */
#line 177 "imagen.y"
           { strcpy((yyval.str), "AZUL"); }
#line 1398 "imagen.tab.c"
    break;

  case 30: /* color: T_NARANJA  */
#line 177 "imagen.y"
                                               { strcpy((yyval.str), "NARANJA"); }
#line 1404 "imagen.tab.c"
    break;

  case 31: /* color: T_MARRON  */
#line 178 "imagen.y"
             { strcpy((yyval.str), "MARRON"); }
#line 1410 "imagen.tab.c"
    break;

  case 32: /* color: T_AMARILLO  */
#line 178 "imagen.y"
                                                    { strcpy((yyval.str), "AMARILLO"); }
#line 1416 "imagen.tab.c"
    break;

  case 33: /* color: T_NEGRO  */
#line 179 "imagen.y"
            { strcpy((yyval.str), "NEGRO"); }
#line 1422 "imagen.tab.c"
    break;

  case 34: /* color: T_GRIS  */
#line 179 "imagen.y"
                                              { strcpy((yyval.str), "GRIS"); }
#line 1428 "imagen.tab.c"
    break;

  case 37: /* $@1: %empty  */
#line 189 "imagen.y"
    {
        // 1. Abrimos ventana
        // Quitamos comillas a la cadena del título si es necesario
        nuevaVentanaImagen((yyvsp[-1].str), (int)(yyvsp[-5].expr).valor, (int)(yyvsp[-3].expr).valor);
    }
#line 1438 "imagen.tab.c"
    break;

  case 38: /* imagen: IMAGEN PAR_IZQ expresion COMA expresion COMA CADENA PAR_DER $@1 opt_saltos lista_acciones FINIMAGEN  */
#line 195 "imagen.y"
    {
        // 2. Pausa y cierre
        pausaImagen(1.5);
    }
#line 1447 "imagen.tab.c"
    break;

  case 42: /* instruccion: PONER IDENTIFICADOR  */
#line 208 "imagen.y"
    {
        tipo_datoTS d;
        if (buscar(TS, (yyvsp[0].str), &d) && d.tipo == T_FIGURA) {
            // RECUPERAMOS DATOS DE MEMORIA Y PINTAMOS
            float f = d.valor.valor_figura.p1;
            float c = d.valor.valor_figura.p2;
            float dim1 = d.valor.valor_figura.p3;
            float dim2 = d.valor.valor_figura.p4;
            int col = obtener_color(d.valor.valor_figura.color);
            
            if (d.valor.valor_figura.subtipo == F_RECTANGULO)
                rectanguloImagen(f, c, dim1, dim2, col);
            else if (d.valor.valor_figura.subtipo == F_CUADRADO)
                rectanguloImagen(f, c, dim1, dim1, col);
            else if (d.valor.valor_figura.subtipo == F_CIRCULO)
                circuloImagen(f, c, dim1, col);
        }
    }
#line 1470 "imagen.tab.c"
    break;

  case 43: /* instruccion: BORRAR IDENTIFICADOR  */
#line 227 "imagen.y"
    {
         tipo_datoTS d;
         if (buscar(TS, (yyvsp[0].str), &d)) {
             // Pintamos en BLANCO
             float f = d.valor.valor_figura.p1;
             float c = d.valor.valor_figura.p2;
             float dim1 = d.valor.valor_figura.p3;
             float dim2 = d.valor.valor_figura.p4;
             
             if (d.valor.valor_figura.subtipo == F_CIRCULO)
                circuloImagen(f, c, dim1, BLANCO);
             else if (d.valor.valor_figura.subtipo == F_RECTANGULO)
                 rectanguloImagen(f, c, dim1, dim2, BLANCO);
             else // Cuadrado
                 rectanguloImagen(f, c, dim1, dim1, BLANCO);
         }
    }
#line 1492 "imagen.tab.c"
    break;

  case 44: /* instruccion: HORIZONTAL IDENTIFICADOR expresion  */
#line 245 "imagen.y"
    {
        // Actualizamos la coordenada X (p2) en memoria
        tipo_datoTS d;
        if (buscar(TS, (yyvsp[-1].str), &d) && d.tipo == T_FIGURA) {
            d.valor.valor_figura.p2 += (yyvsp[0].expr).valor; // Sumar desplazamiento
            // Guardamos el cambio en la tabla
            actualizar(&TS, (yyvsp[-1].str), d.valor, T_FIGURA);
        }
    }
#line 1506 "imagen.tab.c"
    break;

  case 45: /* instruccion: VERTICAL IDENTIFICADOR expresion  */
#line 255 "imagen.y"
    {
        // Actualizamos la coordenada Y (p1) en memoria
        tipo_datoTS d;
        if (buscar(TS, (yyvsp[-1].str), &d) && d.tipo == T_FIGURA) {
            d.valor.valor_figura.p1 += (yyvsp[0].expr).valor; 
            actualizar(&TS, (yyvsp[-1].str), d.valor, T_FIGURA);
        }
    }
#line 1519 "imagen.tab.c"
    break;

  case 46: /* instruccion: PAUSA expresion  */
#line 263 "imagen.y"
                    { pausaImagen((yyvsp[0].expr).valor); }
#line 1525 "imagen.tab.c"
    break;

  case 47: /* instruccion: IDENTIFICADOR ASIGNACION expresion  */
#line 265 "imagen.y"
    { 
        // x := 5
        tipo_valor v; 
        if ((yyvsp[0].expr).tipo == T_ENTERO) v.valor_entero = (int)(yyvsp[0].expr).valor;
        else v.valor_real = (yyvsp[0].expr).valor;
        actualizar(&TS, (yyvsp[-2].str), v, (yyvsp[0].expr).tipo);
    }
#line 1537 "imagen.tab.c"
    break;

  case 48: /* instruccion: cabecera_si LLLAVE opt_saltos lista_acciones RLLAVE  */
#line 274 "imagen.y"
                                                        { /* No hacemos nada */ }
#line 1543 "imagen.tab.c"
    break;

  case 49: /* instruccion: cabecera_si LLLAVE opt_saltos lista_acciones RLLAVE SI_NO LLLAVE opt_saltos lista_acciones RLLAVE  */
#line 275 "imagen.y"
                                                                                                      { /* Nada */ }
#line 1549 "imagen.tab.c"
    break;

  case 50: /* instruccion: REPE expresion LLLAVE opt_saltos lista_acciones RLLAVE  */
#line 276 "imagen.y"
                                                           { /* Nada */ }
#line 1555 "imagen.tab.c"
    break;

  case 51: /* expresion: NUM  */
#line 282 "imagen.y"
      { 
          (yyval.expr).valor = (float)(yyvsp[0].entero); 
          (yyval.expr).tipo = T_ENTERO; // Bandera: Es entero
      }
#line 1564 "imagen.tab.c"
    break;

  case 52: /* expresion: NUMREAL  */
#line 287 "imagen.y"
      { 
          (yyval.expr).valor = (yyvsp[0].real); 
          (yyval.expr).tipo = T_REAL;   // Bandera: Es real
      }
#line 1573 "imagen.tab.c"
    break;

  case 53: /* expresion: IDENTIFICADOR  */
#line 292 "imagen.y"
      { 
          // Leemos de la memoria
          tipo_datoTS d;
          if (buscar(TS, (yyvsp[0].str), &d)) {
              if (d.tipo == T_ENTERO) {
                  (yyval.expr).valor = (float)d.valor.valor_entero;
                  (yyval.expr).tipo = T_ENTERO;
              } else {
                  (yyval.expr).valor = d.valor.valor_real;
                  (yyval.expr).tipo = T_REAL;
              }
          } else {
              (yyval.expr).valor = 0; (yyval.expr).tipo = T_ENTERO; // Error handling basico
          }
      }
#line 1593 "imagen.tab.c"
    break;

  case 54: /* expresion: expresion '+' expresion  */
#line 308 "imagen.y"
      { 
          (yyval.expr).valor = (yyvsp[-2].expr).valor + (yyvsp[0].expr).valor; 
          // Si alguno es Real, el resultado es Real (Promoción)
          if ((yyvsp[-2].expr).tipo == T_REAL || (yyvsp[0].expr).tipo == T_REAL) (yyval.expr).tipo = T_REAL;
          else (yyval.expr).tipo = T_ENTERO;
      }
#line 1604 "imagen.tab.c"
    break;

  case 55: /* expresion: expresion '-' expresion  */
#line 315 "imagen.y"
      { 
          (yyval.expr).valor = (yyvsp[-2].expr).valor - (yyvsp[0].expr).valor;
          if ((yyvsp[-2].expr).tipo == T_REAL || (yyvsp[0].expr).tipo == T_REAL) (yyval.expr).tipo = T_REAL;
          else (yyval.expr).tipo = T_ENTERO;
      }
#line 1614 "imagen.tab.c"
    break;

  case 56: /* expresion: expresion '*' expresion  */
#line 321 "imagen.y"
      { 
          (yyval.expr).valor = (yyvsp[-2].expr).valor * (yyvsp[0].expr).valor;
          if ((yyvsp[-2].expr).tipo == T_REAL || (yyvsp[0].expr).tipo == T_REAL) (yyval.expr).tipo = T_REAL;
          else (yyval.expr).tipo = T_ENTERO;
      }
#line 1624 "imagen.tab.c"
    break;

  case 57: /* expresion: expresion '/' expresion  */
#line 327 "imagen.y"
      { 
          (yyval.expr).valor = (yyvsp[-2].expr).valor / (yyvsp[0].expr).valor;
          (yyval.expr).tipo = T_REAL; // División siempre real
      }
#line 1633 "imagen.tab.c"
    break;

  case 58: /* expresion: PAR_IZQ expresion PAR_DER  */
#line 331 "imagen.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1639 "imagen.tab.c"
    break;

  case 59: /* expresion: '-' expresion  */
#line 332 "imagen.y"
                                 { (yyval.expr).valor = -(yyvsp[0].expr).valor; (yyval.expr).tipo = (yyvsp[0].expr).tipo; }
#line 1645 "imagen.tab.c"
    break;

  case 60: /* expresion_booleana: TRUE  */
#line 336 "imagen.y"
           { (yyval.entero) = 1; }
#line 1651 "imagen.tab.c"
    break;

  case 61: /* expresion_booleana: FALSE  */
#line 337 "imagen.y"
            { (yyval.entero) = 0; }
#line 1657 "imagen.tab.c"
    break;

  case 62: /* expresion_booleana: expresion IGUAL expresion  */
#line 338 "imagen.y"
                                { (yyval.entero) = ((yyvsp[-2].expr).valor == (yyvsp[0].expr).valor); }
#line 1663 "imagen.tab.c"
    break;

  case 63: /* expresion_booleana: expresion_booleana AND expresion_booleana  */
#line 339 "imagen.y"
                                                { (yyval.entero) = (yyvsp[-2].entero) && (yyvsp[0].entero); }
#line 1669 "imagen.tab.c"
    break;


#line 1673 "imagen.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 342 "imagen.y"

void yyerror(const char *s) { fprintf(stderr, "Error línea %d: %s\n", yylineno, s); }
