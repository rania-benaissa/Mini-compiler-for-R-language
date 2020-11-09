%{
    #include <String.h>
    #include "types.h"
    #include "syntax.tab.h"
    
    // compte le nombre de lignes
    int nb_lines = 1;
    // compte le nombre de characteres dans une ligne
    int nb_chars = 1;

    int lexical_error = 1;

    // le texte courant à analyser
    char * currentText ="";

    extern YYSTYPE yylval;
%}

idf [A-Z]([A-Za-z0-9])*

int_pos [0-9]+

int_neg "(-"[1-9]+")"

float ([0-9]+"."[0-9]+)|("(-"[0-9]+"."[0-9]+")")

char "'"."'"

bool "TRUE"|"FALSE"

comment "#"[^\n]*


%%

{comment} 

INTEGER {nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext); return mc_int;}

NUMERIC {nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext);return mc_float;}

CHARACTER {nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext);return mc_char;}

LOGICAL {nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext);return mc_bool;}

IF {nb_chars += yyleng;currentText = strdup(yytext);return mc_if;}

ELSE {nb_chars += yyleng;currentText = strdup(yytext);return mc_else;}

FOR {nb_chars += yyleng;currentText = strdup(yytext);return mc_for;}

IN {nb_chars += yyleng;currentText = strdup(yytext);return mc_in;}

IFELSE {nb_chars += yyleng;currentText = strdup(yytext);return mc_ifelse;}

WHILE {nb_chars += yyleng;currentText = strdup(yytext);return mc_while;}

and {nb_chars += yyleng;currentText = strdup(yytext); return mc_and;}

or {nb_chars += yyleng;currentText = strdup(yytext); return mc_or;}

{int_pos} {inserer(yytext,"CONSTANTE","INTEGER",1," / ",nb_lines,nb_chars); nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext);return int_pos;}

{int_neg} {inserer(yytext,"CONSTANTE","INTEGER",1," / ",nb_lines,nb_chars);nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext);return int_neg;}

{float} {inserer(yytext,"CONSTANTE","NUMERIC",1," / ",nb_lines,nb_chars);nb_chars += yyleng;yylval.value=strdup(yytext);currentText = strdup(yytext);return float_value;}

{char} {inserer(yytext,"CONSTANTE","CHARACTER",1," / ",nb_lines,nb_chars);nb_chars += yyleng; yylval.value=strdup(yytext);currentText = strdup(yytext);return char_value;}

{bool} {inserer(yytext,"CONSTANTE","LOGICAL",1," / ",nb_lines,nb_chars);nb_chars += yyleng; yylval.value=strdup(yytext);currentText = strdup(yytext);return bool_value;}



{idf} { 
        if(yyleng > 10) {printf("Erreur lexicale a la ligne %d colonne %d sur l'entite  %s  : identificateur trop long.\n",nb_lines,nb_chars,yytext); yyterminate();
        lexical_error=0;
         }
        nb_chars += yyleng;
        yylval.value= strdup(yytext);
        currentText = strdup(yytext);
     
        return idf; }
        

[\[\],{}():+*/><=-]  {nb_chars += yyleng;currentText = strdup(yytext); return yytext[0];}

">=" {nb_chars += yyleng;currentText = strdup(yytext);yylval.value=strdup(yytext);return sup_equal;}

"<=" {nb_chars += yyleng;currentText = strdup(yytext);yylval.value=strdup(yytext);return inf_equal;}

"==" {nb_chars += yyleng;currentText = strdup(yytext);yylval.value=strdup(yytext);return equal;}

"!=" {nb_chars += yyleng;currentText = strdup(yytext);yylval.value=strdup(yytext);return diff;}

"<-" {nb_chars += yyleng;currentText = strdup(yytext);  yylval.value=strdup(yytext);return affect;}

[ \t] {nb_chars += yyleng;}

\n {nb_lines++; nb_chars = 1;  return saut_ligne;} 

. {printf("Erreur lexicale a la ligne %d, colonne %d, sur l'entite : %s : entite non definie\n",nb_lines,nb_chars,yytext);lexical_error=0; }


%%

