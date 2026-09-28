/* Returns the actor's target position by target type (candidate part, panel target, or fixed
 * point). */

extern int Ov002_TriggerEntryActive(int arg0);
int func_ov022_020ad0c0(int arg0) {
    int r = 0;
    switch (*(unsigned char *)(arg0 + 0x4f0)) {
    case 1:
        r = **(int **)(arg0 + 0x500) + 4;
        break;
    case 2:
        r = Ov002_TriggerEntryActive(*(int *)(arg0 + 0x4f8));
        break;
    case 3:
        r = *(int *)(arg0 + 0x504) + 0x8f8;
        break;
    }
    return r;
}
