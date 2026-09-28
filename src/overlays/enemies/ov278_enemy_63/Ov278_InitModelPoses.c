/* Model pose init: after the base 020c4924 step, push the +0x3a0 clip's pose (+4) into the
 * +0x3b0 and +0x398 targets' +0x10 slots and the +0x3a4 clip's into the +0x3b4 / +0x39c ones. */
extern void Ov107_AiState_DispatchModelCallbacks(void *obj, int);
struct blk11 { int w[11]; };
void Ov278_InitModelPoses(char *obj, int flag) {
    Ov107_AiState_DispatchModelCallbacks(obj, flag);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3b0)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3a0) + 4);
    *(struct blk11 *)(*(char **)(obj + 0x398) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3a0) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3b4)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3a4) + 4);
    *(struct blk11 *)(*(char **)(obj + 0x39c) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3a4) + 4);
}
