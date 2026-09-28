/* Homing shot step: advances the shot toward its target, resolves hits, and once it has flown too
 * far or too long, or has hit, bursts it (spawn effect, triple spread, local rumble), marks it
 * finished and releases its rig slots. */

struct vec3 { int x, y, z; };
struct bits1 { unsigned char b0 : 1; };

extern void Ov022_ComputeShotStep(struct vec3 *out, void *a, int b, int c);
extern void Ov022_ResolveShotHit(void *a, int b, struct vec3 *c, struct vec3 *d);
extern void VEC_Add(struct vec3 *a, struct vec3 *b, struct vec3 *c);
extern void func_ov022_02091540(int a, int b);
extern int VEC_Distance(int a, struct vec3 *b);
extern void Ov022_MarshalStateByte9(void *a, int b);
extern void Slot_Spawn(int a, int b, struct vec3 *c, int d);
extern void Ov088_emitTripleSpreadShots(struct vec3 *a, struct vec3 *b);
extern int Session_GetLocalPlayerIndex(void);
extern void Ov022_ReleaseRigSlots(int a, int b);

int Ov088_HomingApproachTriggerStep(void *param_1, int param_2, int param_3) {
    struct vec3 s;
    struct vec3 out;
    int *puVar4 = *(int **)((char *)param_1 + 8);
    int *iVar5 = *(int **)(param_2 + 0x138);

    s = *(struct vec3 *)(param_2 + 0xcc);
    Ov022_ComputeShotStep(&out, param_1, param_2, param_3);
    Ov022_ResolveShotHit(param_1, param_2, &s, &out);
    VEC_Add(&s, &out, &s);
    *(struct vec3 *)(param_2 + 0xcc) = s;
    func_ov022_02091540(param_2 + 0x28, param_3);
    if (*(char *)(param_2 + 2) != 3) {
        if (VEC_Distance(param_2 + 0x10, &s) > iVar5[5]) {
            *(char *)(param_2 + 2) = 4;
        }
    }
    Ov022_MarshalStateByte9(param_1, param_2);
    if (*(unsigned char *)param_2 & 1) {
        if (*(int *)(param_2 + 4) >= iVar5[6]) {
            *(char *)(param_2 + 2) = 4;
        }
    }
    if (*(char *)(param_2 + 2) != 2) {
        int i;
        if (*(int *)param_1 == 1) {
            if (((struct bits1 *)((char *)puVar4 + 0x694))->b0) {
                Slot_Spawn(0xcb, 1, &s, 0);
            }
            Ov088_emitTripleSpreadShots(&s, &out);
            if (Session_GetLocalPlayerIndex() == 0 && (*puVar4 & 0x10000) == 0) {
                *(unsigned char *)((char *)puVar4 + 0x47a) = 3;
                *(unsigned char *)((char *)puVar4 + 0x47b) = 1;
            }
        }
        *(char *)(param_2 + 2) = 4;
        *(int *)(param_2 + 4) = 0x3000;
        for (i = 0; i < 8; i++) {
            ((short *)param_2)[i + 0x9e] = -1;
        }
        Ov022_ReleaseRigSlots(param_2, iVar5[0xf]);
    }
    return 0;
}
