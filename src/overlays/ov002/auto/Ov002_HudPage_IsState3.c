/* True when the HUD page state (+0x28) is 3. */

extern int data_ov002_0207f9fc;

int Ov002_HudPage_IsState3(void) {
    return *(int *)(*(int *)&data_ov002_0207f9fc + 0x28) == 3;
}
