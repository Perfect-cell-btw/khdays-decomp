/* Pose sender: fills the pose's flag bytes on first send, then the base send. */

extern void Ov107_AiState_SendPose(int self, int node, int arg3);

void Ov146_SendPoseWithFlags(int self, int node, int arg3) {
    if (*(unsigned char *)(node + 2) == 0) {
        *(signed char *)(node + 0x24) =
            (signed char)((*(int *)(*(int *)(self + 0x384) + 0x5c) << 30) >> 31);
        *(signed char *)(node + 0x25) = *(int *)(self + 0x38c);
    }
    Ov107_AiState_SendPose(self, node, arg3);
}
