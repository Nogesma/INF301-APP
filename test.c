#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */

int mod (int a, int b)
{
    int ret = a % b;
    if(ret < 0)
        ret+=b;
    return ret;
}

int main() {
    char *buffer;
    FILE * f = fopen("./message.txt", "rw");
    size_t size = 512;
    buffer = (char *) malloc (size);
    getdelim (&buffer, &size,'\0', f);

    char premiereLettre;
    for (int diff = 0; diff < 26; diff++) {
        int i = 0;

        while (buffer[i] != '\0') {
            if (isalpha(buffer[i])) {
                if (buffer[i] >= 'a') premiereLettre = 'a';
                else premiereLettre = 'A';

                buffer[i] =
                    premiereLettre + mod(buffer[i] + diff - premiereLettre, 26);
            }
            i++;
        }

        printf("%s\n\n", buffer);
    }
    return 0;
}


