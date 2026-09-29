/* Clear the child field at +0x14, set anim state 1, then dispatch via
 * SetIndexedSlot (handler Ov159_AiMeasureTarget). */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov159_AiMeasureTarget(void);
void Ov159_AiEnterReach(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x14) = 0;
    Ov107_PostTagUpdate(*(int *)child, 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov159_AiMeasureTarget);
}
