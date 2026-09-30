/* Draw hook of the ov218 actor's shadow model: it copies its owner's +0x384 model transform, sinks 2.0
 * lower, is scaled to 1.3 and drawn (0203bc78). */
typedef struct { int w[11]; } SrtTransform;

extern void Srt_SetScaleUniform(void *srt, int scale);
extern int Obj_RenderModel(char *model, int arg);

void Ov218_DrawShadow(char *model, int arg)
{
    *(SrtTransform *)(model + 0x30) = *(SrtTransform *)(*(int *)(**(int **)(model + 0x84) + 0x384) + 0x30);
    *(int *)(model + 0x44) -= 0x2000;
    Srt_SetScaleUniform(model + 0x30, 0x14cd);
    Obj_RenderModel(model, arg);
}
