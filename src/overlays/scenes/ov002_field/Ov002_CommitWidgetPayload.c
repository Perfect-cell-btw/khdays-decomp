/* Commit the widget's payload into the live layout, then release it. Without a
 * layout installed the release still happens, but flagged so the caller knows
 * the payload went nowhere. */
/* The payload is loaded ONCE and reused as the commit argument -- a second field
 * read after the store emits a redundant ldr the ROM does not have. */
extern void Ov002_DestroyOwnedEntry(void *widget, int dropped);
extern void GetResourceSubBlock_CHAR(void *payload, void *slot);

typedef struct {
    char pad0000[8];
    void *pPayload;         /* +8 */
} Ov002Widget;

typedef struct {
    char pad0000[0x14];
    void *pPayload;         /* +0x14 */
    char slot[1];           /* +0x18 */
} Ov002LayoutContext;

extern Ov002LayoutContext *data_ov002_0207f638;

void Ov002_CommitWidgetPayload(Ov002Widget *widget) {
    Ov002LayoutContext *layout = data_ov002_0207f638;
    void *payload;

    if (layout == 0) {
        Ov002_DestroyOwnedEntry(widget, 1);
        return;
    }

    payload = widget->pPayload;
    layout->pPayload = payload;
    GetResourceSubBlock_CHAR(payload, layout->slot);
    Ov002_DestroyOwnedEntry(widget, 0);
}
