/* Ticks an actor's damage-over-time timer: when its period elapses, applies the accumulated damage
 * (keeping the fraction) and increases the rate, while the effect lasts. */

extern void Ov022_ApplyDamageAndFlagHit(int obj, int v, int mode);

struct Bit3_0209d118 { unsigned char lo : 3; unsigned char b3 : 1; };

void Ov022_TickChargeTimer(int obj, int dt) {
    int t = obj + 0x2c00;
    if (*(int *)(t + 4) <= 0) return;
    if (((struct Bit3_0209d118 *)(obj + 0x694))->b3) return;
    {
        int acc = *(int *)t + dt;
        *(int *)t = acc;
        if (acc >= *(int *)(t + 8)) {
            *(int *)t = 0;
            if (*(unsigned short *)(obj + 0x12) != 0) {
                int m = *(int *)(t + 0x10) * *(int *)(t + 0xc);
                int v = m + *(short *)(t + 0x1c);
                Ov022_ApplyDamageAndFlagHit(obj, v >> 0xc, 0);
                *(unsigned short *)(t + 0x1c) = v & 0xfff;
            }
            *(int *)(t + 0x10) = *(int *)(t + 0x10) + *(int *)(t + 0x14);
        }
    }
    {
        int c = *(int *)(t + 4) - dt;
        *(int *)(t + 4) = c;
        if (c <= 0) *(int *)(t + 4) = 0;
    }
}
