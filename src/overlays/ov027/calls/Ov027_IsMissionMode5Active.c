extern int GameState_GetField(int key, int sub);
extern char data_0204c4d8[];
/* True only in mission mode 5 with game field 0x40a/2 equal to 1. */
int Ov027_IsMissionMode5Active(void) {
    if (*(char *)(data_0204c4d8 + 0x11) == 5 && GameState_GetField(0x40a, 2) == 1) {
        return 1;
    }
    return 0;
}
