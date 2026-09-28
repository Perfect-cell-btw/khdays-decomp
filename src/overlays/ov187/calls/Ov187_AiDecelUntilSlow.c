extern int ScaleVec3Fx12();
extern int RandNextScaled();
extern int SetIndexedSlot();

typedef struct { int a, b, c; } Vec3;

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Bits60;

typedef struct {
    unsigned char b0 : 1;
} Bits1;

void Ov187_AiDecelUntilSlow(char *a0)
{
    char *r4 = *(char **)(a0 + 4);

    *(Vec3 *)(r4 + 0x2c) = *(Vec3 *)(r4 + 0x50);

    ScaleVec3Fx12(0xb00, r4 + 0x50, r4 + 0x50);

    if (*(int *)(r4 + 0x30) < 0x20) {
        char *r2 = *(char **)r4;
        ((Bits60 *)(r2 + 0x60))->hi &= ~0x40;
    }

    if (*(unsigned char *)(*(char **)(r4 + 0x48)) != 0)
        return;

    {
        char *r1 = *(char **)r4;
        if (((Bits1 *)(r1 + 0x17a))->b0 == 0) {
            if (((Bits1 *)(r1 + 0x17c))->b0 == 0)
                return;
        }
        *(signed char *)(r1 + 0x1c7) = 2;
    }

    {
        char *r0 = *(char **)r4;
        int r6 = *(int *)(r0 + 0x224);
        int v = *(int *)(r0 + 0x228) - r6;
        if (v < 0)
            v = -v;
        v = v + 1;
        v = RandNextScaled(v);
        *(int *)(r4 + 0x40) = r6 + v;
    }

    SetIndexedSlot(a0, *(signed char *)(a0 + 0x20), 0);
}
