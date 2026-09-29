/* After 0x3000 plays anim 10 and installs the queue-action-2 step. */

extern void Ov107_PostTagUpdate(int obj, int tag1, int tag_lsb);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov188_AiStep_QueueAction2OnAnimEnd_3(void);

void Ov188_AiDelayThenAnim10(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x18) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x18) = val;
    if (val < 0x3000) return;
    Ov107_PostTagUpdate(*(int *)p, 10, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov188_AiStep_QueueAction2OnAnimEnd_3);
}
