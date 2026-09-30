/* Unless story flag 0x200d is set, arm four "unseen" markers in the ov008 UI state block; and
 * whenever the shared game-state bit at +0x9b0 is set, arm a fifth. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008MenuSubEntry {
    s16 nId;                  /* 0x00 */
    u8  nText;                /* 0x02 */
    u8  nHelpText;            /* 0x03 */
} Ov008MenuSubEntry;

typedef struct Ov008MenuEntryDef {
    s16 nId;                  /* 0x00 */
    u8  nText;                /* 0x02 */
    u8  nHelpText;            /* 0x03 */
    u8  nAnchor;              /* 0x04 */
    u8  nState;               /* 0x05: lock state */
    u8  bEnabled;             /* 0x06 */
    u8  nSubCount;            /* 0x07 */
    Ov008MenuSubEntry aSub[3]; /* 0x08 */
} Ov008MenuEntryDef;

extern Ov008MenuEntryDef data_ov008_02090598[];
extern u8 *gGameState;

void Ov008_ArmUnseenMarkers(void) {
    if (GameState_IsFlagSet(0x200d) == 0) {
        data_ov008_02090598[15].bEnabled = 1;
        data_ov008_02090598[16].bEnabled = 1;
        data_ov008_02090598[17].bEnabled = 1;
        data_ov008_02090598[18].bEnabled = 1;
    }
    if (gGameState[0x9b0] != 0) {
        data_ov008_02090598[24].bEnabled = 1;
    }
}
