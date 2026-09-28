/* Initialises a record node for one of its modes: runs the base init, marks it initialised, points
 * it at the mode's handler table and stores the two parameters. */

extern void Record_Init();
extern char data_02042910[];

int InitNodeAndStoreParamsMode2(int this_, int arg1, int arg2, int arg3, int arg4) {
    Record_Init(this_, arg1, arg2, arg3);
    *(unsigned char *)(this_ + 0x21) = 2;
    *(char **)(this_ + 0x1c) = data_02042910;
    *(int *)(this_ + 0x38) = arg3;
    *(int *)(this_ + 0x3c) = arg4;
    return 1;
}
