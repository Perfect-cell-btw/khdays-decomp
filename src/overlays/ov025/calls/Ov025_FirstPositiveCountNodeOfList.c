/* First node with a positive count in the menu context's list at +0x13fc. */

extern int Ov025_GetPageA();
extern int Ov025_FirstPositiveCountNode();

void Ov025_FirstPositiveCountNodeOfList(int arg0) {
    Ov025_FirstPositiveCountNode(Ov025_GetPageA(arg0) + 0x13fc);
}
