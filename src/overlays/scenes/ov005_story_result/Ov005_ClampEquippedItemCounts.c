#include "nitro/types.h"
typedef struct NNSFndList {void *head,*tail;u16 count,offset;} NNSFndList;
typedef struct Ov005PanelView {char opaque[0x20];NNSFndList itemQuantities;char tail[0x100-0x2c];} Ov005PanelView;
typedef struct Ov005ItemQuantity {int itemId,quantity;} Ov005ItemQuantity;
typedef struct PlayerItemLimit {u16 itemId;short limit;} PlayerItemLimit;
extern char *data_0204be18;
extern void NNS_FndInitList(NNSFndList *,u16);
extern void *NNS_FndGetNextListObject(NNSFndList *,void *);
extern void Ov005_InitRecordContext(Ov005PanelView *,void *);
extern void Ov005_BuildMenuGrid(Ov005PanelView *,void **,NNSFndList *,u16 *);
extern void Ov005_RebuildViewAndCountCells(Ov005PanelView *,void **,NNSFndList *);
extern unsigned int Session_GetLocalPlayerIndex(void);
extern PlayerItemLimit *Table_FindKey(int,unsigned int);
extern void Ov005_RemoveEquippedItem(unsigned int,int);
extern void Ov005_ReleaseHandleGridAndList(Ov005PanelView *,void **,NNSFndList *);
/* Historical symbol name; this is the ov005 panel cleanup veneer, not WM code. */
extern void Ov005_ReleasePanelViewVeneer(Ov005PanelView *);
void Ov005_ClampEquippedItemCounts(void) {
    void *entries[120];
    Ov005PanelView view;
    NNSFndList nodes;
    Ov005ItemQuantity *item;
    NNS_FndInitList(&nodes,0x28);
    Ov005_InitRecordContext(&view,0);
    Ov005_BuildMenuGrid(&view,entries,&nodes,(u16 *)(data_0204be18+0xee0));
    Ov005_RebuildViewAndCountCells(&view,entries,&nodes);
    for(item=NNS_FndGetNextListObject(&view.itemQuantities,0);item;item=NNS_FndGetNextListObject(&view.itemQuantities,item)) {
        int id=item->itemId;
        if (id>=2 && id<=11) {
            PlayerItemLimit *limit=Table_FindKey(Session_GetLocalPlayerIndex(),id);
            int excess;
            if (limit==0) excess=item->quantity;
            else excess=item->quantity-limit->limit;
            if(excess>0)Ov005_RemoveEquippedItem(item->itemId,excess);
        }
    }
    Ov005_ReleaseHandleGridAndList(&view,entries,&nodes);
    Ov005_ReleasePanelViewVeneer(&view);
}
