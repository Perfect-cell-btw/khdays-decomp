/* Plays anim 2, seeds the default pose and installs the face-target step. */

#include "game/enemy_common.h"

extern void Ov197_SeedDefaultPoseAndAdvance(int obj, int arg);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov197_FaceTargetThenIdle(void);

void Ov197_AiEnterFaceTarget(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 2, 0);
    Ov197_SeedDefaultPoseAndAdvance(*(int *)p, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov197_FaceTargetThenIdle);
}
