/* Spawn a child object via CreateRegistryEntry (callbacks ov213_020d1c24 and ov213_020d1c90), link it
 * back to this object and store it at +0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *cb, void *cb2, int *out);
extern void Ov213_ThirdForm_AiTaskReleaseNoOp(int);
extern void Ov213_InitStateSlots(int);
void Ov213_ThirdForm_CreateAiTask(int param_1) {
    int obj;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x54, (void *)&Ov213_InitStateSlots,
                  (void *)&Ov213_ThirdForm_AiTaskReleaseNoOp, &obj);
    *(int *)obj = param_1;
    *(int *)(param_1 + 0x214) = obj;
}
