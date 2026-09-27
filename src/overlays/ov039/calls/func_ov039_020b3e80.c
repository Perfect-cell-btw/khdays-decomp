/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov039_020b4404. */
extern void *func_ov039_020b4404();

void *func_ov039_020b3e80() {
    return func_ov039_020b4404();
}
