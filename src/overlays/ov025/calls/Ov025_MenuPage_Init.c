extern int Ov025_GetPageA();
extern int Ov025_PageA_ResetSmall();
extern int Ov025_SetupGridMenuDisplay();
extern int Ov025_LoadMenuBgWithAltChars();
extern int Ov025_Config_Setup();
extern int Ov025_SetupMenuSurface();
extern int Ov025_MoveMenuCursor();

int Ov025_MenuPage_Init(int arg0) {
    Ov025_GetPageA(arg0);
    Ov025_PageA_ResetSmall();
    Ov025_SetupGridMenuDisplay();
    Ov025_LoadMenuBgWithAltChars();
    Ov025_Config_Setup();
    Ov025_SetupMenuSurface();
    Ov025_MoveMenuCursor(0);
    return 1;
}
