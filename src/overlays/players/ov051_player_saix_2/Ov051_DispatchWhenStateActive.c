/* While the effect slot is active, sets its polygon id and draws it. */

extern void NNS_G3dMdlSetMdlPolygonID();
extern void Scene_DrawNode();

void Ov051_DispatchWhenStateActive(int this_) {
    if (*(int *)this_ != 1) return;
    NNS_G3dMdlSetMdlPolygonID(*(int *)(this_ + 0x80), 2, *(int *)(this_ + 4));
    Scene_DrawNode(this_ + 8);
}
