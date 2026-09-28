/* Install the callback pointers and owner link on the child, clear a flag, then dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov255_DecayShakes(int);
extern int Ov255_DrawShakes(int);
extern int Ov255_EmitShakes(int);
void Ov255_ShakeTask_Init(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(*(int *)(owner + 4) + 0x78) = (int)&Ov255_DecayShakes;
    *(int *)(*(int *)(owner + 4) + 0x6c) = (int)&Ov255_DrawShakes;
    *(int *)(*(int *)(owner + 4) + 0x84) = owner;
    *(int *)(*(int *)(owner + 4) + 0x5c) &= ~2;
    *(int *)(owner + 0x10) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov255_EmitShakes);
}
