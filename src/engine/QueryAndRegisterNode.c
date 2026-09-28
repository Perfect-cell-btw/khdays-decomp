extern int ScriptVm_ReadOperandInt(int obj, void *key);
extern void *ByteCode_ResolveOperand(int obj, void *key);
extern void *Msg_OpenContainerAndReadHeader(void *res, int type);

int QueryAndRegisterNode(int obj, unsigned short *keys, int arg3, int arg4) {
    int idx = ScriptVm_ReadOperandInt(obj, keys);
    void *res = ByteCode_ResolveOperand(obj, keys + 4);
    void *node = Msg_OpenContainerAndReadHeader(res, 0xf);
    *(void **)(*(int *)(obj + 0x128) + idx * 4 + 0x48c) = node;
    return 1;
}
