/* Submits the element's render node with its group's table byte. */

#include "game/engine.h"

extern int Ov002_GetCtxTableByte(int slot);

void Ov021_SubmitNode(char *self) {
    Render_SubmitNode(self + (0x49 << 2),
                  (unsigned short)Ov002_GetCtxTableByte((unsigned char)self[0x10]),
                  0, 0);
}
