#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXMSG MAXREP

void decrypte(char * message, char * reponse, int rang) {
  char lettreLue;
  char lettreSuivante;

  for (int i=0; i <strlen(reponse);i++){
    lettreLue = reponse[i];
    if ('a' <= lettreLue && lettreLue <= 'z'){
      lettreSuivante = 'a' + ((lettreLue - 'a' + rang) % 26);
      message[i] = lettreSuivante;
    }
    else if ('A' <= lettreLue && lettreLue <= 'Z'){
      lettreSuivante = 'A' + ((lettreLue - 'A' + rang) % 26);
      message[i] = lettreSuivante;
    }
    else {
      message[i] = lettreLue;
    }
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
    connexion("im2ag-appolab.u-ga.fr", 443);
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
        /*attendre_message();
        fgets(message, MAXMSG, stdin);*/

        if (!strcmp(message, "\n")) {
            puts("Là il faut taper au clavier bande de feignasses !");
        } else if (!strcmp(message, "quit\n")) {
            quit = true;
            puts("bye bye...");
        } else {
		envoyer_recevoir("load decrypte-v1", reponse);
		envoyer_recevoir("depart", reponse);
		for (int i = 0; i<5; i++){	
			decrypte(message,reponse, 21);   //Decalage de 5 vers la gauche = Decalage de 21 vers la droite
			envoyer_recevoir(message,reponse);
		}
		envoyer_recevoir("quit", reponse);
        }
    }

    return 0;
}
