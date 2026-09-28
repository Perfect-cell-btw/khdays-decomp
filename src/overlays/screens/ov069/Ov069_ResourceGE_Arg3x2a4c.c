/* Whether a mission's rank field (0x2a4c + 3 * mission) is set. */

extern int GameState_GetField(int id, int n);

int Ov069_ResourceGE_Arg3x2a4c(int arg) {
    if (GameState_GetField(arg * 3 + 0x2a4c, 3) == 0) {
        return 0;
    }
    return 1;
}
