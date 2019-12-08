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
  char *espece = "autruche";
  liste_t l;
  l.tete = NULL;
  rechercher_espece2(mon_arbre, espece, &l);
  afficher(&l);

  char *abc = "abc";
 
  //liste_carac(mon_arbre);
	
	
	//TESTER
	cellule_t *one = nouvelleCellule();
  cellule_t *two = nouvelleCellule();
 	cellule_t *three = nouvelleCellule();
 	cellule_t *four = nouvelleCellule();
	cellule_t *five = nouvelleCellule();
  cellule_t *six = nouvelleCellule();
 	cellule_t *seven = nouvelleCellule();
  cellule_t *eight = nouvelleCellule();
  cellule_t *nine = nouvelleCellule();

        one->caract = "vertebres";
        one->suivant = two;
        two->caract = "machoires";
        two->suivant = three;
        three->caract = "doigts";
        three->suivant = four;
        four->caract = "amnios";
        four->suivant = five;
        five->caract = "placenta";
        five->suivant = six;
        six->caract = "cornes";
        six->suivant = seven;
        seven->caract = "mdr";
        seven->suivant = NULL;

	ajout_espece(&mon_arbre, abc, one);
	affiche_arbre(mon_arbre, x);
  //affiche_arbre(mon_arbre, x);
  fclose(x);
  printf("Hauteur de l'arbre: %d\n", hauteur(mon_arbre));

  return 0;
}
