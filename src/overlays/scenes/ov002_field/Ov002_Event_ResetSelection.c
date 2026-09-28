/* Resets the event context's selection (index -1, flag 0). */

extern int data_ov002_0207fa14;

void Ov002_Event_ResetSelection(void) {
    int p = *(int *)&data_ov002_0207fa14;
    *(char *)(p + 0x96) = -1;
    *(char *)(p + 0x97) = 0;
}
