/* Runs the model callbacks, copies the clip's pose into the object and applies its rotation to the
 * bones. */

#include "game/enemy_common.h"

extern void Srt_SetRotationQuat(void *pose, void *bones);

typedef struct {
    int words[11];
} Ov191Pose;

typedef struct {
    char pad0000[0xa0];
    char bones[0x2fc];
    Ov191Pose *pClip;   /* +0x39c */
    char pad03a0[0x8];
    Ov191Pose pose;     /* +0x3a8 */
} Ov191Object;

void Ov156_RefreshPose(Ov191Object *self, int flag) {
    Ov107_AiState_DispatchModelCallbacks(self, flag);

    self->pose = *(Ov191Pose *)((char *)self->pClip + 4);

    Srt_SetRotationQuat(&self->pose, self->bones);
}
