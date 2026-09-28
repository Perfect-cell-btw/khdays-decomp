/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov024_MobiClip_Alloc. */
extern void *Ov024_MobiClip_Alloc();

void *func_ov024_02085e3c() {
    return Ov024_MobiClip_Alloc();
}
