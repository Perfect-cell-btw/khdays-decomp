extern int ScriptVm_ReadOperandInt(int a, char *b);
extern void Ov002_DispatchHudCounterCommand(int a, int b, int c);
extern int LoadGlobalPtr4FieldDcOrZero(void);
extern void StoreToGlobalPtr4FieldDcIfSet(int a);

/* Registers the three sub-emitters of a field effect and starts it. */
int Ov002_StartFieldEffect(int scene, char *desc) {
    int a = ScriptVm_ReadOperandInt(scene, desc);
    int b = ScriptVm_ReadOperandInt(scene, desc + 8);
    Ov002_DispatchHudCounterCommand(a, b, ScriptVm_ReadOperandInt(scene, desc + 0x10));
    if (LoadGlobalPtr4FieldDcOrZero() == 0) {
        StoreToGlobalPtr4FieldDcIfSet(1);
    }
    return 1;
}
