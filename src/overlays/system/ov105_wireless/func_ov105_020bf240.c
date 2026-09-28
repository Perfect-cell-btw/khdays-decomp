/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov105_WM_GetLinkLevel. */
extern void *Ov105_WM_GetLinkLevel();

void *func_ov105_020bf240() {
    return Ov105_WM_GetLinkLevel();
}
