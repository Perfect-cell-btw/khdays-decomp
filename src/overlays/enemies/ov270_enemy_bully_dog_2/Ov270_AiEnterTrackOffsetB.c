/* Plays anim 13 and model anim 5 and installs the second offset tracking step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void Ov107_StartAnim(int subject, int anim_id, int mode);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov270_AiTrackOffsetUntilAnimEnd_2(void);

void Ov270_AiEnterTrackOffsetB(char *obj) {
    char *p = *(char **)(obj + 4);
    *(int *)(p + 0x14) = 0;
    Ov107_PostTagUpdate(*(int *)p, 13, 0);
    Ov107_StartAnim(*(int *)(*(char **)p + 0x3d0), 5, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov270_AiTrackOffsetUntilAnimEnd_2);
}
