typedef struct Ov005Context {
    char header[0x54];
    char embeddedManager[0x4a80];
    char opaque4ad4[0x15c];
    int interactiveEntriesInitialized;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern int Ov005_FindEntryById(void *,int);
extern void Ov005_ReleaseTwoSlots_2(void *,int);
void Ov005_InitInteractiveEntries(void) {
    int entry;
    if(data_ov005_0205b80c->interactiveEntriesInitialized)return;
    entry=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,1);
    Ov005_ReleaseTwoSlots_2(data_ov005_0205b80c->embeddedManager,entry);
    entry=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,29);
    Ov005_ReleaseTwoSlots_2(data_ov005_0205b80c->embeddedManager,entry);
    data_ov005_0205b80c->interactiveEntriesInitialized=1;
}
