/* Class pfnCtor: builds the object, loads its archive file unless disabled, requests voice ids
 * 0x51/0xd2 and returns the decoder step. */

extern char *NNSi_FndGetCurrentRootHeap(void);
extern unsigned char data_0204c240;
extern void *data_ov087_020b9b3c;
extern void Ov087_Boot(void *);
extern void *Archive_LoadFile(void *, int);
extern void Resource_BindFileToSlot(void *, int, void *, int);
extern void Ov087_InitEffectSlots(void *);
extern void Ov022_RequestVoiceIds(void *, int, int);
extern void Ov022_ArmDecoder(void);

void *Ov087_ClassCtor(void *a)
{
    char *r = NNSi_FndGetCurrentRootHeap();
    *(void **)(r + 0x2c50) = 0;
    Ov087_Boot(a);
    if (!(data_0204c240 & 4)) {
        void *p = Archive_LoadFile(&data_ov087_020b9b3c, *(int *)a + 7);
        *(void **)(r + 0x2c50) = p;
        Resource_BindFileToSlot(r + 0x2c2c, *(int *)(r + 0x20) + 4, *(void **)(r + 0x2c50), *(int *)a + 7);
    }
    Ov087_InitEffectSlots(r);
    Ov022_RequestVoiceIds(r, 0x51, 0xd2);
    return (void *)Ov022_ArmDecoder;
}
