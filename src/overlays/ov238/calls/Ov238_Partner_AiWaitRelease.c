/* Clear the hw60 flag; if +0x390 was armed, clear it, mark state 0 and dispatch. */
extern int SetIndexedSlot(int, int, void *);
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
void Ov238_Partner_AiWaitRelease(int param_1) {
    int owner = *(int *)(param_1 + 4);
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~0x80;
    if (*(int *)(*(int *)owner + 0x390) == 0) return;
    *(int *)(*(int *)owner + 0x390) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
