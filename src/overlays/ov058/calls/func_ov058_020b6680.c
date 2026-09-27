/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov058_020b6c04. */
extern void *func_ov058_020b6c04();

void *func_ov058_020b6680() {
    return func_ov058_020b6c04();
}
