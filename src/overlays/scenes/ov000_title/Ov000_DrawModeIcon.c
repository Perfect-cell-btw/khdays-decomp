/* Draws the mode-dependent 2x2 icon on the sub-scene, wrapped in the object's begin/submit pair.
 *
 * Obj_InvokeInnerVtable4 is Obj_InvokeInnerVtable4 (dispatch through the inner object's vtable slot 4) and
 * EnqueueObjGfxCommand is EnqueueObjGfxCommand, so the body between them is one drawing pass: begin the
 * object, emit at most one item, submit.
 *
 * Modes 2 and 3 draw the SAME sprite id (0x8d) at the same 2x2 tile size and differ only in the
 * variant they resolve out of the object at +0x4bb8 (0 vs 1). Every other mode draws nothing at
 * all, yet still runs the begin/submit pair -- which is why the switch has no default rather than
 * an early return: the enqueue has to happen either way.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad_0000[0x4b04];
    u8 draw_object[0xb4];    /* +0x4b04 */
    u8 variant_source[1];    /* +0x4bb8 */
} Ov000SubSceneContext;

extern Ov000SubSceneContext *volatile data_ov000_0205ac28;
extern void Obj_InvokeInnerVtable4(void *object);
extern void *Ov000_GetVarRecordByIndex(void *object, int variant);
extern void Ov000_DrawWithShadow_2(void *object, int id, int width, int height,
                                void *variant, int enabled);
extern void EnqueueObjGfxCommand(void *object);

void Ov000_DrawModeIcon(int mode) {
    void *object = data_ov000_0205ac28->draw_object;

    Obj_InvokeInnerVtable4(object);
    switch (mode) {
    case 2:
        Ov000_DrawWithShadow_2(
            object, 0x8d, 2, 2,
            Ov000_GetVarRecordByIndex(data_ov000_0205ac28->variant_source, 0), 1);
        break;
    case 3:
        Ov000_DrawWithShadow_2(
            object, 0x8d, 2, 2,
            Ov000_GetVarRecordByIndex(data_ov000_0205ac28->variant_source, 1), 1);
        break;
    }
    EnqueueObjGfxCommand(object);
}
