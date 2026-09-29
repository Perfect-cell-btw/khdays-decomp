/* Plays anim 5, resets the part and installs the next step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void Ov220_startAnim(int obj, int arg);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov220_stateFixedAngleMatrix_2(void);

void Ov220_AiEnterAnim5(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 5, 0);
    Ov220_startAnim(*(int *)p, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov220_stateFixedAngleMatrix_2);
}
