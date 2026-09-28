extern int NNSi_FndGetCurrentRootHeap(void);
extern void SetMasterBrightnessMain(int level);
extern void Ov007_CopyLine(void *root);
extern int Ov007_TextWindowFadeIn(void);

/* Ramp the screen brightness up over 0x20 frames (level = frame/2 - 0x10); once
 * it saturates, snap to full, reset the counter and the pending-input word, drain
 * the input line, and return the next handler. */
int Ov007_FadeInStep(void) {
    int root = NNSi_FndGetCurrentRootHeap();
    int ret = 0;
    int frame = *(int *)(root + 0x20) + 1;

    *(int *)(root + 0x20) = frame;
    if (frame >= 0x20) {
        SetMasterBrightnessMain(0);
        *(int *)(root + 0x20) = 0;
        *(int *)(root + 0x70) = 0;
        Ov007_CopyLine((void *)root);
        ret = (int)Ov007_TextWindowFadeIn;
    } else {
        SetMasterBrightnessMain(frame / 2 - 0x10);
    }
    return ret;
}
