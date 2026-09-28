/* Sizes the reward list's scrollbar thumb from the visible fraction and shows its segments. */

typedef unsigned char u8;
typedef struct Ov005SelectionState {
    u8 unknown00,activeRow,firstVisibleItem,unknown03;
    int maxFirstVisibleItem,cachedRowItemCounts[2],scrollThumbHeight;
} Ov005SelectionState;
typedef struct Ov005Context {
    char header[0x54];
    char embeddedManager[0x4a80];
    char opaque4ad4[0x128];
    Ov005SelectionState selection;
    char opaque4c10[0x30];
    int scrollCapVisible[2];
    int scrollSegmentVisible[11];
} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern int Ov005_GetVisibleItemPercent(void);
extern int Ov005_FindEntryById(void *,int);
extern void *Ov005_GetEntryBlock2c(void *,int);
extern void Ov005_SetEntrySlotsVisible(void *,int,int);
extern void Ov005_SetEntryOffsetXY(int,short,short);
void Ov005_InitScrollbar(void) {
    Ov005SelectionState *selection=&data_ov005_0205b80c->selection;
    u8 i,count;
    int slot,visible;
    selection->scrollThumbHeight=(Ov005_GetVisibleItemPercent()*112/100)/8*8;
    if(selection->scrollThumbHeight<32) selection->scrollThumbHeight=32;
    count=(selection->scrollThumbHeight-32)/8;
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,5);
    Ov005_GetEntryBlock2c(data_ov005_0205b80c->embeddedManager,slot);
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,4);
    Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,slot,1);
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,5);
    Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,slot,1);
    data_ov005_0205b80c->scrollCapVisible[0]=data_ov005_0205b80c->scrollCapVisible[1]=1;
    for(i=0;i<11;i++) {
        visible=i<count?1:0;
        slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,i+6);
        Ov005_SetEntrySlotsVisible(data_ov005_0205b80c->embeddedManager,slot,visible);
        data_ov005_0205b80c->scrollSegmentVisible[i]=visible;
    }
    Ov005_SetEntryOffsetXY(5,0,count*8);
    Ov005_SetEntryOffsetXY(31,0,count*8);
}
