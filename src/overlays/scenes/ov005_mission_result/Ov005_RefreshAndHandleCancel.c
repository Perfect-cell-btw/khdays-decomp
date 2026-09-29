#include "game/engine.h"

extern void Ov005_InitInteractiveEntries(void);
extern void Ov005_HandleDirectionalInput(void);
extern void Ov005_RenderTextSurface(int layer);
extern void Ov005_UpdateDialogVisibility(void);
extern void Ov005_RefreshDialogChoice(void);
extern unsigned short data_0204c190;
extern char *data_ov005_0205b80c;

/* Per-frame refresh: rebuilds the three layers, and when the pad reports B without A, arms the
 * cancel path. */
void Ov005_RefreshAndHandleCancel(void) {
    unsigned held;
    Ov005_InitInteractiveEntries();
    Ov005_HandleDirectionalInput();
    Ov005_RenderTextSurface(1);
    Ov005_RenderTextSurface(0);
    Ov005_RenderTextSurface(3);
    held = data_0204c190;
    if ((held & 1) == 0 && (held & 2) == 0) {
        return;
    }
    *(int *)(data_ov005_0205b80c + 0x4000 + 0xbf0) = 4;
    Ov005_UpdateDialogVisibility();
    Ov005_RefreshDialogChoice();
    PlaySound(0, 1);
}
