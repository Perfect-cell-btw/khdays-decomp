/* Ov023_Dual3DUpdate -- Ov023_Dual3DUpdate: the "dual3d_update" task of the event scene,
 * run once per frame while the scene renders 3D on both screens.  Picks the dual-3D mode
 * (+0x87594): 0x1f when the active screen (+0x87590) has a model (+0x875d8 + 4 * screen), 1
 * otherwise; applies the fades (Ov023_ApplyFades 02083700) and the mode to the dual-3D block
 * (+0x87554, 0202ea14), then asks the block which screen it will draw next (0202e9b8): when
 * that is still the active one the scene flips the active screen and applies the fades again.
 * With the top screen active, no pending sound-frame (020208e0), in a client session (bit 1
 * of data_0204c240) and an idle lobby (data_0204c254 + 0xe), the display mode is re-entered
 * (Ov023_EnterDisplayMode 020839b8) and mode bit 4 set.  Finally the block's screen
 * becomes the active one and is published in data_0204be04. */

#include "nitro/types.h"

typedef struct Ov023Scene {
    u8   pad_00000[0x87554];
    u8   dual3d[0x87590 - 0x87554]; /* 0x87554: the dual-3D block */
    int  nActiveScreen;       /* 0x87590 */
    int  nDual3DMode;         /* 0x87594 */
    u8   pad_87598[0x875d8 - 0x87598];
    int  aModel[2];           /* 0x875d8: the model shown on each screen */
} Ov023Scene;

typedef struct Ov023SceneRoot {
    int  nField00;            /* 0x00 */
    Ov023Scene *pScene;       /* 0x04 */
} Ov023SceneRoot;

typedef struct Ov023Lobby {
    u8   pad_00[0xe];
    u16  nState;              /* 0x0e */
} Ov023Lobby;

extern void Ov023_ApplyFades(void);                              /* Ov023_ApplyFades */
extern void Obj_SetWord8(void *pCamera, int nMode);
extern char Gfx_ToggleCaptureMode(void *pDual3D);                           /* Dual3D_NextScreen */
extern int  func_020208e0(void);
extern void Ov023_EnterDisplayMode(void);                              /* Ov023_EnterDisplayMode */
extern Ov023SceneRoot data_ov023_0208a784;
extern u8   data_0204c240;                                          /* session bits */
extern Ov023Lobby data_0204c254;
extern u8   data_0204be04;                                          /* the active screen, published */

void Ov023_Dual3DUpdate(void)
{
    Ov023Scene *pScene;
    char nScreen;

    pScene = data_ov023_0208a784.pScene;
    if (pScene->aModel[pScene->nActiveScreen] != 0) {
        pScene->nDual3DMode = 0x1f;
    } else {
        pScene->nDual3DMode = 1;
    }
    Ov023_ApplyFades();
    Obj_SetWord8(data_ov023_0208a784.pScene->dual3d, data_ov023_0208a784.pScene->nDual3DMode);
    nScreen = Gfx_ToggleCaptureMode(data_ov023_0208a784.pScene->dual3d);
    if (data_ov023_0208a784.pScene->nActiveScreen == nScreen) {
        data_ov023_0208a784.pScene->nActiveScreen = data_ov023_0208a784.pScene->nActiveScreen == 0;
        Ov023_ApplyFades();
    }
    if (data_ov023_0208a784.pScene->nActiveScreen == 0 && func_020208e0() == 0 && (data_0204c240 & 2) && data_0204c254.nState == 0) {
        Ov023_EnterDisplayMode();
        data_ov023_0208a784.pScene->nDual3DMode |= 0x10;
    }
    data_ov023_0208a784.pScene->nActiveScreen = nScreen;
    data_0204be04 = data_ov023_0208a784.pScene->nActiveScreen;
}
