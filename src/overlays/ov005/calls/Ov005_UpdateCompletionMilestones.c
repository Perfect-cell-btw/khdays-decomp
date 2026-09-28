/* Loads the mission data overlay, sets the milestone bit of each fully cleared range and reports
 * the new ones; returns the number of changes. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef u32 FSOverlayID;

extern u32 OVERLAY_302_ID[1];
#define FS_OVERLAY_ID_ov302 ((FSOverlayID)(u32)&OVERLAY_302_ID)

typedef struct Ov009ListConfig {
    u32 field0;
    u32 field4;
    u32 capacity;
} Ov009ListConfig;

typedef struct Ov009ObjectList {
    u32 words[9];
} Ov009ObjectList;

extern const Ov009ListConfig data_ov005_0205b3bc;
extern const u16 data_ov005_0205b3c8[60][2];

extern u32 GameState_GetField(u32 field, int index);
extern void GameState_SetField(u32 field, int index, u32 value);
extern void LoadOverlaySync(int processor, int overlay);
extern void UnloadOverlaySync(int processor, int overlay);
extern void Ov005_InitObjectWithList(
    Ov009ObjectList *list,
    const Ov009ListConfig *config
);
extern void Ov005_DestroyMissionList(Ov009ObjectList *list);
extern int Ov005_IsRangeFullyCleared(
    Ov009ObjectList *firstList,
    Ov009ObjectList *secondList,
    int *result,
    int minimum,
    int maximum
);
extern int BitArray_TestBit(const u16 *bits, int index);
extern void BitArray_SetBit(u16 *bits, int index);

int Ov005_UpdateCompletionMilestones(void)
{
    u8 *savedBits;
    int snapshotIndex;
    int changes = 0;
    u16 savedBitsStorage[4];
    int allowNotification = 1;
    Ov009ListConfig config = data_ov005_0205b3bc;
    Ov009ObjectList firstList;
    Ov009ObjectList secondList;
    FSOverlayID overlayId;

    {
        savedBits = (u8 *)savedBitsStorage;
        snapshotIndex = changes;
        do {
            *(u16 *)savedBits = (u16)GameState_GetField(
                (u32)(snapshotIndex + 0x40) * 16 + 0x40c,
                16
            );
            savedBits += 2;
            snapshotIndex++;
        } while (snapshotIndex < 4);
    }

    overlayId = FS_OVERLAY_ID_ov302;
    LoadOverlaySync(0, overlayId);
    Ov005_InitObjectWithList(&firstList, &config);
    config.capacity = 6;
    Ov005_InitObjectWithList(&secondList, &config);

    {
        int rangeIndex;

        rangeIndex = 0;
        do {
            if (Ov005_IsRangeFullyCleared(
                    &firstList,
                    &secondList,
                    &allowNotification,
                    data_ov005_0205b3c8[rangeIndex][0],
                    data_ov005_0205b3c8[rangeIndex][1]
                ) != 0 &&
                BitArray_TestBit(savedBitsStorage, rangeIndex) == 0) {
                changes++;
                BitArray_SetBit(savedBitsStorage, rangeIndex);
            }
            rangeIndex++;
        } while (rangeIndex < 60);
    }

    Ov005_DestroyMissionList(&secondList);
    Ov005_DestroyMissionList(&firstList);
    UnloadOverlaySync(0, overlayId);

    if (changes != 0) {
        u32 difference = 0;
        u16 saved;
        int restoreIndex;

        savedBits = (u8 *)savedBitsStorage;
        restoreIndex = 0;
        do {
            u32 field = (u32)(restoreIndex + 0x40) * 16 + 0x40c;
            saved = *(u16 *)savedBits;
            savedBits += 2;
            u32 current = GameState_GetField(field, 16);

            difference |= saved ^ (current & 0xffff);
            GameState_SetField(field, 16, saved);
            restoreIndex++;
        } while (restoreIndex < 4);

        if (difference != 0 &&
            allowNotification != 0 &&
            GameState_GetField(0x190f, 2) == 0) {
            GameState_SetField(0x190f, 2, 1);
        }
    }

    return changes != 0;
}
