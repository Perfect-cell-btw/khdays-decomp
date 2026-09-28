extern int Ov025_Menu_RenderScenePanels();

int Ov025_MenuScreenClose(int arg0) {
    return Ov025_Menu_RenderScenePanels(arg0 + 0x98);
}
