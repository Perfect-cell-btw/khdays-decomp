/* Ov024_MobiClip_SrcOpen -- MobiClip: stream-source handler, slot +4 of the table installed by
 * Ov024_MobiClip_InstallStreamSourceVtbl. Opens the source through InstantiateClass, passing the descriptor at
 * data_ov024_02093904 and the caller's argument, and parks the resulting handle in
 * data_ov024_02093900 -- one live source at a time, not per-instance state. */
extern int InstantiateClass(void *desc, int arg);
extern int data_ov024_02093904;
extern int data_ov024_02093900;

void Ov024_MobiClip_SrcOpen(int arg) {
    data_ov024_02093900 = InstantiateClass(&data_ov024_02093904, arg);
}
