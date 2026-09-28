/* Stores the draw parameters of sub-object entry idx and dispatches its draw. */

extern void SubObject_DispatchDraw(void *ptr, int index);

void SubObject_SetDrawParams(unsigned char *ptr, int index, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    unsigned char *entry = ptr + index * 0x18;

    *(int *)(entry + 0x18) = arg2;
    *(int *)(entry + 0x1c) = arg3 << 1;
    *(int *)(entry + 0x20) = arg4;
    *(int *)(entry + 0x24) = arg5;
    *(int *)(entry + 0x28) = arg6;
    *(int *)(entry + 0x2c) = arg7;
    SubObject_DispatchDraw(ptr, index);
}
