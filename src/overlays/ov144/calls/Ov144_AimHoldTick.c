/* Aim-hold tick of the ov144 enemy (and its byte-identical twin): turns the yaw towards the
 * target, then, unless the +0x384 item is busy, either plays animation 0 when the +0x4c flag is
 * set or fires the actor's +0x3a4 hook with the target's +0x1b4 id (and the actor) when there is
 * a target. */
typedef unsigned char u8;
typedef void (*IdHook)(int id, int actor);

extern void Ov144_AimYawToTarget(int *state);
extern void Ov107_PostTagUpdate(int actor, int anim, int flag);

void Ov144_AimHoldTick(int *node)
{
    int *state = (int *)node[1];
    IdHook hook;
    int actor;

    Ov144_AimYawToTarget(state);
    actor = *state;
    if (*(u8 *)(*(int *)(actor + 0x384) + 0xad) != 0) {
        return;
    }
    if (state[0x13] != 0) {
        Ov107_PostTagUpdate(actor, 0, 1);
        return;
    }
    hook = *(IdHook *)(actor + 0x3a4);
    if (hook != 0 && state[1] != 0) {
        hook(*(u8 *)(state[1] + 0x1b4), actor);
    }
}
