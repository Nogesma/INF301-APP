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

int rechercher_espece(arbre racine, char *espece, liste_t *seq) {
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

void ajout_espece(arbre *a, char *esp, cellule_t *car) {
  if (length(car) != 0) {
    if ((*a) == NULL) {
      (*a) = nouveau_noeud();
      (*a)->valeur = car->caract;
      car = car->suivant;
      ajout_espece(&(*a)->droit, esp, car);
    } else if (strcmp((*a)->valeur, car->caract) == 0) {
      car = car->suivant;
      ajout_espece(&(*a)->droit, esp, car);
    } else if (estFeuille(*a)) {
      char *tmp = (*a)->valeur;
      (*a) = NULL;
      ajout_espece(a, esp, car);
      arbre b = nouveau_noeud();
      b->valeur = tmp;
      (*a)->gauche = b;
    } else {
      ajout_espece(&(*a)->gauche, esp, car);
    }
  } else {
    if ((*a) == NULL) {
      (*a) = nouveau_noeud();
      (*a)->valeur = esp;
    } else {
      printf("ERROR:ne peut pas ajouter\n");
    }
  }
}

void liste_carac(Fil f) {
  if (f.tete == NULL) {
    printf("\n");
  } else {
    Element *b = f.tete;
    if (!estFeuille(b->a)) {
      printf("%s ", b->a->valeur);
    }
    defiler(&f);
    if (b->a->gauche != NULL) {
      enfiler(&f, &(b->a->gauche));
    }
    if (b->a->droit != NULL) {
      enfiler(&f, &(b->a->droit));
    }
    liste_carac(f);
  }
}

void liste_carac_2(arbre a) {
  int h = hauteur(a);
  int i;
  for (i = 0; i < h; i++) {
    printf("NIVEAU %d: ", i);
    liste_niveau(a, i);
    printf("\n");
  }
}

/* Print nodes at a given level */
void liste_niveau(arbre a, int niveau) {
  if (a == NULL)
    return;
  if (niveau == 0 && !estFeuille(a))
    printf("%s ", a->valeur);
  else if (niveau > 0) {
    liste_niveau(a->gauche, niveau - 1);
    liste_niveau(a->droit, niveau - 1);
  }
}
