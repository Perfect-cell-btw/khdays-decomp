/* Message handler of the ov249 actor: a "spawned" message (kind 5) of sub-kind 0 attaches the +0x390
 * slot model on the +0xa0 node (mode 0x17) — placed when the message's +4 byte is 0, else anchored
 * with that byte — and keeps the effect in the slot's +4. The base handler always runs. */

#include "game/enemy_common.h"

struct Slot { int model; int effect; };
struct Ov249Actor { char pad[0x390]; struct Slot slots[1]; };

extern int Ov107_CreateNodeXformTask(int model, int parent, int kind, int zero, void *transform);
extern void Ov107_AiState_OnMessage(int owner, unsigned char *command, int arg);

void Ov249_ActorOnMessage(int owner, unsigned char *command, int arg)
{
    if (command[2] == 5) {
        switch (command[3]) {
        case 0:
            if (command[4] == 0) {
                ((struct Ov249Actor *)owner)->slots[command[3]].effect =
                    Ov107_CreateNodeXformTask(*(int *)(owner + 0x3c), ((struct Ov249Actor *)owner)->slots[command[3]].model, 0x17, command[4], (void *)(owner + 0xa0));
            } else {
                ((struct Ov249Actor *)owner)->slots[command[3]].effect =
                    Ov107_CreateNodeBodyTask(*(int *)(owner + 0x3c), ((struct Ov249Actor *)owner)->slots[command[3]].model, 0x17, (void *)(owner + 0xa0), command[4], 0);
            }
            break;
        }
    }
    Ov107_AiState_OnMessage(owner, command, arg);
}
