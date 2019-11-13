#ifndef __CLIENT_H__
#define __CLIENT_H__

/*
 * Pour modifier les couleurs d'affichage (certaines peuvent être difficile
 * à lire selon les terminaux).
 * Couleurs possibles:
 * RED     - rouge
 * GRN     - vert
 * YEL     - jaune
 * BLU     - bleu foncé
 * BLUBOLD - bleu clair
 * MAG     - magenta
 * CYN     - cyan
 * WHT     - blanc
 */
#define COL_ENVOI GRN     /* couleur des messages envoyés */
#define COL_RECU MAG      /* couleur des messages reçus   */
#define COL_ATTENTION RED /* couleur des messages importants */

#define MAXREP 100000 /* taille maximale d'une réponse du serveur */

/*
 * Permet l'ouverture d'une connection avec le serveur
 * Les paramètres pour accéder au bon serveur sont à donner en argument:
 * nom du serveur et port.
 * si les arguments sont NULL et 0, les valeurs par défaut sont utilisées.
 * Renvoie une valeur nulle (faux) en cas d'échec
 */
int connexion(char *, int);
/*
 * Permet la fermeture de la connection avec le serveur donné en argument
 */
void deconnexion();
/*
 * Permet d'activer (val != 0) ou non (val == 0) le mode debug
 */
void mode_debug(int val);

/*
 * Permet d'attendre que l'utilisateur appuie sur entrée
 */
void attendre();

/*
 * Demande à l'utilisateur un message
 */
void attendre_message();

/*
 * Permet d'envoyer un message au serveur et de recevoir la réponse.
 * Renvoie le nombre d'octets de la réponse
 */
int envoyer_recevoir(char *message, char *reponse);

#endif
