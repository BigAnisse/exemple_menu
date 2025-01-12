


#ifndef MUR_H

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include "plateau.h"
#include "pion.h"

#define MUR_H


typedef struct {
    int ligne;
    int colonne;
    bool estHorizontal;
    bool estPlace;
} DernierMur;


extern DernierMur dernierMurm;
void tourPlacementMur(int plateau[NB_LIGNES][NB_COLONNES], int joueur, int nbJoueur);
bool estPlacementMurValide(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col, bool estHorizontal);
#endif //MUR_H
