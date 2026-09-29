#include "game/engine.h"

extern int Ov002_GetCtxTableByte(int slot);

/* Rebinds the actor model when its owner entity is still alive. */
void Ov002_RebindActorModelIfAlive(char *self) {
    if (*(signed char *)(*(char **)(self + 8) + 0x58) != 0) {
        Render_SubmitNode(self + 0x2c,
                          (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]), 0, 0);
    }
}
