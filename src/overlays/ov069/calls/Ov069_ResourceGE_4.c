extern unsigned int GameState_GetField(int id, int n);

int Ov069_ResourceGE_4(unsigned int arg) {
    if (GameState_GetField(0x1400, 0xa) < arg) {
        return 0;
    }
    return 1;
}
