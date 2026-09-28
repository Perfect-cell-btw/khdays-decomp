/* If the pointer at *global is non-null, forward it (with param_1). */
extern void Ov002_SceneApplyPanelRequest(int arg, int ptr);
extern int data_ov002_0207f624;

void Ov002_Scene_ApplyPanelRequestIfAny(int param_1) {
    int ptr = *(int *)&data_ov002_0207f624;
    if (ptr != 0) {
        Ov002_SceneApplyPanelRequest(param_1, ptr);
    }
}
