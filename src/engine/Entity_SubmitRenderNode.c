/* Submits the indexed entity's render node (Render_SubmitNode). */

extern void Render_SubmitNode(int, int, int, int);
extern int gEntityMgr;

void Entity_SubmitRenderNode(int param_1, int param_2, int param_3, int param_4) {
    Render_SubmitNode(gEntityMgr + 0xc4 + param_1 * 0x184, param_2, param_3, param_4);
}
