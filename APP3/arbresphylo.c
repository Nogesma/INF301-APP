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
  if (recherche(racine->gauche, espece, cc)) {
    c->suivant = cc;
    cc->caract = racine->valeur;
    return 1;
  }
  return recherche(racine->droit, espece, c);
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
  if (recherche(racine->droit, espece, c)) {
    return 0;
  } else if (recherche(racine->gauche, espece, c)) {
    c->caract = racine->valeur;
    return 0;
  }
  return 1;
}

void ajout_espece(arbre *a, char *esp,cellule car){
  if (length(car)!=0){
    if (a==NULL){
      if (car != NULL) {
        a = nouveau_noeud();
        a.val = car.val;
        car = car.suiv;
        ajout_espèce(a.droit, esp, car);
      }
    }
    else{
      if (a.val==car.val){
        car=car.suiv;
        ajout_espèce(a.droit,esp,car);
      }
      if (estFeuille(a)){
        if (car!=NULL){
          char* tmp=a.valeur;
          a.valeur=car;
          noeud b=nouveau_noeud();
          b.valeur=tmp
          a.gauche=b;
          ajout_espèce(a.droit,esp,car);
        }
        else{
          printf("Ne peut ajouter %s : possède les mêmes caractères que %s",esp,car.valeur);
        }
      }
      if (a.val!=car.val){
        car=car.suiv;
        ajouter(a.gauche,esp,car);
      }
    }
  }
  else{
    if (a==NULL){
      a=nouveau_noeud();
      a.val=esp;
    }
    else
      printf("Ne peut ajouter %s : possède les mêmes caractères que %s",esp,car.valeur);
  }
}

void liste_carac(arbre a) {
  File *f;
  liste_t *l;
  l->tete=NULL
  enfiler(f, a);
  int i = 1;
  int j = 0;
  while (f != NULL) {
    arbre n = defiler(f);
    cellule_t* b=nouvelleCellule();
    b->caract=n.valeur;
    if (j == i) {
      j = 1;
      i++;
      afficher(l);
      while (l!=NULL){
        detruireCellule(l->tete);
      }
      l->tete=b
    }
    else{
      if (present(l,n) && n.gauche!=NIL && n.droit!=NIL){
        l->suivant=n.valeur;
        j++;
      }
    }
    if (n.gauche!=Nil){
      enfiler(f,n.gauche);
    }
    if (n.droit!=Nil){
      enfiler(f,n.droit);
    }
  }
}