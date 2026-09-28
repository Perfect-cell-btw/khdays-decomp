/* Ov253_PlaceMounted -- place the mounted actor: its +0xa0 placement takes the +0x388 item's
 * +0x394 joint anchor, the +0x44c rotation about data_02042264 and the +0x38c offset scaled by
 * +0x398; the +0x3a0 item's animation advances (0202a818) and the actor updates (020c6980),
 * then the placement is copied into the +0x3d4 item's +0x10. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int m[11]; } Pose44;
struct Ov253Placed { char pad[0x10]; Pose44 pose; };
struct Ov253Self { char pad[0xa0]; Pose44 pose; };

extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void Srt_SetTranslation(void *srt, const Vec3 *translation);
extern void Srt_SetRotationAxisAngle(void *srt, const Vec3 *axis, int angle);
extern void Srt_SetScaleVec(void *srt, const Vec3 *offset);
extern int Sequence_UpdateTracks(void *animation, int delta);
extern void Ov107_ProcessObjectTick(int self, int delta);
extern const Vec3 data_02042264;

void Ov253_PlaceMounted(int self, int delta) {
    int item = *(int *)(self + 0x388);
    Vec3 offset;

    ScaleVec3Fx12(*(int *)(self + 0x398), (Vec3 *)(self + 0x38c), &offset);
    Srt_SetTranslation((void *)(self + 0xa0), (Vec3 *)(*(int *)(item + 0x394) + 0x14));
    Srt_SetRotationAxisAngle((void *)(self + 0xa0), &data_02042264, *(int *)(item + 0x44c));
    Srt_SetScaleVec((void *)(self + 0xa0), &offset);
    Sequence_UpdateTracks(*(void **)(*(int *)(self + 0x3a0) + 0x88), delta);
    Ov107_ProcessObjectTick(self, delta);
    ((struct Ov253Placed *)*(int *)(self + 0x3d4))->pose = ((struct Ov253Self *)self)->pose;
}
