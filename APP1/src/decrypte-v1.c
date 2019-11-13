#include "../client.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXMSG MAXREP

void decrypte(char *message, char *reponse, int rang) {
  char lettreLue;
  char lettreSuivante;

  for (int i = 0; i < strlen(reponse); i++) {
    lettreLue = reponse[i];

    if ('a' <= lettreLue && lettreLue <= 'z') {
      lettreSuivante = 'a' + ((lettreLue - 'a' + rang) % 26);
      message[i] = lettreSuivante;
    } else if ('A' <= lettreLue && lettreLue <= 'Z') {
      lettreSuivante = 'A' + ((lettreLue - 'A' + rang) % 26);
      message[i] = lettreSuivante;
    } else {
      message[i] = lettreLue;
    }
  }
}

int main() {
  char *login = "11800911";
  char *mdp = "SEGRANSAN";

  char reponse[MAXREP];
  char message[MAXMSG];

  mode_debug(true);

  puts("Bienvenue dans le client interactif d'AppoLab");
  puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

  // Connexion au serveur AppoLab
  connexion("im2ag-appolab.u-ga.fr", 443);

  // LOGIN
  printf("Identification de %s ...\n", login);
  char user_logs[256];
  snprintf(user_logs, sizeof user_logs, "%s %s %s", "login", login, mdp);
  envoyer_recevoir(user_logs, reponse);
  puts(reponse);

  // INTERACTION
  envoyer_recevoir("load decrypte-v1", reponse);
  envoyer_recevoir("depart", reponse);
  for (int i = 0; i < 5; i++) {
    decrypte(
        message, reponse,
        21); // Decalage de 5 vers la gauche = Decalage de 21 vers la droite
    envoyer_recevoir(message, reponse);
  }

  return 0;
}
