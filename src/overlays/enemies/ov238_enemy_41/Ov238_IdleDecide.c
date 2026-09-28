/* Idle decision of the ov238 actor: a pending rider signal (+0x384 model's +0x394) is consumed and the
 * next move is 5. Otherwise, once the partner holds no queued move: with charges left (+0x2d) one is
 * spent and pose 0 plays; with no rest pending (+0x28) a picked move (020d0b2c) ends the node; a
 * target farther than 20.0 or a rider below -15.0 gives move 4; at 6.0-20.0 the actor starts walking
 * (pose 0x11, part motion 7, node 020d120c); else the node goes to 020d107c. */
extern int Ov238_TargetGap(int *node);
extern int Ov238_PickMove(int *node);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern int Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov238_AiTurnUntilAnimEnd(void);
extern void Ov238_AiEnterIdle(void);

void Ov238_IdleDecide(int *node)
{
    int *state = (int *)node[1];
    int dist = Ov238_TargetGap(node);

    if (*(int *)(*(int *)(*state + 0x384) + 0x394) != 0) {
        *(int *)(*(int *)(*state + 0x384) + 0x394) = 0;
        *(unsigned char *)(*state + 0x1c7) = 5;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    if (*((unsigned char *)state + 0x2d) != 0) {
        *((unsigned char *)state + 0x2d) -= 1;
        Ov107_PostTagUpdate(*state, 0, 0);
        return;
    }
    if (state[0xa] == 0 && Ov238_PickMove(node) != 0) {
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    if (dist > 0x5000 || *(int *)(*(int *)(*state + 0x3e4) + 0x198) < -0xf000) {
        *(unsigned char *)(*state + 0x1c7) = 4;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    if (dist <= 0x5000 && dist >= 0x1800) {
        Ov107_PostTagUpdate(*state, 0x11, 0);
        Ov107_StartAnim(*(int *)(*state + 0x3e0), 7, 0);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov238_AiTurnUntilAnimEnd);
        return;
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov238_AiEnterIdle);
}
