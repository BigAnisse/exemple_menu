#ifndef JEU_H
#define JEU_H
#include <stdbool.h>
#include "plateau.h"
#include "constante.h"
// Caractères pour le tableau
#define AG 0xC9    // ╔
#define AD 0xBB    // ╗
#define BG 0xC8    // ╚
#define BD 0xBC    // ╝
#define LH 0xCD
#define LIGNE_V 0xBA    // ║
#define coeur 0x03
/*
 * La structure Jeu facilitera le passage de toutes les informations du jeu en un seul paramètre de fonction.
 * Toutefois, il faut éviter de toujours passer toutes les données (la structure jeu) aux fonctions.
 * Réfléchissez et ne donnez que ce qui est utile à la fonction.
 * Par exemple, la fonction afficherPlateau prend en paramètre le plateau, pas la structure jeu.
 */
typedef struct Jeu Jeu;
struct Jeu {
    bool partieEnCours;
    int nbJoueurs;
    int quiJoue;
    char nomJoueurActuel[4][10];
    int plateau[NB_LIGNES][NB_COLONNES];
    int joueurActuel;

};

void nouvellePartie(Jeu* jeu);
void chargerPartie(Jeu* jeu);
void partie(Jeu* jeu);
void initialiserJeu(Jeu* jeu);
void joueurSuivant(Jeu* jeu);
void clearMenuArea(int startLine, int numLines);
int de( int nbjoueur);

#endif