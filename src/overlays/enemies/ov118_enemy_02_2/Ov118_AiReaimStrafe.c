/* Ov118_AiReaimStrafe -- AI state: re-aim and re-arm the strafe step.
 *
 * The Q12 scale of the step (w38 * 0x6488, rounded with +0x800) is brought back down with a
 * 64-bit LOGICAL SHIFT, not a division: `/ 4096` on a signed long long makes mwcc call the
 * 64-bit divide helper, while `(unsigned long long)x >> 12` is the ROM's inline
 * `lsr r2,r2,#0xc ; orr r2,r2,r3,lsl #20`. Worth 12 bytes and three instructions.
 * Byte-identical twin of Ov117_AiReaimStrafe. */

#include "game/actor.h"
#include "game/ai_task.h"
#include "game/engine.h"

extern int ScaleVec3Fx12();
extern int Srt_SetRotationQuat();
extern int SetIndexedSlot();

extern int data_020420f8;
extern int data_02042258;
extern int data_02042270;

struct Sub {
    Actor *inner;              /* 0x00 */
    char pad4[0x2c - 0x4];
    int w2c;                   /* 0x2c */
};

struct Mid {
    Actor *inner;              /* 0x00 */
    char pad4[8 - 4];
    char buf8[0x2c - 8];       /* 0x08 */
    char buf2c[0x38 - 0x2c];   /* 0x2c */
    int w38;                   /* 0x38 */
    char pad3c[0x40 - 0x3c];
    int w40;                   /* 0x40 */
};

struct Obj {
    AI_TASK_FIELDS(struct Mid)
};

void Ov118_AiReaimStrafe(struct Obj *o)
{
    struct Mid *m;
    char local[16];

    m = o->pState;

    Vec3TransformViaTempMtx(m->buf2c, m->buf8, &data_02042258);
    ScaleVec3Fx12(0x100, m->buf2c, m->buf2c);

    QuatFromAxisAngle(local, &data_02042270,
                  (int)((unsigned long long)((long long)m->w38 * 0x6488 + 0x800) >> 12));

    m->w38 = m->w38 + ((struct Sub *)o->pList)->w2c;
    Srt_SetRotationQuat(((int)m->inner->pSubitem) + 4, local);

    if (m->w38 < 0x1000)
        return;

    {
        int lo = m->inner->field_224;
        int hi = m->inner->field_228;
        int d = hi - lo;
        if (d < 0) d = -d;
        m->w40 = lo + RandNextScaled(d + 1);
    }

    Srt_SetRotationQuat(((int)m->inner->pSubitem) + 4, &data_020420f8);
    m->inner->nextState = 2;
    SetIndexedSlot(o, o->slot, 0);
}
