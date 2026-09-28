/* Construction of the ov280 enemy's item: installs the handlers (+8
 * 020d2ef0, +0x30 020d2f44, +0x1d0 020d2f0c), raises flags 0x42 in the +0x60 high byte and bit 2
 * of +0x1ae, scales the +0x70 size to 0.58 of the +0x388 owner's and clears +0x54/+0x58. The
 * +0x384 sub-item is built from pose 0x14 of the owner, the +0xa0 pose is scaled by 1.3, the
 * sub-item is subscribed to +0x9c, uniformly scaled by 0x2908/0x1119, its channels 0 and 2 are
 * enabled and it is reset. */
typedef unsigned short u16;

#define FX_MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

extern int FX_Div(int num, int den);
extern int Ov107_PackTextureHandle(int pool, int kind);
extern int CreateSubitemInstance0xB4(int res);
extern void Srt_SetScaleUniform(void *srt, int weight);
extern void RegisterSubscriberSlot(int list, int obj);
extern void Srt_SetScaleXYZ(void *scale, int x, int y, int z);
extern void SetSubitemState(int obj, int channel, int a, int b);
extern void RefreshObjectCallbacks(int obj, int v);
extern void Ov280_OnDespawn(void);
extern void Ov280_CreateAiTask_2(void);
extern void Ov280_SetField1cIfFlags1And10(void);

void Ov280_ItemConstruct(char *self)
{
    int owner = *(int *)(self + 0x388);
    int w = FX_Div(0x2908, 0x1119);
    u16 v;

    *(void **)(self + 8) = (void *)Ov280_OnDespawn;
    *(void **)(self + 0x30) = (void *)Ov280_CreateAiTask_2;
    *(void **)(self + 0x1d0) = (void *)Ov280_SetField1cIfFlags1And10;
    v = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (u16)((v & ~0xff00) | (((((unsigned int)v << 0x10) >> 0x18 | 0x42) << 0x18) >> 0x10));
    *(u16 *)(self + 0x1ae) |= 4;
    *(int *)(self + 0x70) = FX_MUL(*(int *)(*(int *)(self + 0x388) + 0x70), 0x943);
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, 0x14));
    Srt_SetScaleUniform(self + 0xa0, 0x14cd);
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    Srt_SetScaleXYZ((void *)(*(int *)(self + 0x384) + 4), w, w, w);
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}
