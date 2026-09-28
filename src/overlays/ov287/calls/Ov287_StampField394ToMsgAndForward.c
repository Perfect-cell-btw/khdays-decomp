extern void *Ov107_AiState_SendPose();

void *Ov287_StampField394ToMsgAndForward(int this_, unsigned char *msg, int arg3) {
    if (msg[2] == 0) {
        msg[0x24] = *(int *)(this_ + 0x394);
    }
    return Ov107_AiState_SendPose(this_, msg, arg3);
}
