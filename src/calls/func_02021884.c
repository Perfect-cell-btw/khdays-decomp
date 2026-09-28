extern void Game_UpdateObjectMotion();
extern unsigned char data_0204be04;

void func_02021884(int arg0) {
    Game_UpdateObjectMotion(*(int *)(arg0 + 0x128) + 0x30 + data_0204be04 * 0x104);
}
