/* Draw pre-pass of the ov257 enemy (+0xc): after the common draw preparation (020c4924) the four
 * collision parts of the +0x3a4 array take the poses of the four +0x3ec rig bones (indexed as
 * ((T **)self)[0xe9 + i] / [0xfb + i] so the ROM's add base,i<<2 addressing is kept). */
typedef struct { int w[11]; } Srt;
struct Part { char pad[0x30]; Srt pose; };
struct Bone { int pad; Srt srt; };

extern void Ov107_AiState_DispatchModelCallbacks(char *self, int);

void Ov257_DrawPrePass(char *self, int flag)
{
    int i;

    Ov107_AiState_DispatchModelCallbacks(self, flag);
    for (i = 0; i < 4; i++) {
        ((struct Part **)self)[0xe9 + i]->pose = ((struct Bone **)self)[0xfb + i]->srt;
    }
}
