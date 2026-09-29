/* Counts the entries of the list at +0x44 whose bit 1 at +0x40 is set.
 *
 * The flag is a SIGNED one-bit bitfield: the ROM extracts it with `lsl #30 / asrs #31`
 * (which yields -1 or 0) and branches on `ne`.  An unsigned bitfield would give lsr, and
 * a plain `& 2` would give a tst. */

#include "game/engine.h"

typedef struct {
    int pad[16];
    signed int b0 : 1;
    signed int b1 : 1;
} Flags;

extern void *List_First(void *list);

int Ov107_Region_CountFlaggedMembers(char *self) {
    int n = 0;
    void *node = List_First(self + 0x44);
    while (node != 0) {
        if (((Flags *)(*(char **)node))->b1 != 0) {
            n = n + 1;
        }
        node = List_Next(self + 0x44);
    }
    return n;
}
