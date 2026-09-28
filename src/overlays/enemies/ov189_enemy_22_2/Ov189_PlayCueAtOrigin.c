/* State step: posts a pose, plays an effect cue at the actor's origin and installs the next step.
 */

extern void Ov107_PostTagUpdate(int a, int b, int c);
typedef struct { int x, y, z; } Vec3;
extern void func_ov107_020c0b90(int a, int b, Vec3 v, int d);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov189_PoseClearFields18ThenAdvance(void);
extern Vec3 data_02041dc8;

void Ov189_PlayCueAtOrigin(int self) {
    int *s = *(int **)(self + 4);
    Ov107_PostTagUpdate(s[0], 0xb, 0);
    func_ov107_020c0b90(s[0], 5, data_02041dc8, 0);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)&Ov189_PoseClearFields18ThenAdvance);
}
