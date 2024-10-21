#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
