/* Run 020cce08 on the object, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_SetNodeMode3(int);
extern int Ov245_AiHoverArmStart(int);
int Ov245_AiEnterHoverArm(int param_1) {
    Ov245_SetNodeMode3(*(int *)(*(int *)(param_1 + 4)));
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_AiHoverArmStart);
}
