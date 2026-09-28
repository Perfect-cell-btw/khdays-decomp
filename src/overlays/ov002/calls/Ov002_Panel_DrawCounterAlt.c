extern int Ov002_PanelDrawCounter();

int Ov002_Panel_DrawCounterAlt(int a, int b, int c, int d) {
    return Ov002_PanelDrawCounter(a, b, c, d, 1);
}
