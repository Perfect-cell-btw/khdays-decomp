/*
 * Ov209_SetTargetOrient -- x3 (ov208/209/268). Set the target position and orient toward it.
 * Store the incoming vec3 into self[6..8], build the look-at matrix at self[0xc..] via
 * 0202ed60(self+0xc, &data_02042258, &v), then raise the "aim dirty" flag *(*self+0x1c7)=1.
 */
struct vec3 { int x, y, z; };
extern void Quat_FromTwoVectors(unsigned int *out, void *basis, struct vec3 *v);
extern int data_02042258;

void Ov209_SetTargetOrient(int *self, struct vec3 v) {
    *(struct vec3 *)(self + 6) = v;
    Quat_FromTwoVectors((unsigned int *)(self + 0xc), &data_02042258, &v);
    *(unsigned char *)(*self + 0x1c7) = 1;
}
