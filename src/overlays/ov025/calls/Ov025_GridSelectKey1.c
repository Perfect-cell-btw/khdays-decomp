/* Applies grid key selection 1 on the menu context. */

extern int Ov025_GetPageA(void);
extern void Ov025_AdvanceSlotIfMatch(int, int);

void Ov025_GridSelectKey1(void) {
    int temp = Ov025_GetPageA();
    Ov025_AdvanceSlotIfMatch(temp, 1);
}
