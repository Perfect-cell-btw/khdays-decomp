/* Clears the word at +0x24 of the second argument (its timer). */

void Ov086_Deactivate(void *unused, void *self)
{
    *(int *)((char *)self + 0x358) = 0;
}
