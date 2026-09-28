/* Clears the word at +0x24 of the second argument (its timer). */

void Ov073_ClearTimer(void *unused, void *self)
{
    *(int *)((char *)self + 0x24) = 0;
}
