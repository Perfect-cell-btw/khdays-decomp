/* c634 init (chase variant): reset owner status bytes (+0x1c6=0, +0x1c7=-1), cache owner+0xb0
 * into obj[1] and the owner's +0x384 list's +0x3ec entry (+4) into obj[2], seed the three
 * 16-byte pose blocks at obj+0x20 / +0x50 / +0x40 from the shared constant vec data_020420f8,
 * then arm the three phase callbacks (slots 1/0/2). */
struct vec4 { int a, b, c, d; };
extern const struct vec4 data_020420f8;
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov213_EnterRaiseFlags86ClearLocks(void);
extern void Ov213_Companion_AiDispatchAction(void);
extern void Ov213_SlerpPoseAndFlushVelocity(void);
void Ov213_InitChaseState(int self) {
    int *obj = *(int **)(self + 4);
    struct vec4 seed;
    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    obj[1] = *obj + 0xb0;
    obj[2] = *(int *)(*(int *)(*obj + 0x384) + 0x3ec) + 4;
    seed = data_020420f8;
    *(struct vec4 *)(obj + 8) = seed;
    *(struct vec4 *)(obj + 0x14) = seed;
    *(struct vec4 *)(obj + 0x10) = seed;
    SetIndexedSlot(self, 1, &Ov213_EnterRaiseFlags86ClearLocks);
    SetIndexedSlot(self, 0, &Ov213_Companion_AiDispatchAction);
    SetIndexedSlot(self, 2, &Ov213_SlerpPoseAndFlushVelocity);
}
