/* Constructs an AI node of one behaviour type: base-init, set flag bit 3, install the eight
 * callback function pointers into the node's vtable slots, and init its child list at +0x44. */

typedef unsigned short u16;

extern void Ov107_InitNodeBase(u16 *node);
extern void List_Init(void *list);
extern void Ov107_Region_Destroy(void);
extern void Ov107_Region_TickChildren(void);
extern void Ov107_Region_SyncChildVisibility(void);
extern void Ov107_Region_RunHandlersAlternating(void);
extern void Ov107_RunChildHandlers(void);
extern void Ov107_BroadcastValueToChildren(void);
extern void Ov107_LinkChildNode(void);
extern void Ov107_Region_UnlinkChild(void);

void Ov107_InitBehaviorNode(u16 *node) {
    Ov107_InitNodeBase(node);
    *node |= 8;
    *(void **)(node + 4) = (void *)Ov107_Region_Destroy;
    *(void **)(node + 6) = (void *)Ov107_Region_TickChildren;
    *(void **)(node + 8) = (void *)Ov107_Region_SyncChildVisibility;
    *(void **)(node + 0x10) = (void *)Ov107_Region_RunHandlersAlternating;
    *(void **)(node + 0x1a) = (void *)Ov107_RunChildHandlers;
    *(void **)(node + 0xc) = (void *)Ov107_BroadcastValueToChildren;
    *(void **)(node + 0x38) = (void *)Ov107_LinkChildNode;
    *(void **)(node + 0x3a) = (void *)Ov107_Region_UnlinkChild;
    List_Init(node + 0x22);
}
