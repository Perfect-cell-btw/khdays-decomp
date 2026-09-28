/* Commits a mission's results to the game state: its clear/complete status and the
 * all-cleared/all-complete flags, the best rank, and adds the scaled rewards (capped). */

#include "nitro/types.h"

typedef struct Ov005Config {
    u16 sceneId,missionIndex;
    char unknown04[8];
    u16 rewardMode;
    char unknown0e[2];
    int resultRank,specialQuantity;
    char unknown18[16];
    int missionResultValue,updateMissionRecord,missionTargetValue;
    int rewardBase0c,rewardBase08,rewardBase04;
    char unknown40[12];
    u32 rewardScale0c,rewardScale08,rewardScale04;
    char unknown58[12];
    int nOption64;
} Ov005Config;
typedef struct GameState {
    int playTimeSeconds;
    u32 rewardTotal04,rewardTotal08,rewardTotal0c;
    char unknown10[0x197c];
    int missionResultRecords[200];
} GameState;
extern Ov005Config data_ov005_0205b85c;
extern GameState *data_0204be18;
extern u32 GameState_GetField(u32,u32);
extern void GameState_SetField(u32,u32,u32),GameState_SetFlag(u32);
extern int GameState_IsFlagSet(u32);
extern void Ov005_UpdateAllMissionsClearedFlag(void),Ov005_UpdateAllMissionsCompleteFlag(void);
extern int Ov005_UpdateCompletionMilestones(void);
extern int Ov005_ScaleByPercent(int,u32);
static inline int IsMissionCleared(u16 mission) {return GameState_GetField(mission*3+0x28e4,3)>=2;}
static inline void MarkMissionSeen(Ov005Config *config) {
    if((u16)GameState_GetField(config->missionIndex*3+0x28e4,3)<1)GameState_SetField(config->missionIndex*3+0x28e4,3,1);
}
static inline void UpdateAchievementFlag(void) {
    if(GameState_GetField(0x44e,3)>=6 && Ov005_UpdateCompletionMilestones())GameState_SetFlag(0x1909);
}
void Ov005_CommitMissionResults(void) {
    Ov005Config *config=&data_ov005_0205b85c;
    int checkAllCleared,checkAllComplete;
    int rank,reward;
    switch(config->rewardMode) {
    case 255:
        if(config->nOption64!=0)MarkMissionSeen(config);
        else {
            checkAllComplete=0;
            checkAllCleared=0;
            if(!GameState_IsFlagSet(0x2086))MarkMissionSeen(config);
            else if(config->missionResultValue==config->missionTargetValue) {
                if(!IsMissionCleared(config->missionIndex))checkAllCleared=1;
                /* The original performs this extra read even though its result is unused. */
                GameState_GetField(config->missionIndex*3+0x28e4,3);
                GameState_SetField(config->missionIndex*3+0x28e4,3,3);
                checkAllComplete=1;
            } else {
                if((u16)GameState_GetField(config->missionIndex*3+0x28e4,3)<2)GameState_SetField(config->missionIndex*3+0x28e4,3,2);
                checkAllCleared=1;
            }
            if(checkAllCleared)Ov005_UpdateAllMissionsClearedFlag();
            if(checkAllComplete)Ov005_UpdateAllMissionsCompleteFlag();
            UpdateAchievementFlag();
        }
        break;
    case 8:
        if(config->nOption64==0) {
            if(config->resultRank>=0 && config->resultRank<=3) {
                rank=4-config->resultRank;
                if(GameState_GetField(config->missionIndex*3+0x2ca4,3)<(u32)rank)GameState_SetField(config->missionIndex*3+0x2ca4,3,(u16)rank);
            }
            GameState_SetFlag(0x451);
        }
        break;
    default:
        if(config->resultRank>=0 && config->resultRank<=2) {
            rank=3-config->resultRank;
            if(GameState_GetField(config->missionIndex*3+0x2a4c,3)<(u32)rank)GameState_SetField(config->missionIndex*3+0x2a4c,3,(u16)rank);
            UpdateAchievementFlag();
        }
    }
    reward=Ov005_ScaleByPercent(config->rewardBase0c,config->rewardScale0c);
    data_0204be18->rewardTotal0c+=reward;
    if(data_0204be18->rewardTotal0c>999999)data_0204be18->rewardTotal0c=999999;
    reward=Ov005_ScaleByPercent(config->rewardBase08,config->rewardScale08);
    data_0204be18->rewardTotal08+=reward;
    if(data_0204be18->rewardTotal08>999999)data_0204be18->rewardTotal08=999999;
    reward=Ov005_ScaleByPercent(config->rewardBase04,config->rewardScale04);
    data_0204be18->rewardTotal04+=reward;
    if(data_0204be18->rewardTotal04>999999)data_0204be18->rewardTotal04=999999;
    if(config->updateMissionRecord)data_0204be18->missionResultRecords[config->missionIndex]=config->missionResultValue;
}
