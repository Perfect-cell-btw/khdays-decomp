/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to SlotTable_AddEntry. */
extern void *SlotTable_AddEntry();

void *func_02032444() {
    return SlotTable_AddEntry();
}
