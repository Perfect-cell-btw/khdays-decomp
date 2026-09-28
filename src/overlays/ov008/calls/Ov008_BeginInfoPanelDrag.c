extern char *Ov008_GetPageB(void);
extern void Ov008_DragInfoPanel(char *);
void Ov008_BeginInfoPanelDrag(void)
{
    char *obj = Ov008_GetPageB();
    if (*(int *)(obj + 0x180) == 0) {
        *(int *)(obj + 0x158) = 1;
        Ov008_DragInfoPanel(obj);
    }
}
