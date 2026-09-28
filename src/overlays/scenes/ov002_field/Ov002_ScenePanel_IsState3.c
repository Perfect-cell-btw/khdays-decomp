/* True when the scene panel exists and its state is 3. */

extern int data_ov002_0207f624;

int Ov002_ScenePanel_IsState3(void) {
    int p = *(int *)&data_ov002_0207f624;
    return p != 0 && *(int *)p == 3;
}
