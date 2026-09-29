/* Returns the entity manager's model group count (its first word): EntityManager_ReleaseViews
 * frees that many groups (records at +4, blocks at +0x44), which Entity_LoadAndAttach loads one per
 * player slot. No code that writes it has been found yet. */

extern int *data_0204c208;

int EntityMgr_GetModelGroupCount(void) {
    return *data_0204c208;
}
