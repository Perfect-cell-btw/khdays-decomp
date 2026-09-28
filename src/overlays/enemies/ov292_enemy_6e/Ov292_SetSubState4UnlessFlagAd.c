/* AI step: steers the actor and, when the animation ends, queues action 4. */

extern void Ov292_StepSteering();
extern void SetIndexedSlot();

void Ov292_SetSubState4UnlessFlagAd(int this_) {
    int node = *(int *)(this_ + 4);
    Ov292_StepSteering(node);
    if (*(unsigned char *)(*(int *)(node + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)node + 0x1c7) = 4;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
