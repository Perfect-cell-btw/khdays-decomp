/* Ov023_VmTickActor -- script VM command: re-run the actor whose index the operand names.
 * Actors are 0x104 bytes apart in the table at +0x128 of the VM state; the command ticks the
 * actor's +0x6c block (CamAnim_Release) and then its +0x30 block (Camera_Init). Always reports 1
 * (command finished). */
extern int ScriptVm_ReadOperandInt(void *vm, int);
extern void CamAnim_Release(int p);
extern void Camera_Init(int p);

int Ov023_VmTickActor(void *vm, int arg1) {
    int idx = ScriptVm_ReadOperandInt(vm, arg1);
    int off = (idx + idx * 64) * 4;
    CamAnim_Release(*(int *)((char *)vm + 0x128) + 0x6c + off);
    Camera_Init(*(int *)((char *)vm + 0x128) + 0x30 + off);
    return 1;
}
