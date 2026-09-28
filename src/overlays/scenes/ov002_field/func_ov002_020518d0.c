/* Releases the service instance held at data_ov002_0207f600 + 4. */

extern int data_ov002_0207f600;
extern int func_02023ad0();

int func_ov002_020518d0(void) {
    return func_02023ad0(*(int *)((char *)&data_ov002_0207f600 + 4));
}
