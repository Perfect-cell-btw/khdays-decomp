/* Screen close handler (pair of Ov002_EnterLinkSyncScene): clears global array 6 and the instance
 * pointer. */

extern int data_ov002_0207f9f4;
extern int ClearGlobalArrayInt();

void Ov002_LeaveLinkSyncScene(void) {
    ClearGlobalArrayInt(6);
    data_ov002_0207f9f4 = 0;
}
