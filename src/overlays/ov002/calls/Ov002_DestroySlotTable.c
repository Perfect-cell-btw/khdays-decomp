/* Tear the slot table down: stop id 0x1f, free the block at +0x5c, release each
 * of the 0x18 records at +0xb8 (stride 0x184), free the table itself and drop
 * the global. The pool ADDRESS is held across the loop while the pointer it
 * holds is re-read every iteration. */
extern void Ov002_List_ClearEntry(int id);
extern void NNSi_FndFreeFromDefaultHeap(void *block);
extern void Entity_Deactivate(void *record);

extern char *data_ov002_0207fa28;

void Ov002_DestroySlotTable(void) {
    int i;
    int offset;

    if ((&data_ov002_0207fa28)[1] == 0) {
        return;
    }

    Ov002_List_ClearEntry(0x1f);
    NNSi_FndFreeFromDefaultHeap(*(void **)((&data_ov002_0207fa28)[1] + 0x5c));

    i = 0;
    offset = 0;
    for (; i < 0x18; i++) {
        Entity_Deactivate((&data_ov002_0207fa28)[1] + 0xb8 + offset);
        offset += 0x184;
    }

    NNSi_FndFreeFromDefaultHeap((&data_ov002_0207fa28)[1]);
    (&data_ov002_0207fa28)[1] = 0;
}
