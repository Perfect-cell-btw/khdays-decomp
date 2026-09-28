/* Script command: queues the kind-1 sound request with the operand. */

extern int ScriptVm_ReadOperandInt(void *, int);
extern void SoundMgr_QueueKind1(unsigned char);

int ScriptCmd_QueueSoundKind1(void *arg0, int arg1)
{
    SoundMgr_QueueKind1((unsigned char)ScriptVm_ReadOperandInt(arg0, arg1));
    return 0;
}
