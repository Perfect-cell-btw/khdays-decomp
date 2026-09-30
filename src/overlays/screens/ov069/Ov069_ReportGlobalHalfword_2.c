/* Reports a global counter to the field root, then returns whether it is at least the value. */

extern void Ov002_SetRootField85ac(int a, int b);
extern int gGameState;

int Ov069_ReportGlobalHalfword_2(unsigned int arg) {
    Ov002_SetRootField85ac(1, *(unsigned short *)(*(char **)&gGameState + 0x196e));
    if (*(unsigned short *)(*(char **)&gGameState + 0x196e) < arg) {
        return 0;
    }
    return 1;
}
