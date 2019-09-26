//
// Created by fabie on 19/09/2019.
//

#ifndef CLIENT_C_CRYPTESEQ_CRYPT_H
#define CLIENT_C_CRYPTESEQ_CRYPT_H

#endif //CLIENT_C_CRYPTESEQ_CRYPT_H

#include <stdio.h>
#include <string.h>
#define LMAX 100000

typedef struct {
    int longueur;
    char chaine[LMAX];
} Sequence;

Sequence crypt(Sequence *mess);

Sequence decrypt(Sequence *mess);

Sequence stringToSeq(char *mess);

Sequence init();

int lectureFichier(FILE *flux,Sequence *message);

int ajoutChar(Sequence *cle, char c);

int indexC(Sequence *cle, char c);
