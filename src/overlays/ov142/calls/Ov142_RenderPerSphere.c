extern int SrtTransform_SetIdentity();
extern int Srt_SetScaleUniform();
extern int Srt_SetTranslation();
extern int Obj_RenderModel();

void Ov142_RenderPerSphere(char *r7, int r6) {
    int *r4;
    int i;
    int *p;

    r4 = *(int **)(r7 + 0x84);
    SrtTransform_SetIdentity(r7 + 0x30);
    for (i = 0; i < 0x10; i++) {
        p = (int *)r4[i + 2];
        if (p == 0) {
            return;
        }
        Srt_SetScaleUniform(r7 + 0x30, p[0x20] << 1);
        Srt_SetTranslation(r7 + 0x30, (char *)r4[i + 2] + 0x74);
        Obj_RenderModel(r7, r6);
    }
}
