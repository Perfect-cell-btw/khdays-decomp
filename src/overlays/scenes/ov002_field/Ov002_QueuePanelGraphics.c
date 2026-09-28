/*
 * Queues the map panel's VRAM requests for this frame.
 *
 * Three things can be asked for: the overlay icon when its bit is set in the
 * panel flags, the panel's own graphic chosen from a table by the panel kind,
 * and one status graphic. The status graphic is picked from the mission slot
 * when there is one, and otherwise from the panel kind, with kind four reading
 * the day clock and mapping it onto four bands.
 *
 * 0xffff is the table's absent marker and 0xfffe means the fixed graphic.
 *
 * One thing here is load-bearing rather than style. The last day-band test
 * carries a second conjunct on the panel kind that is already known true inside
 * this arm. It changes nothing at runtime, but it is what makes the compiler
 * emit the comparison at all: without it both outcomes reach the same block, so
 * the branch and the comparison go together and the function comes out four
 * bytes short.
 *
 * THUMB.
 */

typedef unsigned short u16;

typedef struct Ov002DayClock {
    unsigned char nFlags;
    unsigned char nPad001;
    u16 nMinutes;
} Ov002DayClock;

extern const u16 data_ov002_0207ee08[];
extern const u16 data_ov002_0207ee20[];
extern Ov002DayClock data_0204c240;

extern int Ov002_Field_GetWordAC(void);
extern short Ov002_Field_GetHalf84(void);
extern char *Ov002_MakePrimaryVramKey(unsigned int nId);
extern char *Ov002_MakeSecondaryVramKey(unsigned int nId);
extern void Ov002_AppendEntry(char *pKey, void *pCallback, int nFlag);
extern int GameState_GetField(int nWho, int nField);
extern void Ov002_ConfirmSaveSlot(void);
extern void Ov002_ShowSlotSummary(void);
extern void Ov002_ShowPageSpread(void);

void Ov002_QueuePanelGraphics(void)
{
    int nKind;
    int nSlot;
    unsigned int bOverlay;
    unsigned int nId;
    unsigned int nDay;
    int nBand;
    int nBase;

    nSlot = Ov002_Field_GetWordAC();
    nKind = Ov002_Field_GetHalf84() & 0xff;
    bOverlay = (unsigned char)(Ov002_Field_GetHalf84() >> 8) & 1;

    if (bOverlay != 0) {
        Ov002_AppendEntry(Ov002_MakePrimaryVramKey(10), Ov002_ConfirmSaveSlot, 0);
    }

    if (nKind < 0xc) {
        nId = data_ov002_0207ee08[nKind];
        if (nId != 0xffff) {
            bOverlay = bOverlay != 0;
            Ov002_AppendEntry(Ov002_MakePrimaryVramKey(nId), Ov002_ShowSlotSummary, bOverlay);
        }
    }

    if (nSlot >= 0) {
        if (nSlot != 0) {
            if (nSlot <= 0x3d) {
                nSlot = nSlot + 0x2f;
            } else {
                nSlot = 0xffff;
            }
            nId = (u16)nSlot;
        } else {
            nId = 0xfffe;
        }
    } else {
        if (nKind >= 0xc) {
            goto fallback;
        }
        if (nKind == 4) {
                if ((data_0204c240.nFlags & 1) != 0) {
                    nBase = 0x547;
                    nDay = data_0204c240.nMinutes;
                    if ((int)nDay <= nBase) {
                        if ((int)nDay < nBase) {
                            if ((int)nDay <= nBase - 0x32) {
                                if ((int)nDay >= nBase - 0x33) {
                                    if ((int)nDay == nBase - 0x33) {
                                        goto band_b1;
                                    }
                                    nBase -= 0x32;
                                    if ((int)nDay != nBase) {
                                        goto band_aa;
                                    }
                                    goto band_b1;
                                }
                            }
                        } else {
                            goto band_ae;
                        }
                    } else {
                        if ((int)nDay <= nBase + 3) {
                            if ((int)nDay >= nBase + 1) {
                                if ((int)nDay == nBase + 1) {
                                    goto band_af;
                                }
                                nBase += 3;
                                if ((int)nDay == nBase && nKind == 4) {
                                    goto band_aa;
                                }
                            }
                        }
                    }
                    goto band_aa;
band_ae:
                    nId = 0xae;
                    goto done;
band_af:
                    nId = 0xaf;
                    goto done;
band_b1:
                    nId = 0xb1;
                    goto done;
band_aa:
                    nId = 0xaa;
                } else {
                    nBand = 0x12a;
                    nDay = GameState_GetField(0, 9);
                    if ((int)nDay <= 0x5d) {
                        nId = 0xaa;
                    } else if ((int)nDay <= 0xc0) {
                        nId = 0xae;
                    } else if ((int)nDay <= nBand) {
                        nId = 0xaf;
                    } else if ((int)nDay <= nBand + 0x35) {
                        nId = 0xb0;
                    } else {
                        nId = 0xb1;
                    }
                }
        } else {
            nId = data_ov002_0207ee20[nKind];
        }
        goto done;
fallback:
        nId = 0xffff;
    }

done:
    if (nId != 0xffff) {
        if (nId == 0xfffe) {
            Ov002_AppendEntry(Ov002_MakePrimaryVramKey(0xb), Ov002_ShowPageSpread, 0);
            return;
        }
        Ov002_AppendEntry(Ov002_MakeSecondaryVramKey(nId), Ov002_ShowPageSpread, 0);
    }
}
