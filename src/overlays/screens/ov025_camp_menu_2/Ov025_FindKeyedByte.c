/* Looks the key up in the five keyed records after the first one and returns that record's byte
 * value (+8), or 0 when absent. */

struct S {
    int key;
    char _pad[4];
    int b8;
    char _pad2[0xdc - 0xc];
};

int Ov025_FindKeyedByte(int a, struct S *p) {
    int i;
    int ret = 0;
    for (i = 0; i < 5; i++) {
        if (a == p[i + 1].key) {
            ret = p[i + 1].b8 & 0xff;
            break;
        }
    }
    return ret;
}
