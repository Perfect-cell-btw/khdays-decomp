/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov022_BuildResNodeSet. */
extern void *Ov022_BuildResNodeSet();

void *func_ov022_020b15a4(void *pReq, void *pSet) {
    return Ov022_BuildResNodeSet(pReq, pSet);
}
