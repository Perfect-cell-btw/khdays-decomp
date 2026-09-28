/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Text_VSNPrintf_2. */
extern void *Text_VSNPrintf_2();

void *Text_VSNPrintf() {
    return Text_VSNPrintf_2();
}
