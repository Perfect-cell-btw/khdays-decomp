/* Ov202_InitModelPose: ported from a matched sibling family (same shape, constants and offsets adjusted). */
extern int Ov107_AiState_DispatchModelCallbacks();
extern int *Ov107_GetActorManager();
extern void ScaleVec3Fx12();
extern void VEC_Add();
extern void Srt_SetTranslation();

typedef struct {
    int data[11];
} Mat;

typedef struct {
    char pad0[0x3d4];
    char *src;
    char padsrc[0xc];
    Mat mat;
    char pad[28];
} Obj;

void Ov202_InitModelPose(Obj *obj, int flag) {
    int tmp[3];

    Ov107_AiState_DispatchModelCallbacks(obj, flag);

    obj->mat = *(Mat *)(obj->src + 4);

    ScaleVec3Fx12(-0x400, *Ov107_GetActorManager() + 0x7c, tmp);
    VEC_Add((char *)&obj->mat + 16, tmp, tmp);
    Srt_SetTranslation(&obj->mat, tmp);
}
