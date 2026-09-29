/* Ov008_MainMenuTopState -- main-menu top state, ov008.
 *
 * Each frame updates the cursor (Ov008_UpdateCursorSprite) and input/state (Ov008_UpdateMenuInput).
 * When the session was ready at init (Ov008_IsSessionReady; always so in single player) it goes on
 * once no other player's slot (1-3) is occupied without being done. Otherwise it stays while the
 * high nibble of heap[0x1e] is 0, latching Ov008_Link_IsReady into heap[0x48] whenever a selection
 * is confirmed (heap[0x2c]). On commit it queues the two transition events (GameState_GetField
 * 0x451/0x44e) into heap[0x12b] and advances to Ov008_MainMenuTopState_2. */

#include "game/engine.h"

struct MenuSlot { char pad0, pad1; unsigned char done : 1; };
extern void Ov008_UpdateCursorSprite(void);
extern void Ov008_UpdateMenuInput(void);
extern int  Ov008_IsSessionReady(void);
extern void *Slot4_GetIfOccupied(int slot);
extern struct MenuSlot *Ov008_GetPlayerRecord(int slot);
extern int  Ov008_Link_IsReady(void);
extern char *data_ov008_02090f00;
extern void Ov008_MainMenuTopState_2(void);

void *Ov008_MainMenuTopState(void) {
    Ov008_UpdateCursorSprite();
    Ov008_UpdateMenuInput();
    if (Ov008_IsSessionReady() != 0) {
        int slot;
        for (slot = 1; slot < 4; slot++) {
            if (Slot4_GetIfOccupied(slot) != 0 && Ov008_GetPlayerRecord(slot)->done == 0) {
                return 0;
            }
        }
    } else if (((unsigned int)*(unsigned char *)(data_ov008_02090f00 + 0x1e) << 24 >> 28) < 1) {
        if (*(unsigned short *)(data_ov008_02090f00 + 0x2c) != 0) {
            unsigned char bit = Ov008_Link_IsReady();
            *(unsigned char *)(data_ov008_02090f00 + 0x48) =
                (*(unsigned char *)(data_ov008_02090f00 + 0x48) & ~1) | (bit & 1);
        }
        return 0;
    }
    {
        unsigned char e1 = GameState_GetField(0x451, 1);
        *(unsigned char *)(data_ov008_02090f00 + 0x12b) =
            (*(unsigned char *)(data_ov008_02090f00 + 0x12b) & ~1) | (e1 & 1);
    }
    {
        unsigned char e2 = GameState_GetField(0x44e, 3);
        *(unsigned char *)(data_ov008_02090f00 + 0x12b) =
            (*(unsigned char *)(data_ov008_02090f00 + 0x12b) & ~0xe) | ((e2 & 7) << 1);
    }
    return (void *)Ov008_MainMenuTopState_2;
}
