/* Sorts the list at +0x1414 by field 6, then field 0x18. */

extern int func_ov025_0208a5ec();
extern int Ov025_CompareByField6ThenField18();

int Ov025_SortListByKey(int arg0) {
    return func_ov025_0208a5ec(arg0 + 0x1414, Ov025_CompareByField6ThenField18);
}
