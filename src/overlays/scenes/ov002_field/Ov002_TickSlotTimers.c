extern char *data_ov002_0207f614;

extern int Ov002_Status_GetHalfCE(int nSlot);
extern void Ov002_UploadSlotIconPalette(int nSlot, int nMode);

/* Tick the four slot timers. When one reaches zero the slot is retired, with
 * the mode chosen by whether it is still occupied. */
void Ov002_TickSlotTimers(void)
{
    char *pBase;
    int nTimer;
    int i;

    pBase = *(char **)&data_ov002_0207f614;

    for (i = 0; i < 4; i++) {
        nTimer = *(unsigned char *)(pBase + i + 0x65);
        if (nTimer != 0) {
            *(unsigned char *)(pBase + i + 0x65) = nTimer - 1;
            if (((nTimer - 1) & 0xff) == 0) {
                Ov002_UploadSlotIconPalette(i, Ov002_Status_GetHalfCE(i) == 0 ? 2 : 0);
            }
        }
    }
}
