/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_TeardownOrInit. */
extern void *Ov025_TeardownOrInit();

void *func_ov025_020ad7ac(int arg0) {
    return Ov025_TeardownOrInit(arg0);
}
