/* AI step: when the byte behind context +0x28 is clear, pendingAction (+0x1c7) = 2 and the step
 * handler is cleared. */

extern int SetIndexedSlot();

void Ov205_AiStep_QueueAction2OnFlag28Clear_5(char *r0) {
    char *r2 = *(char **)(r0 + 4);
    char *r1 = *(char **)(r2 + 0x28);
    if (*(unsigned char *)r1 != 0) {
        return;
    }
    r1 = *(char **)r2;
    *(unsigned char *)(r1 + 0x1c7) = 2;
    SetIndexedSlot(r0, *(signed char *)(r0 + 0x20), 0);
}
