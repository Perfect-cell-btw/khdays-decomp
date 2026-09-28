extern int Ov025_GetPageA();
extern int GameState_GetField();
extern void PlaySound();
extern void Ov025_Hub_SelectMenuGroup();

void Ov025_DispatchIfRngHigh(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    int x = Ov025_GetPageA();
    if ((unsigned int)GameState_GetField(0, 9) <= 7) {
        PlaySound(0, 4);
        return;
    }
    Ov025_Hub_SelectMenuGroup(x, 2);
    PlaySound(0, 1);
}
