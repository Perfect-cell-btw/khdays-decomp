/* Ov024_MobiClip_ReleaseAudioChannel -- MobiClip player: silence and release the video's audio channel.
 * Mutes channel 3, waits for the sound command queue to drain around stopping the timer, then
 * unlocks the channel and waits again. */
extern void SND_SetChannelVolume(int ch, int a, int b);
extern unsigned int SND_GetCurrentCommandTag(void);
extern void SND_FlushCommand(int a);
extern void SND_WaitForCommandProc(unsigned int tag);
extern void SND_StopTimer(int ch, int a, int b, int c);
extern void SND_UnlockChannel(int ch, int a);

void Ov024_MobiClip_ReleaseAudioChannel(void) {
    unsigned int tag;

    SND_SetChannelVolume(3, 0, 0);
    tag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(tag);
    SND_StopTimer(3, 0, 0, 0);
    SND_UnlockChannel(3, 0);
    SND_FlushCommand(1);
}
