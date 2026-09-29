/* Count newly reached reward thresholds and return the last valid threshold. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct MsgDbRecordHeader { short nSlot,nDbId; int nField04,nField08; } MsgDbRecordHeader;
typedef struct MsgDbRewardThresholdRecord { MsgDbRecordHeader header; int threshold; } MsgDbRewardThresholdRecord;
typedef struct Ov005Config { char unknown00[0x34]; int rewardBases[3]; int rewardTotals[3]; unsigned int rewardScales[3]; } Ov005Config;
extern Ov005Config data_ov005_0205b85c;
extern int Ov005_ScaleByPercent(int,int);
u8 Ov005_CountRewardThresholdGains(int *outMaximum) {
    u8 index;
    u8 previousCount;
    u8 newCount;
    int previousTotal=data_ov005_0205b85c.rewardTotals[2];
    int newTotal=data_ov005_0205b85c.rewardTotals[2]+Ov005_ScaleByPercent(data_ov005_0205b85c.rewardBases[2],data_ov005_0205b85c.rewardScales[2]);
    int maximum;
    previousCount=0;
    newCount=0;
    MsgDb_LoadDb(28,14);
    maximum=0;
    for(index=0;index<100;index++) {
        MsgDbRewardThresholdRecord *record=0;
        int threshold;
        MsgDb_FetchRecord(&record,28,index,14);
        threshold=record->threshold;
        if(threshold<0) {DispatchByNodeKind(&record);break;}
        if(threshold<=previousTotal)previousCount++;
        if(threshold<=newTotal)newCount++;
        maximum=threshold;
        DispatchByNodeKind(&record);
    }
    ResSlot_Release_2(28);
    *outMaximum=maximum;
    return newCount-previousCount;
}
