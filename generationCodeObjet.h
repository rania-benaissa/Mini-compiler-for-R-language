#ifndef GENERATION_CODE_OBJET_H
#define GENERATION_CODE_OBJET_H

#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "quadruplets.h"

typedef struct instruction
{
    char numQuad[10];
    char inst[100];

} instruction;

instruction code[1000];

// l indice de l'instruction courante
int currentCode = 0;

/* LABELS */
typedef struct label
{
    char name[50];
    char numQuad[10];

} label;

label labels[100];

// l indice de l'etiquette courante
int currentLabel = 0;

void afficherCode()
{

    printf("\n\n\n\t\t\t                        Code Objet                    \n");
    printf("\t\t__________________________________________________________________________\n");
    printf("\t\t|   Numero du quadruplet   |              Instruction assembleur              \n");
    printf("\t\t|                          |                                                  \n");
    printf("\t\t---------------------------------------------------------------------------\n");

    // pour chaque case de la ts
    for (int i = 0; i < currentCode; i++)
    {

        printf("\t\t|  %12s            |  %8s \n", code[i].numQuad, code[i].inst);
    }
}

void generateArithm(int i)
{
    quad q = quads[i];

    snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV AX,%s", q.arg1);
    currentCode++;

    if (strcmp(q.op, "+") == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "ADD AX,%s", q.arg2);
    }
    if (strcmp(q.op, "*") == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MUL %s", q.arg2);
    }

    if (strcmp(q.op, "-") == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "SUB AX,%s", q.arg2);
    }

    if (strcmp(q.op, "/") == 0 || strcmp(q.op, "%") == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "DIV %s", q.arg2);
    }

    currentCode++;

    if (strcmp(q.op, "%") == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV %s,AH", q.res);
    }
    else
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV %s,AX", q.res);
    }

    currentCode++;
}

char *labelExists(char *numQuad)
{

    for (int i = 0; i < currentLabel; i++)
    {
        if (strcmp(labels[i].numQuad, numQuad) == 0)
        {

            return labels[i].name;
        }
    }
    return "";
}

char *createLabel(char *numQuad)
{
    char *etiquette = calloc(50, sizeof(char));

    // creating the label
    if (strcmp(labelExists(numQuad), "") == 0)
    {
        strcpy(labels[currentLabel].numQuad, numQuad);
        snprintf(labels[currentLabel].name, sizeof(labels[currentLabel].name), "Label_%s", intToChar(currentLabel + 1));
        strcpy(etiquette, labels[currentLabel].name);
        currentLabel++;
    }
    else
    {
        strcpy(etiquette, labelExists(numQuad));
    }

    return etiquette;
}

int generateCmp(int i)
{
    quad q = quads[i];

    char etiquette[50];

    // si c'est pas juste un instruction inconditionnelle
    if (strcmp(q.op, "BR") != 0)
    {
        // on fait la comparaison
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "CMP %s, %s", q.arg1, q.arg2);
        currentCode++;

        // on affecte le num du quadruplet au code
        strcpy(code[currentCode].numQuad, intToChar(i + 2));

        if (strcmp(q.op, ">") == 0)
        {

            if (atoi(quads[i + 1].res) == i + 3)
            {

                strcpy(etiquette, createLabel(q.res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JA %s", etiquette);
            }
            else
            {
                strcpy(etiquette, createLabel(quads[i + 1].res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JBE %s", etiquette);
            }
        }
        if (strcmp(q.op, ">=") == 0)
        {
            if (atoi(quads[i + 1].res) == i + 3)
            {
                strcpy(etiquette, createLabel(q.res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JAE %s", etiquette);
            }
            else
            {
                strcpy(etiquette, createLabel(quads[i + 1].res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JB %s", etiquette);
            }
        }
        if (strcmp(q.op, "<") == 0)
        {
            if (atoi(quads[i + 1].res) == i + 3)
            {
                strcpy(etiquette, createLabel(q.res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JB %s", etiquette);
            }
            else
            {
                strcpy(etiquette, createLabel(quads[i + 1].res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JAE %s", etiquette);
            }
        }
        if (strcmp(q.op, "<=") == 0)
        {
            if (atoi(quads[i + 1].res) == i + 3)
            {
                strcpy(etiquette, createLabel(q.res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JBE %s", etiquette);
            }
            else
            {
                strcpy(etiquette, createLabel(quads[i + 1].res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JA %s", etiquette);
            }
        }
        if (strcmp(q.op, "==") == 0)
        {
            if (atoi(quads[i + 1].res) == i + 3)
            {
                strcpy(etiquette, createLabel(q.res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JE %s", etiquette);
            }
            else
            {
                strcpy(etiquette, createLabel(quads[i + 1].res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JNE %s", etiquette);
            }
        }
        if (strcmp(q.op, "!=") == 0)
        {
            if (atoi(quads[i + 1].res) == i + 3)
            {
                strcpy(etiquette, createLabel(q.res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JNE %s", etiquette);
            }
            else
            {
                strcpy(etiquette, createLabel(quads[i + 1].res));
                snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JE %s", etiquette);
            }
        }
        currentCode++;

        return 1;
    }
    else
    {
        strcpy(etiquette, createLabel(q.res));
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "JMP %s", etiquette);
        currentCode++;
        return 0;
    }
}

int isAlpha(char k)
{

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (c == k)
        {

            return 1;
        }
    }

    if (k == 'x')
        return 1;

    return 0;
}

int generateAffect(int i)
{

    quad q = quads[i];

    if (strcmp("True", q.arg1) == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV %s,1", q.res);
        currentCode++;
        return 1;
    }

    if (strcmp("False", q.arg1) == 0)
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV %s,0", q.res);
        currentCode++;
        return 1;
    }

    if (isAlpha(q.arg1[0]) && isAlpha(q.res[0]))
    {
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV AX,%s", q.arg1);
        currentCode++;
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV %s,AX", q.res);
        currentCode++;
        return 1;
    }

    snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "MOV %s,%s", q.res, q.arg1);
    currentCode++;
    return 1;
}

void addLabels()
{
    char etiquette[50] = "";
    char temp[50] = "";

    for (int j = 0; j < currentCode; j++)
    {
        if (!strcmp(code[j].numQuad, "") == 0)
        {
            if (strcmp(labelExists(code[j].numQuad), "") != 0)
            {

                strcpy(etiquette, labelExists(code[j].numQuad));

                strcpy(temp, code[j].inst);

                snprintf(code[j].inst, sizeof(code[j].inst), "%s : %s", etiquette, temp);
            }
        }
    }

    if (!strcmp(labelExists(intToChar(currentQuad)), "") == 0)
    {
        strcpy(code[currentCode].numQuad, intToChar(currentQuad));
        strcpy(etiquette, labelExists(intToChar(currentQuad)));
        snprintf(code[currentCode].inst, sizeof(code[currentCode].inst), "%s :", etiquette);
        currentCode++;
    }
}

// genere le code objet a partir de la table des quadruplets optimisée
void generateCode()
{
    // we loop through the quads tab
    for (int i = 0; i < currentQuad; i++)
    {
        if (!strcmp(quads[i].op, "") == 0)
        {
            int comp = 1;
            // on affecte le num du quadruplet
            strcpy(code[currentCode].numQuad, intToChar(i + 1));

            if (strcmp(quads[i].op, "+") == 0 || strcmp(quads[i].op, "-") == 0 ||
                strcmp(quads[i].op, "*") == 0 || strcmp(quads[i].op, "/") == 0 ||
                strcmp(quads[i].op, "%") == 0)
            {

                comp = 0;
                generateArithm(i);
            }

            if (strcmp(quads[i].op, "<-") == 0)
            {
                comp = 0;
                generateAffect(i);
            }
            if (comp == 1)
            {
                if (generateCmp(i))
                {
                    i++;
                }
            }
        }
    }
    addLabels();
    afficherCode();
}

#endif

