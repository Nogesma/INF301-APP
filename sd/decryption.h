//
// Created by Mano Ségransan on 26/09/2019.
//

#ifndef APP1_DECRYPTION_H
#define APP1_DECRYPTION_H

#endif // APP1_DECRYPTION_H

struct Sequence {
  int size;
  char table[128][3];
};

void encryption(char *encryptedMessage, char *message);
void decryption(char *encryptedMessage, char *decryptedMessage);
