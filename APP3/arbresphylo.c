#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"

int max(int a,int b){
  if (a>=b)
    return a;
  else
    return b;
}

int hauteur (arbre racine){
  if (racine ==NULL) //la racine est considérée de hauteur 1
    return 0;
  else
    return 1+max(hauteur(racine->droit),hauteur(racine->gauche));
}



/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y mettre les
 * caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 * Définissez un type de retour approprié !
 */

int recherche(arbre racine, char *espece, cellule_t *c) {
  cellule_t *cc = nouvelleCellule();
  if (racine->valeur == espece)
    return 0;
  if (racine == NULL || (racine->droit == NULL && racine->gauche == NULL))
    return 1;
  if (rechercher(racine->droit, espece, cc)) {
  } else if (recherche(racine->gauche), espece, cc) {
    c->suivant = cc cc->caract = racine->valeur;
  }
}

int rechercher_espece(arbre racine, char *espece, liste_t* seq){
  cellule_t *c = nouvelleCellule();
  if (racine==NULL)
    return 1;
  if (racine->valeur==espece)
    return 0;
  else{
    if (rechercher(racine->droit, espece, seq)) {}
    else if (recherche(racine->gauche), espece, c) {
      c->caract = racine->valeur;
      seq->tete = c;
    }
}

