extern int Script_EvalExpr();
int CommitRecordCursor(int param_1, int *param_2)
{
    int entry = param_1 + 4 + *(int *)(param_1 + 0x124) * 0x48;
    int r = Script_EvalExpr(param_1, (short *)(*(int *)(entry + 0x14) + *param_2));
    if (*(int *)(r + 4) == 0) {
        *(int *)(entry + 0x10) = *(int *)(entry + 0xc) + param_2[1];
        return 2;
    }
    return 1;
}
