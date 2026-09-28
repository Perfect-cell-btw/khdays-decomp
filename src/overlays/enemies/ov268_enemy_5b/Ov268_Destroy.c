/* Ov268_Destroy -- tear the object down: release its sub-objects, then the five entries of
 * the table at +0x40c (stride 8, so only the first word of each pair is an object), then the
 * table itself, and finally hand the object back. */

typedef struct {
    int obj;
    int reserved;
} Entry;

/* `table` is a real field, not `*(int *)(self + 0x40c)`: pointer arithmetic makes mwcc hoist a
 * partial base (`add r4,r5,#0xc`) out of the loop and address it as [r4,#0x400], where the ROM
 * just uses [r5,#0x40c] -- 0x40c fits an ldr offset, so the hoist buys nothing. Note it only does
 * this INSIDE the loop; the same expression outside compiles to [r5,#0x40c] either way. */
typedef struct {
    char reserved[0x40c];
    Entry *table;
} Obj;

extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int obj);
extern void Ov107_ActionResource_Destroy(int a);
extern void FreeInstanceMemory(int table);
extern void Ov107_DestroyObject(int self);

void Ov268_Destroy(int self) {
    int i;

    FreeAllResourceTables(self + 0x388);
    DestroyInstance(*(int *)(self + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x3ac));

    /* The stride is 8, so the table is an array of 8-byte entries; expressing it that way is what
     * keeps the ROM's scaled index (`ldr r0,[r0,r4,lsl #3]`). Byte-offset arithmetic gets
     * strength-reduced to a walking offset and drags the base out of the loop with it. */
    for (i = 0; i < 5; i++) {
        DestroyInstance(((Obj *)self)->table[i].obj);
    }

    FreeInstanceMemory((int)((Obj *)self)->table);
    Ov107_DestroyObject(self);
}
