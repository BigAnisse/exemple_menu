#include "mur.h"
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include "plateau.h"
#include "pion.h"




bool estPlacementMurValide(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col, bool estHorizontal) {



    if (estHorizontal) {
        if (lig >= NB_LIGNES || col < 0 || col + 3 >= NB_COLONNES) {
            return false;
        }


        for (int i = 0; i < 4; i++) {
            if (plateau[lig][col + i] == MUR) {
                return false;
            }
        }
    } else {
        if (lig + 3 >= NB_LIGNES || col < 0 || col >= NB_COLONNES) {
            return false;
        }


        for (int i = 0; i < 4; i++) {
            if (plateau[lig + i][col] == MUR) {
                return false;
            }
        }
    }

    return true;
}

void dessinerMur(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col, bool estHorizontal, bool estFantome) {
    char symboleH = estFantome ? '~' : 'B';
    char symboleV = estFantome ? ':' : 'B';

    if (estHorizontal) {
        for (int i = 0; i < 4; i++) {
            int ligneConsole = LIGNE_DEBUT + (lig * 2);
            int colonneConsole = COL_DEBUT + ((col + i) * 5) + 1;

            gotoligcol(ligneConsole, colonneConsole);
            printf("%c", symboleH);
            if (!estFantome) {
                plateau[lig][col + i] = MUR;
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int ligneConsole = LIGNE_DEBUT + ((lig + i) * 2);
            int colonneConsole = COL_DEBUT + (col * 5) + 1;

            gotoligcol(ligneConsole, colonneConsole);
            printf("%c", symboleV);
            if (!estFantome) {
                plateau[lig + i][col] = MUR;
            }
        }
    }
}

void effacerMurFantome(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col, bool estHorizontal) {
    if (estHorizontal) {
        for (int i = 0; i < 4; i++) {
            int ligneConsole = LIGNE_DEBUT + (lig * 2);
            int colonneConsole = COL_DEBUT + ((col + i) * 5) + 1;
            gotoligcol(ligneConsole, colonneConsole);
            printf(" ");
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int ligneConsole = LIGNE_DEBUT + ((lig + i) * 2);
            int colonneConsole = COL_DEBUT + (col * 5) + 1;
            gotoligcol(ligneConsole, colonneConsole);
            printf(" ");
        }
    }
}

bool placerMur(int plateau[NB_LIGNES][NB_COLONNES], int lig, int col, bool estHorizontal, int* nbMurs) {
    if(*nbMurs <= 0) {
        printf("Vous n'avez plus de murs disponibles !\n");
        return false;
    }

    if (!estPlacementMurValide(plateau, lig, col, estHorizontal)) {
        gotoligcol(36, 120);
        printf("Placement de mur impossible ! ");
        Sleep(500);
        gotoligcol(36, 120);
        printf("                             ");
        return false;
    }

    dessinerMur(plateau, lig, col, estHorizontal, false);
   ( *nbMurs)--;
    return true;
}
void tourPlacementMur(int plateau[NB_LIGNES][NB_COLONNES], int joueur, int nbJoueur) {
    int lig = NB_LIGNES + 2;  // Position sous le plateau
    int col = 1;
    bool estHorizontal = true;
    bool murFantomeValide = true;
    int* nbMurs;
    if( nbJoueur == 2) {
        static int nbMursJoueur1 = 10;
        static int nbMursJoueur2 = 10;
        if (joueur == 1) {
            nbMurs = &nbMursJoueur1;
        } else {
            nbMurs = &nbMursJoueur2;
        }
    } else {
        static int nbMursJoueur1 = 5;
        static int nbMursJoueur2 = 5;
        static int nbMursJoueur3 = 5;
        static int nbMursJoueur4 = 5;
        if (joueur == 1) {
            nbMurs = &nbMursJoueur1;
        } else if( joueur ==2){
            nbMurs = &nbMursJoueur2;
        }else if(joueur ==3) {
            nbMurs = &nbMursJoueur3;
        } else {
            nbMurs = &nbMursJoueur4;
        }
    }
    printf("Joueur %d, il vous reste %d murs\n", joueur, *nbMurs);


    gotoligcol(19, 120);
    if (estHorizontal) {
        printf("Joueur %d - Mur horizontal: Z/S=2 cases haut/bas, Q/D=1 case gauche/droite", joueur);
    } else {
        printf("Joueur %d - Mur vertical: Z/S=1 case haut/bas, Q/D=2 cases gauche/droite", joueur);
    }

    bool murPlace = false;
    char touche;


    murFantomeValide = (lig >= NB_LIGNES) || estPlacementMurValide(plateau, lig, col, estHorizontal);
    if (murFantomeValide) {
        dessinerMur(plateau, lig, col, estHorizontal, true);
    }

    while (!murPlace) {
        if (_kbhit()) {
            touche = _getch();


            if (murFantomeValide) {
                effacerMurFantome(plateau, lig, col, estHorizontal);
            }

            int nouvLig = lig;
            int nouvCol = col;

            switch(touche) {
                case 'z':
                    if (estHorizontal) {
                        if (lig >= 2) nouvLig = lig - 2;
                    } else {
                        if (lig >= 1) nouvLig = lig - 1;
                    }
                    break;
                case 's':
                    if (estHorizontal && lig < NB_LIGNES + 3) {
                        nouvLig = lig + 2;
                    } else if (!estHorizontal && lig < NB_LIGNES + 4) {
                        nouvLig = lig + 1;
                    }
                    break;
                case 'q':
                    if (estHorizontal) {
                        if (col >= 1) nouvCol = col - 1;
                    } else {
                        if (col >= 2) nouvCol = col - 2;
                    }
                    break;
                case 'd':
                    if (estHorizontal) {
                        if (col <= NB_COLONNES-5) nouvCol = col + 1;
                    } else {
                        if (col <= NB_COLONNES-3) nouvCol = col + 2;
                    }
                    break;
                case 'r':
                    estHorizontal = !estHorizontal;
                    if (estHorizontal) {
                        if (lig % 2 == 0) {
                            if (lig + 1 <= NB_LIGNES+3) {
                                nouvLig = lig + 1;
                            } else if (lig >= 1) {
                                nouvLig = lig - 1;
                            }
                        }
                    } else {
                        if (col % 2 == 0) {
                            if (col + 1 <= NB_COLONNES-3) {
                                nouvCol = col + 1;
                            } else if (col >= 1) {
                                nouvCol = col - 1;
                            }
                        }
                    }


                    break;
                case ' ':

                    if (lig < NB_LIGNES && murFantomeValide && placerMur(plateau, lig, col, estHorizontal, nbMurs)) {
                        murPlace = true;
                    }
                    break;
            }


            nouvLig = (nouvLig >= 0) ? nouvLig : lig;
            if (nouvLig >= 0 && nouvCol >= 0) {
                lig = nouvLig;
                col = nouvCol;
            }


            murFantomeValide = (lig >= NB_LIGNES) || estPlacementMurValide(plateau, lig, col, estHorizontal);


            if (!murPlace && murFantomeValide) {
                dessinerMur(plateau, lig, col, estHorizontal, true);
            }
        }
    }


    gotoligcol(19, 123);
    printf("                                                                          ");
}