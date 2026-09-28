extern void Ov025_SetCtxField9678();
extern void Ov025_SetCtxObject9630();
extern void Ov025_SetCtxObject9634();
extern void Ov025_SetTargetSlot();
extern void PlaySound();

void Ov025_InitSequence(void) {
    Ov025_SetCtxField9678(0);
    Ov025_SetCtxObject9630(1);
    Ov025_SetCtxObject9634(1);
    Ov025_SetTargetSlot(1, -1);
    PlaySound(0, 1);
}
