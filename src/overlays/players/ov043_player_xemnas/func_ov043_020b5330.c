/* Draws the request effect of every live entry of the object's list (types other than 0 and 3). */

extern void Ov043_DrawRequestEffect(int arg0);
void func_ov043_020b5330(int arg0) {
    int i = 0;
    if (i < *(unsigned char *)(arg0 + 0x19)) {
        int e = i;
        do {
            int slot = *(int *)(arg0 + 0xc) + e;
            char c = *(char *)(slot + 2);
            if (c != 0 && c != 3) Ov043_DrawRequestEffect(slot);
            i++;
            e += 0x1c8;
        } while (i < *(unsigned char *)(arg0 + 0x19));
    }
}
