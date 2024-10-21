#include "function.h"

#define TRUC 10

int p_int(int val, int b_sup, int b_inf);
int menu(void);
void delay(int seconds);
int lancerpartie(char *j1[10], char *j2[10],char *j3[10], char *j4[10], int nbjoueur, int partie_en_cours);

int main(void) {
  // declaration des variables
  int choix;
  FILE *pscores = NULL;
  char j1[10] = "bot1";
  char j2[10] = "bot2";
  char j3[10] = "bot3";
  char j4[10] = "bot4";
  int nbjoueur = 0;
  int score;
  int partie_en_cours = 0;

  do {
    // l'utilisateur choisis ce qu'il veut faire
    do {
      choix = menu();
    } while (p_int(choix, 1, 5)); // on recupere choix avec une protection sur
                                  // choix (int entre 1 et 5)
    // lancemement de la fonction correspondant au choix de l'utilisateur
    switch (choix) {
    case 1:
      system("cls");
      printf("Lancement d'une nouvelle partie\n");

      // une fois la partie fini, on enregistre les scores
      score = lancerpartie(&j1, &j2, &j3, &j4, nbjoueur, partie_en_cours);

      pscores = fopen("scores.txt", "a");
      if (pscores == NULL)
        printf("probleme d'ouverture du fichier scores.txt\n");
      else {
        fprintf(pscores, "%d %s %s %s %s %d\n", nbjoueur, j1, j2, j3, j4,
                score);
      }
      fclose(pscores);

      break;
    case 2:
      system("cls");
      printf("Reprise d'une partie sauvegardée\n");

      // une fois la partie fini, on enregistre les scores

      pscores = fopen("scores.txt", "a");
      if (pscores == NULL)
        printf("probleme d'ouverture du fichier scores.txt\n");
      else {
        fprintf(pscores, "%d %s %s %s %s %d\n", nbjoueur, j1, j2, j3, j4,
                score);
      }

      break;
    case 3:
      system("cls");
      printf("affichage de l'aide\n");
      break;
    case 4:
      system("cls");
      printf("Affichage des scores des joueurs\n");
      break;
    case 5:
      system("cls");
      printf("Fermeture du jeu\n");
      printf("Merci d'avoir joué !\n");
      delay(2000);
      break;
    }

    // enregistrement des scores dans scores.txt

  } while (choix != 5);
  return 0;
}
