#include "../client.h"
#include "NothLost/NothLost.h"
#include <stdbool.h>
#include <stdio.h>
#define MAXMSG MAXREP

int main() {
  char *login = "11800911";
  char *mdp = "SEGRANSAN";

  char reponse[MAXREP];
  char message[MAXMSG];

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
  envoyer_recevoir("load LostCause", reponse);
  decryption2(reponse, message);
  printf("\nMessage decrypte:\n\n%s\n", message);
  envoyer_recevoir("start", reponse);
  decryption2(reponse, message);
  printf("\nMessage decrypte:\n\n%s\n", message);
  envoyer_recevoir("There will be no Nineteen Eighty-Four", reponse);

  return 0;
}