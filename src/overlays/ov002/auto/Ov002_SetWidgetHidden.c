/* Set or clear the widget's hidden bit (0x4000 of the flags halfword at +0x10). */

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
