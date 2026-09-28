/* Creates the ov014 element pool from its parameters and installs its handler table. */

typedef struct {
    int nField00;
    int nField04;
    signed char bField08;
    char pad09;
    short nField0a;
    short nField0c;
    short nField0e;
    int nField10;
    int nField14;
    int nField18;
    unsigned char bField1c;
} Ov014Params;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *dst, const char *src, unsigned int n);

extern void Ov014_PoolHookNoOp(void);
extern void Ov014_HandleCounterMessage(void);
extern void Ov014_tailDispatch_2(void);
extern void Ov014_ActorRebindModel(void);
extern void Ov014_tailDispatch(void);
extern void Ov014_ActorBindModel(void);
extern void Ov014_TryRecordHit(void);
extern void Ov014_GetField1cIfQueryBit1Set(void);
extern void Ov014_GetSubField68IfQueryBit1(void);
extern void Ov014_AddrOfField0xE0(void);
extern void Ov014_DispatchTouchAction(void);

void *Ov014_CreatePool(int nCount, Ov014Params *params) {
    char *self = (char *)Ov002_CreateEntryPool(0x84, 0x1d4, nCount);

    strncpy(self + 0x58, (const char *)params->nField00, 0x10);
    *(int *)(self + 0x68) = params->nField04;
    *(signed char *)(self + 0x6c) = params->bField08;
    *(short *)(self + 0x6e) = params->nField0a;
    *(short *)(self + 0x70) = params->nField0c;
    *(short *)(self + 0x72) = params->nField0e;
    *(int *)(self + 0x74) = params->nField10;
    *(int *)(self + 0x78) = params->nField14;
    *(int *)(self + 0x7c) = params->nField18;
    *(unsigned char *)(self + 0x80) = params->bField1c;

    *(int *)(self + 0x00) = 0;
    *(void **)(self + 0x04) = (void *)&Ov014_PoolHookNoOp;
    *(void **)(self + 0x08) = (void *)&Ov014_HandleCounterMessage;
    *(void **)(self + 0x0c) = (void *)&Ov014_tailDispatch_2;
    *(void **)(self + 0x10) = (void *)&Ov014_ActorRebindModel;
    *(void **)(self + 0x14) = (void *)&Ov014_tailDispatch;
    *(void **)(self + 0x18) = (void *)&Ov014_ActorBindModel;
    *(void **)(self + 0x1c) = (void *)&Ov014_TryRecordHit;
    *(int *)(self + 0x20) = 0;
    *(void **)(self + 0x24) = (void *)&Ov014_GetField1cIfQueryBit1Set;
    *(void **)(self + 0x28) = (void *)&Ov014_GetSubField68IfQueryBit1;
    *(void **)(self + 0x2c) = (void *)&Ov014_AddrOfField0xE0;
    *(int *)(self + 0x38) = 0;
    *(int *)(self + 0x44) = 0;
    *(void **)(self + 0x3c) = (void *)&Ov014_DispatchTouchAction;
    *(unsigned short *)(self + 0x4c) = 7;

    return self;
}
