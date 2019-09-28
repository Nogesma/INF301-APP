#include "../client.h"
#include "crypt.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXMSG MAXREP

int main() {
  char *login = "11800911";
  char *mdp = "SEGRANSAN";

  char reponse[MAXREP];
  char message[MAXMSG];
  FILE *f;
  Sequence texte;

  puts("Bienvenue dans le client interactif d'AppoLab");
  puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

  // Connexion au serveur AppoLab
  connexion("im2ag-appolab.u-ga.fr", 443);

  mode_debug(true);

  // LOGIN
  printf("Identification de %s ...\n", login);
  char user_logs[256];
  snprintf(user_logs, sizeof user_logs, "%s %s %s", "login", login, mdp);
  envoyer_recevoir(user_logs, reponse);
  puts(reponse);

  // INTERACTION
  envoyer_recevoir("load crypteSeq", reponse);
  envoyer_recevoir("start", reponse);
  f = fopen("crypteSeq/message.txt", "r");

  if (f == NULL) {
    printf("ERROR\n");
    return -1;
  }

  lectureFichier(f, &texte);
  texte.chaine[texte.longueur - 1] = '\0';
  envoyer_recevoir(crypt(&texte).chaine, reponse);
  Sequence aDecrypte = stringToSeq(&reponse[83]);
  printf("\nVoici le message décrypté\n%s\n", decrypt(&aDecrypte).chaine);

  return 0;
}
