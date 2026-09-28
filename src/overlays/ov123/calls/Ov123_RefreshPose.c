extern void Ov107_AiState_DispatchModelCallbacks(void *self);
extern void Srt_SetRotationQuat(void *pose, void *bones);

typedef struct {
    int words[11];
} Ov191Pose;

typedef struct {
    char pad0000[0xa0];
    char bones[0x2f0];
    Ov191Pose *pClip;   /* +0x390 */
    char pad0394[0x8];
    Ov191Pose pose;     /* +0x39c */
} Ov191Object;

void Ov123_RefreshPose(Ov191Object *self) {
    Ov107_AiState_DispatchModelCallbacks(self);

    self->pose = *(Ov191Pose *)((char *)self->pClip + 4);

    Srt_SetRotationQuat(&self->pose, self->bones);
}
