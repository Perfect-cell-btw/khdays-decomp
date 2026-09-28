/* Sets the all-missions-complete field once missions 1 to 93 are all complete. */

#include "nitro/types.h"
extern u32 GameState_GetField(u32,u32);
extern void GameState_SetField(u32,u32,u32);
static inline int IsMissionComplete(int mission) {return GameState_GetField(mission*3+0x28e4,3)==3;}
void Ov005_UpdateAllMissionsCompleteFlag(void) {
    int mission;
    if(GameState_GetField(0x1913,2)!=0)return;
    for(mission=1;mission<=93;mission++) {
        if(!IsMissionComplete(mission))return;
    }
    GameState_SetField(0x1913,2,1);
}
