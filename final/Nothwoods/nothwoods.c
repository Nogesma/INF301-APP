//
// Created by Mano Ségransan on 17/09/2019.
//

#include "nothwoods.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *s, char c) {
  long len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}

void end(char *s, long i) {
  char c = s[i];
  long j;
  for (j = i; j < strlen(s); j++) {
    s[j] = s[j + 1];
  }
  s[j - 1] = c;
}

void decrypt(char c, char *sequence, char *decrypted) {
  long indexInSeq = -1;

  for (long i = 0; i < strlen(sequence); i++)
    if (c == sequence[i])
      indexInSeq = i;

  if (indexInSeq == -1) {
    append(sequence, c);
    append(decrypted, c);
  } else {
    if (indexInSeq == strlen(sequence) - 1) {
      append(decrypted, sequence[0]);
      end(sequence, 0);
    } else {
      append(decrypted, sequence[indexInSeq + 1]);
      end(sequence, indexInSeq + 1);
    }
  }
}

void decryption(char *encryptedMessage, char *decryptedMessage) {
  char *sequence;

  sequence = (char *)malloc(128);

  for (long i = 0; i < strlen(encryptedMessage); i++) {
    decrypt(encryptedMessage[i], sequence, decryptedMessage);
  }
}

void end2(struct Sequence *s, int i) {
  char c[3];
  strcpy(c, s->table[i]);
  int j;
  for (j = i; j < s->size - 1; j++) {
    strcpy(s->table[j], s->table[j + 1]);
  }
  strcpy(s->table[j], c);
}

void addSequence(struct Sequence *s, char c) {
  char cc[3];
  cc[0] = c;
  cc[1] = c;
  cc[2] = '\0';
  strcpy(s->table[s->size], cc);
  s->size++;
}

void swap(struct Sequence *s, int i, int j) {
  char tmp = s->table[i][1];
  s->table[i][1] = s->table[j][1];
  s->table[j][1] = tmp;
}

void encrypt(char c, struct Sequence *s, char *encrypted) {
  int indexInSeq = -1;

  for (int i = 0; i < s->size; i++)
    if (c == s->table[i][0])
      indexInSeq = i;

  if (indexInSeq == -1) {
    addSequence(s, c);
    append(encrypted, c);
  } else {
    if (indexInSeq == 0) {
      swap(s, 0, s->size - 1);
      append(encrypted, s->table[0][1]);
    } else {
      swap(s, indexInSeq, indexInSeq - 1);
      append(encrypted, s->table[indexInSeq][1]);
    }
    end2(s, indexInSeq);
  }
}

void encryption(char *encryptedMessage, char *message) {
  struct Sequence s;
  s.size = 0;

  for (unsigned long i = 0; i < strlen(encryptedMessage); i++) {
    encrypt(encryptedMessage[i], &s, message);
  }
}
