/* Closes the MobiClip container; returns the argument. */

extern void Ov024_MobiClip_CloseContainer(void);

int Ov024_MobiClip_DecoderFreeBuffers_2(int a)
{
    Ov024_MobiClip_CloseContainer();
    return a;
}
