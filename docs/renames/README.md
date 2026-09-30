# Symbol renames

Tables of `old_name<TAB>new_name<TAB>module` for every rename that changed a function symbol, so
code outside this repository that refers to functions by name can migrate mechanically.

| File | What changed |
|---|---|
| `2026-09-27-sdk-and-veneers.tsv` | NitroSDK/NitroSystem identifications and the undoing of shape-matched names (`WM_EndKeySharing_0x*`, `SNDi_UnlockMutex_0x*`, ...). Some old names are reused as new names for other addresses (for example `SNDi_UnlockMutex`, `FX_Inv`, `OS_UnlockByWord`), so apply the table in one pass, never line by line. |
| `2026-09-28-function-names.tsv` | 22036 `func_<addr>` symbols given the names they carry in the Ghidra project. Functions whose name could not be verified keep `func_<addr>`. |
| `2026-09-29-header-placeholders.tsv` | The 56 `func_<addr>` placeholders left in the shared prototype headers (`include/game/engine.h`, `include/game/enemy_common.h`), named from their callers and the globals they touch (`Sleep_Block`, `GetFrameRateMode`, `SoundMgr_SwitchBgm`, ...). |
| `2026-09-30-field-controls.tsv` | Names the field's controls and traces say otherwise: the command deck's cursor movers (`Ov002_PanelCursorNext`/`Prev`/`StepRight`), the camera's `Ov002_Camera_LeaveLookView`, the lock-on `Ov022_TryLockOn`, the animation step's `Ov022_SetAnimSpeed`/`Ov022_StepScaledAnimTracks`, and the entity manager's casts with ready-made parameters. |
| `2026-09-29-sdk-names.tsv` | NitroSDK functions identified by their body (`func_02003948` is `OS_ResetSystem`). |
| `2026-09-29-misleading-names.tsv` | Names that described something else (`StreamReader_InitU16` is `NNS_G2dFontInitUTF16`, `Session_GetSlotTable` is `Session_GetSetup`, `Callbacks_SetByte` is `PauseMenu_SetMode`, ...). |

Addresses never change, so a name can always be recovered from `config/arm9/**/symbols.txt`.

The build reads these tables too: `tools/gen_delinks.py` uses them to carry a committed DATA
claim (a function's local `.rodata`) over to its source's new file name. Add a table for every
future rename of function symbols, and keep the old ones.
