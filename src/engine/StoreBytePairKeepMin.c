/* Stores a pair of bytes into a global 2D table row, keeping the first no larger than the second,
 * then updates the packed slot parameter. */

#include "game/engine.h"

extern char data_0204c678[];
void StoreBytePairKeepMin(int param_1, int param_2, unsigned int param_3, unsigned char *param_4)
{
    unsigned char *row = (unsigned char *)(data_0204c678 + param_1 * 0x104 + 0x9c) + param_2 * 2;
    unsigned char b;
    row[0] = param_4[0];
    b = param_4[1];
    row[1] = b;
    if (row[0] > b)
        row[0] = b;
    Slot_EvalPackedParamWith(param_1, param_2 + 1, param_3);
}
