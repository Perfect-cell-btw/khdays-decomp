/* Push the current scroll span to the view, but only when it changed: the span
 * is the head position minus the tail, and both it and the head are cached at
 * +0x20/+0x24. A zero head means there is nothing to show. */
extern int Ov002_GetRootField8d18(void);
extern int Ov002_CountRemainingSlots(void);
extern void Ov002_DrawPageCounter(unsigned short head, unsigned short span);

extern char *data_ov002_0207f634;

void Ov002_PushScrollSpan(void) {
    char *ctx = data_ov002_0207f634;
    int head = Ov002_GetRootField8d18();
    int span = head - Ov002_CountRemainingSlots();

    if (head == 0) {
        return;
    }
    if (*(int *)(ctx + 0x20) == head && *(int *)(ctx + 0x24) == span) {
        return;
    }

    Ov002_DrawPageCounter((unsigned short)head, (unsigned short)span);
}
