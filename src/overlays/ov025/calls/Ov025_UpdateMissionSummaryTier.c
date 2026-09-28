typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov008MissionListEntry {
    u8 pad00[2];
    u16 missionId;
    u8 pad04[0x11];
    u8 completionWeight;
} Ov008MissionListEntry;

typedef struct Ov008MenuContext {
    u8 pad0000[0x14f0];
    u8 missionSummaryTiers[3];
    u8 completedMissionWeight;
} Ov008MenuContext;

extern Ov008MenuContext *Ov025_GetPageA(void);
extern u32 GameState_GetField(u32 field, int selector);
extern u8 data_0204c300[];

u8 Ov025_UpdateMissionSummaryTier(Ov008MissionListEntry *missionEntry)
{
    Ov008MenuContext *menuContext = Ov025_GetPageA();
    u32 missionWeight = menuContext->completedMissionWeight;
    u8 summaryTier;

    if (missionEntry != 0) {
        int isComplete =
            GameState_GetField(missionEntry->missionId * 3 + 0x28e4, 3) >= 2;
        if (isComplete == 0) {
            missionWeight =
                (missionWeight + missionEntry->completionWeight) & 0xff;
        }
    }

    summaryTier = 1;
    if (missionWeight > (u32)menuContext->missionSummaryTiers[0]) {
        summaryTier++;
    }
    if ((int)missionWeight >
        (int)menuContext->missionSummaryTiers[1] +
            (int)menuContext->missionSummaryTiers[0]) {
        summaryTier++;
    }

    data_0204c300[0x4f] = summaryTier;
    return summaryTier;
}
