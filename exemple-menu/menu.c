#include <stdio.h>
#include <windows.h>
#include "menu.h"
#include "jeu.h"
#include "pion.h"
#include <conio.h>
#include <math.h>

void clearScreen() {
    system("cls"); // SUPPRIME TOUT CE QU4IL Y A A L ECRAN
}

// ICI BEAUCOUP DE FONCTION CONCERNANT L AFFICHAGE
void afficherMenu() {
    Color(15, 0);
    gotoligcol(20, 85);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c MENU PRINCIPAL %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
    gotoligcol(21, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(22, 85);
    printf("%c  0. Reprendre la partie                  %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(23, 85);
    printf("%c  1. Nouvelle partie                      %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(24, 85);
    printf("%c  2. Charger partie                       %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(25, 85);
    printf("%c  3. Credits                              %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(26, 85);
    printf("%c  4. Quitter                              %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(27, 85);
    printf("%c  5. afficher les regle                   %c\n",LIGNE_V,LIGNE_V);
    gotoligcol(28, 85);
    printf("%c                                          %c\n", LIGNE_V, LIGNE_V);
    gotoligcol(29, 85);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BG,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,BD);
}

void menuPrincipal(Jeu *const jeu) {
    int choix;
    while (1) {
        clearScreen();
        Color(6, 0);
        // Carrés originaux (déjà présents dans votre code)
        // Coin supérieur gauche
        Color(5, 0);
        gotoligcol(20, 70);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(21, 70);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(22, 70);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Coin supérieur droit
        gotoligcol(20, 140);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(21, 140);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(22, 140);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Coin inférieur gauche
        gotoligcol(28, 70);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(29, 70);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(30, 70);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Coin inférieur droit
        gotoligcol(28, 140);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(29, 140);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(30, 140);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Carrés supplémentaires pour élargir le décor
        // Haut gauche supplémentaire
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

        // Bas gauche supplémentaire
        gotoligcol(32, 60);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(33, 60);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(34, 60);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Bas droite supplémentaire
        gotoligcol(32, 150);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(33, 150);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(34, 150);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Ajouter un carré au centre gauche
        gotoligcol(24, 50);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(25, 50);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(26, 50);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Ajouter un carré au centre droit
        gotoligcol(24, 160);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(25, 160);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(26, 160);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);

        // Le menu central
        gotoligcol(24, 90);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
               LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
        gotoligcol(25, 90);
        printf("%c   Nombre de joueurs (2/4):    %c\n", LIGNE_V, LIGNE_V);
        gotoligcol(26, 90);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", BG,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
               LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,BD);

        afficherMenu(jeu);
        gotoligcol(30,95);
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                clearScreen();
                nouvellePartie(jeu);
                break;
            }
            case 2: {
                clearScreen();
                chargerPartie(jeu);
                break;
            }
            case 3: {
                clearScreen();
                afficherCredits();
                printf("\nAppuyez sur Entrée pour revenir au menu...");
                fflush(stdin);
                getchar();
                break;
            }
            case 4: {
                clearScreen();
                gotoligcol(0, 0);
                printf("Au revoir !\n");
                return;
            }
            case 5: {
                clearScreen();
                afficherRegle();
                fflush(stdin);
                getchar();
                break;
            }
            case 0: {
                if (jeu->partieEnCours) {
                    clearScreen();
                    partie(jeu);
                    break;
                }
                // Si pas de partie en cours, afficher message d'erreur
                gotoligcol(12, 0);
                printf("Aucune partie en cours !");
                Sleep(1500); // Pause de 1.5 secondes
                break;
            }
            default: {
                gotoligcol(35, 95);
                printf("Choix incorrect !");
                Sleep(1500); // Pause de 1.5 secondes
                break;
            }
        }
    }
}

void pause(void) {
    clearScreen();
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PAUSE %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
    printf("%c                                                %c\n", LIGNE_V, LIGNE_V);
    printf("%c     Appuyez sur Entrée pour reprendre...      %c\n", LIGNE_V, LIGNE_V);
    printf("%c                                                %c\n", LIGNE_V, LIGNE_V);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BG,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,BD);
    fflush(stdin);
    getchar();
    clearScreen();
}

void afficherCredits(void) {
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c CREDITS %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", AG,LH,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,AD);
    printf("%c                                                %c\n", LIGNE_V, LIGNE_V);
    printf("%c              QUORIDOR - 2024                  %c\n", LIGNE_V, LIGNE_V);
    printf("%c                                                %c\n", LIGNE_V, LIGNE_V);
    printf("%c          Développé par : [Votre nom]          %c\n", LIGNE_V, LIGNE_V);
    printf("%c                                                %c\n", LIGNE_V, LIGNE_V);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", BG,LH,LH,LH,LH,
           LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,LH,
           LH,LH,BD);
}

void demanderNomJoueur(char *nom) {
    fgets(nom, 10, stdin);
    // Retire le caractère de nouvelle ligne
    if (nom[strlen(nom) - 1] == '\n') {
        nom[strlen(nom) - 1] = '\0';
    }
}

void demanderPions(char *pion) {
    fgets(pion, 3, stdin); // 2 caractères + 1 pour \0
    pion[strcspn(pion, "\n")] = 0; // Retire le retour chariot
}

void afficherRegle() {
    Color(15, 0);
    gotoligcol(20, 90);

    gotoligcol(22, 70);
    printf("%c  1. le but est d'arriver en premier a la ligne opposer                                         %c\n",LIGNE_V, LIGNE_V);
    gotoligcol(23, 70);
    printf("%c  2. chaque joueur possede 10 mur si joueur ou 5 si 4 joueur                                    %c\n",LIGNE_V, LIGNE_V);
    gotoligcol(24, 70);
    printf("%c  3. a tour de role le joueur choisis de deplacer son pion ou poser une barriere                %c\n",LIGNE_V, LIGNE_V);
    gotoligcol(25, 70);
    printf("%c  4. les pions se deplacent d'une case vers hzut bas gauche droite en contourant les barrieres  %c\n",LIGNE_V, LIGNE_V);
    gotoligcol(26, 70);
    printf("%c  5. poser les barriere entre deux blocs de deux case                                           %c\n",LIGNE_V, LIGNE_V);
    gotoligcol(27, 70);
    printf("%c  6. quand deux pions sont face a face on peut sauter                                           %c\n",LIGNE_V, LIGNE_V);
    gotoligcol(28, 70);
    printf("%c  7. durer 10 a 20 min                                                                          %c\n",LIGNE_V,LIGNE_V);
}
void feuxArtifice() {
    Color(11,0);
    // Feux d'artifice du coin supérieur gauche
    gotoligcol(10, 40);
    printf("   |   ");
    gotoligcol(30, 40);
    printf("   |   ");
    gotoligcol(10, 170);
    printf("   |   ");
    gotoligcol(30, 170);
    printf("   |   ");
    Sleep(400);

    gotoligcol(9, 40);
    printf("   |   ");
    gotoligcol(29, 40);
    printf("   |   ");
    gotoligcol(9, 170);
    printf("   |   ");
    gotoligcol(29, 170);
    printf("   |   ");
    Sleep(400);

    gotoligcol(8, 40);
    printf("   |   ");
    gotoligcol(28, 40);
    printf("   |   ");
    gotoligcol(8, 170);
    printf("   |   ");
    gotoligcol(28, 170);
    printf("   |   ");
    Sleep(400);

    // Début des explosions
    for(int i = 0; i < 4; i++) {
        int x = (i < 2) ? 40 : 170;
        int y = (i % 2 == 0) ? 7 : 27;

        gotoligcol(y, x-3);
        printf("   *   ");
        gotoligcol(y, x+3);
        printf("*   * ");
        gotoligcol(y, x);
        printf(" ***  ");
    }
    Sleep(400);

    // Expansion des explosions
    for(int i = 0; i < 4; i++) {
        int x = (i < 2) ? 40 : 170;
        int y = (i % 2 == 0) ? 6 : 26;

        gotoligcol(y, x-4);
        printf("  * *  ");
        gotoligcol(y, x+4);
        printf(" *   * ");
        gotoligcol(y, x);
        printf(" ***** ");
    }
    Sleep(400);

    for(int i = 0; i < 4; i++) {
        int x = (i < 2) ? 40 : 170;
        int y = (i % 2 == 0) ? 5 : 25;

        gotoligcol(y, x-6);
        printf(" *     * ");
        gotoligcol(y, x+6);
        printf(" *     * ");
        gotoligcol(y, x);
        printf(" ******* ");
    }
    Sleep(400);

    // Explosion finale
    for(int i = 0; i < 4; i++) {
        int x = (i < 2) ? 40 : 170;
        int y = (i % 2 == 0) ? 4 : 24;

        gotoligcol(y, x-8);
        printf("*       * ");
        gotoligcol(y, x+8);
        printf("*       * ");
        gotoligcol(y, x);
        printf("*********");
    }
    Sleep(400);



}
void animationDiagonale() {
    Color(12,0);
    for(int i = 0; i < 5; i++) {
        int ligne = 6 + (i * 3);
        int colonne = 35 + (i * 10);     // 30 + 5 = 35

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(150);
    }

    // Animation diagonale supérieure droite
    for(int i = 0; i < 5; i++) {
        int ligne = 6 + (i * 3);
        int colonne = 155 - (i * 10);    // 150 + 5 = 155

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(150);
    }

    // Animation spirale gauche
    for(int i = 0; i < 4; i++) {
        int ligne = 35 - (i * 3);
        int colonne = 45 + (i * 5);      // 40 + 5 = 45

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(150);
    }

    // Animation spirale droite
    for(int i = 0; i < 4; i++) {
        int ligne = 35 - (i * 3);
        int colonne = 145 - (i * 5);     // 140 + 5 = 145

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(150);
    }

    // Animation cercle extérieur
    for(int angle = 0; angle < 360; angle += 45) {
        int rayon = 20;
        int ligne = 24 + (int)(rayon * sin(angle * 3.14159 / 180));
        int colonne = 95 + (int)(rayon * cos(angle * 3.14159 / 180));  // 90 + 5 = 95

        if (abs(ligne - 24) > 5 || abs(colonne - 95) > 15) {  // Centre ajusté à 95
            gotoligcol(ligne, colonne);
            printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
            gotoligcol(ligne + 1, colonne);
            printf("%c   %c", LIGNE_V, LIGNE_V);
            gotoligcol(ligne + 2, colonne);
            printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
            Sleep(150);
        }
    }
}
void animationExterne() {
    // Animation cascade coin supérieur gauche
    Color(13,0);
    for(int i = 0; i < 4; i++) {
        int ligne = 4 + (i * 2);
        int colonne = 15 + (i * 8);

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(100);
    }

    // Animation cascade coin supérieur droit
    for(int i = 0; i < 4; i++) {
        int ligne = 4 + (i * 2);
        int colonne = 175 - (i * 8);

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(100);
    }

    // Animation cascade coin inférieur gauche
    for(int i = 0; i < 4; i++) {
        int ligne = 44 - (i * 2);
        int colonne = 15 + (i * 8);

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(100);
    }

    // Animation cascade coin inférieur droit
    for(int i = 0; i < 4; i++) {
        int ligne = 44 - (i * 2);
        int colonne = 175 - (i * 8);

        gotoligcol(ligne, colonne);
        printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
        gotoligcol(ligne + 1, colonne);
        printf("%c   %c", LIGNE_V, LIGNE_V);
        gotoligcol(ligne + 2, colonne);
        printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
        Sleep(100);
    }
}