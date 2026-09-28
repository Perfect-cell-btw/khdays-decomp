extern int Ov025_GetCueRequest();
extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_GoToPage6WithCue(int arg0) {
    *(int *)(Ov025_GetCueRequest(arg0) + 0xc) = 1;
    Ov025_SetTargetSlot(6, -1);
    PlaySound(0, 1);
}
