/* Ov000_DispatchLogoAction -- dispatch a logo action by selector, ov000. Routes arg to
 * one of three handlers (0/1/2); ignores any other selector. */
extern void Ov000_DrawModeIcon(int arg);
extern void Ov000_ModeSelect_DrawVariants(int arg);
extern void Ov000_SelectPanelText(int arg);
void Ov000_DispatchLogoAction(int sel, int arg) {
    switch (sel) {
    case 0: Ov000_DrawModeIcon(arg); break;
    case 1: Ov000_ModeSelect_DrawVariants(arg); break;
    case 2: Ov000_SelectPanelText(arg); break;
    }
}
