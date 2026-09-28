void Ov025_SetState1IfIdle(char *obj) {
    if (*(int *)(obj + 0x158) == 0 && *(int *)(obj + 0x180) == 0) {
        *(int *)(obj + 8) = 1;
    }
}
