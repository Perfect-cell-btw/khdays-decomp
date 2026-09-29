/* Ov008_EnterSelectedPage -- advance the main menu into the selected page, ov008.
 * Refreshes the cursor (Ov008_UpdateCursorSprite) and marks the menu busy (heap+0x18=2). With a
 * sub-scene active, ungates input (GameSession_SetSyncEnabled(0)), clears the four per-slot save flags
 * (heap+0x92/0x96/0x9a/0x9e) and hands off to Ov008_CommitSelectedPage. Otherwise it only proceeds
 * once the current page's option count (high nibble of heap+0x1e) reaches 3, clearing the
 * transition marker (heap+0x172) before handing off; below 3 it stays (returns 0). */

#include "game/engine.h"

extern void  Ov008_UpdateCursorSprite(void);
extern int   Ov008_IsSessionReady(void);
extern char *data_ov008_02090f00;
extern void  Ov008_CommitSelectedPage(void);

void *Ov008_EnterSelectedPage(void) {
    Ov008_UpdateCursorSprite();
    *(int *)(data_ov008_02090f00 + 0x18) = 2;
    if (Ov008_IsSessionReady() != 0) {
        GameSession_SetSyncEnabled(0);
        *(short *)(data_ov008_02090f00 + 0x92) = 0;
        *(short *)(data_ov008_02090f00 + 0x96) = 0;
        *(short *)(data_ov008_02090f00 + 0x9a) = 0;
        *(short *)(data_ov008_02090f00 + 0x9e) = 0;
        return (void *)Ov008_CommitSelectedPage;
    }
    if ((unsigned int)*(unsigned char *)(data_ov008_02090f00 + 0x1e) << 0x18 >> 0x1c < 3) {
        return 0;
    }
    *(short *)(data_ov008_02090f00 + 0x172) = 0;
    GameSession_SetSyncEnabled(0);
    return (void *)Ov008_CommitSelectedPage;
}
