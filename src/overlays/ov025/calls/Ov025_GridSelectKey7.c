extern int Ov025_GetPageA(void);
extern void Ov025_AdvanceSlotIfMatch(int, int);

void Ov025_GridSelectKey7(void) {
    int temp = Ov025_GetPageA();
    Ov025_AdvanceSlotIfMatch(temp, 7);
}
