/* Init the reaction: point (child)+8 at (*child)+0xb0, reset the sub-state bytes (+0x1c6=0,
 * +0x1c7=-1), clear flag 0 in the high byte at (*child)+0x60 and bit 0 of the halfword at
 * (*child)+0x1ae, then register the two phase handlers on slots 0 and 1. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov230_dispatchByStatusByte(int);
extern void Ov230_ClearSetVisFlagsAdvance(int);
struct node60_020d5f60 { unsigned short lo : 8; unsigned short hi : 8; };
void Ov230_AiStateInit(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 8) = *(int *)child + 0xb0;
    *(signed char *)(*(int *)child + 0x1c6) = 0;
    *(signed char *)(*(int *)child + 0x1c7) = -1;
    ((struct node60_020d5f60 *)(*(int *)child + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)child + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov230_dispatchByStatusByte);
    SetIndexedSlot(param_1, 1, (void *)&Ov230_ClearSetVisFlagsAdvance);
}
