/* Ov002_FindActiveEntryByTag bound to the tag tracker embedded at +0xdc of the ov002 context. */

extern int data_ov002_0207f60c;
extern int Ov002_FindActiveEntryByTag();

int Ov002_Ctx_FindActiveEntryByTag(int arg0) {
    return Ov002_FindActiveEntryByTag(*(int *)&data_ov002_0207f60c + 0xdc, arg0);
}
