extern void RegisterSubscriberSlot(int list, int child);
/* Register the actor's attached sub-object (obj+0x9c) into the region's child list, if present. */
void Ov107_RegisterChildInRegion(int obj, int region) {
    int child = *(int *)(obj + 0x9c);
    if (child != 0) {
        RegisterSubscriberSlot(*(int *)(region + 0x100), child);
    }
}
