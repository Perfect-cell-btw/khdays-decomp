/* Reset the reaction slot (mark 0, state -1) then fan out three dispatches. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov255_Partner_AiDispatchAction(int);
extern int Ov255_ClearAndSetNodeFlags(int);
extern int Ov255_PublishPoseAndReset(int);
void Ov255_Partner_AiStateInit(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 4) = *(int *)owner + 0xb0;
    *(signed char *)(*(int *)owner + 0x1c6) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    SetIndexedSlot(param_1, 0, (void *)&Ov255_Partner_AiDispatchAction);
    SetIndexedSlot(param_1, 1, (void *)&Ov255_ClearAndSetNodeFlags);
    SetIndexedSlot(param_1, 2, (void *)&Ov255_PublishPoseAndReset);
}
