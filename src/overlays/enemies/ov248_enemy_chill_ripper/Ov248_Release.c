/* Tick of the ov248 actor's release step: unless bit 0 of the +0x60 low byte is set, the +0x394 node
 * is unlinked from the +0x3c list and cleared; then the base tick runs. */
typedef struct { unsigned short lo : 8; unsigned short hi : 8; } Flags60;

extern void TaskList_FinishByTag(int list, int node);
extern void Ov107_AiState_PostTickBase(int obj);

void Ov248_Release(int self)
{
    if (!(((Flags60 *)(self + 0x60))->lo & 1) && *(int *)(self + 0x394) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(self + 0x394));
        *(int *)(self + 0x394) = 0;
    }
    Ov107_AiState_PostTickBase(self);
}
