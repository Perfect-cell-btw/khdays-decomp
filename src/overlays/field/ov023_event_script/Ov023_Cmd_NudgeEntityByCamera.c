extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(int index);
extern void BindAnimTrack(void *dst, int kind, void *src, short value);

extern int Ov002_ScenePanel_IsState3(void);
extern int Ov002_ScenePanel_IsState4(void);
extern int Ov002_GetPanelField018c(void);
extern void Ov023_SetScriptSlotWord(int a, int b);

/* Script command: nudges the entity node by the per-axis operands that the current camera mode
 * actually uses, then refreshes both HUD panels. */
int Ov023_Cmd_NudgeEntityByCamera(int ctx, char *args) {
    char *node;
    int id = func_02020d10(ctx, ScriptVm_ReadOperandInt(ctx, args));
    if (id != 0x40) {
        node = ArrayEntryPtrD0((unsigned short)id);
        if (Ov002_ScenePanel_IsState3() != 0) {
            BindAnimTrack(node + 4, 3, node + 0xe4, (short)ScriptVm_ReadOperandInt(ctx, args + 8));
        }
        if (Ov002_ScenePanel_IsState4() != 0) {
            BindAnimTrack(node + 4, 3, node + 0xe4, (short)ScriptVm_ReadOperandInt(ctx, args + 0x10));
        }
    }
    if (Ov002_GetPanelField018c() != 0) {
        if (id != 0x40) {
            BindAnimTrack(node + 4, 3, node + 0xe4, (short)ScriptVm_ReadOperandInt(ctx, args + 0x10));
        }
        Ov023_SetScriptSlotWord(0, 0);
        Ov023_SetScriptSlotWord(0, 1);
        return 1;
    }
    return 0;
}
