/* Per-frame update of a sequence node: tears the attached node down when needed (unless flag 0x10),
 * then advances its tracks unless paused (flags 0x20/0x40); returns the track result. */

extern void TeardownNodeIfBit0Set();
extern unsigned short Sequence_UpdateTracks();
unsigned int DetachThenApplyNode(int param_1, unsigned int *param_2, int param_3)
{
    unsigned int r = 0;
    if (param_1 != 0 && (*param_2 & 0x10) == 0)
        TeardownNodeIfBit0Set(**(int **)(param_1 + 4), param_2 + 0x44);
    if ((*param_2 & 0x20) == 0 && (*param_2 & 0x40) == 0)
        r = Sequence_UpdateTracks((unsigned short *)(param_2 + 1), param_3);
    return r;
}
