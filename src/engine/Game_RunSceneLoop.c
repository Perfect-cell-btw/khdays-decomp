/* Run one scene to completion: blank both engines, hand control to the ov105
 * per-frame driver until Game_PollSceneAlive says to stop, then restore the
 * displays and report the outcome.
 *
 * Two codegen facts this function pins down, both worth reusing:
 *
 * 1. A switch's dispatch COMPARES are emitted in value order (0, 1, 3) but the
 *    case BODIES are laid out in SOURCE order.  The ROM puts case 1's body
 *    before case 0's, so the source lists case 1 first -- writing them in
 *    numeric order compiles to the same size with the two blocks swapped.
 *
 * 2. `packed = a() << 16; packed |= b();` is not the same as
 *    `packed = (a() << 16) | b();`.  The ROM shifts the first result
 *    immediately (lsls r4,r0,#0x10 right after the bl); the single-expression
 *    form makes mwcc hold the value and shift later, costing two instructions.
 *
 * The `lsls r2, r0, #0x10` at the top is mwcc deriving 0x04000000 from the
 * 0x05000400 it already has in a register -- one pool entry doing double duty,
 * not a second address.
 *
 * The DISPCNT masks clear bits 8-12 (the four BG layers and OBJ) on both
 * engines; the closing GXx_SetMasterBrightness_ pair drives both MASTER_BRIGHT
 * registers to 0x10. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Gfx_Reset2DEngines(void);
extern void Res_TearDownBlock(void);
extern int Game_PollSceneAlive(void);              /* Game_PollSceneAlive */
extern void Ov105_RunScriptedStepState3(void);
extern void Ov105_WH_Finalize(void);
extern void GXx_SetMasterBrightness_(unsigned int reg, int value);
extern unsigned short Ov105_GetState(void);
extern unsigned short Ov105_GetStatusLow(void);
extern void func_0202362c(int a);
extern void func_02003948(unsigned int a);

void Game_RunSceneLoop(void) {
    int running;
    unsigned int packed;

    NNSi_FndGetCurrentRootHeap();
    *(unsigned short *)0x05000000 = 0;
    *(unsigned short *)0x05000400 = 0;
    *(unsigned int *)0x04000000 = *(unsigned int *)0x04000000 & 0xffffe0ff;
    *(unsigned int *)0x04001000 = *(unsigned int *)0x04001000 & 0xffffe0ff;
    Gfx_Reset2DEngines();
    Res_TearDownBlock();
    if (Game_PollSceneAlive() != 0) {
        running = 1;
        do {
            switch (Game_PollSceneAlive()) {
            case 1:
                Ov105_RunScriptedStepState3();
                break;
            case 0:
                running = 0;
                break;
            case 3:
                break;
            default:
                Ov105_WH_Finalize();
                break;
            }
        } while (running != 0);
    }
    GXx_SetMasterBrightness_(0x400006c, 0x10);
    GXx_SetMasterBrightness_(0x400106c, 0x10);
    packed = Ov105_GetState() << 16;
    packed |= Ov105_GetStatusLow();
    func_0202362c(0);
    func_02003948(packed | 0x80000000);
}
