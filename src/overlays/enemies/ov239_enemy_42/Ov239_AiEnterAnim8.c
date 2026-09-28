/* Plays anim 8, resets the state and installs the next step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov239_TimedRequestThenPose4(void);

void Ov239_AiEnterAnim8(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 8, 0);
    p[0x30] = 0;
    *(int *)(p + 0x2c) = 0;
    p[0x32] = 0;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov239_TimedRequestThenPose4);
}
