/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to SceneNode_JointCallback. */
extern void *SceneNode_JointCallback();

void *func_0202afe8() {
    return SceneNode_JointCallback();
}
