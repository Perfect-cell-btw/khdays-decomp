/* Ov245_TargetHeightGap -- distance to the current target: refreshes the actor's +0x3f8 target
 * (020cab14 with mode 0) and returns 0 when there is none; otherwise the absolute height gap
 * between the target's +0x198 position and the node's +8 origin, reduced (when `flat` is set)
 * by the target's +0x80 radius plus 19.0 and clamped at zero. */
extern int Ov107_FindNearestObject(int actor, int mode);

int Ov245_TargetHeightGap(int *node, int flat) {
    int *state = (int *)node[1];
    int target;
    int gap;

    *(int *)(*state + 0x3f8) = Ov107_FindNearestObject(*state, 0);
    target = *(int *)(*state + 0x3f8);
    if (target == 0) {
        return 0;
    }
    gap = *(int *)(target + 0x198) - *(int *)(state[2] + 8);
    if (gap < 0) {
        gap = -gap;
    }
    if (flat == 0) {
        return gap;
    }
    gap -= *(int *)(target + 0x80) + 0x4c00;
    if (gap < 0) {
        gap = 0;
    }
    return gap;
}
