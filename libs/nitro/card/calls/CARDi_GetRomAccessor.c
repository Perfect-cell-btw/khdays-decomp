/* CARDi_GetRomAccessor: returns the address of the ROM accessor routine CARDi_ReadCard. */

extern void CARDi_ReadCard(void);

int CARDi_GetRomAccessor(void) {
    return (int)CARDi_ReadCard;
}
