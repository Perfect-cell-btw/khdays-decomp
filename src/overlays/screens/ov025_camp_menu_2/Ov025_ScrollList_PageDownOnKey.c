/* When idle, pages the list down on key pattern 0x10. */

extern int Ov025_ScrollList_PageStep();
extern int gPadHeld;

void Ov025_ScrollList_PageDownOnKey(int arg0) {
    if (*(int *)(arg0 + 0xc) != 0 || *(int *)(arg0 + 0x10) != 0) {
        return;
    }
    if ((*(unsigned short *)&gPadHeld & 0xf0) != 0x10) {
        return;
    }
    Ov025_ScrollList_PageStep(arg0, 1);
}
