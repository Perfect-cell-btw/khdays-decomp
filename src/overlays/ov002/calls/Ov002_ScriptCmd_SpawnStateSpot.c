/* Resolve four consecutive 8-byte descriptors and hand the results to
 * Ov002_SpawnStateSpots. The first two go through ScriptVm_ReadOperandInt, the last two
 * through ByteCode_ResolveOperand -- the split is deliberate, not a transcription slip.
 * Same shape as Ov002_ResolveFourDescriptors, which uses ScriptVm_ReadOperandInt for all
 * four. Always reports success. */
extern int ScriptVm_ReadOperandInt(void *self, void *desc);
extern int ByteCode_ResolveOperand(void *self, void *desc);
extern void Ov002_SpawnStateSpots(int a, int b, int c, int d);

int Ov002_ScriptCmd_SpawnStateSpot(void *self, char *descs) {
    int a = ScriptVm_ReadOperandInt(self, descs);
    int b = ScriptVm_ReadOperandInt(self, descs + 8);
    int c = ByteCode_ResolveOperand(self, descs + 0x10);
    int d = ByteCode_ResolveOperand(self, descs + 0x18);

    Ov002_SpawnStateSpots(a, b, c, d);
    return 1;
}
