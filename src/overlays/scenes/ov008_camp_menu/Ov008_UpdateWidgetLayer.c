/* Ov008_UpdateWidgetLayer -- per-frame update for a scene's widget layer.
 * Runs Ov008_ProcessAllListNodes first, then unless bit 2 of +0x4a6c suppresses it, re-projects the
 * anchor at +0x4a54 and feeds the Q12 result (>> 12) to ClampToRange0to16At0x4628.
 * Bit 0 of +0x4a7c enables the hit/selection pass (Ov008_RouteNewPressToWidget); if that found nothing
 * and bit 1 is set, Ov008_MoveFocusByDpad handles the fallback, otherwise the field at +0x4a78 is
 * parked at 0xf0 (off-screen).
 * Finally the layer is committed through DispObjList_UpdateImmediate or DispObjList_UpdateQueued depending on `flag`. */

typedef struct {
    char pad[0x4a54];
    int f4a54;
    char pad2[0x4a6c - 0x4a58];
    unsigned int b4a6c_0 : 2;
    unsigned int b4a6c_2 : 1;
    unsigned int b4a6c_rest : 29;
    char pad3[0x4a78 - 0x4a70];
    unsigned short f4a78;
    unsigned short pad4;
    unsigned int b4a7c_0 : 1;
    unsigned int b4a7c_1 : 1;
    unsigned int b4a7c_rest : 30;
} Obj;

extern void Ov008_ProcessAllListNodes(Obj *o);
extern void Tween_Sample(int *anchor, int *out);
extern void ClampToRange0to16At0x4628(Obj *o, int v);
extern int Ov008_RouteNewPressToWidget(Obj *o);
extern void Ov008_MoveFocusByDpad(Obj *o, int p);
extern void DispObjList_UpdateImmediate(Obj *o);
extern void DispObjList_UpdateQueued(Obj *o);

void Ov008_UpdateWidgetLayer(Obj *o, int p, int flag) {
    int v;
    int sel;

    sel = 0;
    v = 0;
    Ov008_ProcessAllListNodes(o);
    if (!o->b4a6c_2) {
        Tween_Sample(&o->f4a54, &v);
        ClampToRange0to16At0x4628(o, v >> 12);
    }
    if (o->b4a7c_0) {
        sel = Ov008_RouteNewPressToWidget(o);
    }
    if (sel == 0 && o->b4a7c_1) {
        Ov008_MoveFocusByDpad(o, p);
    } else {
        o->f4a78 = 0xf0;
    }
    if (flag != 0) {
        DispObjList_UpdateImmediate(o);
    } else {
        DispObjList_UpdateQueued(o);
    }
}
