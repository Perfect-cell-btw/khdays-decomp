/*
 * Ov255_PingAllSubNodes -- x3 (ov185/186/187). Ping all 9 sub-nodes, then tick the owner.
 * For i in 0..3, call 020c2b38(arg, (*(self+0x3f0))[i]); finish with 020c7c1c(self, arg).
 */
extern void Ov107_InitObjectFromSource(int owner, int node);
extern void Ov107_HandleRegionEvent(int self, int arg);

void Ov255_PingAllSubNodes(int self, int arg) {
    int i;

    for (i = 0; i < 9; i++) {
        Ov107_InitObjectFromSource(arg, (*(int **)(self + 0x3f0))[i]);
    }
    Ov107_HandleRegionEvent(self, arg);
}
