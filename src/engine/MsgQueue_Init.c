/* Clears the four message queue slots and installs the receive dispatcher on channel 11. */

extern void StoreGlobalPtrArray4At0c(int a, void (*b)(void));
extern void MsgQueue_RecvDispatch(void);

struct Foo02030ccc {
    char _0[0x60];
    unsigned short arr[4];
};

extern struct Foo02030ccc *data_0204c22c;

void MsgQueue_Init(void)
{
    struct Foo02030ccc *p = data_0204c22c;
    int i;
    for (i = 0; i < 4; i++) {
        p->arr[i] = 0;
    }
    StoreGlobalPtrArray4At0c(11, MsgQueue_RecvDispatch);
}
