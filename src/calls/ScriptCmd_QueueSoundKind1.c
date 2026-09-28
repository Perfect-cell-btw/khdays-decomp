/* Script command: queues the kind-1 sound request with the operand. */

extern int ScriptVm_ReadOperandInt(void);
extern void SoundMgr_QueueKind1(unsigned char);

int ScriptCmd_QueueSoundKind1(void)
{
    SoundMgr_QueueKind1((unsigned char)ScriptVm_ReadOperandInt());
    return 0;
}
