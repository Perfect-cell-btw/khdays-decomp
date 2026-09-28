/* Ov006_BlankScreensAndTeardownText -- blank both screens' BG mode bits and tear down the text layers. */
#define REG_DISPCNT     (*(volatile unsigned int *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile unsigned int *)0x04001000)
extern void Ov006_ResetTextLayers(void);   /* reset text layers */
extern void Ov006_FlushTextLayers(void);   /* flush text layers */
extern void Ov006_RequestMenuState(int a, int b, int c);

void Ov006_BlankScreensAndTeardownText(void) {
    REG_DISPCNT &= 0xffffe0ff;
    REG_DISPCNT_SUB &= 0xffffe0ff;
    Ov006_ResetTextLayers();
    Ov006_FlushTextLayers();
    Ov006_RequestMenuState(10, 0, 0);
}
