#include "arbresphylo.h"
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
int rechercher_espece(arbre racine, char *espece, liste_t *seq) {
  /* à compléter */
  return -1;
}

void ajout_espèce(arbre *a, char *esp,cellule car){
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

void liste_carac(a){

}