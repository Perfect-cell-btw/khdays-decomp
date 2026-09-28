/* Returns the target when the object is armed and the player is within range 0xc. */

#include "nitro/types.h"

int QueryActiveStateOrDelegate(void);
int GetEntryField20ByIndex(int idx);
int Ov022_ForwardArg1(int arg0, int arg1);

typedef struct {
    u8 pad_00[0x1c];
    u8 field_1c[1];
    u8 pad_1d[0x40 - 0x1d];
    u8 flags_40;
} Obj_ov015_0208075c;

void *Ov015_GetTargetIfInRange(Obj_ov015_0208075c *obj)
{
    if (obj->flags_40 & 2)
    {
        if (Ov022_ForwardArg1(GetEntryField20ByIndex(QueryActiveStateOrDelegate()), 0xc))
            return obj->field_1c;
    }

    return 0;
}
