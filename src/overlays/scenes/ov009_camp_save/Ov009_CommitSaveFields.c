/* Prepares the save: records the play time and slot, rolls the save variant, bumps the save
 * sequence number, clears two transient flags (restored later) and writes the slot. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov009SaveSlot {
    u16 profileValue;
    u16 cellCount;
    int gameValue8;
    int field40a;
    int gameValue0;
    int mappedResult;
    int hasCompleteData;
    int fieldC4b;
} Ov009SaveSlot;

typedef struct Ov009SaveContext {
    int variant;
    u8 pad004[0x04];
    int state;
    int result;
    u8 pad010[0x04];
    Ov009SaveSlot slots[3];
    u8 pad068[0x1d4];
    int transferState;
    u8 pad240[0x1cbc];
    u32 sequence;
    u8 flag18bd;
    u8 flag18c9;
} Ov009SaveContext;

extern int GameState_GetField(int field, int kind);
extern void GameState_SetField(int field, int kind, u16 value);
extern int Rand16NextScaled(u16 range);
extern int GameState_IsFlagSet(int flag);
extern void func_020235bc(int flag);
extern int Ov009_CommitSaveToSlot(int slot);

int Ov009_CommitSaveFields(Ov009SaveContext *ctx, int slot)
{
    u32 sequence;
    int result;

    GameState_SetField(0x452, 9, (u16)GameState_GetField(0, 9));

    ctx->slots[slot].fieldC4b =
        Rand16NextScaled(
            (u16)((u32)GameState_GetField(0, 9) >= 0x1a ? 3 : 2));
    GameState_SetField(0xc4b, 2, (u16)ctx->slots[slot].fieldC4b);
    GameState_SetField(0xc98, 2, (u16)slot);

    sequence = ctx->sequence + 1;
    GameState_SetField(0xc77, 0x10, (u16)(sequence >> 16));
    GameState_SetField(0xc87, 0x10, (u16)sequence);

    ctx->flag18bd = GameState_IsFlagSet(0x18bd);
    ctx->flag18c9 = GameState_IsFlagSet(0x18c9);
    func_020235bc(0x18bd);
    func_020235bc(0x18c9);

    result = Ov009_CommitSaveToSlot(slot);
    ctx->transferState = 3;
    return result;
}
