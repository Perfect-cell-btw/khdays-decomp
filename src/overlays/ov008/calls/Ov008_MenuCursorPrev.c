extern char *Ov008_GetMenuContext(void);
extern void PlaySound(int arg0, int arg1);
extern void Ov008_MoveMenuCursor(int arg0);

void Ov008_MenuCursorPrev(void)
{
    char *context = Ov008_GetMenuContext();

    PlaySound(0, 2);
    Ov008_MoveMenuCursor((short)(*(short *)context - 1));
}
