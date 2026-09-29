/* Leave handling of the ov125 enemy: when the +0x1c4 flags carry 0xa the two effect handles at
 * +0x3ac / +0x3a8 are released, the aim node deactivated and, with no pending mode, mode 8 is
 * queued unless the current mode is 0/1/3/8/9. Outside mode 6 an active aim node is
 * deactivated and both handles released. Then the shared pre-update runs. */

#include "nitro/types.h"
#include "game/actor.h"

typedef struct Ov125AimNode Ov125AimNode;

typedef struct {
    Actor base;                  /* 0x000 */
    u8 pad38c[0x4];
    Ov125AimNode *aimNode_0390;
    char pad_0394[0x3a8 - 0x394];
    void *handle_03a8;
    void *handle_03ac;
} Ov125Object;

extern void Ov107_UnlinkNodeFromOwner(void *handle);
extern void Ov126_SetNodeActiveState(Ov125AimNode *node, int active);
extern int Ov126_IsField34Nibble1(Ov125AimNode *node);
extern void Ov107_AiState_PostTickBase(Ov125Object *self);

void Ov126_LeaveHandling(Ov125Object *self) {
    if ((self->base.flags1c4 & 0xa) != 0) {
        if (self->handle_03ac != 0) {
            Ov107_UnlinkNodeFromOwner(self->handle_03ac);
            self->handle_03ac = 0;
        }
        if (self->handle_03a8 != 0) {
            Ov107_UnlinkNodeFromOwner(self->handle_03a8);
            self->handle_03a8 = 0;
        }
        Ov126_SetNodeActiveState(self->aimNode_0390, 0);
        if (self->base.nextState == -1) {
            s8 mode = self->base.state;
            if (mode != 0 && mode != 1 && mode != 3 && mode != 8 && mode != 9) {
                self->base.nextState = 8;
            }
        }
    }
    if (self->base.state != 6) {
        if (Ov126_IsField34Nibble1(self->aimNode_0390) != 0) {
            Ov126_SetNodeActiveState(self->aimNode_0390, 0);
        }
        if (self->handle_03a8 != 0) {
            Ov107_UnlinkNodeFromOwner(self->handle_03a8);
            self->handle_03a8 = 0;
        }
        if (self->handle_03ac != 0) {
            Ov107_UnlinkNodeFromOwner(self->handle_03ac);
            self->handle_03ac = 0;
        }
    }
    Ov107_AiState_PostTickBase(self);
}
