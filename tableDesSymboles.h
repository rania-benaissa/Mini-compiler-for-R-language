#ifndef TABLE_DES_SYMBOLES_H
#define TABLE_DES_SYMBOLES_H

#include <stdlib.h>
#include <stdio.h>
#include <String.h>

int error = 1;

//structure de la table des symboles
typedef struct element *listeH;

typedef struct element
{
    char nom[20];
    char nature[20];
    char type[20];
    long taille;
    char declared[3];
    listeH svt;

} element;

/* table des symboles est un tableau de pointeurs */
listeH ts[100];

// taille de la table des symboles
const int tsSize = 100;

// get key according to the idf's name
int getKey(char entite[])
{
    int key = 0;

    for (int i = 0; i < strlen(entite); i++)
    {
        key += (int)entite[i];
    }

    return key;
}

//hach function
int hach(int key)
{
    return key % tsSize;
}

//recherche verifie et retourne si une entité existe dans la TS
listeH recherche(char entite[])
{
    int key = getKey(entite);

    int indice = hach(key);

    listeH val = ts[indice];

    while (val != NULL)
    {
        // si ils sont pas egaux j'avance
        if (strcmp(val->nom, entite) != 0)
        {
            val = val->svt;
        }
        else
        {
            return val; // si nomEntité  = entité
        }
    }

    return NULL;
}

// insere un nouvel element dans la liste chainée
listeH insererElement(int indice)
{
    listeH dernier = ts[indice];

    //on creer le nouvel element a inserer
    listeH new = calloc(1, sizeof(element));

    new->svt = NULL;

    if (dernier != NULL)
    {
        while (dernier->svt != NULL)
        {
            dernier = dernier->svt;
        }

        dernier->svt = new;
    }
    else
    {
        ts[indice] = new;
    }

    return new;
}

//une fonction qui va insérer les entités du programme dans la TS
void inserer(char entite[], char code[], char type[], long taille, char declared[], int line, int chars)
{
    listeH element = NULL;

    char *temp_ent = calloc(50, sizeof(char));

    strcpy(temp_ent, entite);

    char *e = strchr(entite, '[');
    if (e != NULL)
    {
        char *temp = calloc(50, sizeof(char));

        strncpy(temp, entite, (int)(e - entite));
        strcpy(entite, temp);
    }

    int key = getKey(entite);

    int indice = hach(key);

    if (recherche(entite) == NULL) // s'il existe pas
    {

        // on insere une new ligne :
        element = insererElement(indice);

        strcpy(element->nom, entite);

        strcpy(element->nature, code);

        strcpy(element->type, type);

        strcpy(element->declared, declared);

        /*/si taille > 0 pas de soucis soit tab ou idf */
        if (taille > 0) //c est un tableau
        {
            element->taille = taille;
        }
    }
    else
    {

        //je remplace la variable par sa nouvelle valeur
        element = recherche(entite);

        // je remplace seulement si il n a pas été declaré
        if (strcmp(element->declared, "NO") == 0)
        {

            strcpy(element->nature, code);

            strcpy(element->type, type);

            element->taille = taille;
        }
        else
        {
            // si  l entité va etre ajouté as a declared one
            if (strcmp(declared, "YES") == 0)
            {
                printf("Erreur semantique a la ligne %d, colonne %d : < %s > est doublement declare\n", line, chars, entite);
                error = 0;
            }
        }
    }

    strcpy(entite, temp_ent);
}

void checkTableau(char tab[], char indice[], int line, int chars)
{

    if (recherche(tab) != NULL && recherche(indice) != NULL)
    {
        listeH element1 = recherche(tab);
        listeH element2 = recherche(indice);

        if (!strcmp(element2->type, "INTEGER") == 0)
        {
            printf("Erreur semantique a la ligne %d, colonne %d : indice incorrect.\n", line, chars);
            error = 0;
        }
        else
        {

            if (strcmp(element2->nature, "CONSTANTE") == 0)
            {
                if (element1->taille <= atoi(element2->nom))
                {
                    printf("Erreur semantique a la ligne %d, colonne %d sur  < %s > : taille du tableau depasse.\n", line, chars, element1->nom);
                    error = 0;
                }
            }
        }
    }
    else
    {
        if (recherche(indice) == NULL)
        {

            printf("Erreur semantique a la ligne %d, colonne %d sur  < %s > : identificateur non declare.\n", line, chars, indice);
            error = 0;
        }
    }
}

char *checkCompatible(char idf1[], char idf2[], int line, int chars)
{
    char *id1 = calloc(50, sizeof(char));
    char *id2 = calloc(50, sizeof(char));

    strcpy(id1, idf1);
    strcpy(id2, idf2);

    char *e = strchr(id1, '[');
    if (e != NULL)
    {
        char *temp = calloc(50, sizeof(char));

        strncpy(temp, id1, (int)(e - id1));
        strcpy(id1, temp);
    }

    e = strchr(id2, '[');
    if (e != NULL)
    {
        char *temp = calloc(50, sizeof(char));
        strncpy(temp, id2, (int)(e - id2));
        strcpy(id2, temp);
    }

    if (recherche(id1) != NULL && recherche(id2) != NULL)
    {
        listeH element1 = recherche(id1);
        listeH element2 = recherche(id2);

        if (strcmp(element1->type, element2->type) != 0)
        {
            printf("Erreur semantique a la ligne %d, colonne %d :  < %s > et <%s> sont incompatibles.\n", line, chars, idf1, idf2);
            error = 0;
        }

        return element1->type;
    }
    else
    {
        if (recherche(id1) == NULL)
        {

            printf("Erreur semantique a la ligne %d, colonne %d : < %s > non declare\n", line, chars, idf1);
            error = 0;
        }
        else
        {
            printf("Erreur semantique a la ligne %d, colonne %d : < %s > non declare\n", line, chars, idf2);
            error = 0;
        }
    }

    return "";
}

void divisionParZero(char idf[], int line, int chars)
{

    if (strcmp(idf, "0") == 0)
    {

        error = 0;
        printf("Erreur semantique a la ligne %d, colonne %d  : division par zero.\n", line, chars);
    }
}

//une fonction pour afficher la TS
void afficherTS()
{

    printf("\n\n\n\t\t                            Table des symboles                          \n");
    printf("\t\t___________________________________________________________________________\n");
    printf("\t\t|               |              |             |              |              \n");
    printf("\t\t|     Nom       |    Nature    |    Type     |    Taille    |    Declar\x82   \n");
    printf("\t\t|               |              |             |              |              \n");
    printf("\t\t---------------------------------------------------------------------------\n");

    listeH element = NULL;

    // pour chaque case de la ts
    for (int i = 0; i < tsSize; i++)
    {
        element = ts[i];

        // je verifie chaque liste chainée
        while (element != NULL)
        {
            printf("\t\t|%10s\t| %12s |%12s |%12ld  |%12s\n", element->nom, element->nature, element->type, element->taille, element->declared);

            element = element->svt;
        }
    }
}

#endif