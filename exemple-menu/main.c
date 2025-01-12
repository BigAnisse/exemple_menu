#include <conio.h>
#include <time.h>
#include "menu.h"
#include "jeu.h"
#include <windows.h>
#include <stdio.h>

void gotoligcol( int lig, int col )
{


    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void Color(int couleurDuTexte,int couleurDeFond) {// fonction d'affichage de couleurs
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int main(void) {

    Jeu jeu = {0};
    clearScreen();
Color(5, 0);


    gotoligcol(2, 20);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(3, 20);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(4, 20);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

gotoligcol(2, 40);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(3, 40);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(4, 40);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

gotoligcol(2, 60);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(3, 60);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(4, 60);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(2, 80);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(3, 80);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(4, 80);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(2, 100);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(3, 100);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(4, 100);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(2, 120);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(3, 120);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(4, 120);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
    gotoligcol(2, 140);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(3, 140);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(4, 140);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(2, 160);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(3, 160);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(4, 160);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(2, 180);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(3, 180);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(4, 180);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    // encadrer cote droit
    gotoligcol(11, 180);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(12, 180);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(13, 180);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(22, 180);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(23, 180);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(24, 180);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(33, 180);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(34, 180);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(35, 180);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

  // gauche

    gotoligcol(11, 20);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(12, 20);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(13, 20);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(22, 20);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(23, 20);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(24, 20);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(33, 20);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(34, 20);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(35, 20);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
// Encadrés décoratifs en bas
    gotoligcol(45, 20);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(46, 20);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(47, 20);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

gotoligcol(45, 40);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(46, 40);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(47, 40);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(45, 60);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(46, 60);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(47, 60);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(45, 80);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(46, 80);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(47, 80);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(45, 100);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(46, 100);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(47, 100);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);
gotoligcol(45, 120);
printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
gotoligcol(46, 120);
printf("%c   %c", LIGNE_V, LIGNE_V);
gotoligcol(47, 120);
printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(45, 140);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(46,140 );
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(47, 140);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(45, 160);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(46,160 );
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(47, 160);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

    gotoligcol(45, 180);
    printf("%c%c%c%c%c", AG, LH, LH, LH, AD);
    gotoligcol(46, 180);
    printf("%c   %c", LIGNE_V, LIGNE_V);
    gotoligcol(47, 180);
    printf("%c%c%c%c%c", BG, LH, LH, LH, BD);
    _sleep(250);

Color(14, 0);

    gotoligcol(14, 70);
    printf("  _______  _     _  _______  _______  ___ _______   _______  _______ ");
    gotoligcol(15, 70);
    printf(" |       ||  | |  ||       ||   __  ||   ||      | |       ||   __  |");
    gotoligcol(16, 70);
    printf(" |  ___  ||  | |  ||  ___  ||  |__| ||   ||  _    ||  ___  ||  |__| |");
    gotoligcol(17, 70);
    printf(" | |   | ||  |_|  || |   | ||   _   ||   || |  |  || |   | ||   _   |");
    gotoligcol(18, 70);
    printf(" | |___| ||       || |   | || |  | | |   || |_ |  || |   | || |  | |  ");
    gotoligcol(19, 70);
    printf(" |____   ||       || |___| || |   | ||   ||       || |___| || |   | | ");
    gotoligcol(20, 70);
    printf("      |__||_______||_______||_|   |_||___||______| |_______||_|   |_|");

gotoligcol(30, 85);
printf("Appuyez sur espace pour commencer...");

Color(15, 0);
    while(1) {
        if(_kbhit()) {

            menuPrincipal(&jeu);
        }
    }
return 0;

}
