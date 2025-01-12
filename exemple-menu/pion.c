#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include "plateau.h"
#include "pion.h"
#include "menu.h"
#include "jeu.h"
#include "constante.h"




char *getSymboleJoueur(int joueur, char pionJoueurActuel[4][3]) { // PERMET DE RECUPERER LE SYMBOLE QUE CHAQUE JOUEUR A CHOISIS
    switch (joueur) {
        case JOUEUR_1: return pionJoueurActuel[0];
        case JOUEUR_2: return pionJoueurActuel[1];
        case JOUEUR_3: return pionJoueurActuel[2];
        case JOUEUR_4: return pionJoueurActuel[3];
        default: return " ";
    }
}


void effacerPion(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col) { // EFFACE LES PIONS PAR RAPORT A LA LIGNE ET COLONNE
    if (lig >= 0 && lig < NB_LIGNES && col >= 0 && col < NB_COLONNES) {
        int ligneConsole = LIGNE_DEBUT + (lig * 2); // CALCULE DE LA POSITION DU PION
        int colonneConsole = COL_DEBUT + (col * 5)-1;

        gotoligcol(ligneConsole, colonneConsole);
        printf(" "); // PERMET D EFFACER LE PION
        plateau[lig][col] = CASE_VIDE;
    }
}


void dessinerPion(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col, int joueur) { // DESSINE LE PION EN FONCTION DE SA POSITION
    if (lig >= 0 && lig < NB_LIGNES && col >= 0 && col < NB_COLONNES) {
        int ligneConsole = LIGNE_DEBUT + (lig * 2);  // CALCULE LA POSITION OU PLACE LE PION
        int colonneConsole = COL_DEBUT + (col * 5)-1;

        gotoligcol(ligneConsole, colonneConsole);
        printf("%s", getSymboleJoueur(joueur,pionJoueurActuel));
        plateau[lig][col] = joueur;
    }
}

bool estMouvementValide(int plateau[NB_LIGNES][NB_COLONNES], int nouvLig, int nouvCol, int ancienneLig,
                        int ancienneCol) {
    // 1. Vérifier les limites du plateau
    if (nouvLig < 0 || nouvLig >= NB_LIGNES || nouvCol < 0 || nouvCol >= NB_COLONNES) { // VERIFIE LES LIMITES DU TABLEAU
        return false;
    }


    if (plateau[nouvLig][nouvCol] == MUR || (plateau[nouvLig][nouvCol] > 0 && plateau[nouvLig][nouvCol] < 5)) {
        return false; // VERIFIE LA PRESENCE D4UN MUR
    }


    int diffLig = nouvLig - ancienneLig;
    int diffCol = nouvCol - ancienneCol;


    if (abs(diffLig) + abs(diffCol) != 2) { // VERIFIE QUE LE JOUEUR S4EST DEPLACER DE DEUX CASE
        return false;
    }


    int ligIntermediaire = ancienneLig + (diffLig / 2);
    int colIntermediaire = ancienneCol + (diffCol / 2);
    if (plateau[ligIntermediaire][colIntermediaire] == MUR ||
        (plateau[ligIntermediaire][colIntermediaire] > 0 &&
         plateau[ligIntermediaire][colIntermediaire] < 5)) {
        return false;
    }

    return true;
}


bool deplacerPion(int plateau[NB_LIGNES][NB_COLONNES], int joueur, int *ligJ, int *colJ, char direction) {
    int nouvLig = *ligJ;
    int nouvCol = *colJ;


    switch (direction) {
        case 'z': nouvLig = *ligJ - 2;
            break; // haut
        case 's': nouvLig = *ligJ + 2;
            break; // bas
        case 'q': nouvCol = *colJ - 2;
            break; // gauche
        case 'd': nouvCol = *colJ + 2;
            break; // droite
        default: return false;
    }


    if (!estMouvementValide(plateau, nouvLig, nouvCol, *ligJ, *colJ)) {
        Color(5,0);
        gotoligcol(21, 120);
        printf("Mouvement impossible ! ");
        Sleep(500);
        gotoligcol(21, 120);
        printf("                      ");
        Color(15,0);
        return false;
    }



    effacerPion(plateau, *ligJ, *colJ);


    *ligJ = nouvLig;
    *colJ = nouvCol;


    dessinerPion(plateau, *ligJ, *colJ, joueur);

    return true;
}


void tourJoueur(int plateau[NB_LIGNES][NB_COLONNES], int joueur) {
    int ligJ = -1, colJ = -1;


    for (int i = 0; i < NB_LIGNES && ligJ == -1; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (plateau[i][j] == joueur) {
                ligJ = i;
                colJ = j;
                break;
            }
        }
    }

    if (ligJ == -1) {
        printf("Erreur: Pion du joueur %d non trouvé!\n", joueur);
        return;
    }


    gotoligcol(19, 123);
    printf("Joueur %d (%s): ZQSD pour deplacer, Espace pour finir    ", joueur, getSymboleJoueur(joueur, pionJoueurActuel));


    char touche;
    bool tourFini = false;

    do {
        if (_kbhit()) {

            touche = _getch();

            switch (touche) {
                case 'z':
                case 's':
                case 'q':
                case 'd':
                    deplacerPion(plateau, joueur, &ligJ, &colJ, touche);
                    break;
                case ' ':
                    tourFini = true;
                    break;
            }
        }
    } while (!tourFini);


    gotoligcol(19, 123);
    printf("                                                         ");
    gotoligcol(2, 1);
    printf("                    ");
}

bool victoireJoueur(int plateau[NB_LIGNES][NB_COLONNES], int joueur) {

    for (int col = 0; col < NB_COLONNES; col++) {

        if (joueur == 1 && plateau[NB_LIGNES - 1][col] == 1) {
            return true;
        }

        if (joueur == 2 && plateau[0][col] == 2) {
            return true;
        }
    }
    for (int lig = 0; lig < NB_LIGNES; lig++) {
            if (joueur == 3 && plateau[lig][NB_COLONNES - 1] == 3) {
                return true;
            }
            if (joueur == 4 && plateau[lig][0] == 4) {
                return true;
            }

    }
    return false;
}

void verifierVictoire(int plateau[NB_LIGNES][NB_COLONNES], int joueur) {
    if (victoireJoueur(plateau, joueur)) {

        clearScreen();
        feuxArtifice();
        Color(15,0);
        gotoligcol(30, 90);
        printf("Felicitation ! Joueur %d (%s) a gagne !\n", joueur, getSymboleJoueur(joueur, pionJoueurActuel));
        Sleep(10000);
        clearScreen();

    }
}
