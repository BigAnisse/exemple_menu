#include <stdbool.h>
#include <windows.h>
#include "jeu.h"
#include <stdio.h>
#include "constante.h"
#include "menu.h"

// Fonction de validation du nombre de joueurs
bool estNombreJoueursValide(int nbJoueurs) {
    return nbJoueurs == 2 || nbJoueurs == 4;
}
void initialiserPlateau(int plateau[NB_LIGNES][NB_COLONNES], int nbJoueurs) {
    if (!estNombreJoueursValide(nbJoueurs)) {
        printf("Erreur : nombre de joueurs invalide (2 ou 4 uniquement)\n");
        return;
    }

    // Vider le plateau avec une constante plutôt qu'un nombre magique
    for(int i = 0; i < NB_LIGNES; i++) {
        for(int j = 0; j < NB_COLONNES; j++) {
            plateau[i][j] = CASE_VIDE;
        }
    }

    // Placement des pions avec des positions calculées
    const int centreColonne = (NB_COLONNES / 2) ;
    const int centreLigne = NB_LIGNES / 2;

    // Placement des joueurs de base (2 joueurs minimum)
    Color(9,0);
    plateau[0][centreColonne ] = JOUEUR_1;
    Color(10,0);
    plateau[NB_LIGNES-1][centreColonne] = JOUEUR_2;

    // Ajout des joueurs supplémentaires si 4 joueurs
    if(nbJoueurs == 4) {
        Color(3,0);
        plateau[centreLigne][0] = JOUEUR_3;
        Color(12,0);
        plateau[centreLigne][NB_COLONNES - 1] = JOUEUR_4;
    }
    Color(15,0);
}

const char* obtenirSymbolePion(int valeurCase, char pionJoueurActuel[4][3]) {
    switch(valeurCase) {
        case JOUEUR_1: return pionJoueurActuel[0];
        case JOUEUR_2: return pionJoueurActuel[1];
        case JOUEUR_3: return pionJoueurActuel[2];
        case JOUEUR_4: return pionJoueurActuel[3];
        case MUR: return SYMBOLE_MUR;
        default: return SYMBOLE_VIDE;
    }
}
void afficherPlateau(int plateau[NB_LIGNES][NB_COLONNES], int ligneCouleur, int colonneCouleur) {
    printf("\nPlateau de jeu Corridor\n\n");

    // En-tête avec numéros de colonnes
    printf("    ");
    for (int j = 0; j < NB_COLONNES; j++) {
        Color(14,0);
        if (j <= 9) {
            printf("  %d  ", j);
        } else {
            printf(" %d  ", j);
        }
    }
    printf("\n");

    // Première ligne du cadre
    Color(13,0);
    printf("   %c", 0xDA); // ┌
    for (int j = 0; j < NB_COLONNES; j++) {
        printf("%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC2); // ─ ┬
    }
    printf("\b%c\n", 0xBF); // ┐

    // Contenu du plateau
    for (int i = 0; i < NB_LIGNES; i++) {

        Color(14,0);
        // Affiche les numéros de ligne
        if (i <= 9) {

            printf(" %d %c", i, 0xB3); // Numéro de ligne et │
        } else {
            printf("%d %c", i, 0xB3); // Numéro de ligne et │
        }

        // Affichage des pions et des barres verticales
        for (int j = 0; j < NB_COLONNES; j++) {



                printf("%s   %c", obtenirSymbolePion(plateau[i][j],pionJoueurActuel), 0xB3); // Texte normal
            }



        printf("\n");
        Color(13,0);
        // Lignes horizontales entre les rangées (sauf après la dernière rangée)
        if (i < NB_LIGNES - 1) {
            printf("   %c", 0xC3); // ├
            for (int j = 0; j < NB_COLONNES; j++) {
                printf("%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC5); // ─ ┼
            }
            printf("\b%c\n", 0xB4); // ┤
        }
    }

    // Dernière ligne du cadre
    printf("   %c", 0xC0); // └
    for (int j = 0; j < NB_COLONNES; j++) {
        printf("%c%c%c%c%c", 0xC4, 0xC4, 0xC4, 0xC4, 0xC1); // ─ ┴
    }
    printf("\b%c\n", 0xD9); // ┘
    Color(15,0);
}