#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define TRUC 10

int p_int(int val, int b_inf, int b_sup){
  // revoie 0 si aucun probleme et 1 sinon (p pour protection int)
int result = 1;
  if(val <= b_sup && val >= b_inf){
    result = 0;
  }
  return result;
}

int menu(void){
  int choix=0;
  printf("MENU\n\n");
  printf("entrez votre choix\n");
  printf("1- Lancer une nouvelle partie\n2- Reprendre une partie sauvegardée\n3- Afficher l’aide\n4- Afficher les scores des joueurs\n5- Quitter le jeu\n");

  scanf("%d", &choix);

  return choix;
}

void delay(int miliseconds) {
    usleep(1000 * miliseconds);
}

int lancerpartie(char *j1[10], char *j2[10],char *j3[10], char *j4[10], int nbjoueur, int partie_en_cours){
  
}


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
