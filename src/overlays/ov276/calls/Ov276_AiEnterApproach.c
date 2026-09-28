extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void Ov276_startAnim(int obj, int arg);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov276_AiWalkToTargetTick(void);

void Ov276_AiEnterApproach(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate(*(int *)p, 2, 1);
    Ov276_startAnim(*(int *)p, 1);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov276_AiWalkToTargetTick);
}
