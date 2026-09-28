/* +0xf8 and +0x114 are 0x1c apart, i.e. two adjacent descriptors of the size
 * Tween_Configure initialises -- an array of two, not two unrelated fields. */
typedef struct {
    char pad00[0x1c];
} Ov002Fader;

typedef struct {
    char pad00[0xf8];
    Ov002Fader fade[2];   /* +0xf8, +0x114 */
} Ov002Ctx;

extern void Ov002_PushMapSnapshot(int a);
extern int Ov002_ForwardToSubDc(int a);
extern void Ov002_Ctx_InvokeTagTrackerCallback(void);
extern void Tween_Configure(void *p, int a1, int a2, int a3, int a4);
extern void Tween_Start(void *p);
extern void Ov002_SelectEntryByKey(int a);

extern Ov002Ctx *data_ov002_0207f614;

void Ov002_ResetFaders(void) {
    Ov002Ctx *c = data_ov002_0207f614;

    Ov002_PushMapSnapshot(0);
    Ov002_ForwardToSubDc(0x50);
    Ov002_Ctx_InvokeTagTrackerCallback();
    Tween_Configure(&c->fade[0], 2, 0x18000, 0, 300);
    Tween_Configure(&c->fade[1], 0, 0, 0, 0);
    Tween_Start(&c->fade[0]);
    Tween_Start(&c->fade[1]);
    Ov002_SelectEntryByKey(0);
}
