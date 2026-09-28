/* Stores a widget's tag halfword (+0x104). */

void Widget_SetTagWord(unsigned short *p, unsigned short v) {
    p[0x82] = v;
}
