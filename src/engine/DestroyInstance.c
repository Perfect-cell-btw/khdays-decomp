/* Destroys an instance: drops its class's reference count, runs its destructor (+0x64) when it has
 * one, counts it out and frees it. */

extern int data_0204caa8;
extern void FreeInstanceMemory(int obj);

void DestroyInstance(int *param_1) {
    void (*dtor)(int *);
    int cls = *param_1;
    if (cls != 0) {
        unsigned char rc = *(unsigned char *)(cls + 0x60);
        if (rc != 0) *(unsigned char *)(cls + 0x60) = rc - 1;
    }
    dtor = (void (*)(int *))param_1[0x19];
    if (dtor != 0) dtor(param_1);
    data_0204caa8 = data_0204caa8 - 1;
    FreeInstanceMemory((int)param_1);
}
