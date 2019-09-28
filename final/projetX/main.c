#include "../client.h"
#include "cesar.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXMSG MAXREP

int main() {
  char reponse[MAXREP];

  // Affiche les échanges avec le serveur (false pour désactiver)
  mode_debug(true);

  // Connexion au serveur AppoLab
  // utilisez le port 443 en cas de problème sur le 9999
  connexion("im2ag-appolab.u-ga.fr", 443);

  // Remplacez <identifiant> et <mot de passe> ci dessous.
  envoyer_recevoir("login 11800911 SEGRANSAN", reponse);
  envoyer_recevoir("load projetX", reponse);
  envoyer_recevoir("help", reponse);
  cesar(reponse);
  envoyer_recevoir("start", reponse);
  envoyer_recevoir("Veni, vidi, vici", reponse);

  return 0;
}
