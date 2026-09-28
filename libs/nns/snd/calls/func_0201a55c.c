/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to ShutdownPlayer. */
extern void *ShutdownPlayer();

void *func_0201a55c(void *seqPlayer) {
    return ShutdownPlayer(seqPlayer);
}
