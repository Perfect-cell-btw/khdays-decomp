/* Whether the value is at most the player's amount of a fixed resource (game-state field 0x140b).
 */

extern unsigned int GameState_GetField(int id, int n);

int Ov069_ResourceGE_3(unsigned int arg) {
    if (GameState_GetField(0x141f, 0xa) < arg) {
        return 0;
    }
    return 1;
}
