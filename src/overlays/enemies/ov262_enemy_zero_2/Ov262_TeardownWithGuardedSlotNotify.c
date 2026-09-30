/* Destructor: when it still holds a grabbed spot object outside action 2, reports the spot as
 * reached; then frees the spot table, destroys the three models and the base object. */

extern void Ov015_SpotArrive(int a, int b, int c, int d);
extern void FreeInstanceMemory(int p);
extern void DestroyInstance(int p);
extern void Ov107_DestroyObject(int p);

void Ov262_TeardownWithGuardedSlotNotify(int this_) {
    if (*(int *)(this_ + 0x3a4) != 0 &&
        *(int *)(this_ + 0x3a8) != 0 &&
        *(signed char *)(this_ + 0x1c6) != 2 &&
        *(int *)(*(int *)(this_ + 0x3a0)) != 0) {
        int e = *(unsigned char *)(this_ + 0x3ad);
        int flag = 0;
        if ((unsigned short)*(int *)(*(int *)(this_ + 0x3a0) + e * 0x24 + 0x18) == 1)
            flag = 1;
        Ov015_SpotArrive(*(int *)(*(int *)(this_ + 0x3a0)), e, flag, 1);
    }
    if (*(int *)(this_ + 0x3a0) != 0) {
        FreeInstanceMemory(*(int *)(this_ + 0x3a0));
    }
    DestroyInstance(*(int *)(this_ + 0x384));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x38c));
    Ov107_DestroyObject(this_);
}
