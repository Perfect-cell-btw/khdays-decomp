typedef struct Widget {
    char unk_00[0x10];
    unsigned short wFlags;
} Widget;

void Ov002_SetWidgetHidden(int arg0, Widget *widget, int hide) {
    if (hide) {
        widget->wFlags &= ~0x4000;
    } else {
        widget->wFlags |= 0x4000;
    }
}
