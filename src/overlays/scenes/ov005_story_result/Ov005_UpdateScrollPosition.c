/* Moves the scrollbar thumb to the list's scroll position. */

typedef unsigned char u8;
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
extern int Ov005_FindEntryById(void *,int);
extern void *Ov005_GetEntryBlock2c(void *,int);
extern void Ov005_SetEntryOffsetXY(int,short,short);
extern int func_02020400(int numerator,int denominator);
static inline int GetScrollOffset(Ov005SelectionState *selection) {
    if(selection->maxFirstVisibleItem==0)return 0;
    return func_02020400((112-selection->scrollThumbHeight)*selection->firstVisibleItem,selection->maxFirstVisibleItem);
}
void Ov005_UpdateScrollPosition(void) {
    Ov005Context *context=data_ov005_0205b80c;
    Ov005SelectionState *selection=&context->selection;
    u8 count=(selection->scrollThumbHeight-32)/8;
    short y=(short)GetScrollOffset(selection);
    u8 i;
    int entry;
    entry=Ov005_FindEntryById(context->embeddedManager,5);
    Ov005_GetEntryBlock2c(data_ov005_0205b80c->embeddedManager,entry);
    Ov005_SetEntryOffsetXY(4,0,(short)y);
    Ov005_SetEntryOffsetXY(30,0,(short)y);
    for(i=0;i<count;i++) {
        Ov005_SetEntryOffsetXY(i+6,0,(short)y);
        Ov005_SetEntryOffsetXY(i+32,0,(short)y);
    }
    Ov005_SetEntryOffsetXY(5,0,y+count*8);
    Ov005_SetEntryOffsetXY(31,0,y+count*8);
}
