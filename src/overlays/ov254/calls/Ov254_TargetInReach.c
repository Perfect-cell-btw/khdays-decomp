/* Reach test: while the +0x78 aggressive flag is set, returns 1 when the target touches any of the
 * owner's four probes (the +0x3f8 / +0x3f4 spheres at +0x68, the +0x3fc / +0x400 capsules at
 * +0x78; 020cd198), else 0. */
extern int Ov254_ReboundHitTest(int *ctx, int target, void *sphere, void *capsule);

int Ov254_TargetInReach(int *ctx, int target)
{
    if (ctx[0x1e] != 0) {
        if (Ov254_ReboundHitTest(ctx, target, (void *)(*(int *)(ctx[0] + 0x3f8) + 0x68), 0) != 0 ||
            Ov254_ReboundHitTest(ctx, target, (void *)(*(int *)(ctx[0] + 0x3f4) + 0x68), 0) != 0 ||
            Ov254_ReboundHitTest(ctx, target, 0, (void *)(*(int *)(ctx[0] + 0x3fc) + 0x78)) != 0 ||
            Ov254_ReboundHitTest(ctx, target, 0, (void *)(*(int *)(ctx[0] + 0x400) + 0x78)) != 0) {
            return 1;
        }
    }
    return 0;
}
