#ifndef PLATEAU_H
#define PLATEAU_H
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "jeu.h"
#include "constante.h"
#define CASE_VIDE 0
#define JOUEUR_1 1
#define JOUEUR_2 2
#define JOUEUR_3 3
#define JOUEUR_4 4
#define MUR 9

// Définition des constantes pour améliorer la lisibilité
#define CASE_VIDE 0
#define JOUEUR_1 1
#define JOUEUR_2 2
#define JOUEUR_3 3
#define JOUEUR_4 4
#define MUR 9

// Définition des symboles pour les pions utilisant les codes ASCII étendus
#define SYMBOLE_J1 " @  "  // Cœur pour joueur 1
#define SYMBOLE_J2 " $  "  // Visage souriant pour joueur 2
#define SYMBOLE_J3 " *  "  // Spade pour joueur 3
#define SYMBOLE_J4 " ?  "  // Diamond pour joueur 4
#define SYMBOLE_MUR "B" // Block plein pour mur
#define SYMBOLE_VIDE " "


void afficherPlateau(int plateau[NB_LIGNES][NB_COLONNES], int ligneCouleur, int colonneCouleur);
void initialiserPlateau(int plateau[NB_LIGNES][NB_COLONNES], int nbJoueurs);
void afficherLigneVide();

#endif

