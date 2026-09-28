/* Ov023_ReleaseArmedSlots -- release every armed slot of the ov023 scene.
 * After the shared teardown (Ov002_ResetViewToDefault), walk the five 0x30-byte slots of the scene
 * object (data_ov023_0208a784[1]) and hand each one whose handle at +0xf0 is set to
 * Ov002_ResourceNodeCallback. The +0xf0 handle is indexed with a 4-byte stride and the slot itself with
 * 0x30, so they are two parallel tables, not one struct. */
extern void Ov002_ResetViewToDefault(void);
extern int Ov002_ResourceNodeCallback(int slot);
extern int data_ov023_0208a784;

void Ov023_ReleaseArmedSlots(void) {
    int i;
    int off;
    int step;
    int base;

    Ov002_ResetViewToDefault();
    i = 0;
    off = 0;
    step = 0;
    do {
        base = *(int *)((char *)&data_ov023_0208a784 + 4);
        if (*(int *)(base + off + 0xf0) != 0) {
            Ov002_ResourceNodeCallback(base + step);
        }
        i = i + 1;
        off = off + 4;
        step = step + 0x30;
    } while (i < 5);
}
