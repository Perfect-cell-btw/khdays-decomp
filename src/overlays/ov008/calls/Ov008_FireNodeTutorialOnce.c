/* Fire the "first time on this mission node" tutorial once. Does nothing while input is locked;
 * otherwise resolves the current node's tutorial flag id through the two lookups and, if that
 * story flag is still clear, posts it and answers true.
 *
 * Parked as a CSE tie -- the original recomputes `id + 0x3bd5` (a two-instruction constant add)
 * before each of the two flag calls while mwcc caches the sum. The fix is not about the sum at
 * all: the two lookups take `unsigned short`, so the narrowing after each call belongs to the
 * CALL, and the calls chain directly into one another. Written with `& 0xffff` and intermediate
 * locals, the whole dataflow lands in the caller where mwcc is free to reuse it; nested, it
 * comes out as the original has it. */
extern int Ov008_GetCtxObject9630(void);
extern int GameState_GetField(int event, int bits);
extern int Ov008_FindFirstThresholdRow(unsigned short sel);
extern int Ov008_GetTableValue(unsigned short node);
extern int GameState_IsFlagSet(int flag);
extern void GameState_SetFlag(int flag);

int Ov008_FireNodeTutorialOnce(void) {
    int id;
    int result;

    if (Ov008_GetCtxObject9630() != 0) {
        return 0;
    }
    id = Ov008_GetTableValue(Ov008_FindFirstThresholdRow(GameState_GetField(0, 9)));
    result = 0;
    if (GameState_IsFlagSet(id + 0x3bd5) == 0) {
        GameState_SetFlag(id + 0x3bd5);
        result = 1;
    }
    return result;
}
