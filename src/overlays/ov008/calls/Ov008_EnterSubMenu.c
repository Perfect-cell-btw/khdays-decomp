extern int *NNSi_FndGetCurrentRootHeap(void);
extern int InstantiateClass(void *data, int arg1);
extern void Ov008_UpdateMenuInput(void);
extern void Ov008_TickMenuAndCheckTransition(void);
extern int data_ov008_02090db0[];

void (*Ov008_EnterSubMenu(void))(void)
{
    int *state = NNSi_FndGetCurrentRootHeap();

    state[5] = InstantiateClass(data_ov008_02090db0, 0);
    Ov008_UpdateMenuInput();
    return Ov008_TickMenuAndCheckTransition;
}
