#include "game/ov008_camp_menu.h"
/* Ov008_MissionIsEntryActive -- is the highlighted menu entry already the active one?
 * True while the scene is locked out (obj+0x4e8 set). Otherwise compares the current
 * selection (obj+0x4e4) against the entry id of the cursor row (obj+0x4b0, stride 6);
 * row 0 always counts as a match.
 *
 * PROVENANCE: byte-identical twin of Ov006_MissionIsEntryActive -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */
extern int Session_GetLocalPlayerIndex(void);
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

#define OBJ ((int *)data_ov008_02090f24.pContext)

int Ov008_MissionIsEntryActive(void) {
    unsigned short row;
    int *obj;
    int same;
    if (OBJ[0x13a] != 0) {
        return 1;
    }
    row = (unsigned short)Session_GetLocalPlayerIndex();
    obj = OBJ;
    same = 1;
    if (*(unsigned short *)((char *)obj + 0x4e4) !=
            *(unsigned short *)((char *)obj + row * 6 + 0x4b0) && row != 0) {
        same = 0;
    }
    return same;
}
