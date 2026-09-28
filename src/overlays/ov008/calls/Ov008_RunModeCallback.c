extern int Ov008_GetCtxField95cc(void);
extern void (*data_ov008_0208e87c[])(void);
void Ov008_RunModeCallback(void)
{
    void (*callback)(void) = data_ov008_0208e87c[Ov008_GetCtxField95cc()];
    if (callback != 0) {
        callback();
    }
}
