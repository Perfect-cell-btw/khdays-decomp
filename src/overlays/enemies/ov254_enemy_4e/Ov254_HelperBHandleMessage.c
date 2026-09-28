/* Message handler of an ov254 helper: a "spawned" message (kind 5) of sub-kind 0 starts the +0x390
 * pair's effect (kind 5, the packet's mode byte, weight 1.0, the packet's payload) into its handle; the base handler
 * always runs. */
#include "nitro/types.h"
struct Pairs { char pad[0x390]; struct { int res; int handle; } pair[1]; };

extern int Ov107_CreateNodeXformTaskFx24(int model, int res, int kind, int arg, int scale, void *pos);
extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

void Ov254_HelperBHandleMessage(char *self, u8 *msg, int arg)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            ((struct Pairs *)self)->pair[msg[3]].handle =
                Ov107_CreateNodeXformTaskFx24(*(int *)(self + 0x3c), ((struct Pairs *)self)->pair[msg[3]].res, 5, msg[4], 0x1000, msg + 5);
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}
