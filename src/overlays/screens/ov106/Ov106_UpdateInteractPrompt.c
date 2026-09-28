/* Interaction check of the ov106 scene: unless the scene is paused (field 0x248c clear while a player
 * is selected), with the ov022 camera, the ov002 scene, a player actor and its controller ready and
 * the selected player's entity present, an actor that is not free to act (ov022 02086620/02086888) is
 * left alone; otherwise its prompt is shown when the entity may act on its target (020b79dc), or hidden
 * while the prompt is up. */

#include "nitro/types.h"

extern int GameState_IsFlagSet(int flag);
extern u8 data_0204be04;
extern int func_ov022_02083f0c(void);
extern int Ov002_GetBit0OfField38IfValid(int self);
extern int func_ov022_02083f5c(void);
extern int func_ov022_02088338(void);
extern void *GetEntryField20ByIndex(int nPlayer);
extern int Ov022_IsBit2SetVia0x20(int nHandle);
extern int Ov022_GetWordVia0x20Then0x230(int nHandle);
extern void func_ov022_02086834(int nHandle, int show);
extern int Ov106_CanActOnTarget(void *entity);

void Ov106_UpdateInteractPrompt(void)
{
    int actor;
    void *entity;
    int player;

    if (GameState_IsFlagSet(0x248c) == 0 && data_0204be04 != 0) {
        return;
    }
    if ((player = func_ov022_02083f0c()) == 0) {
        return;
    }
    if (Ov002_GetBit0OfField38IfValid(player) == 0) {
        return;
    }
    if ((actor = func_ov022_02083f5c()) == 0) {
        return;
    }
    if (func_ov022_02088338() == 0) {
        return;
    }
    if ((entity = GetEntryField20ByIndex(data_0204be04)) == 0) {
        return;
    }
    if (Ov022_IsBit2SetVia0x20(actor) != 0 && Ov022_GetWordVia0x20Then0x230(actor) == 0) {
        return;
    }
    if (Ov106_CanActOnTarget(entity) != 0) {
        func_ov022_02086834(actor, 1);
    } else if (Ov022_GetWordVia0x20Then0x230(actor) != 0) {
        func_ov022_02086834(actor, 0);
    }
}
