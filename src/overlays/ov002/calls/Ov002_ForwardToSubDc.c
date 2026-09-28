/* Forward to Ov002_FindEntryByTag with the sub-object embedded at +0xdc of the ov002 context
 * (data_ov002_0207f60c). */

extern int data_ov002_0207f60c;
extern int Ov002_FindEntryByTag();

int Ov002_ForwardToSubDc(int arg0) {
    return Ov002_FindEntryByTag(*(int *)&data_ov002_0207f60c + 0xdc, arg0);
}
