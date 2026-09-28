/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_ScrollList_Confirm. */
extern void *Ov025_ScrollList_Confirm();

void *func_ov025_020aebbc(void *pList) {
    return Ov025_ScrollList_Confirm(pList);
}
