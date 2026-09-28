/* Queues the panel graphics when the panel exists. */

extern int data_ov002_0207f634;
extern int Ov002_QueuePanelGraphics();

void Ov002_Panel_QueueGraphicsIfAny(void) {
    int p = *(int *)&data_ov002_0207f634;
    if (p != 0) {
        Ov002_QueuePanelGraphics(p);
    }
}
