#include "game/engine.h"

extern int Ov002_GetCtxTableByte(int slot);

/* Rebinds the actor model and picks its idle variant from the owner's kind. */
void Ov002_RebindActorModelByKind(char *self) {
    char *owner = *(char **)(self + 8);
    Render_SubmitNode(self + 0x2c, (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]),
                      0, 0);
    if (*(short *)(owner + 0x68) == 0x2b) {
        Actor_SetBindingByte(self + 0x148, 3, 2);
    } else {
        Actor_SetBindingByte(self + 0x148, 3, 1);
    }
}
