/* ScriptCmd_RequestKind3 -- script VM command: read the operand, arm the "waiting" flag at data_020425e8
 * (-1 = waiting) and hand the operand to RequestQueue_SetOrPushKind3. Always reports 1 (finished).
 * The flag's address doubles as the call's second argument, which is why the ROM sets it up once. */
extern int ScriptVm_ReadOperandInt(void *vm, void *op);
extern void RequestQueue_SetOrPushKind3(int a, void *b);
extern char data_020425e8;

int ScriptCmd_RequestKind3(void *vm, void *op) {
    int r = ScriptVm_ReadOperandInt(vm, op);
    data_020425e8 = -1;
    RequestQueue_SetOrPushKind3(r, &data_020425e8);
    return 1;
}
