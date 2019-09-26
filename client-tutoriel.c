#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

int main() {
    char reponse[MAXREP];
    char message[MAXMSG];

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    // utilisez le port 443 en cas de problème sur le 9999
    connexion("im2ag-appolab.u-ga.fr", 443);

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 11800911 SEGRANSAN", reponse);
    envoyer_recevoir("load tutoriel", reponse);

    while (true) {
        int num_char;
        attendre_message();
        do {
            fgets (message, MAXMSG, stdin);
            num_char = strlen(message);
            printf("%d chars\n", num_char);
            message[num_char-1] = '\0'; /* on supprime le retour à la ligne */
        } while (num_char < 2);         /* on n'envoie pas de ligne vide */
        envoyer_recevoir(message, reponse);
    }

    return 0;
}
