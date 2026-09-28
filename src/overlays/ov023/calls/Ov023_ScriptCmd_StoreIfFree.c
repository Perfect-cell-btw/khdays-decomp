extern int Ov023_Cmd_TestEntityCollisionBit();
extern int Slot48_StoreAtCurrentIndex();

int Ov023_ScriptCmd_StoreIfFree(int arg0, int arg1) {
    int r = Ov023_Cmd_TestEntityCollisionBit(arg0, arg1);
    if (r == 0) {
        Slot48_StoreAtCurrentIndex(arg0, arg1);
    }
    return r;
}
