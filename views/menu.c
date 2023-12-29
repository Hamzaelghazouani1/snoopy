#include <stdio.h>
#include <stdlib.h>
#include "../header/protolib.h"

/**
 * @brief Affiche le menu principal
 * @return void
 */
void menu(void){
    printf("\033[1;32m                         [ Menu ]\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  1. Regles du jeu                                         |\n");
    printf("|  2. Lancer un nouveau Jeu a partir du niveau 1            |\n");
    printf("|  3. Charger une partie                                    |\n");
    printf("|  4. Lancer directement un niveau via son Mot de passe     |\n");
    printf("|  5. Scores                                                |\n");
    printf("|  0. Quitter                                               |\n");
    printf("+-----------------------------------------------------------+\033[0m\n\n");
}

/**
 * @brief Affiche les regles du jeu
 * @return void
 */
void displayGameRules(void) {
    system("clear");
    printf("\033[1;32m                                             [ Bienvenue dans notre jeu! ]\033[0m\n");
    printf("\033[1;31m                 Lisez attentivement et respectez scrupuleusement toutes les regles du jeu suivantes:\033[0m\n\n");
    printf("\033[1;30m+----------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| Au commencement, vous avez 3 vies.                                                                                               |\n");
    printf("| Chaque niveau doit etre resolu en moins de 120 secondes. Sinon, vous perdez une vie et recommencez le niveau.                    |\n");
    printf("| Votre mission: recuperer les 4 oiseaux du niveau sans vous faire toucher par la balle et/ou les ennemis (s'ils sont presents).   |\n");
    printf("| Chaque niveau est represente par une matrice rectangulaire de caracteres de 10 lignes par 20 colonnes.                           |\n");
    printf("+----------------------------------------------------------------------------------------------------------------------------------+\033[0m\n");

    printf("\n\033[1;37mDeplacement de votre personnage:\033[0m\n");
    printf("Vous pouvez vous deplacer dans les 4 directions classiques (Haut, Bas, Gauche et Droite) d'une seule case a la fois.\n");
    printf("Pas de deplacements en diagonale, et vous ne pouvez pas sortir du niveau.\n");

    printf("\n\033[1;37mMouvement de la balle:\033[0m\n");
    printf("La balle se deplace en diagonale, rebondit sur les murs et vous 'tue' si elle vous touche.\n");

    printf("\n\033[1;37mGestion des objets:\033[0m\n");
    printf("Un bloc poussable peut etre deplace une seule fois dans une direction precise, sans sortir du niveau.\n");

    printf("\n\033[1;37mCondition de victoire ou de defaite:\033[0m\n");
    printf("Pour gagner, recuperez les 4 oiseaux du niveau. Si vous perdez toutes vos vies, c'est Game Over!\n");

    printf("\n\033[1;37mGestion du temps:\033[0m\n");
    printf("Chaque niveau a un timer de 120 secondes. Si le temps atteint 0, vous perdez une vie.\n");
    printf("Le timer peut etre represente par des cases autour du terrain ou par un affichage de compte a rebours.\n");

    printf("\n\033[1;37mGestion des scores:\033[0m\n");
    printf("Le score pour chaque niveau est calcule en fonction du temps restant. Les scores s'additionnent pour former le score final.\n");

    printf("\n\033[1;37mSauvegarde et chargement d'une partie:\033[0m\n");
    printf("Sauvegardez en appuyant sur 's'. La sauvegarde inclut la position de votre personnage, la balle, les elements du decor, le temps restant, le nombre de vies et le score courant.\n");
    printf("Chargez une partie depuis le menu principal en choisissant 'Charger une partie'.\n");

    printf("\n\033[1;37mGestion des mots de passe:\033[0m\n");
    printf("Chaque niveau est accessible par un mot de passe unique. Entrez le mot de passe depuis le menu principal.\n");

    printf("\n\033[1;37mMode 'pause':\033[0m\n");
    printf("Appuyez sur une touche de 'pause' pour figer la balle et votre personnage, arreter le timer. Appuyez a nouveau pour reprendre le jeu.\n");

    getchar();
}
