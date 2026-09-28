extern void Ov025_GetCtxBlock954c(void);
extern int Ov025_GetCtxObject9630(void);
extern int Ov025_GetCtxObject9634(void);
extern void Ov025_MissionList_ShowSlotArrows(char *self);
extern void Ov025_LayoutMissionCounter(char *self);
extern void Ov025_LayoutMissionTiles(char *self);
extern void Ov025_LookupTag42AndDispatch(char *self);
extern void Ov025_LayoutMissionDots(char *self);

/* Draws the shop row in the style the current mode calls for. */
void Ov025_DrawShopRow(char *self) {
    Ov025_GetCtxBlock954c();
    if (Ov025_GetCtxObject9630() != 0) {
        if (Ov025_GetCtxObject9634() != 0) {
            Ov025_MissionList_ShowSlotArrows(self);
            return;
        }
        Ov025_LayoutMissionCounter(self);
        Ov025_LayoutMissionTiles(self);
        return;
    }
    if (*(int *)(self + 0x38) != 0) {
        Ov025_LookupTag42AndDispatch(self);
    } else {
        Ov025_LayoutMissionDots(self);
    }
    Ov025_LayoutMissionTiles(self);
}
