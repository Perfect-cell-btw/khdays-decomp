/* Ov245_ArmScriptedMove -- arm the node for a scripted move: raise the owner's +0x39c request, seed
 * the three tween words (+0x1c, +0x24, +0x20) with the caller's value, clear the elapsed counter
 * at +0x2c and put the owner in state 1. */
void Ov245_ArmScriptedMove(int *node, int v) {
    *(int *)(node[0] + 0x39c) = 1;
    node[7] = v;
    node[9] = v;
    node[8] = v;
    node[0xb] = 0;
    *(unsigned char *)(node[0] + 0x1c7) = 1;
}
