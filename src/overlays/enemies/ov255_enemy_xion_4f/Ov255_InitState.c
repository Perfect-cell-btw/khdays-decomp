/* State init of the ov255 enemy: the owner's +0x1c6 kind clears and +0x1c7 becomes -1, the +0x1c
 * orientation is set to the identity quaternion (data_020420f8) and copied to +0x2c, +4 caches the
 * owner's +0x74 centre, +8 its +0xb0 point and +0xc the +0x384 rig's +0xad byte, +0x6c is raised
 * and the three node callbacks are installed (slots 1, 0 and 2). */
struct vec4 { int a, b, c, d; };
extern const struct vec4 data_020420f8;
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov255_AiDispatchAction(void);
extern void Ov255_CommonUpdate(void);
extern void Ov255_stateSetFlagsClearBit(void);
void Ov255_InitState(int self) {
    int *obj = *(int **)(self + 4);
    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    *(struct vec4 *)(obj + 7) = data_020420f8;
    *(struct vec4 *)(obj + 0xb) = *(struct vec4 *)(obj + 7);
    obj[1] = *obj + 0x74;
    obj[2] = *obj + 0xb0;
    obj[3] = *(int *)(*obj + 0x384) + 0xad;
    obj[0x1b] = 1;
    SetIndexedSlot(self, 1, &Ov255_stateSetFlagsClearBit);
    SetIndexedSlot(self, 0, &Ov255_AiDispatchAction);
    SetIndexedSlot(self, 2, &Ov255_CommonUpdate);
}
