/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to data_ov002_0207f62c. */
extern int data_ov002_0207f62c;

int func_ov002_0206373c(void) {
    return data_ov002_0207f62c;
}
