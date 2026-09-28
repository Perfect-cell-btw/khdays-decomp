/* On a hit deactivates the aim nodes and queues a reaction for interruptible actions, then the base
 * post-tick. */

typedef signed char s8;
typedef unsigned char u8;

typedef struct Ov200AimNode Ov200AimNode;

typedef struct {
    char pad_0000[0x1c4];
    u8 leavingFlags_01c4;
    u8 pad_01c5;
    s8 mode_01c6;
    s8 pendingMode_01c7;
    char pad_01c8[0x390 - 0x1c8];
    Ov200AimNode *aimNodes_0390[3];
    char pad_039c[0x3b0 - 0x39c];
    void *handle_03b0;
    void *handle_03b4;
    void *handle_03b8;
} Ov200Object;

extern void Ov271_SetNodeActiveState(Ov200AimNode *node, int active);
extern int Ov271_IsMode1(Ov200AimNode *node);
extern int Ov271_IsField38NibbleZero(Ov200AimNode *node);
extern void Ov107_UnlinkNodeFromOwner(void *handle);
extern void Ov107_AiState_PostTickBase(Ov200Object *self);

void Ov271_PostTickCleanup(Ov200Object *self) {
    int i;

    if ((self->leavingFlags_01c4 & 0xa) != 0) {
        Ov271_SetNodeActiveState(self->aimNodes_0390[0], 0);
        for (i = 1; i < 3; i++) {
            Ov271_SetNodeActiveState(self->aimNodes_0390[i], 0);
        }
        if (self->pendingMode_01c7 == -1) {
            s8 mode = self->mode_01c6;
            if (mode != 0 && mode != 1 && mode != 3 && mode != 8 && mode != 9) {
                self->pendingMode_01c7 = 8;
            }
        }
    }
    if (Ov271_IsMode1(self->aimNodes_0390[0]) != 0 && self->mode_01c6 != 6) {
        Ov271_SetNodeActiveState(self->aimNodes_0390[0], 0);
    }
    for (i = 1; i < 3; i++) {
        if (Ov271_IsMode1(self->aimNodes_0390[i]) != 0 && self->mode_01c6 != 7) {
            Ov271_SetNodeActiveState(self->aimNodes_0390[i], 0);
        }
    }
    if (self->mode_01c6 != 6 && self->handle_03b4 != 0) {
        Ov107_UnlinkNodeFromOwner(self->handle_03b4);
        self->handle_03b4 = 0;
    }
    if (self->mode_01c6 != 7 &&
        Ov271_IsField38NibbleZero(self->aimNodes_0390[2]) != 0 &&
        Ov271_IsField38NibbleZero(self->aimNodes_0390[1]) != 0 &&
        self->handle_03b8 != 0) {
        Ov107_UnlinkNodeFromOwner(self->handle_03b8);
        self->handle_03b8 = 0;
    }
    if (self->mode_01c6 != 6 && self->mode_01c6 != 7 && self->handle_03b0 != 0) {
        Ov107_UnlinkNodeFromOwner(self->handle_03b0);
        self->handle_03b0 = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
