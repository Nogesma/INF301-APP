#include "../client.h"
#include "nothwoods.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXMSG MAXREP

int main() {
  size_t size = 100000;

  char *login = "11800911";
  char *mdp = "SEGRANSAN";

  char *reponse = (char *)malloc(size);
  char *message = (char *)malloc(size);
  char *cryptedMessage = (char *)malloc(size);

  // Affiche les échanges avec le serveur (false pour désactiver)
  mode_debug(true);

  puts("Bienvenue dans le client interactif d'AppoLab");
  puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

  // Connexion au serveur AppoLab
  connexion("im2ag-appolab.u-ga.fr", 443);

  // LOGIN
  if (strcmp(login, "") && strcmp(mdp, "")) {
    printf("Identification de %s ...\n", login);
    char user_logs[256];
    snprintf(user_logs, sizeof user_logs, "%s %s %s", "login", login, mdp);
    envoyer_recevoir(user_logs, reponse);
    puts(reponse);
  } else {
    puts("Identifiez vous maintenant (login <login> <mot de passe>)");
  }

  // Interaction
  envoyer_recevoir("load Nothwoods", reponse);
  decryption(reponse, message);
  printf("%s", message);
  encryption(message, cryptedMessage);
  envoyer_recevoir("start", reponse);
  envoyer_recevoir(cryptedMessage, reponse);

  return 0;
}
