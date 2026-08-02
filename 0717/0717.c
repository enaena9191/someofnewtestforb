#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    while (i < bitsSize  - 1) {
        i += bits[i] + 1;
    }
    if (i == bitsSize - 1) return true;
    return false;
}