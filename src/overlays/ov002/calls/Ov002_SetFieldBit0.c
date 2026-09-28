/*
 * Ov002_SetFieldBit0 - set bit 0 of a game-state field to a boolean (ARM).
 *
 * Reads the game-state field addressed by the actor's (fieldHi, fieldLo) id pair via GameState_GetField,
 * clears its low bit, sets that bit to (on != 0), and writes it back via GameState_SetField. The id pair
 * is re-read for the store because the get call may touch the same state. The value is kept as a u16
 * (mask 0xfffe), which is why each step re-truncates to 16 bits.
 */
typedef struct {
    char _0[0x14];
    unsigned short fieldHi;   /* +0x14 */
    unsigned char  fieldLo;   /* +0x16 */
} Ov002Actor;

extern int GameState_GetField(int hi, int lo);
extern void GameState_SetField(int hi, int lo, int value);

void Ov002_SetFieldBit0(Ov002Actor *actor, int on)
{
    unsigned short v = GameState_GetField(actor->fieldHi, actor->fieldLo) & 0xfffe;
    if (on != 0) v |= 1;
    GameState_SetField(actor->fieldHi, actor->fieldLo, v);
}
