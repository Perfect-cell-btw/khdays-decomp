/* c634 init: reset owner status bytes (+0x1c6=0, +0x1c7=-1), seed obj[0xa..0xd] from a shared
 * constant vec (data_020420f8) and mirror it into obj[0xe..0x11], cache owner+0x74 into obj[1]
 * and (owner->f384)+0xad into obj[2], latch the owner's +0x1b0 halfword into the +0x74 byte,
 * then arm the three phase callbacks (slots 1/0/2). */
struct vec4 { int a, b, c, d; };
extern const struct vec4 data_020420f8;
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov273_AiDispatchAction(void);
extern void Ov273_SlerpPoseCountdownAndFlushVelocity(void);
extern void Ov273_EnterStopAnimRaiseFlags86(void);
void Ov273_InitActionState(int self) {
    int *obj = *(int **)(self + 4);
    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    *(struct vec4 *)(obj + 0xa) = data_020420f8;
    *(struct vec4 *)(obj + 0xe) = *(struct vec4 *)(obj + 0xa);
    obj[1] = *obj + 0x74;
    obj[2] = *(int *)(*obj + 0x384) + 0xad;
    *((unsigned char *)obj + 0x74) = *(unsigned short *)(*obj + 0x100 + 0xb0);
    SetIndexedSlot(self, 1, &Ov273_EnterStopAnimRaiseFlags86);
    SetIndexedSlot(self, 0, &Ov273_AiDispatchAction);
    SetIndexedSlot(self, 2, &Ov273_SlerpPoseCountdownAndFlushVelocity);
}
