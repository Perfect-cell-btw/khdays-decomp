/* Facing update: when a heading word is supplied, rebuild the actor's +0xa0 orientation about
 * world Y from it scaled by pi/180 (x 0x3244 / 180). */
typedef struct { int x, y, z; } Vec3;
extern void Srt_SetRotationAxisAngle(void *quat, const Vec3 *axis, int angle);
extern const Vec3 data_02042264;

void Ov277_SetHeadingDegrees(char *actor, int unused, int *pHeading) {
    if (pHeading == 0) return;
    Srt_SetRotationAxisAngle(actor + 0xa0, &data_02042264, *pHeading * 0x3244 / 180);
}
