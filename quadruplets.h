#ifndef QUADRUPLETS_H
#define QUADRUPLETS_H

#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "types.h"

typedef struct quad
{
    char op[5];
    char arg1[20];
    char arg2[20];
    char res[20];

} quad;

quad quads[100];

// l indice du quad courant
int currentQuad = 0;

//indice des vars temporaires
int currentTemp = 1;
// taille de la matrice
const int quadsSize = 100;

/* converts an int into a char */
char *intToChar(int val)
{
    char *temp = calloc(10, sizeof(char));

    char *number = calloc(10, sizeof(char));

    itoa(val, number, 10);

    return number;
}

// genere  le quad
int genererQuad(char op[], char arg1[], char arg2[], char res[])
{
    strcpy(quads[currentQuad].op, op);
    strcpy(quads[currentQuad].arg1, arg1);
    strcpy(quads[currentQuad].arg2, arg2);
    strcpy(quads[currentQuad].res, res);

    return currentQuad++;
}

// modifie l'adresse du quad (la partie resultat)
void modifyQuad(int pos, int res)
{

    strcpy(quads[pos].res, intToChar(res));
}

// creer une var temporaire
char *getTemp()
{
    char *temp = calloc(10, sizeof(char));

    strcpy(temp, "x");

    char *number = calloc(10, sizeof(char));

    itoa(currentTemp, number, 10);

    strcat(temp, number);

    currentTemp++;

    return temp;
}

// ajoute la position d'un quad dans une des listes
liste addPosQuad(liste l)
{
    liste dernier = NULL;

    if (l == NULL)
    {
        l = calloc(1, sizeof(int));
        l->pos = currentQuad;
        l->svt = NULL;
    }
    else
    {

        dernier = l;

        while (dernier->svt != NULL)
        {
            dernier = dernier->svt;
        }

        dernier->svt = calloc(1, sizeof(int));

        dernier = dernier->svt;

        dernier->pos = currentQuad;
        dernier->svt = NULL;
    }

    return l;
}

liste removePosQuad(liste l, int value)
{
    liste dernier = NULL;

    if (l != NULL)
    {

        dernier = l;

        while (dernier != NULL)
        {
            // le plus 1 psk le current quad commence a 0

            modifyQuad(dernier->pos, value + 1);

            dernier = dernier->svt;
        }

        l = NULL;
    }

    return l;
}

liste fusion(liste l1, liste l2)
{

    liste new = NULL;

    liste tete = l1;

    if (tete == NULL)
    {
        return l2;
    }
    else
    {

        while (tete->svt != NULL)
        {
            tete = tete->svt;
        }

        while (l2 != NULL)
        {

            new = calloc(1, sizeof(int));
            new->pos = l2->pos;
            new->svt = NULL;
            tete->svt = new;

            tete = tete->svt;
            l2 = l2->svt;
        }
    }

    return l1;
}

void afficherQuads()
{

    printf("\n\n\n\t\t\t                        Quadruplets                    \n");
    printf("\t\t_______________________________________________________________________________\n");
    printf("\t\t|         |        |                   |                  |              \n");
    printf("\t\t|  Ligne  |   OP   |        ARG1       |       ARG2       |      RES     \n");
    printf("\t\t|         |        |                   |                  |              \n");
    printf("\t\t-------------------------------------------------------------------------------\n");

    int addENd = 0;

    for (int i = 0; i < currentQuad; i++)
    {

        if (atoi(quads[i].res) == currentQuad + 1)
            addENd = 1;
    }
    if (addENd)
        currentQuad++;

    // pour chaque case de la ts
    for (int i = 0; i < currentQuad; i++)
    {
        printf("\t\t|   %2d    |  %3s   |%15s    |%15s   |    %15s   \n", i + 1, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
    }
}

#endif
