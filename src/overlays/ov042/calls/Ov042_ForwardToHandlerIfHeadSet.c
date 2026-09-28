extern void Scene_DrawNode();

void Ov042_ForwardToHandlerIfHeadSet(int this_) {
    if (*(int *)this_ == 0) {
        return;
    }
    Scene_DrawNode(this_ + 4);
}
