extern void Ov002_ForwardToSubDc(int id);
extern void Ov002_Ctx_InvokeTagTrackerCallback(void);
extern void Ov002_PaintGroupRow(int slot);
extern void Ov002_SelectEntry(int id);

/* Redraws the party strip: the header line, the four member rows and the two side panels. */
void Ov002_RedrawPartyStrip(void) {
    int i;
    Ov002_ForwardToSubDc(0x51);
    Ov002_Ctx_InvokeTagTrackerCallback();
    for (i = 0; i < 4; i++) {
        Ov002_PaintGroupRow(i);
    }
    Ov002_SelectEntry(9);
    Ov002_SelectEntry(0xb);
}
