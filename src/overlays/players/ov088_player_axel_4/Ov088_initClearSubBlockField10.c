/* Binds the character's rig and clears the active word of its two sub-objects. */

extern void Ov088_BindRig(int a);

void Ov088_initClearSubBlockField10(int param_1, int param_2) {
    int i;
    Ov088_BindRig(param_1);
    i = 0;
    do {
        i++;
        *(int *)(param_2 + 0x10) = 0;
        param_2 += 0x118;
    } while (i < 2);
}
