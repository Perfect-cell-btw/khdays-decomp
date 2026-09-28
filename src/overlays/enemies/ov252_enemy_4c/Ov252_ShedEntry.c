/* Shed entry of the ov252 actor: bits 0-1 of +0x1ae are set, the nine +0x4e8 armour shapes hide, sound
 * 0/0x4a plays at its +0x74 position and the node moves on to 020d2d88. */
#include "nitro/types.h"
typedef struct { unsigned f : 8; } B8;
struct Ov252Armour { char pad[0x4e8]; int shapes[9]; };

extern void Ov107_BuildAndSendUpdate(int actor, int bank, int variant, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov252_AiEndStep(void);

void Ov252_ShedEntry(int *node)
{
    int *state = (int *)node[1];
    int i;

    *(u16 *)(*state + 0x1ae) |= 3;
    for (i = 0; i < 9; i++) {
        ((B8 *)(((struct Ov252Armour *)*state)->shapes[i] + 8))->f &= ~1;
    }
    Ov107_BuildAndSendUpdate(*state, 0, 0x4a, (void *)(*state + 0x74));
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov252_AiEndStep);
}
