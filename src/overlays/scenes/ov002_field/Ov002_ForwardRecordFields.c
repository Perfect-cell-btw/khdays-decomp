/*
 * Ov002_ForwardRecordFields - look up a record and forward two of its fields to a handler (ARM).
 *
 * Resolves param_2 to a record via Ov002_GetRootField8d14, then calls Ov002_SpawnSpot with the
 * record's signed halfword at +0x42 and unsigned halfword at +0x40 in place of param_2, keeping the
 * other arguments (param_1, param_3, param_4, and the byte args param_5/param_6) unchanged.
 */
typedef struct {
    char _0[0x40];
    unsigned short f40;   /* +0x40 */
    short f42;            /* +0x42 */
} Ov002Record;

extern int Ov002_GetRootField8d14(int key);
extern void Ov002_SpawnSpot(int a, int b, int c, int d, int e, int f, int g);

void Ov002_ForwardRecordFields(int param_1, int param_2, int param_3, int param_4,
                         signed char param_5, unsigned char param_6)
{
    Ov002Record *r = (Ov002Record *)Ov002_GetRootField8d14(param_2);
    Ov002_SpawnSpot(param_1, r->f42, r->f40, param_3, param_4, param_5, param_6);
}
