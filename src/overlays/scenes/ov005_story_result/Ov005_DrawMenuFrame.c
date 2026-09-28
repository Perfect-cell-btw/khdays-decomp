/* Historical SDK misidentification: this is ov005's texture-refresh/draw wrapper,
 * not FX_Inv. The linkage symbol is retained; ownership follows the actual calls. */
extern int Ov005_RefreshQuadTextures();
extern int Ov005_DrawVisibleMenuItems();

void Ov005_DrawMenuFrame(void) {
    Ov005_RefreshQuadTextures();
    Ov005_DrawVisibleMenuItems();
}
