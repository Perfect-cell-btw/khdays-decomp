/* Clears the world's target slot. */

extern int data_ov002_0207fa00;

void Ov002_World_ClearTarget(void) {
    int base = *(int *)&data_ov002_0207fa00 + 0x8d64;
    *(char *)(base + 4) = -1;
    *(int *)base = -1;
}
