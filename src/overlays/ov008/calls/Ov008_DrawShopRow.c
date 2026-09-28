extern void Ov008_GetCtxBlock954c(void);
extern int Ov008_GetCtxObject9630(void);
extern int Ov008_GetCtxObject9634(void);
extern void Ov008_UpdateMissionListArrows(char *self);
extern void Ov008_LayoutMissionCounter(char *self);
extern void Ov008_LayoutMissionTiles(char *self);
extern void Ov008_LookupTag42AndDispatch(char *self);
extern void Ov008_LayoutMissionDots(char *self);

/* Draws the shop row in the style the current mode calls for. */
void Ov008_DrawShopRow(char *self) {
    Ov008_GetCtxBlock954c();
    if (Ov008_GetCtxObject9630() != 0) {
        if (Ov008_GetCtxObject9634() != 0) {
            Ov008_UpdateMissionListArrows(self);
            return;
        }
        Ov008_LayoutMissionCounter(self);
        Ov008_LayoutMissionTiles(self);
        return;
    }
    if (*(int *)(self + 0x38) != 0) {
        Ov008_LookupTag42AndDispatch(self);
    } else {
        Ov008_LayoutMissionDots(self);
    }
    Ov008_LayoutMissionTiles(self);
}
