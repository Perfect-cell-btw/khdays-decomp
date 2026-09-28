/* Plays anim 12 and model anim 4 and installs the offset tracking step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void Ov107_StartAnim(int subject, int anim_id, int mode);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov196_AiTrackOffsetUntilAnimEnd(void);

void Ov196_AiEnterTrackOffset(char *obj) {
    char *p = *(char **)(obj + 4);
    *(int *)(p + 0x14) = 0;
    Ov107_PostTagUpdate(*(int *)p, 12, 0);
    Ov107_StartAnim(*(int *)(*(char **)p + 0x3d0), 4, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov196_AiTrackOffsetUntilAnimEnd);
}
