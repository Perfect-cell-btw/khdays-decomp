/* Instantiate the ov014 object: allocate class 0x70 (0x138 bytes) on the given
 * owner, copy the descriptor's 0x10-byte name into +0x58, carry its two extra
 * words to +0x68/+0x6c, then fill the handler table at +0x8..+0x2c and +0x3c
 * with this overlay's entry points and set the type tag at +0x4c to 0x12. */
extern void *Ov002_CreateEntryPool(int cls, int size, int owner);
extern char *strncpy(char *dst, const char *src, unsigned int n);

extern void Ov014_OnMessage(void);
extern void Ov014_InstanceHookNoOp(void);
extern void Ov014_InstanceHookNoOp_2(void);
extern void Ov014_ForwardIfSubFieldNonZero(void);
extern void Ov014_Element_Refresh(void);
extern void Ov014_OnTouch(void);
extern void Ov014_GetNodeIfFlag8(void);
extern void Ov014_GetOwnerIfFlag8(void);
extern void Ov014_AddrOfField0x1C(void);
extern void Ov014_InstanceHookNoOp_3(void);

void *Ov014_Instantiate(int owner, int *desc) {
    char *self = (char *)Ov002_CreateEntryPool(0x70, 0x70 + 0xc8, owner);

    strncpy(self + 0x58, (const char *)desc[0], 0x10);
    *(int *)(self + 0x68) = desc[1];
    *(int *)(self + 0x6c) = desc[2];

    *(int *)(self + 0x00) = 0;
    *(int *)(self + 0x04) = 0;
    *(void **)(self + 0x08) = (void *)&Ov014_OnMessage;
    *(void **)(self + 0x0c) = (void *)&Ov014_InstanceHookNoOp;
    *(void **)(self + 0x10) = (void *)&Ov014_InstanceHookNoOp_2;
    *(void **)(self + 0x14) = (void *)&Ov014_ForwardIfSubFieldNonZero;
    *(void **)(self + 0x18) = (void *)&Ov014_Element_Refresh;
    *(int *)(self + 0x1c) = 0;
    *(void **)(self + 0x20) = (void *)&Ov014_OnTouch;
    *(void **)(self + 0x24) = (void *)&Ov014_GetNodeIfFlag8;
    *(void **)(self + 0x28) = (void *)&Ov014_GetOwnerIfFlag8;
    *(void **)(self + 0x2c) = (void *)&Ov014_AddrOfField0x1C;
    *(int *)(self + 0x38) = 0;
    *(int *)(self + 0x44) = 0;
    *(void **)(self + 0x3c) = (void *)&Ov014_InstanceHookNoOp_3;
    *(unsigned short *)(self + 0x4c) = 0x12;

    return self;
}
