/* Steps the animation cursor at +0x20 through Angle_TurnToward, resolves the resulting frame
 * out of data_02042264 into a 0x10-byte record and applies it to the sub-object at +0xa0.
 *
 * ★ The struct ladder: with the cursor written as `*(int *)(o + 0x20)` mwcc copies the call
 * result into r2 BEFORE storing it; as the struct field `o->a` it stores r0 first and then
 * copies, exactly as the ROM does. */
typedef struct {
    char pad[0x20];
    int cursor;
    int limit;
} Obj;

extern int Angle_TurnToward(int a, int b, int c, int d);
extern void QuatFromAxisAngle(void *out, void *tbl, int idx);
extern void Srt_SetRotationQuat(char *p, void *m);
extern char data_02042264[];

void Ov245_FourShape_TurnTick(int *ctx) {
    char m[0x10];
    char *self = (char *)ctx[0];
    Obj *o = (Obj *)ctx[1];
    o->cursor = Angle_TurnToward(o->cursor, o->limit, *(int *)(self + 0x2c), 0);
    QuatFromAxisAngle(m, data_02042264, o->cursor);
    Srt_SetRotationQuat(*(char **)o + 0xa0, m);
}
