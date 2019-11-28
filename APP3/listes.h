#ifndef _LISTES_H
#define _LISTES_H

struct cellule {
  char *caract;
  struct cellule *suivant;
};

typedef struct cellule cellule_t;

struct liste {
  cellule_t *tete;
};

typedef struct liste liste_t;
/* Type de liste à compléter selon votre besoin. */

cellule_t *nouvelleCellule();

#endif /* _LISTES_H */
