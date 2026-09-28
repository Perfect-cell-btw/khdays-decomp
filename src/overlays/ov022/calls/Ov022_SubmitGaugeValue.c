extern int Anim_GetFrame(int a, int b);
extern int func_ov022_0209fc78(int obj, int a);
extern int Ov022_GetGlobal34(void);
extern void Ov022_DrawTaggedVoice(int a, int b, int c, int d);

/* Bit 52 of the 64-bit flag word at obj+0x464. The struct-field form keeps the
 * direct `ldr [obj,#0x468]` for the high half; a plain cast splits the base. */
struct Flags0209c7dc { char pad0[0x464]; unsigned long long flags; };

void Ov022_SubmitGaugeValue(int obj) {
    int v = *(int *)(obj + 0x6bc);
    int base = Anim_GetFrame(*(int *)(obj + 0x20) + 4, 0);
    short cur;
    if (func_ov022_0209fc78(obj, -1) == 0) return;
    if (*(int *)(obj + 0x6bc) < 0x1e) return;
    if (*(int *)(obj + 0x6bc) >= 0x2e) return;
    cur = *(short *)(obj + 0x2aba);
    if (cur == Ov022_GetGlobal34()) {
        if ((((struct Flags0209c7dc *)obj)->flags & 0x10000000000000LL) == 0)
            base -= cur;
    }
    Ov022_DrawTaggedVoice(obj + 0x910, v - 0x1e, base, obj + 0x588);
}
