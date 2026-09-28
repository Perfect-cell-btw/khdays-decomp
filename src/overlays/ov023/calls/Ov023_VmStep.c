/* Ov023_VmStep -- script VM command: run the ov023 step and report whether the command is
 * finished. Finished (1) only when the VM says so AND the flag byte at +0x4a4 of the VM state is
 * clear; if the flag is set the step runs a second time and the command stays alive (0).
 *
 * The two constant returns live OUT OF LINE at the end, which is what the ROM's `beq` to the tail
 * shows; written as plain `return 0;` inside the guard mwcc inlines it and the branch polarity
 * flips. `goto` labels after the body reproduce the layout. */
extern void Ov023_CmdShowCharacterPanel(int a, int b);
extern int Ov002_ScenePanel_IsState3(void);

int Ov023_VmStep(int a, int b) {
    Ov023_CmdShowCharacterPanel(a, b);
    if (Ov002_ScenePanel_IsState3() == 0) {
        goto ret0;
    }
    if (*(signed char *)(*(int *)(a + 0x128) + 0x4a4) == 0) {
        goto ret1;
    }
    Ov023_CmdShowCharacterPanel(a, b);
    goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
