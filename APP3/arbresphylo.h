#ifndef ARBRESPHYLO_H
#define ARBRESPHYLO_H

#include "arbres.h"
#include "listes.h"
#include <stdio.h>

/* Renvoie la hauteur de l'arbre passé en argument */
int max(int a, int b);
int hauteur(arbre racine);

int estFeuille(arbre a);
void compter_rec(arbre a, int *nb_car, int *nb_esp);
void compter(arbre a, int *nb_car, int *nb_esp);

/* Recherche une espèce dans l'arbre et renvoie en argument
 * la séquence de ses caractéristiques.
 * Note: vous devez définir un type séquence approprié et modifier le
 * type de retour de cette fonction.
 */

int rechercher_espece(arbre racine, char *espece, liste_t *seq);
int rechercher_esp(arbre racine, char *espece, liste_t *seq);
int rechercher_espece2(arbre racine, char *espece, liste_t *seq);

void ajout_espece(arbre *a, char *esp,cellule_t *car);
void liste_carac(arbre a);

#endif
