/* Runs the base callbacks, copies the source transform and offsets it 0.19 units toward the camera.
 */

extern int Ov107_AiState_DispatchModelCallbacks();
extern int *func_ov107_020c9848();
extern void ScaleVec3Fx12();
extern void VEC_Add();
extern void Srt_SetTranslation();

typedef struct {
    int data[11];
} Mat;

typedef struct {
    char pad0[0x390];
    char *src;
    Mat mat;
    char pad[28];
} Obj;

void Ov132_TickAndPlaceBelowCamera(Obj *obj, int flag) {
    int tmp[3];

    Ov107_AiState_DispatchModelCallbacks(obj, flag);

    obj->mat = *(Mat *)(obj->src + 4);

    ScaleVec3Fx12(-0x300, *func_ov107_020c9848() + 0x7c, tmp);
    VEC_Add((char *)&obj->mat + 16, tmp, tmp);
    Srt_SetTranslation(&obj->mat, tmp);
}
