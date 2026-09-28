/* Advances the child model's animation tracks and marks the task finished when they end. */

extern unsigned short Sequence_UpdateTracks(int arg0, int arg1);
extern void Task_MarkFinished(void *node);

void Ov253_NotifyIfQueryBit0Set(int *node) {
    if ((Sequence_UpdateTracks(*(int *)(*(int *)(node[1] + 4) + 0x88), *(int *)(*node + 0x2c) * 0x1e) & 1) != 0) {
        Task_MarkFinished(node);
    }
}
