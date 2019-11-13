#include "listes.h"
#define TAILLE_MAX 5000

typedef struct {
  int n;
  cellule_t tab[TAILLE_MAX];
} PileCellules;

/* Constructeurs */

/* Créer une pile vide */
void creer_pile(PileCellules *p);

/* Opérations d'accès */

/* Retourne vrai ssi p est vide */
int est_vide(PileCellules p);

/* Renvoie l'entier en haut de la pile */
/* Précondition : p doit être non vide */
void sommet(PileCellules p, cellule_t **c);

/* Renvoie le nombre d'éléments dans la pile */
int taille(PileCellules p);

/* Afficher les éléments de la pile */
void print(PileCellules p);

/* Opérations de modification */

/* Vider la pile p */
void vider(PileCellules *p);

/* Empiler un entier x */
/* Précondition : taille(p) < TAILLE_MAX */
void empiler(PileCellules *p, cellule_t x);

/* Supprimer l'entier en haut de la pile */
/* Précondition : p non vide */
void depiler(PileCellules *p);
