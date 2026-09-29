/* Plays anim 2, seeds the default pose and installs the face-target step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void Ov198_SeedDefaultPoseAndAdvance(int obj, int arg);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov198_FaceTargetThenIdle(void);

void Ov198_AiEnterFaceTarget(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 2, 0);
    Ov198_SeedDefaultPoseAndAdvance(*(int *)p, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov198_FaceTargetThenIdle);
}
