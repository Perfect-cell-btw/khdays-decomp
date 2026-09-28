extern void Ov008_UpdateMenuInput(void);
extern int Ov008_Shop_IsClosed(void);
extern void Ov008_ReturnToCommitPage(void);
void *Ov008_WaitShopClosed(void)
{
    void *result = 0;
    Ov008_UpdateMenuInput();
    if (Ov008_Shop_IsClosed() != 0) {
        result = Ov008_ReturnToCommitPage;
    }
    return result;
}
