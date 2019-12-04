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

  affiche_arbre(mon_arbre, x);
  printf("Hauteur de l'arbre: %d\n", hauteur(mon_arbre));
  char *espece = "limace";
  liste_t l;
  rechercher_espece2(mon_arbre, espece, &l);
  cellule_t *c = nouvelleCellule();
  c = l.tete;
  while (c != NULL) {
    printf("%s ", c->caract);
    c = c->suivant;
  }
  affiche_arbre(mon_arbre, x);
  printf("Hauteur de l'arbre: %d\n", hauteur(mon_arbre));

  return 0;
}
