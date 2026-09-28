/* MobiClip: advance the stream window by one frame and refill when it runs out.
 *
 * One frame costs the fixed base step plus whatever the stream's own header
 * says this frame carries. If stepping again would run past the window limit
 * the position is put back and the reader is asked for more data first.
 */
#include "nitro/types.h"

typedef struct MobiClipStream {
    u8 _pad00[0x44];
    int nStepLimit;
    u8 _pad48[0x0c];
    int nBaseStep;
    u8 _pad58[0x04];
    int nWindowPosition;
} MobiClipStream;

extern u8 MobiClip_GetStreamStepDelta(MobiClipStream *pStream);
extern void TextWindow_ScrollUp(MobiClipStream *pStream, int nStep);
extern void Ov024_MobiClip_UpdateStreamLead(MobiClipStream *pStream);

int Ov024_MobiClip_StreamAdvance(MobiClipStream *pStream) {
    int nPosition;
    int nStep;

    nStep = pStream->nBaseStep + MobiClip_GetStreamStepDelta(pStream);
    nPosition = (pStream->nWindowPosition += nStep);
    if (nPosition + nStep - pStream->nBaseStep > pStream->nStepLimit) {
        pStream->nWindowPosition -= nStep;
        TextWindow_ScrollUp(pStream, nStep);
    }
    Ov024_MobiClip_UpdateStreamLead(pStream);
    return 1;
}
