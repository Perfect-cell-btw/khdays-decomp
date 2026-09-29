/* Kick the primary anim 7 and the +0x3d8 sub-anim 3, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov237_EnterLunge(int);
void Ov237_AiEnterLungeWindup(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 7, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3d8), 3, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov237_EnterLunge);
}
