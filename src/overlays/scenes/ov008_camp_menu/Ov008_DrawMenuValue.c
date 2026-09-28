/* Ov008_DrawMenuValue -- Ov008_DrawMenuValue (184 B, 9 relocs).
 * Draws a computed value onto the menu surface at arg0+0x4c. Bails if arg0 is null or if
 * Ov008_GetWordAt0x4a70 (fed the Ov008_GetContext context) returns null. Reads a value via
 * Ov008_MapMenuObjectTypeToIcon(obj->fieldC); when it is >= 0 it is stored (u16) to arg0->field5c4. When
 * cue 0x200c is active (GameState_IsFlagSet) the value is replaced by 0x20 if Ov008_IsSessionReady()
 * reports idle, else -1; a negative value aborts the draw. Otherwise it builds a cell from the
 * value (Ov008_GetVarRecordByIndex on arg0+4) and renders it onto the surface
 * (Obj_InvokeInnerVtable4 / Text_DrawWithShadow(.., 0x56, 0, 2, cell, 1) / EnqueueObjGfxCommand). */
typedef unsigned short u16;

extern void *Ov008_GetContext(void);
extern void *Ov008_GetWordAt0x4a70(void *ctx);
extern int   Ov008_MapMenuObjectTypeToIcon(int a);
extern int   GameState_IsFlagSet(int flag);
extern int   Ov008_IsSessionReady(void);
extern int   Ov008_GetVarRecordByIndex(void *p, int v);
extern void  Obj_InvokeInnerVtable4(void *surface);
extern void  Text_DrawWithShadow(void *surface, int a, int b, int c, int d, int e);
extern void  EnqueueObjGfxCommand(void *surface);

void Ov008_DrawMenuValue(void *arg0)
{
    char *p = (char *)arg0;
    void *ctx = Ov008_GetContext();
    void *obj;
    int r4;

    if (p == 0) {
        return;
    }
    obj = Ov008_GetWordAt0x4a70(ctx);
    if (obj == 0) {
        return;
    }
    r4 = Ov008_MapMenuObjectTypeToIcon(*(int *)((char *)obj + 0xc));
    if (r4 >= 0) {
        *(u16 *)(p + 0x5c4) = r4;
    }
    if (GameState_IsFlagSet(0x200c) != 0) {
        r4 = (Ov008_IsSessionReady() == 0) ? 0x20 : -1;
    }
    if (r4 < 0) {
        return;
    }
    r4 = Ov008_GetVarRecordByIndex(p + 4, r4);
    Obj_InvokeInnerVtable4(p + 0x4c);
    Text_DrawWithShadow(p + 0x4c, 0x56, 0, 2, r4, 1);
    EnqueueObjGfxCommand(p + 0x4c);
}
