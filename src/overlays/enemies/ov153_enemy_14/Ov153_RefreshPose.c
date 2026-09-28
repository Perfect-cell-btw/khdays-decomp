/* Pose refresh: run the animator, copy the 44-byte pose out of the current clip (past its 4-byte
 * header) into the object's own slot, and hand that slot to the blender with the bone table at
 * +0xa0. The copy is a WHOLE-STRUCT assignment -- that is what gives the three ldm/stm pairs. The
 * destination must be a STRUCT FIELD of the object, not a cast pointer: written as a cast the
 * compiler folds the address and drops the `mov ip,lr` that preserves the start for the blender
 * call, four bytes short. One of six byte-identical siblings across two layouts (clip at +0x38c,
 * pose at +0x39c). */

extern void Ov107_AiState_DispatchModelCallbacks(void *self);
extern void Srt_SetRotationQuat(void *pose, void *bones);

typedef struct {
    int words[11];
} Ov191Pose;

typedef struct {
    char pad0000[0xa0];
    char bones[0x2ec];
    Ov191Pose *pClip;   /* +0x38c */
    char pad0390[0xc];
    Ov191Pose pose;     /* +0x39c */
} Ov191Object;

void Ov153_RefreshPose(Ov191Object *self) {
    Ov107_AiState_DispatchModelCallbacks(self);

    self->pose = *(Ov191Pose *)((char *)self->pClip + 4);

    Srt_SetRotationQuat(&self->pose, self->bones);
}
