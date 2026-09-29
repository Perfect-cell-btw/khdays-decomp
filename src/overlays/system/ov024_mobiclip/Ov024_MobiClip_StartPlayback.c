/* MobiClip: start playback of up to three streams on one screen pair.
 *
 * Records which of the first two streams are present, picks the layer base --
 * layers 0-2 when the first stream is given, 4-6 otherwise -- builds the
 * eleven-entry parameter block the header reader fills in, then clears both
 * tilemap layers to it, enables the decoder and the two display hooks, and
 * finally opens the streams. Only a successful open raises the playing bit.
 */

#include "nitro/types.h"

struct MobiClipOpenRequest {
    const char *pszStream0;
    const char *pszStream1;
    const char *pszStream2;
    void *pfnFrameReady;
};

extern int data_ov024_02093a20;
extern void Ov024_MobiClip_PlayerTick(void);
extern void Ov024_MobiClip_OpenStreamFromHeader(void *pDecoder, int nLayer, void *pHeader, u16 *aParams);
extern u16 *GetBGScreenBaseForLayer(int nLayer);
extern void Tilemap_FillRect(u16 *pScreen, int nWidth, int nHeight, int nLeft,
                          int nTop, int nStride, int nPalette, int nTile);
extern void Ov024_TileTextRenderer_SetReady(void *pDecoder, int bEnable);
extern void MsgQueue_SetMoviePlaying(int bOn);
extern void Session_SetMoviePlaying(int bOn);
extern int Ov024_MobiClip_OpenStreams(struct MobiClipOpenRequest *pRequest);

void Ov024_MobiClip_StartPlayback(const char *pszStream0, const char *pszStream1,
                         const char *pszStream2)
{
    struct MobiClipOpenRequest req;
    u16 aParams[11];
    char *player;
    int nLayer;

    req.pfnFrameReady = (void *)&Ov024_MobiClip_PlayerTick;
    player = ((char **)&data_ov024_02093a20)[1];
    req.pszStream0 = pszStream0;
    req.pszStream1 = pszStream1;
    req.pszStream2 = pszStream2;
    if (pszStream0 != 0) {
        *(int *)(player + 0x8bd8) = 1;
    }
    if (pszStream1 != 0) {
        *(int *)(player + 0x8bdc) = 1;
    }
    nLayer = pszStream0 != 0 ? 0 : 4;

    aParams[0] = 0;
    aParams[1] = 0x14;
    aParams[2] = 0x20;
    aParams[3] = 2;
    aParams[4] = 1;
    aParams[5] = 0xd;
    aParams[6] = 0;
    aParams[7] = 0;
    aParams[8] = 0;
    aParams[9] = 3;
    aParams[10] = 0;

    Ov024_MobiClip_OpenStreamFromHeader(player + 0x8b4c, nLayer, player + 0x8b40, aParams);
    Tilemap_FillRect(GetBGScreenBaseForLayer(nLayer + 1), aParams[2], aParams[3], aParams[0],
                  aParams[1], 0x20, aParams[4], 0xe);
    Tilemap_FillRect(GetBGScreenBaseForLayer(nLayer + 2), aParams[2], aParams[3], aParams[0],
                  aParams[1], 0x20, aParams[4], 0xe);
    Ov024_TileTextRenderer_SetReady(player + 0x8b4c, 1);
    MsgQueue_SetMoviePlaying(1);
    Session_SetMoviePlaying(1);
    if (Ov024_MobiClip_OpenStreams(&req) == 0) {
        *(u16 *)(player + 2) |= 2;
    }
}
