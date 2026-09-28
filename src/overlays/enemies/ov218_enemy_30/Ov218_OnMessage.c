/* Message handler of the ov218 actor: a spawn message (kind 5) starts the +0x39c effect pair of sub 0
 * from the payload (kind 5, variant byte 4, scale 1.3), knocks the actor back and clears +0x394, or
 * for sub 1 starts the flash helper (020cf0fc) into pair 1. The base handler always runs. */

#include "nitro/types.h"

struct EffectPair { int res; int handle; };
struct Ov218Effects { char pad[0x39c]; struct EffectPair pair[2]; };

extern int Ov107_CreateNodeXformTaskFx24(int model, int parent, int kind, int arg, int weight, void *payload);
extern void Ov107_ForwardVisibleEvent(char *self, int a);
extern int Ov218_SpawnChild10AndBackLink(char *self);
extern void Ov107_AiState_OnMessage(char *self, u8 *msg, int arg);

void Ov218_OnMessage(char *self, u8 *msg, int arg)
{
    if (msg[2] == 5) {
        switch (msg[3]) {
        case 0:
            ((struct Ov218Effects *)self)->pair[msg[3]].handle = Ov107_CreateNodeXformTaskFx24(
                *(int *)(self + 0x3c), ((struct Ov218Effects *)self)->pair[msg[3]].res, 5, msg[4], 0x14cd, msg + 5);
            Ov107_ForwardVisibleEvent(self, 1);
            *(int *)(self + 0x394) = 0;
            break;
        case 1:
            ((struct Ov218Effects *)self)->pair[msg[3]].handle = Ov218_SpawnChild10AndBackLink(self);
            break;
        }
    }
    Ov107_AiState_OnMessage(self, msg, arg);
}
