extern int Ov025_GetPageB();
extern int Ov025_IsEntryBusyOrInactive();
extern void Tween_Configure();
extern void Tween_Start();

void Ov025_InitOverlayFade(void) {
    int x = Ov025_GetPageB();
    if (Ov025_IsEntryBusyOrInactive() == 0) {
        Tween_Configure((unsigned int *)(x + 0x10), 0, *(unsigned int *)(x + 0x2c), 0xffff0000, 100);
        Tween_Start(x + 0x10);
        *(int *)(x + 500) = 1;
        *(int *)(x + 0x1f8) = 2;
    }
}
