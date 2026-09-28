/* Stop the ov237 actor's two looping effects: the +0x4c and +0x54 handles of its +0x490 state are
 * released on the +0x3c model (0203c650) and cleared. */
extern void TaskList_FinishByTag(int model, int handle);

void Ov237_StopLoopEffects(char *self)
{
    if (*(int *)(*(int *)(self + 0x490) + 0x4c) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x490) + 0x4c));
        *(int *)(*(int *)(self + 0x490) + 0x4c) = 0;
    }
    if (*(int *)(*(int *)(self + 0x490) + 0x54) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(*(int *)(self + 0x490) + 0x54));
        *(int *)(*(int *)(self + 0x490) + 0x54) = 0;
    }
}
