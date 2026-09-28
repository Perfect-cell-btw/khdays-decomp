extern int Ov022_IsState9Or6WithFlag200();
extern void BindAnimTrack();
extern void Ov051_UpdateGuardedSlots();
extern void Ov051_UpdateSlotsAndFlush();
extern void *data_ov051_020b7380;

void Ov051_beginStateBindHandlers(void *this)
{
    char *obj = (char *)*(int *)&data_ov051_020b7380;
    if ((*(unsigned long long *)((char *)this + 0x464) & 0x10000ULL) == 0 &&
        Ov022_IsState9Or6WithFlag200((char *)this + 0x22f8) == 0 &&
        *(int *)((char *)this + 0x6bc) != 0x2e) {
        BindAnimTrack((char *)this + 0xf10, 1, (char *)this + 0xff0, 0);
    }
    Ov051_UpdateGuardedSlots(this, obj + 0x2c2c, *(short *)((char *)this + 0x2aba));
    Ov051_UpdateSlotsAndFlush(this, obj + 0x2c2c);
}
