/* Message handler of the ov146 actor: a snapshot (kind 0) outside phase 1 restores the +0x384 model's
 * shown bit (+0x24) and the +0x38c value (+0x25); the base handler always runs. */

#include "nitro/types.h"

typedef struct { int b0 : 1; int b1 : 1; } Bits;

extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

void Ov146_OnMessage(char *self, u8 *msg, int arg)
{
    if (msg[2] == 0 && *(int *)(self + 0x50) != 1) {
        ((Bits *)(*(int *)(self + 0x384) + 0x5c))->b1 = msg[0x24];
        *(int *)(self + 0x38c) = msg[0x25];
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}
