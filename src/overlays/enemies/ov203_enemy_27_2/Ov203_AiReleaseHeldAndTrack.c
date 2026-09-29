/* Unlinks the held node and follows the owner offset; once grounded and the flag clears queues
 * action 2. */

#include "game/enemy_common.h"

extern int Vec3TransformViaTempMtx();
extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

void Ov203_AiReleaseHeldAndTrack(int this) {
    int s = *(int *)(this + 4);
    int p = *(int *)s;
    int local[3];
    int r6;

    if (*(int *)(p + 0x410) != 0) {
        Ov107_UnlinkNodeFromOwner((void *)(*(int *)(p + 0x410)));
        *(int *)(*(int *)s + 0x410) = 0;
    }

    p = *(int *)s;
    r6 = Ov107_ActionResource_GetOffsetAndScale(*(int *)(p + 0x388), (VecFx32 *)local);

    Vec3TransformViaTempMtx(s + 0x14, *(int *)s + 0xa0, local);

    ScaleVec3Fx12(r6, s + 0x14, s + 0x14);

    p = *(int *)s;
    if (((unsigned int)(*(unsigned char *)(p + 0x17a) << 0x1f) >> 0x1f) == 0) {
        return;
    }
    if (*(unsigned char *)(*(int *)(s + 0x44)) != 0) {
        return;
    }

    *(unsigned char *)(p + 0x1c7) = 2;
    SetIndexedSlot(this, *(signed char *)(this + 0x20), 0);
}
