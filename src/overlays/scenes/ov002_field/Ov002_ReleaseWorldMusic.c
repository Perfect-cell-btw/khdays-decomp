
/* Only the leading flag word of a player record matters here: bit 16 takes the
   player out of the walk. */

#include "nitro/types.h"

typedef struct Ov002PlayerRecord {
    unsigned long long nFlags;
} Ov002PlayerRecord;

/* Index of the local player; zero for the one running the session. */
extern int Session_GetLocalPlayerIndex(void);
/* Number of players the session currently holds. */
extern int func_ov022_020882f8(void);
extern Ov002PlayerRecord *GetEntryField20ByIndex(int nPlayer);
extern int Ov022_GetEntryField66(int nPlayer);
extern int Ov002_GetSlotTableByte(int nWorld);
extern void Ov002_SetActiveMaskBit(int nTrack);

/* Drop the music a world was holding, once nobody is left in it.
 *
 * Only the player running the session decides this, and only for a real world.
 * Every player still in play is checked, and finding one of them in that world
 * leaves the music alone; otherwise the world's track is looked up and stopped.
 */
void Ov002_ReleaseWorldMusic(int nWorld)
{
    int i;
    int nPlayerWorld;

    if (nWorld < 0) {
        return;
    }
    if (Session_GetLocalPlayerIndex() != 0) {
        return;
    }

    for (i = 0; i < func_ov022_020882f8(); i++) {
        if ((GetEntryField20ByIndex(i)->nFlags & 0x10000) == 0) {
            nPlayerWorld = Ov022_GetEntryField66(i);
            if (nPlayerWorld >= 0) {
                if (nWorld == nPlayerWorld) {
                    return;
                }
            }
        }
    }

    Ov002_SetActiveMaskBit((u16)Ov002_GetSlotTableByte(nWorld));
}
