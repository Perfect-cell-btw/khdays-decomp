extern int ScriptVm_ReadOperandInt(void);
extern int GameState_SetField(int query, int kind, int value);

/* Store the current party-slot index into stat key 0x2080 (kind 5). */
int Ov019_StoreSlotIndex(void) {
    int slot = ScriptVm_ReadOperandInt();
    GameState_SetField(0x82 << 6, 5, (unsigned short)slot);
    return 0;
}
