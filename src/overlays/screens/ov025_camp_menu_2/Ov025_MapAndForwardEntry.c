extern int Ov025_GetVarRecordByIndex();
extern void Text_VSNPrintfWide();

int Ov025_MapAndForwardEntry(int arg0, int arg1, int arg2, int arg3, int arg4) {
    Text_VSNPrintfWide(arg2, arg3, Ov025_GetVarRecordByIndex(arg0, arg1), arg4);
    return arg2;
}
