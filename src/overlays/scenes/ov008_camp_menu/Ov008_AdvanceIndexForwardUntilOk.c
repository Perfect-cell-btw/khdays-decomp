extern int Ov008_Menu_ChangePage(void *context, int index);

void Ov008_AdvanceIndexForwardUntilOk(void *context, int index)
{
    do {
        index = (index + 1) % 8;
    } while (Ov008_Menu_ChangePage(context, index) == 0);
}
