#include <stdint-gcc.h>
#include "include/encryption.h"

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))


union longUnion {
    unsigned long long   l;
    uint8_t   byte[8];
};

unsigned long long encrypt(unsigned long long sourceNumber) {
    union longUnion un;

    un.l = sourceNumber;
    for(int i = 7; i > 0; i = i - 2) {
        SWAP(un.byte[i], un.byte[i - 1]);
    }

    return un.l;
}