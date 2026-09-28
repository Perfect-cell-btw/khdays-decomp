typedef unsigned char u8;

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
extern void Ov012_MobiClip_UpdateStreamLead(MobiClipStream *pStream);

int Ov012_MobiClip_StreamAdvance(MobiClipStream *pStream) {
    int nPosition;
    int nStep;

    nStep = pStream->nBaseStep + MobiClip_GetStreamStepDelta(pStream);
    nPosition = (pStream->nWindowPosition += nStep);
    if (nPosition + nStep - pStream->nBaseStep > pStream->nStepLimit) {
        pStream->nWindowPosition -= nStep;
        TextWindow_ScrollUp(pStream, nStep);
    }
    Ov012_MobiClip_UpdateStreamLead(pStream);
    return 1;
}