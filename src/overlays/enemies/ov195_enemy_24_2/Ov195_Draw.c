/* Draw hook of the ov194 enemy (x3: ov194/195/196): refreshes the +0x3d0 sub-node, runs the
 * ov107 base draw, copies the +0x394 item's +4 placement into the actor's +0x3a4 slot and
 * scales that copy to 0x2199 (the Ov120_ReleaseAndDestroy shape with a placement mirror). */
typedef struct { int w[11]; } Placement;

extern void Ov107_RefreshAndSelectChild(int node, int arg1);
extern void Ov107_ProcessObjectTick(int *self, int arg);
extern void Srt_SetScaleUniform(Placement *placement, int scale);

void Ov195_Draw(int *self, int arg)
{
    Ov107_RefreshAndSelectChild(self[0xf4], arg);
    Ov107_ProcessObjectTick(self, arg);
    *(Placement *)(self + 0xe9) = *(Placement *)(self[0xe5] + 4);
    Srt_SetScaleUniform((Placement *)(self + 0xe9), 0x2199);
}
