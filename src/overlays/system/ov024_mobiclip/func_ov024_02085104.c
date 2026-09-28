/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to WM_EndKeySharing_0x02083d00. */
extern void *func_ov024_02083d00();

void *func_ov024_02085104() {
    return func_ov024_02083d00();
}
