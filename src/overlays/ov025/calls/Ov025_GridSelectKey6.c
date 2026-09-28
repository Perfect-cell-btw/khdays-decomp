/* Applies grid key selection 6 on the menu context. */

extern int Ov025_GetPageA(void);
extern void Ov025_AdvanceSlotIfMatch(int, int);

void Ov025_GridSelectKey6(void) {
    int temp = Ov025_GetPageA();
    Ov025_AdvanceSlotIfMatch(temp, 6);
}
