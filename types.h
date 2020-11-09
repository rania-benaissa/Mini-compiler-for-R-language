/* structure des quadruplets */

#ifndef TYPE_H
#define TYPE_H

typedef struct elt *liste;

typedef struct elt
{
    int pos;
    liste svt;

} elt;

typedef struct
{
    liste true;
    liste false;

} listes;

typedef struct
{
    liste next;

    int quad;

    char *idf;

} br;

/* la signature de la fonction pour eviter un warning

    parceque la fonction inserer est utilisée implicitement dans lexical.l*/

void inserer(char entite[], char code[], char type[], long taille, char declared[], int line, int chars);

#endif