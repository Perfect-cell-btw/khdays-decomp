/* NitroSystem g3d anm.c: the animation-object init dispatch table NNS_G3dInitAnmObj (02014abc)
 * searches by the animation resource's category bytes -- 'M' 'AM' (material animation),
 * 'M' 'PT' (texture pattern), 'M' 'AT' (texture SRT), 'V' 'AV' (visibility), 'J' 'AC' (joint) --
 * with room for five user-registered entries (the count in use, data_02042490, sits apart).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*NNSG3dAnimInitFunc)(void *pAnmObj, void *pResAnm, const void *pResMdl);

typedef struct NNSG3dAnmObjInitFunc {
    u8 category0;
    u8 dummy;
    u16 category1;
    NNSG3dAnimInitFunc func;
} NNSG3dAnmObjInitFunc;

#define NNS_G3D_ANMOBJ_INITFUNC_MAX 10
#define CATEGORY1(a, b) ((u16)((a) | ((b) << 8)))

extern void AnmObj_InitMatTable(void *, void *, const void *);   /* NNSi_G3dAnmObjInitNsBma */
extern void NNSi_G3dAnmObjInitNsBtp(void *, void *, const void *);   /* NNSi_G3dAnmObjInitNsBtp */
extern void AnmObj_InitVisTable(void *, void *, const void *);   /* NNSi_G3dAnmObjInitNsBta */
extern void NNSi_G3dAnmObjInitNsBva(void *, void *, const void *);   /* NNSi_G3dAnmObjInitNsBva */
extern void NNSi_G3dAnmObjInitNsBca(void *, void *, const void *);   /* NNSi_G3dAnmObjInitNsBca */

/* NNSi_G3dAnmObjInitFuncArray */
NNSG3dAnmObjInitFunc data_020424b4[NNS_G3D_ANMOBJ_INITFUNC_MAX] = {
    { 'M', 0, CATEGORY1('A', 'M'), AnmObj_InitMatTable },
    { 'M', 0, CATEGORY1('P', 'T'), NNSi_G3dAnmObjInitNsBtp },
    { 'M', 0, CATEGORY1('A', 'T'), AnmObj_InitVisTable },
    { 'V', 0, CATEGORY1('A', 'V'), NNSi_G3dAnmObjInitNsBva },
    { 'J', 0, CATEGORY1('A', 'C'), NNSi_G3dAnmObjInitNsBca },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
};
