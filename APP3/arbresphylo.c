#include "arbresphylo.h"
#include "listes.h"
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
  if (a >= b)
    return a;
  else
    return b;
}

int hauteur(arbre racine) {
  if (racine == NULL) // la racine est considérée de hauteur 1
    return 0;
  else
    return 1 + max(hauteur(racine->droit), hauteur(racine->gauche));
}

/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y
 * mettre les caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 * Définissez un type de retour approprié !
 */

int recherche(arbre racine, char *espece, cellule_t *c) {
  cellule_t *cc = nouvelleCellule();
  if (racine->valeur == espece)
    return 1;
  if (racine == NULL || (racine->droit == NULL && racine->gauche == NULL))
    return 0;
  if (recherche(racine->gauche, espece, cc)) {
    c->suivant = cc;
    cc->caract = racine->valeur;
    return 1;
  }
  return recherche(racine->droit, espece, c);
}

int rechercher_espece(arbre racine, char *espece, liste_t *seq) {
  cellule_t *c = nouvelleCellule();
  seq->tete = c;
  if (racine == NULL) {
    return 1;
  }
  if (racine->valeur == espece) {
    return 0;
  }
  if (recherche(racine->droit, espece, c)) {
    return 0;
  } else if (recherche(racine->gauche, espece, c)) {
    c->caract = racine->valeur;
    return 0;
  }
  return 1;
}
