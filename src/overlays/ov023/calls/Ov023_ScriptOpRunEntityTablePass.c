extern void Ov023_ResetEntryTable(int table);
/* Script op: run the entity-table pass when the VM has one (*(vm+0x128))+0x440; always returns 1. */
int Ov023_ScriptOpRunEntityTablePass(int vm) {
    int table = *(int *)(*(int *)(vm + 0x128) + 0x440);
    if (table != 0) {
        Ov023_ResetEntryTable(table);
    }
    return 1;
}
