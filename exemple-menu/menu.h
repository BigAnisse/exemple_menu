#ifndef MENUS_H
#define MENUS_H
#include "jeu.h"

void menuPrincipal(Jeu* jeu);
void pause(void);
void afficherCredits(void);
void clearScreen(void);
void demanderNomJoueur();
void Color(int couleurDuTexte,int couleurDeFond);
void demanderPions( char*pion);
void afficherRegle();
void feuxArtifice ();
void animationDiagonale();
void animationExterne();

#endif