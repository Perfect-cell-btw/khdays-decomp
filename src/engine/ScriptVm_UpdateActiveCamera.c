/* Updates the active camera of the script's event block (+0x128): its 0x104-byte camera records
 * start at +0x30 and data_0204be04 selects the active one, as in Game_RunActionScript. */

extern void Game_UpdateObjectMotion();
extern unsigned char data_0204be04;

void ScriptVm_UpdateActiveCamera(int script) {
    Game_UpdateObjectMotion(*(int *)(script + 0x128) + 0x30 + data_0204be04 * 0x104);
}
