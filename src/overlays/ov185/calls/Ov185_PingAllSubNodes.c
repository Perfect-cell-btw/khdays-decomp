/*
 * Ov185_PingAllSubNodes -- x3 (ov185/186/187). Ping all 4 sub-nodes, then tick the owner.
 * For i in 0..3, call 020c2b38(arg, (*(self+0x390))[i]); finish with 020c7c1c(self, arg).
 */
extern void Ov107_InvokeSlot0x74(int owner, int node);
extern void Ov107_Actor_DetachFromRegion(int self, int arg);

void Ov185_PingAllSubNodes(int self, int arg) {
    int i;

    for (i = 0; i < 4; i++) {
        Ov107_InvokeSlot0x74(arg, (*(int **)(self + 0x390))[i]);
    }
    Ov107_Actor_DetachFromRegion(self, arg);
}
