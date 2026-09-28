/* Screen pfnClose: renders the scene panels at +0x98. */

extern int Ov025_Menu_RenderScenePanels();

int Ov025_MenuScreenClose(int arg0) {
    return Ov025_Menu_RenderScenePanels(arg0 + 0x98);
}
