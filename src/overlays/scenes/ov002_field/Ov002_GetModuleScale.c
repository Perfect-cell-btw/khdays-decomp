/* Return the Q12 scale at +0x64 of the ov002 module (data_ov002_0207fa20+4). Ov002_SceneEnter seeds
 * it to 0x1000, i.e. 1.0. */

extern int data_ov002_0207fa20;

int Ov002_GetModuleScale(void) {
    return *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + 0x64);
}
