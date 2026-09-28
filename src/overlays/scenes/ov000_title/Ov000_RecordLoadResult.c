/* Records a load-request result for entry `index`: maps the raw result code (0->1, 2->0, 4->2, else
 * -1) into the entry's mappedResult, latches it into publishedResult if still unset (-1), and on
 * success (result 0) builds the entry's working lists. */

#include "nitro/types.h"

typedef struct Ov000LoadEntry {
    u16 profileValue;
    u16 cellCount;
    int gameValue8;
    int field40a;
    int gameValue0;
    int mappedResult;
    int publishedResult;
    int hasCompleteData;
    int fieldC4b;
} Ov000LoadEntry;

typedef struct Ov000LoadSceneContext {
    u8 pad_0000[0x4b10];
    Ov000LoadEntry loadEntries[1];
} Ov000LoadSceneContext;

typedef struct Ov000GameState {
    int value0;
    int pad_0004;
    int value8;
    u8 pad_000c[0xed4];
    u16 menuIds[1];
} Ov000GameState;

extern Ov000LoadSceneContext *volatile data_ov000_0205ac24;
extern Ov000GameState *volatile data_0204be18;
extern void NNS_FndInitList(void *list, int offset);
extern void Ov000_InitRecordContext(void *state, int value);
extern void Ov000_BuildMenuGrid(
    void *state,
    void *work,
    void *list,
    const u16 *ids
);
extern void Ov000_RebuildViewAndCountCells(void *state, void *work, void *list);
extern void Ov000_ReleaseHandleGridAndList(void *state, void *work, void *list);
extern void func_ov000_02058360(void *state);
extern int GameState_GetField(int field, int kind);

void Ov000_RecordLoadResult(int index, int result) {
    char list[0xc];
    char work[0x1e0];
    char state[0x100];
    Ov000LoadEntry *entry =
        &data_ov000_0205ac24->loadEntries[index];

    switch (result) {
    case 0:
        entry->mappedResult = 1;
        break;
    case 2:
        entry->mappedResult = 0;
        break;
    case 4:
        entry->mappedResult = 2;
        break;
    default:
        entry->mappedResult = -1;
        break;
    }

    if (entry->publishedResult == -1) {
        entry->publishedResult = entry->mappedResult;
    }
    if (result != 0) {
        return;
    }

    NNS_FndInitList(list, 0x28);
    Ov000_InitRecordContext(state, 0);
    Ov000_BuildMenuGrid(state, work, list,
                        data_0204be18->menuIds);
    Ov000_RebuildViewAndCountCells(state, work, list);
    entry->cellCount = *(int *)(state + 0x78) + 1;
    Ov000_ReleaseHandleGridAndList(state, work, list);
    func_ov000_02058360(state);

    entry->gameValue8 = data_0204be18->value8;
    entry->profileValue = GameState_GetField(0, 9);
    entry->gameValue0 = data_0204be18->value0;
    entry->field40a = GameState_GetField(0x40a, 2);
    entry->fieldC4b = GameState_GetField(0xc4b, 2);
    entry->hasCompleteData = GameState_GetField(0x44e, 3) == 6;
}
