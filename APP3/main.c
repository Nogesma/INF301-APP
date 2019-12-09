#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DEBUG = 0;

int main(int argc, char *argv[]) {
  char *fichier = NULL;

  if (argc < 2) {
    fprintf(stderr, "Usage:  %s [-d] <fichier>\n", argv[0]);
    fprintf(stderr, "\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "\t-d\tmode debug\n");
    exit(1);
  } else {
    int arg = 1;

    while (arg < argc) {
      if (!strncmp(argv[arg], "-d", 2)) {
        DEBUG = 1;
        arg++;
        continue;
      }
      if (fichier == NULL) {
        fichier = argv[arg];
        arg++;
        continue;
      } else {
        fprintf(stderr, "Trop de fichiers sur la ligne de commande !\n");
        exit(1);
      }
    }
  }

  debug("Ouverture de %s\n", fichier);
  FILE *f = fopen(fichier, "r");
  FILE *x = fopen("arbre.dot", "w+");

  if (!f) {
    fprintf(stderr, "Erreur à l'ouverture du fichier `%s'\n", fichier);
    perror(fichier);
    exit(1);
  }

  arbre mon_arbre = lire_arbre(f);
  printf("Hauteur de l'arbre: %d\n", hauteur(mon_arbre));
  char* reponse=NULL;
  printf("Que voulez-vous faire ? (ajouter espece, rechercher espece ou afficher les caracteristiques)\n");
  scanf("%s",reponse);
  char *ajout="ajouter";
  char *ajout2="ajouter espece";
  if (strcmp(reponse,ajout)==0 || strcmp(reponse,ajout2)==0){
    printf("Quelle espèce voulez-vous ajouter ?\n");
    char *abc=NULL;
    scanf("%s", abc);
    printf("Combien a-t-il de caractéristiques ?\n");
    int nb;
    scanf("%d", &nb);
    int i=1;
    printf("quelles sont ses caractéristiques ?\n");
    char* c=NULL;
    scanf("%s\n", c);
    cellule_t *one=nouvelleCellule();
    one->caract=c;
    while (i!=nb){
      ajout_fin(one,c);
      scanf("%s\n",c);
      i++;
    }
    ajout_espece(&mon_arbre, abc, one);
    printf("Nouvelle hauteur de l'arbre: %d\n", hauteur(mon_arbre));
  }
  if (strcmp(reponse,"rechercher")==0 || strcmp(reponse,"rechercher espece")==0){
    printf("Quelle espèce recherchez-vous ?\n");
    char *espece=NULL;
    scanf("%s\n", espece);
    liste_t l;
    l.tete = NULL;
    rechercher_espece2(mon_arbre, espece, &l);
    afficher(&l);
  }
  if (strcmp(reponse,"afficher")==0 || strcmp(reponse,"afficher les caracteristiques")==0){
    liste_carac(mon_arbre);
  }
  affiche_arbre(mon_arbre, x);
  fclose(x);

  return 0;
}
