/* BootTask_Construct: constructor of g_BootTaskClassDesc (run by RunClassConstructor).
 * Inits subsystems, then selects the first scene from the persisted state word @0x027ffc20:
 * 0 (fresh boot) -> Scene 1 (boot/logo); -2 -> Scene 1; else -> Scene 12. The scene request
 * is latched by StoreGlobalPairAt10 (StoreGlobalPairAt10). Returns the boot task's initial
 * per-frame state fn (Scene_StepAndContinue), stored by the caller into obj+0x14.
 *
 * The 4 bytes that kept this parked were the second branch pair: the ROM emits
 * `beq c ; b d` and every if/goto spelling of the chain gave mwcc's `bne d ; b c`.
 * `beq X ; beq Y ; b Z` is the SWITCH compare-chain shape, not an if-chain shape -- so this
 * wants a switch. The old note rejected the switch for the right reason and the wrong
 * conclusion: mwcc orders a switch's compare chain NUMERICALLY, so with `case 0` and
 * `case -2` on a SIGNED selector it tests -2 first, which is backwards. Read the selector
 * as UNSIGNED and the same two cases become 0 and 0xfffffffe, so 0 is tested first and the
 * chain comes out in the ROM's order. The numeric ordering is not an obstacle -- it is the
 * knob. */
extern void FileLoader_Init(void);
extern void SoundSys_Start(int a);
extern void FSi_BindCardTransfer(int a);
extern void Scene_ClearPending(void);
extern void StoreGlobalPairAt10();
extern int Scene_StepAndContinue(void);

void *Boot_InitScene(void) {
    unsigned int state;
    FileLoader_Init();
    SoundSys_Start(0);
    FSi_BindCardTransfer(0);
    Scene_ClearPending();
    state = *(unsigned int *)0x027ffc20;
    switch (state) {
    case 0:
        StoreGlobalPairAt10(1, 0);
        break;
    case 0xfffffffeu:
        StoreGlobalPairAt10(1, state);
        break;
    default:
        StoreGlobalPairAt10(0xc, state);
        break;
    }
    return (void *)Scene_StepAndContinue;
}
