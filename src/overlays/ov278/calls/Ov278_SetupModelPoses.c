/* Model pose setup: composes the +0x39c clip's pose (+4) with the constant data_ov278_020d6234
 * rotation into a scratch pose, writes it to the clip, then broadcasts the clip poses: +0x39c
 * into the +0x394 item's +0x10 and the +0x3a4 handle's target, +0x3a0 into the +0x398 item's
 * +0x10 and the +0x3a8 handle's target, and the +0x398 item's pose into the +0x3b0 owner's
 * +0x40 / +0x48 bone slots. */
struct m4 { int w[4]; };
struct blk11 { int w[11]; };
extern void Quat_Multiply(void *out, void *a, void *b);
extern void Srt_SetRotationQuat(int srt, void *pose);
extern const struct m4 data_ov278_020d6234;

void Ov278_SetupModelPoses(int unused, char *obj) {
    struct m4 turn = data_ov278_020d6234;
    struct m4 pose;

    Quat_Multiply(&pose, *(char **)(obj + 0x39c) + 4, &turn);
    Srt_SetRotationQuat(*(int *)(obj + 0x39c) + 4, &pose);
    *(struct blk11 *)(*(char **)(obj + 0x394) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x39c) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3a4)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x39c) + 4);
    *(struct blk11 *)(*(char **)(obj + 0x398) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3a0) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3a8)) + 0x10) = *(struct blk11 *)(*(char **)(obj + 0x3a0) + 4);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3b0) + 0x40) + 4) = *(struct blk11 *)(*(char **)(obj + 0x398) + 0x10);
    *(struct blk11 *)(*(char **)(*(char **)(obj + 0x3b0) + 0x48) + 4) = *(struct blk11 *)(*(char **)(obj + 0x398) + 0x10);
}
