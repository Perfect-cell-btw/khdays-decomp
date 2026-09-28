extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void Ov148_SeedDefaultPoseAndAdvance(int obj, int arg);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov148_FaceTargetThenIdle(void);

void Ov148_AiEnterFaceTarget(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 2, 0);
    Ov148_SeedDefaultPoseAndAdvance(*(int *)p, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov148_FaceTargetThenIdle);
}
