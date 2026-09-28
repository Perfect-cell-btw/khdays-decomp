extern void RemoveChildFromListByPtr(int list, int child);
/* Remove the actor's attached sub-object (obj+0x9c) from the region's child list, if present. */
void Ov107_RemoveChildFromRegion(int obj, int region) {
    int child = *(int *)(obj + 0x9c);
    if (child != 0) {
        RemoveChildFromListByPtr(*(int *)(region + 0x100), child);
    }
}
