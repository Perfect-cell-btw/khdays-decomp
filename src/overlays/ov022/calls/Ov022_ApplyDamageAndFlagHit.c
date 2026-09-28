extern int Slot_EvalPackedParam(int a, int b);
extern int func_ov022_020ad7b0(int obj);
extern void Ov022_ActorSetHp(int obj, int v);
extern int Session_GetLocalPlayerIndex(void);

void Ov022_ApplyDamageAndFlagHit(int obj, unsigned int v, int mode) {
    int ok = 1;
    if (mode == 0 && Slot_EvalPackedParam(*(unsigned char *)(obj + 9), 0x41) != 0 &&
        func_ov022_020ad7b0(obj) != 0) {
        ok = 0;
    }
    if (ok == 0) return;
    if (mode != 0) Ov022_ActorSetHp(obj, v);
    else Ov022_ActorSetHp(obj, *(unsigned short *)(obj + 0x12) + v);
    if (Session_GetLocalPlayerIndex() != 0) return;
    *(unsigned long long *)(obj + 0x46c) |= 0x10000000000LL;
}
