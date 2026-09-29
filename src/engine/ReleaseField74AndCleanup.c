/* Releases a model instance: frees its resource tables, releases its animation sequence (+0x74) and
 * detaches its scene node. */

extern void FreeAllResourceTables();
extern void ResSlot_ReleaseResource();
extern void ResSlot_Release();
extern void SceneNode_Detach();

void ReleaseField74AndCleanup(void *pThis_) {
    int this_ = (int)pThis_;
    FreeAllResourceTables(this_ + 0xe0);
    if (*(int *)(this_ + 0x74) != 0) {
        ResSlot_ReleaseResource(*(int *)(this_ + 0x74));
        ResSlot_Release(*(int *)(this_ + 0x74));
    }
    *(int *)(this_ + 0x74) = 0;
    SceneNode_Detach(this_);
}
