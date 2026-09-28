/* Sets the all-missions-cleared field once missions 1 to 93 are all cleared. */

#include "nitro/types.h"

extern u32 GameState_GetField(u32,u32);
extern void GameState_SetField(u32,u32,u32);
static inline int IsMissionCleared(int mission) {return GameState_GetField(mission*3+0x28e4,3)>=2;}
void Ov005_UpdateAllMissionsClearedFlag(void) {
    int mission;
    if(GameState_GetField(0x1911,2)!=0)return;
    for(mission=1;mission<=93;mission++) {
        if(!IsMissionCleared(mission))return;
    }
    GameState_SetField(0x1911,2,1);
}
