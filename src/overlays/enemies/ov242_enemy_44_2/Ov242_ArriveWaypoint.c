/* Waypoint arrival of the ov241 enemy (x3: ov241/242/243): reads the current 20-byte waypoint
 * (+0x3a4 table, +0x24 index) -- its +0xc dwell time goes to +0x2c; with luck under the
 * waypoint's +0x10 chance (a 0..99 roll) the actor plays pose 3 and the wait handler 020d08ec
 * takes over; otherwise a dwell of at most 0x100 advances straight to the next waypoint
 * (020d09c8) and a longer one plays pose 0 (looping) under the dwell handler 020d0994. */

#include "game/enemy_common.h"

struct Waypoint {
    int pad[3];
    int nDwell;
    unsigned int uChance;
};

extern int RandNextScaled(int bound);
extern void SetIndexedSlot(int node, int slot, void *cb);
extern void Ov242_CountdownTimer2cThenPose6(void);
extern void Ov242_NextWaypoint(void);
extern void Ov242_AiWaypointWait(void);

void Ov242_ArriveWaypoint(int node)
{
    int *state = *(int **)(node + 4);
    struct Waypoint *wp = (struct Waypoint *)(*(int *)(*state + 0x3a4) + state[9] * 0x14);
    state[0xb] = wp->nDwell;
    if ((unsigned int)RandNextScaled(0x64) < wp->uChance) {
        Ov107_PostTagUpdate((Actor *)(*state), 3, 0);
        SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov242_CountdownTimer2cThenPose6);
        return;
    }
    if (state[0xb] <= 0x100) {
        SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov242_NextWaypoint);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0, 1);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov242_AiWaypointWait);
}
