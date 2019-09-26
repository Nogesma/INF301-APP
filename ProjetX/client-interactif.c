#include "client.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMSG MAXREP

int mod(int a, int b) {
  int ret = a % b;
  if (ret < 0)
    ret += b;
  return ret;
}

void cesar(int dec, char *buffer) {
  int i = 0;
  while (buffer[i] != '\0') {
    if (isalpha(buffer[i])) {
      char premiereLettre = 'a';

      buffer[i] = premiereLettre + mod(buffer[i] + dec - premiereLettre, 26);
    }
    i++;
  }
}
int main() {
  /*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      !!! Éviter le plus possible de modifier ce fichier !!!
      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

      Modifications autorisées :
          * login et mdp

      modifiez les variables ci-dessous: mettez vos identifiant et mot de passe
   */
  char *login = "11800911";
  char *mdp = "SEGRANSAN";

  char reponse[MAXREP];
  char message[MAXMSG];

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
      //      if (!strcmp(message, "start\n")) {
      //        envoyer_recevoir(message, reponse);
      //        char *message;
      //
      //        FILE *f = fopen("./nothwoodcrypt.txt", "r");
      //        size_t size = 512;
      //        message = (char *)malloc(size);
      //
      //        getdelim(&message, &size, '\0', f);
      //        envoyer_recevoir(message, reponse);
      //      } else {
      message[strlen(message) - 1] = '\0';
      envoyer_recevoir(message, reponse);
      //      }
    }
  }
  return 0;
}
