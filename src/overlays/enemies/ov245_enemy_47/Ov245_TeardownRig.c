/* Ov245_TeardownRig -- tear down the object's rig: release the main handle at +0x384 and then
 * the first word of each of the two 8-byte slots at +0x3b8, before the base teardown.
 * The slot walk is `((Pair8 *)self)[i + 0x77].a` -- an 8-byte element with 0x3b8 / 8 = 0x77 folded
 * into the index, which is what produces the ROM's `add r0, self, i lsl #3 ; ldr [r0,#0x3b8]`. */
extern void DestroyInstance(int obj);
extern void Ov107_DestroyObject(int self);

typedef struct { int a, b; } Pair8;

void Ov245_TeardownRig(int self) {
    int i;
    DestroyInstance(*(int *)(self + 0x384));
    for (i = 0; i < 2; i++) {
        DestroyInstance(((Pair8 *)self)[i + 0x77].a);
    }
    Ov107_DestroyObject(self);
}
