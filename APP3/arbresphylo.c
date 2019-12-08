#include "arbresphylo.h"
#include "listes.h"
#include <stdio.h>
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

int estFeuille(arbre a) { return (a->gauche == NULL && a->droit == NULL); }

void compter_rec(arbre a, int *nb_car, int *nb_esp) {

  if (estFeuille(a)) {
    (*nb_esp)++;
  } else {
    (*nb_car)++;
    if (a->gauche != NULL) {
      compter_rec(a->gauche, nb_car, nb_esp);
    }
    if (a->droit != NULL) {
      compter_rec(a->droit, nb_car, nb_esp);
    }
  }
}

void compter(arbre a, int *nb_car, int *nb_esp) {
  *nb_car = 0;
  *nb_esp = 0;
  if (a == NULL) {
    return;
  }
  compter_rec(a, nb_car, nb_esp);
}

/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y
 * mettre les caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 * Définissez un type de retour approprié !
 */
int rechercher_espece(arbre racine, char *espece, liste_t *carac) {
  if (racine == NULL) {
    return 1;
  }
  if (strcmp(racine->valeur, espece) == 0 ||
      rechercher_espece(racine->gauche, espece, carac) == 0 ||
      rechercher_espece(racine->droit, espece, carac) == 0) {
    if (strcmp(racine->valeur, espece) != 0) {
      cellule_t *cel = nouvelleCellule();
      cel->caract = racine->valeur;
      cel->suivant = carac->tete;
      carac->tete = cel;
    }
    return 0;
  }
  return 1;
}

int recherche(arbre racine, char *espece, cellule_t *c) {
  cellule_t *cc = nouvelleCellule();
  if (racine == NULL)
    return 0;
  if (strcmp(racine->valeur, espece) == 0) {
    return 1;
  }
  if (recherche(racine->droit, espece, cc)) {
    c->suivant = cc;
    cc->caract = racine->valeur;
    return 1;
  }
  return recherche(racine->gauche, espece, c);
}

int rechercher_espece2(arbre racine, char *espece, liste_t *seq) {
  cellule_t *c = nouvelleCellule();
  seq->tete = c;
  if (racine == NULL) {
    return 1;
  }
  if (strcmp(racine->valeur, espece) == 0) {
    return 0;
  }
  if (recherche(racine->gauche, espece, c)) {
    return 0;
  } else if (recherche(racine->droit, espece, c)) {
    c->caract = racine->valeur;
    return 0;
  }
  return 1;
}

void ajout_espece(arbre *a, char *esp,cellule_t *car){
	printf("CALLED,current is %s and %s\n",car->caract,(*a)->valeur);
  if (length(car)!=0){
		printf("1\n");
		if ((*a) == NULL){
			printf("5\n");
			(*a) = nouveau_noeud();
			strcpy((*a)->valeur,car->caract);
			car = car->suivant;
			ajout_espece(&(*a)->droit,esp,car);
		}
		else if(strcmp((*a)->valeur,car->caract) == 0){
			printf("3\n");
			car = car->suivant;
			ajout_espece(&(*a)->droit,esp,car);
		}
		else if(estFeuille(*a)){
			printf("4\n");
			char *tmp = (*a)->valeur;
			(*a) = NULL;
			ajout_espece(&(*a)->droit,esp,car);
			arbre b = nouveau_noeud();
			strcpy(b->valeur,tmp);
			(*a)->gauche = b; 
		}
		else{
			ajout_espece(&(*a)->gauche,esp,car);
		}
	}
	else{
		printf("2\n");
		if ((*a) == NULL){
			(*a) = nouveau_noeud();
			strcpy((*a)->valeur,esp);
		}
		else{
			printf("ERROR\n");
		} 
	}
}

void liste_carac(arbre a) {
  File f;
  f.tete = NULL;
  liste_t l;
  cellule_t *c = nouvelleCellule();
  l.tete = c;
  enfiler(&f, &a);
  int i = 1;
  int j = 0;
  while (f.tete != NULL) {
    noeud n = defiler(&f);
    cellule_a *b = nouvelleCellule_a();
    b->n = &n;
    if (j == i) {
      j = 1;
      i++;
      afficher(&l);
      while (l.tete != NULL) {
        detruireCellule(l.tete);
      }
      l.tete = b;
    } else {
      if (present(&l, n.valeur) && n.gauche != NULL && n.droit != NULL) {
        c->suivant = b;
        c = c->suivant;
        j++;
      }
    }
    if (n.gauche != NULL) {
      enfiler(&f, &n.gauche);
    }
    if (n.droit != NULL) {
      enfiler(&f, &n.droit);
    }
  }
  remove("temp.txt");
}