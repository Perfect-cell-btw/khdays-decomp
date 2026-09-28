extern void Ov027_FloatCharacterObject(int obj);
extern void Ov002_ResetViewToDefault(void);
extern void Ov002_ResourceEntryCallback(int arg);
extern char data_ov027_02084360[];
/* Run the per-frame update, flush, then forward the active entry (*(table+4)+0x588) to the HUD. */
void Ov027_UpdateFlushForward(int obj) {
    Ov027_FloatCharacterObject(obj);
    Ov002_ResetViewToDefault();
    Ov002_ResourceEntryCallback(*(int *)(data_ov027_02084360 + 4) + 0x588);
}
