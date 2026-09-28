/* Ov006_ResetTextLayers -- reset the two Mission Mode-screen BG text layers (ctx+0x976c, +0x97b8, mode 0). */
extern void CallVirtSlot1(int layer, int mode);
extern int  data_ov006_02056664;   /* -> Mission Mode-screen context */

void Ov006_ResetTextLayers(void) {
    CallVirtSlot1(data_ov006_02056664 + 0x976c, 0);
    CallVirtSlot1(data_ov006_02056664 + 0x97b8, 0);
}
