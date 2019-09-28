#include "client.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXMSG MAXREP

int main() {
  /*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      !!! Éviter le plus possible de modifier ce fichier !!!
      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

      Modifications autorisées :
          * login et mdp

      modifiez les variables ci-dessous: mettez vos identifiant et mot de passe
   */
  char *login = "11802298";
  char *mdp = "\"DA COSTA BARROS\"";

  /*	######################################
      #  NE PLUS RIEN MODIFIER CI-DESSOUS  #
      ######################################
   */

  char reponse[MAXREP];
  char message[MAXMSG];

  // Affiche les échanges avec le serveur (false pour désactiver)
  mode_debug(true);

  puts("Bienvenue dans le client interactif d'AppoLab");
  puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

  // Connexion au serveur AppoLab
  connexion("im2ag-appolab.u-ga.fr", 9999);
  /* connexion("im2ag-appolab.u-ga.fr", 443); */

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
  bool quit = false;
  while (!quit) {
    attendre_message();
    fgets(message, MAXMSG, stdin);

    if (!strcmp(message, "\n")) {
      puts("Là il faut taper au clavier bande de feignasses !");
    } else if (!strcmp(message, "quit\n")) {
      quit = true;
      puts("bye bye...");
    } else {
      message[strlen(message) - 1] = '\0';
      envoyer_recevoir(message, reponse);
    }
  }

  return 0;
}
