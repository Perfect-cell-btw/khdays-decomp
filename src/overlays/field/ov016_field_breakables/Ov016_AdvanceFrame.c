/* When visible advances the frame (capped at 0x1d000) on the active tracks. */

#include "nitro/types.h"

typedef struct {
    char _0[0xe0];
    short slots[1];   /* +0xe0 */
} Ov002SlotTable;

typedef struct {
    char _0[0x12];
    u16 flags;          /* +0x12 */
    char _14[0x1c0 - 0x14];
    int accum;           /* +0x1c0 */
} Obj;

extern int Ov002_GetModuleScale(void);
extern void Ov002_SetFrameOnActiveTracks(Ov002SlotTable *tbl, int param_2);

void Ov016_AdvanceFrame(Obj *self) {
    if ((self->flags & 4) != 0) {
        self->accum += Ov002_GetModuleScale();
        if (self->accum >= 0x1d000) {
            self->accum = 0x1d000;
        }
        Ov002_SetFrameOnActiveTracks((Ov002SlotTable *)((char *)self + 0x2c), self->accum);
    }
}
