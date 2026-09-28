/* Ov008_SetTagValueAndNotify -- push (param_3,param_4) to the widget bound to tag param_2, then fire its
 * change callback. Finds the entry (Ov008_FindEntryByTag), sets its value (Ov008_Elem_SetPos),
 * and invokes its +0x?? handler (Ov008_InvokeCallback40). */
extern int  Ov008_FindEntryByTag(int owner, unsigned int tag);
extern void Ov008_Elem_SetPos(int owner, int entry, unsigned short a, unsigned short b);
extern void Ov008_InvokeCallback40(int owner, int entry);

void Ov008_SetTagValueAndNotify(int param_1, unsigned int param_2, unsigned short param_3, unsigned short param_4) {
    int entry = Ov008_FindEntryByTag(param_1, param_2 & 0xffff);
    Ov008_Elem_SetPos(param_1, entry, param_3, param_4);
    Ov008_InvokeCallback40(param_1, entry);
}
