/* Swap which of the ov259 rig's two shells is shown: `open` scales the +0x388 shell to 1.0 and
 * hides the +0x384 one, otherwise the reverse (0203ca9c on each transform). */
extern void Srt_SetScaleUniform(int srt, int scale);

void Ov259_SwapShells(char *self, int open)
{
    if (open) {
        Srt_SetScaleUniform(*(int *)(self + 0x388) + 4, 0x1000);
        Srt_SetScaleUniform(*(int *)(self + 0x384) + 4, 0);
    } else {
        Srt_SetScaleUniform(*(int *)(self + 0x388) + 4, 0);
        Srt_SetScaleUniform(*(int *)(self + 0x384) + 4, 0x1000);
    }
}
