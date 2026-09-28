/* Arms the walk state, posts two updates and installs the walk tick. */

extern void Ov238_Reaction_ForwardTwoUpdates(int self, int param_2, int param_3, int param_4, void *cb);
extern void Ov238_WalkTick(void);

void Ov238_AiEnterWalk(int param_1) {
    int obj = *(int *)(param_1 + 4);
    *(int *)(obj + 0x20) = 0;
    *(signed char *)(obj + 0x31) = 2;
    *(signed char *)(obj + 0x2d) = 2;
    Ov238_Reaction_ForwardTwoUpdates(param_1, 0x12, 8, 0, (void *)&Ov238_WalkTick);
}
