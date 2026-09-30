/* Stores the value into the first word of the entity manager. */

extern int gEntityMgr;

void StoreToGlobalDblPtr(int arg0) {
    *(int *)(*(int *)&gEntityMgr) = arg0;
}
