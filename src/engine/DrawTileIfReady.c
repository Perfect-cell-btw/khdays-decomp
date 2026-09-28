/* When the node system is active and the tile is idle, appends the tile's cell to the channel
 * buffer (flagged for kinds 1 and 4). */

extern int IsKind1Or4();
extern void ChannelBuf_Append();
extern int data_0204c22c;
void DrawTileIfReady(int param_1)
{
    int v;
    if (data_0204c22c == 0)
        return;
    if (*(unsigned short *)(param_1 + 2) != 0)
        return;
    if (*(unsigned short **)(param_1 + 0xc) == 0)
        return;
    v = IsKind1Or4(((unsigned int)**(unsigned short **)(param_1 + 0xc) << 0x1a) >> 0x1b);
    ChannelBuf_Append(*(int *)(param_1 + 0xc), (unsigned int)*(unsigned short *)(param_1 + 0x10), v, 1);
}
