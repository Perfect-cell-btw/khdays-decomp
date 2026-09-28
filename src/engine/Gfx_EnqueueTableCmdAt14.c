/* Enqueues command table[idx] with the object's +0x14 data. */

extern int GFXi_EnqueueCommand(void *a, int b, int c, int d);
extern void *data_02041f8c[];

int Gfx_EnqueueTableCmdAt14(int idx, void *p, int arg2, int arg3) {
    return GFXi_EnqueueCommand(data_02041f8c[idx], arg2, *(int *)((char *)p + 0x14), arg3);
}
