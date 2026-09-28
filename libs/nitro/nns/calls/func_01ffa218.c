

#include "nitro/types.h"
#include "nitro/fx.h"

typedef struct NNSG3dJntAnmResult {
    u32 flag;
    VecFx32 scale;
    VecFx32 scaleEx0;
    VecFx32 scaleEx1;
    MtxFx43 mtx;
} NNSG3dJntAnmResult;

enum {
    JNT_SCALE_ONE = 0x01,
    JNT_ROT_ZERO = 0x02,
    JNT_TRANS_ZERO = 0x04,
    JNT_SCALEEX0_ONE = 0x08,
    JNT_MAYA_SSC = 0x20
};

extern void GX_SendFifoWords(u32 op, const void *args, u32 numWords);

void func_01ffa218(const NNSG3dJntAnmResult *result)
{
    BOOL sendTranslation = 0;
    u32 flag = result->flag;

    if (!(flag & JNT_TRANS_ZERO)) {
        sendTranslation = 1;
    }

    if ((flag & JNT_MAYA_SSC) && !(flag & JNT_SCALEEX0_ONE)) {
        if (sendTranslation) {
            GX_SendFifoWords(0x1c, &result->mtx._30, 3);
            sendTranslation = 0;
        }
        GX_SendFifoWords(0x1b, &result->scaleEx0, 3);
    }

    if (!(result->flag & JNT_ROT_ZERO)) {
        if (sendTranslation) {
            GX_SendFifoWords(0x19, &result->mtx, 12);
        } else {
            GX_SendFifoWords(0x1a, &result->mtx, 9);
        }
    } else if (sendTranslation) {
        GX_SendFifoWords(0x1c, &result->mtx._30, 3);
    }

    if (result->flag & JNT_SCALE_ONE) {
        return;
    }
    GX_SendFifoWords(0x1b, &result->scale, 3);
}
