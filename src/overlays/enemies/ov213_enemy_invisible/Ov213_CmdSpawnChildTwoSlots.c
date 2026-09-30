/* Command 5 (slots 0 and 1): spawn a child of kind 0x17 at a packed 24-bit big-endian offset,
 * then chain to the next handler.
 *
 * The command carries three signed 24-bit coordinates as raw bytes (cmd[5..7], [8..a], [b..d]).
 * Each is assembled big-endian into the top 3 bytes of a 4-byte scratch word and read back with an
 * arithmetic >>8, sign-extending the 24-bit value. The three become an SrtTransform translation
 * (identity rotation via SrtTransform_SetIdentity, then Srt_SetTranslation) and Ov107_CreateNodeXformTask spawns
 * the child under the slot's parent in the +0x394 record (slot 0: +0/+4, slot 1: +8/+0xc). Each
 * case unpacks with its own scratch words. */

typedef struct {
    int aRot[4];
    int aTranslation[3];
    int aScale[3];
    unsigned char bFlags;
    unsigned char aPad29[3];
} SrtTransform;

extern void SrtTransform_SetIdentity(int *aRot);
extern void Srt_SetTranslation(SrtTransform *srt, int *translation);
extern int Ov107_CreateNodeXformTask(int model, int parent, int kind, int arg, SrtTransform *srt);
extern void Ov107_AiState_OnMessage(int this_, int cmd, int p3);

void Ov213_CmdSpawnChildTwoSlots(int this_, int cmd, int p3) {
    SrtTransform srt;
    int pos[3];

    switch (*(unsigned char *)(cmd + 2)) {
    case 5:
        switch (*(unsigned char *)(cmd + 3)) {
        case 0: {
            int w2, w1, w0;
            SrtTransform_SetIdentity(srt.aRot);
            *((unsigned char *)&w0 + 3) = *(unsigned char *)(cmd + 5);
            *((unsigned char *)&w0 + 2) = *(unsigned char *)(cmd + 6);
            *((unsigned char *)&w0 + 1) = *(unsigned char *)(cmd + 7);
            pos[0] = w0 >> 8;
            *((unsigned char *)&w1 + 3) = *(unsigned char *)(cmd + 8);
            *((unsigned char *)&w1 + 2) = *(unsigned char *)(cmd + 9);
            *((unsigned char *)&w1 + 1) = *(unsigned char *)(cmd + 0xa);
            pos[1] = w1 >> 8;
            *((unsigned char *)&w2 + 3) = *(unsigned char *)(cmd + 0xb);
            *((unsigned char *)&w2 + 2) = *(unsigned char *)(cmd + 0xc);
            *((unsigned char *)&w2 + 1) = *(unsigned char *)(cmd + 0xd);
            pos[2] = w2 >> 8;
            Srt_SetTranslation(&srt, pos);
            *(int *)(*(int *)(this_ + 0x394) + 4) =
                Ov107_CreateNodeXformTask(*(int *)(this_ + 0x3c), *(int *)(*(int *)(this_ + 0x394)), 0x17, 0, &srt);
            break;
        }
        case 1: {
            int w2, w1, w0;
            SrtTransform_SetIdentity(srt.aRot);
            *((unsigned char *)&w0 + 3) = *(unsigned char *)(cmd + 5);
            *((unsigned char *)&w0 + 2) = *(unsigned char *)(cmd + 6);
            *((unsigned char *)&w0 + 1) = *(unsigned char *)(cmd + 7);
            pos[0] = w0 >> 8;
            *((unsigned char *)&w1 + 3) = *(unsigned char *)(cmd + 8);
            *((unsigned char *)&w1 + 2) = *(unsigned char *)(cmd + 9);
            *((unsigned char *)&w1 + 1) = *(unsigned char *)(cmd + 0xa);
            pos[1] = w1 >> 8;
            *((unsigned char *)&w2 + 3) = *(unsigned char *)(cmd + 0xb);
            *((unsigned char *)&w2 + 2) = *(unsigned char *)(cmd + 0xc);
            *((unsigned char *)&w2 + 1) = *(unsigned char *)(cmd + 0xd);
            pos[2] = w2 >> 8;
            Srt_SetTranslation(&srt, pos);
            *(int *)(*(int *)(this_ + 0x394) + 0xc) =
                Ov107_CreateNodeXformTask(*(int *)(this_ + 0x3c), *(int *)(*(int *)(this_ + 0x394) + 8), 0x17, 0, &srt);
            break;
        }
        }
        break;
    }
    Ov107_AiState_OnMessage(this_, cmd, p3);
}
