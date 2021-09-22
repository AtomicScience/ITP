#include "include/scanUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

void removeNewlineCharacter(char* string);

unsigned long long scanUnsignedLongLong(char* promptToPrint) {
    while(1) {
        if(promptToPrint != NULL) printf("%s: ", promptToPrint);
        char* scannedLine = malloc(256);
        fgets(scannedLine, 256, stdin);
        removeNewlineCharacter(scannedLine);

        if(*scannedLine == '\0') {
            free(scannedLine);
            printf("%s", "Empty string passed\n");
            continue;
        }

        errno = 0;
        char* leftovers = 0;
        unsigned long long llu = strtoull(scannedLine, &leftovers, 10);

        if (leftovers == scannedLine || *leftovers != '\0' ||
            ((llu == LONG_MIN || llu == LONG_MAX) && errno == ERANGE)) {
            free(scannedLine);
            printf("%s", "Incorrect value provided\n");
            continue;
        } else {
            free(scannedLine);
            return llu;
        }
    }
}

void removeNewlineCharacter(char* string) {
    while(*string) {
        string++;
    }

    *(string - 1) = '\0';
}