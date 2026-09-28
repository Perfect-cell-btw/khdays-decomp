typedef struct Ov005Context {
    char header[0x54];
    char embeddedManager[0x4a80];
    char opaque4ad4[0x13c];
    unsigned char dialogChoice;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern int Ov005_FindEntryById(void *,int);
extern void Ov005_SwapParamOverrides(void *,int);
extern void Ov005_SetEntrySlotsVisible(void *,int,int);
static inline void SetVisible(int id,int visible) {
    int entry=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,id);
    Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,entry,visible);
}
void Ov005_RefreshDialogChoice(void) {
    Ov005Context *context=data_ov005_0205b80c;
    int entry;
    if(context->dialogChoice) {
        entry=Ov005_FindEntryById(context->embeddedManager,25);
        Ov005_SwapParamOverrides(context->embeddedManager,entry);
        SetVisible(27,1);
        SetVisible(28,0);
    } else {
        entry=Ov005_FindEntryById(context->embeddedManager,26);
        Ov005_SwapParamOverrides(context->embeddedManager,entry);
        SetVisible(27,0);
        SetVisible(28,1);
    }
}
