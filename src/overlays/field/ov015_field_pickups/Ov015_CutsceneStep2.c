extern void Ov002_GetModuleScale(char *self);
extern int Ov002_GetRootField8b68Alt(void);
extern void Ov002_StreamFormattedLine(void *desc, char *out);
extern int Session_IsActive(void);
extern void Ov002_SetRootField8b41(int mask);
extern int Ov002_GetRootField8b41(void);
extern void Ov002_SetRootField8b40(void);
extern void Ov002_SetFieldBit0(char *self, int a);
extern void Ov002_DoneTick(void);
extern int data_ov015_02082900;

/* Step 2 of the cutscene: once the loader is idle, reads the next command, drops the two skip
 * flags on the retail build and hands over to step 3. */
void *Ov015_CutsceneStep2(char *self) {
    Ov002_GetModuleScale(self);
    if (*(unsigned char *)(self + 0x50) == 2) {
        if (Ov002_GetRootField8b68Alt() != 0) {
            return 0;
        }
        Ov002_StreamFormattedLine(&data_ov015_02082900, self + 0x51);
        if (Session_IsActive() != 0) {
            Ov002_SetRootField8b41(0);
        } else {
            Ov002_SetRootField8b41((unsigned char)(Ov002_GetRootField8b41() & ~0xa));
        }
        Ov002_SetRootField8b40();
        *(char *)(self + 0x50) = 3;
        Ov002_SetFieldBit0(self, 0);
        return (void *)&Ov002_DoneTick;
    }
    return 0;
}
