/* Initialises the character's two sub-objects: clears the shared block, registers each one's effect
 * sequence for the owner's palette slot and records its index; then creates the actor's
 * sub-objects. */

#include "game/engine.h"

extern void Ov031_ActorCreateSubObjects(int a);
extern int data_ov031_020b4dc0;
extern int data_ov031_020b4d5c;

void Ov031_initTwoEntrySlots(void) {
    int obj = data_ov031_020b4dc0;
    int i = 0;
    int puVar5;
    int ibase = obj + 0x2c2c;
    puVar5 = ibase + 0x14;
    *(int *)(obj + 0x2c2c) = 0;
    *(int *)(ibase + 4) = 0;
    do {
        RegisterSeqAndInit((void *)puVar5, &data_ov031_020b4d5c, 1, *(unsigned char *)(obj + 9) + 7);
        *(int *)(ibase + 0xc) = i;
        i++;
        *(int *)(ibase + 0x10) = 0;
        puVar5 += 0x118;
        ibase += 0x118;
    } while (i < 2);
    Ov031_ActorCreateSubObjects(obj);
}
