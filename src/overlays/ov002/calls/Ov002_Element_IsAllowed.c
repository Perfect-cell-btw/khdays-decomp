extern int Ov002_GetRootField8b68();

int Ov002_Element_IsAllowed(int arg0, int arg1) {
    if (*(signed char *)(*(int *)(arg0 + 8) + 0x7e) == 1) {
        return 1;
    }
    return Ov002_GetRootField8b68(arg1) == 0;
}
