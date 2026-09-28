/* Finds the element with the tag, moves it to the position and runs its callback. */

extern int Ov025_FindEntryByTag();
extern void Ov025_Elem_SetPos();
extern void Ov025_InvokeCallback40();

void Ov025_ConfigureEntryByTag_2(int arg0, unsigned int arg1, unsigned short arg2, unsigned short arg3) {
    int e = Ov025_FindEntryByTag(arg0, arg1 & 0xffff);
    Ov025_Elem_SetPos(arg0, e, arg2, arg3);
    Ov025_InvokeCallback40(arg0, e);
}
