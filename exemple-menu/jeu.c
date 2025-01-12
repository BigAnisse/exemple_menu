#include <stdio.h>
#include "menu.h"
#include "jeu.h"
#include "plateau.h"
#include "pion.h"
#include <windows.h>
#include <stdlib.h>
#include "constante.h"
#include <time.h>
#include "mur.h"


void afficherMenuPartie() {
    gotoligcol(10, 120);
    // AFFICHAGE DU MENU
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ACTIONS %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
    gotoligcol(11, 120);
    printf("%c                                      %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(12, 120);
    printf("%c  1. Déplacer mon pion               %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(13, 120);
    printf("%c  2. Poser un mur                     %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(14, 120);
    printf("%c  3. Pause                            %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(15, 120);
    printf("%c  4. Retour au menu principal         %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(16, 120);
    printf("%c                                      %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(17, 120);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BG,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,BD);
}

void nouvellePartie(Jeu *const jeu) {
    clearScreen();
    gotoligcol(0, 0);
    printf("Initialisation nouvelle partie...\n");
    initialiserJeu(jeu);
    partie(jeu);
}

void partie(Jeu *const jeu) {
    clearScreen();
    srand(time(NULL));
    afficherPlateau(jeu->plateau, 3, 5);


    // VARIABLE POUR CHOIX JOUEUR
    int choix;
    // TOUR VALIDER OU NON
    bool tourValide;
    // UTILISATION D UN DE POUR QUE LE JOUEUR QUI COMMENCE SOIT DESIGNER AU HASARD
    int chiffreDe = de(jeu->nbJoueurs);

    jeu->joueurActuel = chiffreDe;

    while(1) {
        gotoligcol(20, 120);
        afficherMenuPartie();


        gotoligcol(27, 121);
        // AFFICHER LE NOM DU JOUEUR ACTUEL
        printf("Tour du Joueur %s ", jeu->nomJoueurActuel[jeu->joueurActuel - 1]);



        gotoligcol(29,121);
        printf("Votre choix : ");
        scanf("%d", &choix);
        tourValide = true; // TOUR VALIDE INITIALISER A TRUE
        // CHOIX DE L ACTION
            switch (choix) {
                case 1: {
                    // DEPLACEMENT DES PIONS
                    tourJoueur(jeu->plateau, jeu->joueurActuel);
                    // VERIFIE SI APRES CHAQUE DEPLACEMENT LE JOUEUR A GAGNER
                    if (victoireJoueur(jeu->plateau, jeu->joueurActuel)) {
                        verifierVictoire(jeu->plateau, jeu->joueurActuel);
                        return; // Retour au menu principal si victoire
                    }


                    break;
                }
                case 2: {
                    gotoligcol(44, 0);
                    printf("Placement des murs en cours de développement...");
                    // DEPLACEMENT DES MUR
                    tourPlacementMur(jeu->plateau, jeu->joueurActuel, jeu->nbJoueurs);
                    Sleep(1500);
                    break;
                }
                case 3: {
                    pause();
                    clearScreen();
                    // AFFICHAGE DU PLATEAU
                    afficherPlateau(jeu->plateau, 3, 5);
                    break;
                }
                case 4: {
                    clearScreen();
                    // REVENIR AU MENU
                    return;
                }
                default: {
                    gotoligcol(47, 0);
                    printf("Choix incorrect !");
                    Sleep(1500);
                    tourValide = false;
                }

            }



        gotoligcol(47, 0);
        printf("                                                    ");
        gotoligcol(29,130);
        printf("                               ");
        if(tourValide) { // VERIFIE SI LE JOUEUR A ENTRER UN CHIFFRE ENTRE 0 ET 4
            joueurSuivant(jeu); // PASSAGE AU JOUEUR SUIVANT
        }
    }
}


void chargerPartie(Jeu *const jeu) {
    clearScreen();
    animationExterne(); // DECORATIF
    gotoligcol(20, 85); // AFFICHAGE DU MENU PRINCIPAL
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c MENU PRINCIPAL %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
    gotoligcol(21, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(22, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(23, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(24, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(25, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(26, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(27, 85);
    printf("%c                                          %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(28, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(29, 85);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BG,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,BD);
    gotoligcol(24, 90);
    printf("Chargement de la partie...\n");
gotoligcol(25,90);

    for (int i = 0; i < 15; i++) { // CREATION D UNE BARRE DE CHARGEMENT
        printf("_");
        Sleep(350);
    }
    gotoligcol(26,90);
    printf("Partie chargée !\n");
    Sleep(1000);
    partie(jeu);
}

void initialiserJeu(Jeu *const jeu) {
    jeu->partieEnCours = true;
    jeu->joueurActuel = 1;

    do { // AFFICHE LE CHOIX DU NOMBRE DES JOUEUR TANT QUE CELUI CI N EST PAS 2 OU 4
        clearScreen();


Color(5, 0);
gotoligcol(20, 70);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(21, 70);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(22, 70);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
_sleep(500);
// Coin supérieur droit
gotoligcol(20, 140);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(21, 140);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(22, 140);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
_sleep(500);

gotoligcol(28, 70);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(29, 70);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(30, 70);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
_sleep(500);

gotoligcol(28, 140);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(29, 140);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(30, 140);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
_sleep(500);

gotoligcol(16, 60);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(17, 60);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(18, 60);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

// Haut droite supplémentaire
gotoligcol(16, 150);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(17, 150);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(18, 150);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);


gotoligcol(32, 60);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(33, 60);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(34, 60);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);


gotoligcol(32, 150);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(33, 150);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(34, 150);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);


gotoligcol(24, 50);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(25, 50);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(26, 50);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);


gotoligcol(24, 160);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(25, 160);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(26, 160);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);



        gotoligcol(24, 90);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
               LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
        gotoligcol(25,90);
        printf("%c   Nombre de joueurs (2/4):    %c\n", LIGNE_V, LIGNE_V);
        gotoligcol(26,90);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BG,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
               LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,BD);


Color(15, 0);


        gotoligcol(24, 90);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
               LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
        gotoligcol(25,90);
        printf("%c   Nombre de joueurs (2/4):    %c\n", LIGNE_V, LIGNE_V);
        gotoligcol(26,90);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BG,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
               LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,BD);

        gotoligcol(25, 118);
        scanf("%d", &jeu->nbJoueurs);
        clearScreen();
        while (getchar() != '\n');
    } while (jeu->nbJoueurs != 2 && jeu->nbJoueurs != 4);
    animationDiagonale();
        for (int i = 0; i < jeu->nbJoueurs; i++) {

            Color(15,0);
            gotoligcol(24,85);
            printf("Nom du joueur %d : ", i + 1); // LE NOM DU JOUEUR SRA STOCKER DANS UN TABLEAU
            demanderNomJoueur(jeu->nomJoueurActuel[i]);
            gotoligcol(25,85);
            printf("pion du joueur %d : ", i + 1); // LE PION DU JOUEUR SERA STOCKER DANS UNE TABLEAU
            demanderPions(pionJoueurActuel[i]);
            printf("\n");
        }



    initialiserPlateau(jeu->plateau, jeu->nbJoueurs);
}

void joueurSuivant(Jeu *const jeu) {  // PERMET DE PASSER AU JOUEUR SUIVANT EN INCREMENTANT DE 1 JUSQAU NB DE JOUEUR
    jeu->joueurActuel = (jeu->joueurActuel % jeu->nbJoueurs) + 1;
}

int de( int nbjoueur) {  // FONCTION POUR LE DE
    return (rand() % nbjoueur) + 1;
}