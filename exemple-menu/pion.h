#ifndef PION_H
#define PION_H
#include "constante.h"




#define LIGNE_DEBUT 5  // Ligne où commence l'affichage du plateau
#define COL_DEBUT 5    // Colonne où commence l'affichage du plateau
#define LIGNE_DEBUT 5
#define COL_DEBUT 5
#define CASE_VIDE 0
#define MUR 9
bool estMouvementValide(int plateau[NB_LIGNES][NB_COLONNES], int nouvLig, int nouvCol, int ancienneLig, int ancienneCol);
bool deplacerPion(int plateau[NB_LIGNES][NB_COLONNES], int joueur, int* ligJ, int* colJ, char direction);
void tourJoueur(int plateau[NB_LIGNES][NB_COLONNES], int joueur);
void gotoligcol( int lig, int col );
void verifierVictoire(int plateau[NB_LIGNES][NB_COLONNES], int joueur);
bool victoireJoueur(int plateau[NB_LIGNES][NB_COLONNES], int joueur);
#endif