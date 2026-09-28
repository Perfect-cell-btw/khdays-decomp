/* First node with a positive count in the menu context's list at +0x13fc. Returns the node, or 0.
 */

extern int Ov025_GetPageA();
extern int Ov025_FirstPositiveCountNode();

int Ov025_FirstPositiveCountNodeOfList(int arg0) {
    return Ov025_FirstPositiveCountNode(Ov025_GetPageA(arg0) + 0x13fc);
}
