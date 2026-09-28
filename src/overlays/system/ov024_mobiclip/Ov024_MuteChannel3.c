/* Ov024_MuteChannel3 -- mute channel 3 and stop its stream, ov024. */
extern void SND_SetChannelVolume(int ch, int vol, int flags);
extern void SND_FlushCommand(int);
void Ov024_MuteChannel3(void) {
    SND_SetChannelVolume(3, 0x7f, 0);
    SND_FlushCommand(1);
}
