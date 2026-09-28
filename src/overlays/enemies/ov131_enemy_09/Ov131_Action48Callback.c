/* AI step: sets the stance bits 0x82, flags the actor, sends the action 0x48 update and continues
 * with aiming at the target. */

extern void Ov107_BuildAndSendUpdate(int, int, int, int);
extern void SetIndexedSlot(int, int, void *);
extern void Ov131_stAdvanceTimerAimTarget(void);

struct node60 { unsigned short lo : 8; unsigned short hi : 8; };
struct flagword { unsigned f8 : 8; };

void Ov131_Action48Callback(int param_1) {
    int *node = *(int **)(param_1 + 4);
    unsigned short h = *(unsigned short *)(*node + 0x60);

    *(unsigned short *)(*node + 0x60) =
        h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10);
    ((struct node60 *)(*node + 0x60))->hi &= ~0xc;
    *(unsigned short *)(*node + 0x1ae) |= 1;
    ((struct flagword *)(*(int *)(*node + 0x388) + 8))->f8 &= ~1;
    node[0xc] = 0;
    Ov107_BuildAndSendUpdate(*node, 0, 0x48, node[0x10]);
    SetIndexedSlot(param_1, *(char *)(param_1 + 0x20), Ov131_stAdvanceTimerAimTarget);
}
