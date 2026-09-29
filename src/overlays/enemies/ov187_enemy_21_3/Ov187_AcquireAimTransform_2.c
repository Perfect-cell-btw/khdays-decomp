/* c634 handler: clear owner hw60 hi bits 0x8c, set bit0 of owner+0x1ae, clear bit0 of the
 * low byte at *(owner+0x388)+8, then query the aim target (Ov107_FindNearestObject). If found,
 * fetch its transform into obj[6..9] (Ov187_LookAtQuat_2) and copy it to obj[2..5]. Finally
 * notify Ov107_PostTagUpdate(owner,0,0) and dispatch via SetIndexedSlot. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo:8, hi:8; };
struct b8 { unsigned int b:8; };
struct vec4 { int a, b, c, d; };
extern int Ov107_FindNearestObject(int owner, int a);
extern void Ov187_LookAtQuat_2(int *obj, int *out);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov187_AiRollTimerQueue2B(void);
void Ov187_AcquireAimTransform_2(int self) {
    int *obj = *(int **)(self + 4);
    ((struct hw60 *)(*obj + 0x60))->hi &= ~0x8c;
    *(unsigned short *)(*obj + 0x1ae) |= 1;
    ((struct b8 *)(*(int *)(*obj + 0x388) + 8))->b &= ~1;
    obj[1] = Ov107_FindNearestObject(*obj, 0);
    if (obj[1] != 0) {
        Ov187_LookAtQuat_2(obj, obj + 6);
        *(struct vec4 *)(obj + 2) = *(struct vec4 *)(obj + 6);
    }
    Ov107_PostTagUpdate((Actor *)(*obj), 0, 0);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov187_AiRollTimerQueue2B);
}
