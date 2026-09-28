/* Runs the callback of the tracker tagged 0x42. */

extern int Ov025_GetCtxBlock954c();
extern int Ov025_FindEntryByTag();
extern void Ov025_TagTracker_InvokeCallback();

void Ov025_LookupTag42AndDispatch(void) {
    int a = Ov025_GetCtxBlock954c();
    Ov025_TagTracker_InvokeCallback(a, Ov025_FindEntryByTag(a, 0x42));
}
