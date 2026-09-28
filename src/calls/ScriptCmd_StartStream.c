extern int ScriptVm_ReadOperandInt(int a, void *b);
extern int SoundStrm_HasPlaybackPos(int a);
extern void StampByteAndInvokeSubStructAt(int a, int b);

int ScriptCmd_StartStream(int param_1, unsigned short *param_2) {
    int r = ScriptVm_ReadOperandInt(param_1, param_2);
    if (SoundStrm_HasPlaybackPos(0)) return 0;
    StampByteAndInvokeSubStructAt(0, r);
    return 1;
}
