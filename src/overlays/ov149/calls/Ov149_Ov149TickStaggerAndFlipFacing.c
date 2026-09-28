/* Tick this enemy's stagger timer on a hit, stash the hit info and flip the node's
 * facing bit. Same shape as Ov185_ApplyHitReaction, with different sub-state ids
 * (3 when the timer runs out, 7 on the 0x8000 hit flag), the hit's Vec3 copied to
 * p4+0x24, the hit owner parked at p4+0x38, and reaction id 0x14e.
 *
 * The hit descriptor at a2 is a bitfield container: a 16-bit flag word plus a
 * 16-bit kind. The bare `lsr #0x10` with no paired `lsl` is the tell. The gate at
 * a2+0x10 reads its low half SIGNED, hence the lsl/asr pair. */
extern int Ov107_CalcHitDamage();
extern void Ov107_BuildAndSendUpdate(int obj, int id, unsigned short mode, int node);

typedef struct { int a, b, c; } Blk3;
struct NodeFacing { unsigned char facing : 1; };
struct HitFlags { unsigned int lo : 16, hi : 16; };
struct HitGate { int lo : 16, hi : 16; };

int Ov149_Ov149TickStaggerAndFlipFacing(int this, int a1, int a2)
{
    int s = (int)*(short *)(this + 0x21a);
    int *p4 = *(int **)(this + 0x214);
    int n;
    int d;
    int result;
    struct HitFlags *hf;
    struct NodeFacing *fb;

    if (s <= 0)
        return 0;

    n = Ov107_CalcHitDamage(this, a2);
    *(int *)(a2 + 0x28) = n;

    d = (int)*(short *)(this + 0x21a) - n;
    if (d < 0) {
        result = 0;
    } else {
        result = (int)*(short *)(this + 0x218);
        if (d <= result)
            result = d;
    }
    *(short *)(this + 0x21a) = (short)result;

    if ((int)*(short *)(this + 0x21a) == 0) {
        *(char *)(*(int *)p4 + 0x1c7) = 3;
    } else {
        if ((unsigned short)*(int *)a2 & 0x8000)
            *(char *)(*(int *)p4 + 0x1c7) = 7;
    }

    *(int *)((char *)p4 + 0x38) = a1;
    *(Blk3 *)((char *)p4 + 0x24) = *(Blk3 *)(a2 + 4);

    if (((struct HitGate *)(a2 + 0x10))->lo > 0) {
        hf = (struct HitFlags *)a2;
        if ((hf->lo & 8) == 0 || (hf->lo & 0x80) == 0 || hf->hi != 0x80) {
            fb = (struct NodeFacing *)((char *)p4 + 0x49);
            if (hf->lo & 0x22) {
                fb->facing = fb->facing + 1;
                Ov107_BuildAndSendUpdate(this, 0x14e, (fb->facing & 1) ? 2 : 3,
                                    *(int *)((char *)p4 + 0x3c));
            } else {
                fb->facing = fb->facing + 1;
                Ov107_BuildAndSendUpdate(this, 0x14e, (fb->facing & 1) ? 0 : 1,
                                    *(int *)((char *)p4 + 0x3c));
            }
        }
    }

    return 1;
}
