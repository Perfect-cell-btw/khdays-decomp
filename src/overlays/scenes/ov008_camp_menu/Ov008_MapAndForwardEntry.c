/* Formats the variable record with the given index into the buffer (wide vsnprintf) and returns the
 * buffer. */

extern int Ov008_GetVarRecordByIndex(int arg0, int arg1);
extern void Text_VSNPrintfWide(int arg0, int arg1, int arg2, int arg3);

int Ov008_MapAndForwardEntry(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int value = Ov008_GetVarRecordByIndex(arg0, arg1);
    Text_VSNPrintfWide(arg2, arg3, value, arg4);
    return arg2;
}
