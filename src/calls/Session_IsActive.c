extern int *data_0204c228;

int Session_IsActive(void) {
    int *p = data_0204c228;
    if (p != 0 && *p != 1) {
        return 1;
    }
    return 0;
}
