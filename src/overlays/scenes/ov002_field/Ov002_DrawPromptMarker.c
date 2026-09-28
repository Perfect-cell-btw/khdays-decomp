
#include "nitro/types.h"

typedef struct Ov002SceneContext {
    int aHandles[4];
    u8 gap10[0x18];
    u8 bStateFlags;
} Ov002SceneContext;

extern Ov002SceneContext *data_ov002_0207f618;
extern u8 data_ov002_0207e9c4;

extern void Ov002_BlitNibbleRun(int nHandle, int nRight, int nCount,
                                int nWidth, int nPad, int nRow,
                                const u8 *pSource);

/* Draw the fixed six-pixel prompt marker and dirty the panel state. */
void Ov002_DrawPromptMarker(unsigned int nRight)
{
    Ov002SceneContext *pContext = data_ov002_0207f618;

    if (nRight >= 0x4d) {
        nRight = 0x4c;
    }
    Ov002_BlitNibbleRun(pContext->aHandles[0], nRight, 6, 0x4d, 1, 0,
                        &data_ov002_0207e9c4);
    pContext->bStateFlags |= 8;
}
