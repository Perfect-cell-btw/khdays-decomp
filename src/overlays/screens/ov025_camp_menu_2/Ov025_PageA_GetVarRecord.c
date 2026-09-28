/* Returns a text record of page A's text table. */

extern int Ov025_GetPageA();
extern int Ov025_GetVarRecordByIndex();

void Ov025_PageA_GetVarRecord(int arg0) {
    Ov025_GetVarRecordByIndex(Ov025_GetPageA(arg0) + 0x6c, arg0);
}
