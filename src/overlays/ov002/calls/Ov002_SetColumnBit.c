/* Set or clear one column's bit in the mask at +0x4b4 and refresh, but only when
 * the bit is not already in the requested state. Ov002_Panel_IsSlotEnabledB resolves
 * the id to a bit index (through the stack out-param) and reports its current
 * state, so its return value is compared directly against the requested one.
 * A suppressed panel forces the request to "clear". */
extern int Ov002_GetPanelField0058(void);
extern int Ov002_Panel_IsSlotEnabledB(int *bit, int id);
extern void Ov002_PanelRefreshRing(void);

extern char *data_ov002_0207f620;

void Ov002_SetColumnBit(int id, int on) {
    char *ctx = data_ov002_0207f620;
    int bit;

    if (Ov002_GetPanelField0058() != 0) {
        on = 0;
    }

    {
        int state = Ov002_Panel_IsSlotEnabledB(&bit, id);

        if (state == on) {
            return;
        }
    }

    if (on != 0) {
        *(int *)(ctx + 0x4b4) |= 1 << bit;
    } else {
        *(int *)(ctx + 0x4b4) &= ~(1 << bit);
    }

    Ov002_PanelRefreshRing();
}
