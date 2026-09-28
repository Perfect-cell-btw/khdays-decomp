extern void *data_ov106_020b8b60;
extern void Ov106_LoadFontAndCaption(void);

void *Ov106_WaitPendingText(void) {
    if ((*(unsigned short *)((char *)data_ov106_020b8b60 + 0x8e44) & 2) != 0) {
        return (void *)Ov106_LoadFontAndCaption;
    }
    return 0;
}
