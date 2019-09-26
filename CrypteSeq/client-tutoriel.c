#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "crypt.h"

#define MAXMSG MAXREP

int main() {
    char reponse[MAXREP];
    FILE *f;
    Sequence texte;

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 443);
    // utilisez le port 443 en cas de problème sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 11802298 \"DA COSTA BARROS\"", reponse);
    //envoyer_recevoir("login 11816027 \"BUI\"", reponse);
    envoyer_recevoir("load crypteSeq", reponse);

    attendre_message();
    envoyer_recevoir("start", reponse);

    attendre_message();



    f = fopen("test.txt","rw");

    if(f == NULL) {
        printf("ERROR\n");
        return -1;
    }

    lectureFichier(f,&texte);
    texte.chaine[texte.longueur-1]='\0';
    envoyer_recevoir(crypt(&texte).chaine,reponse);
    Sequence aDecrypte = stringToSeq(&reponse[83]);
    printf("\nVoici le message décrypté\n%s\n",decrypt(&aDecrypte).chaine);
    attendre_message();

    return 0;
}
