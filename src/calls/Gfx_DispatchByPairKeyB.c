/* Looks up the pair key in table B and calls handler index with the value. */

extern int LookupPairKey(void *ptr, unsigned short arg1, unsigned short arg2);
extern void (*data_02041eac[])(int value, int arg1, int arg2);
extern char data_02041de4;

void Gfx_DispatchByPairKeyB(int index, unsigned short *args, int arg1, int arg2) {
    int value = LookupPairKey(&data_02041de4, args[0], args[1]);

    data_02041eac[index](value, arg1, arg2);
}
