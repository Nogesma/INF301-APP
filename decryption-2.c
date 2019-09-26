//
// Created by Mano Ségransan on 22/09/2019.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sequence {
  int size;
  char table[128][3];
};

void append(char *s, char c) {
  unsigned long len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}

void end(struct Sequence *s, int i) {
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
    if (indexInSeq == s->size - 1) {
      swap(s, indexInSeq, 0);
      append(encrypted, s->table[indexInSeq][1]);
    } else {
      swap(s, indexInSeq, indexInSeq + 1);
      append(encrypted, s->table[indexInSeq][1]);
      end(s, indexInSeq);
    }
  }
}

int main() {
  char *encryptedMessage;
  char *message;
  struct Sequence s;
  s.size = 0;
  FILE *f = fopen("./lostcause2.txt", "r");
  //  FILE *f = fopen("./nothwoodcrypt.txt", "w");
  size_t size = 512;
  message = (char *)malloc(size);

  size = getdelim(&message, &size, '\0', f);

  encryptedMessage = (char *)malloc(size);

  for (unsigned long i = 0; i < size; i++) {
    encrypt(message[i], &s, encryptedMessage);
  }

  printf("%s", encryptedMessage);
  return 0;
}
