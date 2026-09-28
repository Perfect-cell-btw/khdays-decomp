/* Draw a page-A element via Text_DrawDirectional_2, optionally preceded by a drop-shadow pass offset by
 * (+1,+1,-1). The element base is page A + 0x78; param_1 is forwarded as the draw's last argument. */
extern int Ov025_GetPageA(void);
extern void Text_DrawDirectional_2(int base, int x, int y, int z, unsigned int flags, int arg);

void Ov025_DrawTextShadowed(int param_1, int param_2, int param_3, int param_4, unsigned int param_5, int param_6) {
    int page = Ov025_GetPageA();
    if (param_6 != 0) {
        Text_DrawDirectional_2(page + 0x78, param_2 + 1, param_3 + 1, param_4 - 1, param_5, param_1);
    }
    Text_DrawDirectional_2(page + 0x78, param_2, param_3, param_4, param_5, param_1);
}
