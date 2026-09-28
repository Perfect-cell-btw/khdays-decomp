/* Store speed*30/15 into +0x18, feed the linked emitter node, then unless busy reset anim 0 and
 * dispatch 020d0500. */
extern int Actor_SetVecAndSyncChild(int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AiCarryWait(int);
void Ov253_AiPickupFollow(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x18) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 15;
    int obj = *(int *)owner;
    Actor_SetVecAndSyncChild(*(int *)(*(int *)(*(int *)(obj + 0x3bc) + 0x18c) + 0x20),
        *(int *)(*(int *)(obj + 0x3b0) + 8) + 0x40);
    if (*(unsigned char *)(*(int *)(owner + 8)) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 0, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiCarryWait);
}
