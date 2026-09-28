/* Kick the animation selected by +0xc on the object, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_AiStep_QueueAction0OnAnimEnd_4(int);
void Ov254_Marker_AiPlayStoredAnim(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, *(unsigned char *)(owner + 0xc), 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_AiStep_QueueAction0OnAnimEnd_4);
}
