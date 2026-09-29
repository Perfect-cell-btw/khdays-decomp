/* On a hit deactivates the aim nodes and queues a reaction for interruptible actions, then the base
 * post-tick. */

#include "nitro/types.h"
#include "game/actor.h"
#include "game/enemy_common.h"

typedef struct Ov200AimNode Ov200AimNode;

typedef struct {
    Actor base;                  /* 0x000 */
    u8 pad38c[0x4];
    Ov200AimNode *aimNodes_0390[3];
    char pad_039c[0x3b0 - 0x39c];
    void *handle_03b0;
    void *handle_03b4;
    void *handle_03b8;
} Ov200Object;

extern void Ov201_SetNodeActiveState(Ov200AimNode *node, int active);
extern int Ov201_IsMode1(Ov200AimNode *node);
extern int Ov201_IsField38NibbleZero(Ov200AimNode *node);

void Ov201_PostTickCleanup(Ov200Object *self) {
    int i;

    if ((self->base.flags1c4 & 0xa) != 0) {
        Ov201_SetNodeActiveState(self->aimNodes_0390[0], 0);
        for (i = 1; i < 3; i++) {
            Ov201_SetNodeActiveState(self->aimNodes_0390[i], 0);
        }
        if (self->base.nextState == -1) {
            s8 mode = self->base.state;
            if (mode != 0 && mode != 1 && mode != 3 && mode != 8 && mode != 9) {
                self->base.nextState = 8;
            }
        }
    }
    if (Ov201_IsMode1(self->aimNodes_0390[0]) != 0 && self->base.state != 6) {
        Ov201_SetNodeActiveState(self->aimNodes_0390[0], 0);
    }
    for (i = 1; i < 3; i++) {
        if (Ov201_IsMode1(self->aimNodes_0390[i]) != 0 && self->base.state != 7) {
            Ov201_SetNodeActiveState(self->aimNodes_0390[i], 0);
        }
    }
    if (self->base.state != 6 && self->handle_03b4 != 0) {
        Ov107_UnlinkNodeFromOwner(self->handle_03b4);
        self->handle_03b4 = 0;
    }
    if (self->base.state != 7 &&
        Ov201_IsField38NibbleZero(self->aimNodes_0390[2]) != 0 &&
        Ov201_IsField38NibbleZero(self->aimNodes_0390[1]) != 0 &&
        self->handle_03b8 != 0) {
        Ov107_UnlinkNodeFromOwner(self->handle_03b8);
        self->handle_03b8 = 0;
    }
    if (self->base.state != 6 && self->base.state != 7 && self->handle_03b0 != 0) {
        Ov107_UnlinkNodeFromOwner(self->handle_03b0);
        self->handle_03b0 = 0;
    }
    Ov107_AiState_PostTickBase((char *)self);
}
