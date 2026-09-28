typedef struct Ov005SelectionState {
    signed char selectedItem,activeRow,firstVisibleItem,unknown03;
    int maxFirstVisibleItem,cachedRowItemCounts[2],scrollThumbHeight;
} Ov005SelectionState;
typedef struct Ov005Context {
    char header[0x54];
    char embeddedManager[0x4a80];
    char opaque4ad4[0x128];
    Ov005SelectionState selection;
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void Ov005_SetEntryOffsetXY(int,short,short);
extern int Ov005_FindEntryById(void *,int);
extern void Ov005_SetEntrySlotsVisible(void *,int,int);
extern void Ov005_UpdateScrollPosition(void);
void Ov005_RefreshSelectionIndicators(void) {
    Ov005Context *context=data_ov005_0205b80c;
    Ov005SelectionState *selection=&context->selection;
    int entry;
    Ov005_SetEntryOffsetXY(1,selection->activeRow*112,selection->selectedItem*16);
    Ov005_SetEntryOffsetXY(29,selection->activeRow*112,selection->selectedItem*16);
    if(selection->cachedRowItemCounts[0]!=0 || selection->cachedRowItemCounts[1]!=0) {
        entry=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,1);
        Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,entry,1);
    } else {
        entry=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,1);
        Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,entry,0);
    }
    Ov005_UpdateScrollPosition();
}
