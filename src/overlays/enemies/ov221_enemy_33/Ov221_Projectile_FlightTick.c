/* Ov221_Projectile_FlightTick -- per-tick: settle the motion, then re-arm the driver.
 * Flag 0x80 is cleared from the high byte of the owner's +0x60 halfword every tick.
 * While the latch at +0x60 is clear the motion is integrated by ScaleVec3Fx12; once the value at
 * +0x44 passes 0x3400 the speed at +0x48 is cut to 70% and the latch is set, so the cut happens
 * exactly once. After the latch is set the path is reset instead: +0x18/+0x1c zeroed, the speed
 * parked at +0x20, and Vec3TransformViaTempMtx given the block.
 * Either way the driver is re-armed, told twice over whether +0x5c is still clear.
 *
 * The 70% is kept as `x * 70 / 100` -- mwcc emits mul #0x46 then the 0x51eb851f magic with asr #5
 * (that shift is /100). Hand-folding it would change behaviour: the x*70 intermediate can overflow.
 * The +0x60 update uses the BITFIELD form because the ROM has the `lsl #0x10 ; lsr #0x10` trunc
 * pair -- see the discriminator table in codegen-cracks.md. */

#include "game/engine.h"

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

extern void ScaleVec3Fx12(int speed, void *a, void *b);
extern void Ov221_ProjectileTick(int self, int a, int b);

void Ov221_Projectile_FlightTick(int self) {
    int *ctx;
    int speed;
    int idle;

    ctx = *(int **)(self + 4);
    ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x80;

    if (ctx[0x18] == 0) {
        ScaleVec3Fx12(ctx[0x12], (char *)ctx + 0x24, (char *)ctx + 0x18);
        if (ctx[0x11] > 0x3400) {
            ctx[0x12] = ctx[0x12] * 70 / 100;
            ctx[0x18] = 1;
        }
    } else {
        speed = ctx[0x12];
        ctx[6] = 0;
        ctx[7] = 0;
        ctx[8] = speed;
        Vec3TransformViaTempMtx((char *)ctx + 0x18, (char *)ctx + 0x30, (char *)ctx + 0x18);
    }

    idle = ctx[0x17] == 0 ? 1 : 0;
    Ov221_ProjectileTick(self, idle, idle);
}
