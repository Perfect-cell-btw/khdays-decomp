/* Sweep all 0x18 slots: for each one the id resolver accepts, walk the object
 * list hanging off +0xc4 of its 0x184-byte record and retire every entry whose
 * kind byte at +0x2c is below 6. The next pointer is read BEFORE the callee runs,
 * because the callee may unlink the entry. */
extern int Ov002_GetCtxTableByte(int slot);
extern void Ov002_ReleaseSlotOwner(void *entry);

extern char *data_ov002_0207fa28;

void Ov002_RetireAllSlotEntries(void) {
    char *next;
    int i = 0;
    int offset = 0;

    for (; i < 0x18; i++) {
        if (Ov002_GetCtxTableByte(i) >= 0) {
            char *entry = *(char **)((&data_ov002_0207fa28)[1] + offset + 0xc4);

            if (entry != 0) {
                do {
                    next = *(char **)entry;

                    if (*(unsigned char *)(entry + 0x2c) < 6) {
                        Ov002_ReleaseSlotOwner(entry);
                    }
                    entry = next;
                } while (entry != 0);
            }
        }
        offset += 0x184;
    }
}
