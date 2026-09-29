/* Play the anim (ov107 mode 2). When +0x4c is live, build a transform in a local from
 * data_02042264 / +0x44 / (+0x4c)+0x190 (via 0203cd7c), apply it to +0x18 (via 0202ea48) and
 * copy the result into +8. Always dispatch. */

#include "game/enemy_common.h"

struct w4 { int a, b, c, d; };
struct mtx { int w[9]; };
extern void Mtx33_LookAt(struct mtx *out, int a, int b, const void *c);
extern void Quat_FromMtx33(int a, struct mtx *b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov185_DecayOffsetGiveUp(int);
extern const struct mtx data_02042264;
void Ov185_BuildTransformMatrixThenAdvance(int param_1) {
    int child = *(int *)(param_1 + 4);
    struct mtx buf;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 2, 0);
    if (*(int *)(child + 0x4c) != 0) {
        Mtx33_LookAt(&buf, *(int *)(child + 0x4c) + 0x190, *(int *)(child + 0x44), &data_02042264);
        Quat_FromMtx33(child + 0x18, &buf);
        *(struct w4 *)(child + 8) = *(struct w4 *)(child + 0x18);
    }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov185_DecayOffsetGiveUp);
}
