/* Install the panel handlers once, then pass the call on.
 *
 * The four handler addresses go into the context at 0x230 only while the mode word at 0x60 is
 * still zero, so this runs its setup on the first pass and is a plain forward afterwards.
 *
 * The parameter is never used here, and that is not an oversight: it is handed to the routine this
 * one tails into. The original keeps it in r0 from entry to exit and starts its own temporaries at
 * r1, which is the only reason to know it exists.
 *
 * Ghidra carries the slots as aHandlers and the gate as nPanelMode on Ov002PanelContext.
 */

typedef void (*Ov002PanelHandler)(void);

extern char *data_ov002_0207f614;
extern void Ov002_SetBgOfs_sub1010(void);
extern void Ov002_SetBgOfs_sub1014(void);
extern void Ov002_SetWindowRegs_sub1040(void);
extern void Ov002_SetWindowRegs_sub1042(void);
extern void Ov002_SetCaptionText(int a);

void Ov002_InstallPanelHandlers(int a) {
    char *ctx = data_ov002_0207f614;

    if (*(int *)(ctx + 0x60) == 0) {
        *(Ov002PanelHandler *)(ctx + 0x230) = Ov002_SetBgOfs_sub1010;
        *(Ov002PanelHandler *)(ctx + 0x234) = Ov002_SetBgOfs_sub1014;
        *(Ov002PanelHandler *)(ctx + 0x238) = Ov002_SetWindowRegs_sub1040;
        *(Ov002PanelHandler *)(ctx + 0x23c) = Ov002_SetWindowRegs_sub1042;
    }
    Ov002_SetCaptionText(a);
}
