extern int Ov025_GetPageA();
extern int PlaySound();
extern int Ov025_Reports_RefreshCurrentEntry();

void Ov025_Reports_ToggleView(int arg0) {
    int x = Ov025_GetPageA(arg0);
    if (*(unsigned short *)*(int *)(x + 0x204) == 0) {
        return;
    }
    PlaySound(0, 0);
    Ov025_Reports_RefreshCurrentEntry();
    *(unsigned char *)(x + 0x22c) ^= 1;
}
