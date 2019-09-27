//
// Created by Mano Ségransan on 20/09/2019.
//

#include <string.h>

void append2(char *s, char c) {
  unsigned long len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
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
    append2(encrypted, c);
  } else {
    if (indexInSeq == 0) {
      swap(s, 0, s->size - 1);
      append2(encrypted, s->table[0][1]);
    } else {
      swap(s, indexInSeq, indexInSeq - 1);
      append2(encrypted, s->table[indexInSeq][1]);
    }
    end2(s, indexInSeq);
  }
}

void encryption(char *encryptedMessage, char *message) {

  struct Sequence s;
  s.size = 0;

  for (unsigned long i = 0; i < strlen(encryptedMessage); i++) {
    encrypt(message[i], &s, encryptedMessage);
  }
}
