/* Enables (1) or disables (0) a scene node. */

extern int SceneNode_Disable();
extern int SceneNode_Enable();

void Ov002_SetSceneNodeEnabled(int arg0, int arg1) {
    switch (arg1) {
    case 0:
        SceneNode_Disable(arg0);
        break;
    case 1:
        SceneNode_Enable(arg0);
        break;
    }
}
