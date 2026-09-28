/* Looks up the pair key in table A and calls handler index with the value. */

extern int LookupPairKey(void *ptr, int arg1, int arg2);
extern void (*data_02041e2c[])(int value, int arg1, int arg2);
extern char data_02041dfc;

void Gfx_DispatchByPairKeyA(int index, unsigned short *args, int arg1, int arg2) {
    int value = LookupPairKey(&data_02041dfc, args[0], args[1]);

    data_02041e2c[index](value, arg1, arg2);
}
