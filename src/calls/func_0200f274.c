/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_02046d40. */
extern int data_02046d40;

int func_0200f274(void) {
    return data_02046d40;
}
