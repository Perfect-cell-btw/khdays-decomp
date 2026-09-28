/* G3dRes_DefaultSetup -- the game's NNS_G3dResDefaultSetup, MAIN. Model and texture files get their
 * texture/4x4/palette VRAM from the GFD allocator hooks (NNS_GfdAllocTexVram & co.) -- unless the
 * loader's texture flag (data_020427f0, InstallHandlerPairByFlag) is off -- and are uploaded with the game's
 * own loaders (Tex_LoadVram / Gfx_UploadBlock); a model file then binds its model set to the
 * textures. Any failed allocation frees all three keys and fails. Animation files need nothing;
 * unknown signatures fail. */
#include "nitro/types.h"
typedef u32 NNSG3dTexKey;
typedef u32 NNSG3dPlttKey;

#define NNS_G3D_SIGNATURE_NSBMD 0x30444d42   /* 'BMD0' */
#define NNS_G3D_SIGNATURE_NSBTX 0x30585442   /* 'BTX0' */
#define NNS_G3D_SIGNATURE_NSBCA 0x30414342   /* 'BCA0' */
#define NNS_G3D_SIGNATURE_NSBVA 0x30415642   /* 'BVA0' */
#define NNS_G3D_SIGNATURE_NSBMA 0x30414d42   /* 'BMA0' */
#define NNS_G3D_SIGNATURE_NSBTP 0x30505442   /* 'BTP0' */
#define NNS_G3D_SIGNATURE_NSBTA 0x30415442   /* 'BTA0' */
#define NNS_G3D_RESPLTT_USEPLTT4 0x8000
#define NNS_GFD_ALLOC_ERROR_TEXKEY  0
#define NNS_GFD_ALLOC_ERROR_PLTTKEY 0

typedef struct NNSG3dResTex {
    char pad00[0x20];
    u16 tex4x4Flag;                     /* +0x20 */
} NNSG3dResTex;

typedef NNSG3dTexKey (*NNSGfdTexVramAllocFunc)(u32 szByte, BOOL is4x4comp, u32 opt);
typedef NNSG3dPlttKey (*NNSGfdPlttVramAllocFunc)(u32 szByte, BOOL b4Pltt, u32 bAllocFromLo);
typedef int (*NNSGfdTexVramFreeFunc)(NNSG3dTexKey key);
typedef int (*NNSGfdPlttVramFreeFunc)(NNSG3dPlttKey key);

extern NNSGfdTexVramAllocFunc data_020423ec;    /* NNS_GfdDefaultFuncAllocTexVram */
extern NNSGfdTexVramFreeFunc data_020423f0;     /* NNS_GfdDefaultFuncFreeTexVram */
extern NNSGfdPlttVramAllocFunc data_020423f4;   /* NNS_GfdDefaultFuncAllocPlttVram */
extern NNSGfdPlttVramFreeFunc data_020423f8;    /* NNS_GfdDefaultFuncFreePlttVram */
extern BOOL data_020427f0;                      /* texture setup enabled */

#define NNS_GfdAllocTexVram(sz, is4x4, opt)  (*data_020423ec)(sz, is4x4, opt)
#define NNS_GfdFreeTexVram(key)              (*data_020423f0)(key)
#define NNS_GfdAllocPlttVram(sz, b4, opt)    (*data_020423f4)(sz, b4, opt)
#define NNS_GfdFreePlttVram(key)             (*data_020423f8)(key)

extern NNSG3dResTex *NNS_G3dGetTex(void *file);                     /* NNS_G3dGetTex */
extern u32 NNS_G3dTexGetRequiredSize(const NNSG3dResTex *tex);                  /* NNS_G3dTexGetRequiredSize */
extern u32 NNS_G3dTex4x4GetRequiredSize(const NNSG3dResTex *tex);                  /* NNS_G3dTex4x4GetRequiredSize */
extern u32 NNS_G3dPlttGetRequiredSize(const NNSG3dResTex *tex);                  /* NNS_G3dPlttGetRequiredSize */
extern void NNS_G3dTexSetTexKey(NNSG3dResTex *tex, NNSG3dTexKey key, NNSG3dTexKey key4x4);   /* NNS_G3dTexSetTexKey */
extern void NNSG2d_SetOamManExDrawOrderType(NNSG3dResTex *tex, NNSG3dPlttKey key);    /* NNS_G3dPlttSetPlttKey */
extern void Tex_LoadVram(NNSG3dResTex *tex);                       /* texture upload */
extern void Gfx_UploadBlock(NNSG3dResTex *tex);                       /* palette upload */
extern void *NNS_G3dGetMdlSet(void *file);                             /* NNS_G3dGetMdlSet */
extern BOOL NNS_G3dBindMdlSet(void *mdlSet, NNSG3dResTex *tex);         /* NNS_G3dBindMdlSet */

BOOL G3dRes_DefaultSetup(void *pResData)
{
    u8 *binFile = (u8 *)pResData;

    switch (*(u32 *)&binFile[0]) {
    case NNS_G3D_SIGNATURE_NSBTX:
    case NNS_G3D_SIGNATURE_NSBMD:
        if (data_020427f0) {
            NNSG3dResTex *tex;
            u32 szTex, szTex4x4, szPltt;
            BOOL sucTex = 1;
            BOOL sucTex4x4 = 1;
            BOOL sucPltt = 1;
            NNSG3dTexKey keyTex;
            NNSG3dTexKey keyTex4x4;
            NNSG3dPlttKey keyPltt;

            tex = NNS_G3dGetTex(pResData);
            if (tex) {
                szTex = NNS_G3dTexGetRequiredSize(tex);
                szTex4x4 = NNS_G3dTex4x4GetRequiredSize(tex);
                szPltt = NNS_G3dPlttGetRequiredSize(tex);

                if (szTex > 0) {
                    keyTex = NNS_GfdAllocTexVram(szTex, 0, 0);
                    if (keyTex == NNS_GFD_ALLOC_ERROR_TEXKEY) {
                        sucTex = 0;
                    }
                } else {
                    keyTex = 0;
                }

                if (szTex4x4 > 0) {
                    keyTex4x4 = NNS_GfdAllocTexVram(szTex4x4, 1, 0);
                    if (keyTex4x4 == NNS_GFD_ALLOC_ERROR_TEXKEY) {
                        sucTex4x4 = 0;
                    }
                } else {
                    keyTex4x4 = 0;
                }

                if (szPltt > 0) {
                    keyPltt = NNS_GfdAllocPlttVram(szPltt, tex->tex4x4Flag & NNS_G3D_RESPLTT_USEPLTT4, 0);
                    if (keyPltt == NNS_GFD_ALLOC_ERROR_PLTTKEY) {
                        sucPltt = 0;
                    }
                } else {
                    keyPltt = 0;
                }

                if (!sucTex || !sucTex4x4 || !sucPltt) {
                    NNS_GfdFreePlttVram(keyPltt);
                    NNS_GfdFreeTexVram(keyTex4x4);
                    NNS_GfdFreeTexVram(keyTex);
                    return 0;
                }

                NNS_G3dTexSetTexKey(tex, keyTex, keyTex4x4);
                NNSG2d_SetOamManExDrawOrderType(tex, keyPltt);
                Tex_LoadVram(tex);
                Gfx_UploadBlock(tex);
            }

            if (*(u32 *)&binFile[0] == NNS_G3D_SIGNATURE_NSBMD) {
                void *mdlSet = NNS_G3dGetMdlSet(pResData);

                if (tex) {
                    NNS_G3dBindMdlSet(mdlSet, tex);
                }
            }
        }
        return 1;
    case NNS_G3D_SIGNATURE_NSBCA:
    case NNS_G3D_SIGNATURE_NSBVA:
    case NNS_G3D_SIGNATURE_NSBMA:
    case NNS_G3D_SIGNATURE_NSBTP:
    case NNS_G3D_SIGNATURE_NSBTA:
        return 1;
    default:
        return 0;
    }
}
