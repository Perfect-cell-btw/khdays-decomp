/* Ov002_RecreateObjectSlot -- (re)create slot `i` of the ov002 scene's object table (+0x1c of the root
 * context) and hand the new object to the shared registrar.
 *
 * The slot is stored and then RE-READ, and the re-read has to happen before the registrar's first
 * argument is computed -- that is the ROM's `str r0,[r5,r4] ; ldr r4,[r5,r4] ; bl`. Writing the
 * call as `f(*g(), slots[i])` lets mwcc sink the load past the `bl`; binding the FIRST argument to
 * its own local first pins the order. (This is the function state.md listed as "mwcc
 * rematerialises slots[idx] after the call where the ROM loads it before" -- it was an
 * evaluation-order problem, not a rematerialisation one.) */
extern int Ov107_Region_New(int i);
extern int *Ov107_GetActorManager(void);
extern void Ov107_InitObjectFromSource(int a, int b);
extern int data_ov002_0207fa14;

void Ov002_RecreateObjectSlot(int i) {
    int *slots = (int *)(*(int *)&data_ov002_0207fa14 + 0x1c);
    int v;
    slots[i] = Ov107_Region_New(i);
    v = slots[i];
    {
        int h = *Ov107_GetActorManager();
        Ov107_InitObjectFromSource(h, v);
    }
}
