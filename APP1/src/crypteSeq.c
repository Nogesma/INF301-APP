#include "../client.h"
#include "crypteSeq/crypt.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXMSG MAXREP

int getDigits1(char *reponse, char *num) {
  int i;
  int j = 0;
  int size = 0;
  char watch[10] = "You f";
  int val = 1;
  for (i = 0; i < 5; i++) {
    if (watch[i] != reponse[i]) {
      val = 0;
      break;
    }
  }
  while (reponse[size] < '0' || reponse[size] > '9' ||
         reponse[size + 2] < '0' || reponse[size + 2] > '9') {
    size++;
  }
  i = size;
  while (reponse[i] >= '0' && reponse[i] <= '9') {
    num[j] = reponse[i];
    j++;
    i++;
  }
  num[j] = '\0';
  if (val)
    return 1;
  return 0;
}

int getDigits2(char *reponse, char *num) {
  int i;
  char watch[15] = " Pretending";
  int val = 1;
  for (i = 0; i < 11; i++) {
    if (watch[i] != reponse[i]) {
      val = 0;
      break;
    }
  }
  i = 0;
  while (reponse[i] != '\0') {
    i++;
  }
  if (reponse[i - 1] == '.' || reponse[i - 1] == '!') {
    i--;
  }
  int j = i;
  while (reponse[j] != ' ') {
    j--;
  }
  int k;
  for (k = 0; k < i; k++) {
    num[k] = reponse[j];
    j++;
  }
  num[k] = '\0';
  if (val)
    return 1;
  return 0;
}

int main() {
  char *login = "11800911";
  char *mdp = "SEGRANSAN";

  char reponse[MAXREP];

  puts("Bienvenue dans le client interactif d'AppoLab");
  puts("Connection à AppoLab dans le client interactif d'AppoLab ...");

  // Connexion au serveur AppoLab
  connexion("im2ag-appolab.u-ga.fr", 443);

  mode_debug(true);

  // LOGIN
  printf("Identification de %s ...\n", login);
  char user_logs[256];
  snprintf(user_logs, sizeof user_logs, "%s %s %s", "login", login, mdp);
  envoyer_recevoir(user_logs, reponse);
  puts(reponse);

  // INTERACTION
  char num[30];
  char numBeg[6];
  envoyer_recevoir("load leGateau", reponse);
  envoyer_recevoir("start", reponse);
  getDigits1(reponse, numBeg);
  envoyer_recevoir(numBeg, reponse);
  while (!getDigits1(reponse, num)) {
    envoyer_recevoir(num, reponse);
  }
  envoyer_recevoir(numBeg, reponse);
  while (!getDigits1(reponse, num)) {
    envoyer_recevoir(num, reponse);
  }
  envoyer_recevoir(num, reponse);
  while (!getDigits2(reponse, num)) {
    envoyer_recevoir(num, reponse);
  }
  envoyer_recevoir(num, reponse);
  while (!getDigits2(reponse, num)) {
    envoyer_recevoir(num, reponse);
  }
  return 0;
}
